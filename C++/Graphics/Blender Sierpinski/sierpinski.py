import bpy
import math
from mathutils import Vector as Vec

triangle_edge_top = math.sqrt(3) / 2        #triangle_h
triangle_edge_center = math.sqrt(3) / 3     #triangle_c

def create_equilateral_triangle(name, scale, origin=Vec(0, 0, 0)):
    vertices = [
        origin + Vec((0, 0, 0)),
        origin + Vec((scale, 0, 0)),
        origin + Vec(((0.5 * scale), (scale * triangle), 0))
    ]
    
    edges = []
    faces = [
        (0, 1, 2)
    ]
    mesh = bpy.data.meshes.new(f'{name}-mesh')      # creating new mesh
    obj = bpy.data.objects.new(name, mesh)          # creating new object
    mesh.from_pydata(vertices, edges, faces)        # making mesh with shape components
    mesh.update()                                   # show name, update the mesh
    bpy.context.collection.object.link(obj)         # link object to active collection
    return obj


def copy_cat_triangle(obj, suffix, transform):
    obj2 = bpy.data.objects.new(obj.name + suffix, obj.data)    # duplicate the triangle
    obj.location += transform                                   # move object
    bpy.context.collection.objects.link(obj2)                   # link object to active collection
    return obj2


def main():
    levels = 3
    size = 10
    unit_measure = pow((0.5 * size), levels)
    merge_threshold = unit_measure * 0.5
    
    cursor = bpy.context.scene.cursor.location
    offset = cursor + Vec((-size / 2), (-size * triangle_edge_center / 2), 0)
    triangle = triangle("Triangle", unit_measure, offset)
    
    for x in range(levels):
        base = pow(2, x)                            # set base transform
        triangle = bpy.data.object["Triangle"]      # set triangle
        triangle_x = copy_cat_triangle(triangle, '-X', Vec(unit_measure * base, 0, 0))
        triangle_x.select_set(state=True)
        triangle_t = copy_cat_triangle(triangle, '-T', Vec(((base * unit_measure) * 0.5), (base * unit_measure * triangle_edge_top), 0))
        triangle_t.select_set(state=True)
        
        triangle.select_set(state=True)
        bpy.context.view_layer.objects.active = triangle
        bpy.ops.objects.join()
        
    def clear_extra_vertices():
        bpy.ops.object.mode_set(mode='EDIT')
        bpy.mesh.select_all(action='SELECT')
        bpy.ops.mesh.remove_doubles(threshold=merge_threshold)
        bpy.ops.object.mode_set(mode='OBJECT')
        
if __name__ =='__main__':
    main()
    
    
    
    
    

