import bpy
import math
from mathutils import Vector

# pre-calculated proportions
tri_h = math.sqrt(3) / 2  # edge to top
tri_c = math.sqrt(3) / 3  # edge to center


# triangle function
def create_equilateral_triangle(name, scale, origin=Vector((0, 0, 0))):
    # shape components
    coords = [
        origin + Vector((0, 0, 0)),
        origin + Vector((scale, 0, 0)),
        origin + Vector((scale / 2, scale * tri_h, 0))
    ]
    edges = [
    ]
    faces = [
        (0, 1, 2)
    ]

    # create new mesh and new object
    mesh = bpy.data.meshes.new(f'{name}-mesh')
    obj = bpy.data.objects.new(name, mesh)

    # make mesh from shape components
    mesh.from_pydata(coords, edges, faces)

    # show name and update the mesh
    mesh.update()

    # link object to active collection
    bpy.context.collection.objects.link(obj)

    return obj


def copy_cat_triangle(obj, suffix, translate):
    # duplicate object
    obj2 = bpy.data.objects.new(obj.name + suffix, obj.data)

    # move object
    obj2.location += translate

    # link object to active collection
    bpy.context.collection.objects.link(obj2)

    return obj2

def clear_extra_vertices():
    # clean up extra vertices
    # disable this for bpy.ops.mesh.select_more() to color entire tris (vs sides)
    bpy.ops.object.mode_set(mode='EDIT')
    bpy.ops.mesh.select_all(action='SELECT')
    bpy.ops.mesh.remove_doubles(threshold=merge_threshold)
    bpy.ops.object.mode_set(mode='OBJECT')


def grenier_hormann_clipping(tri):
    # defining the bounding box of the initial triangle
    min_x = min(vert.co.x for vert in triangle.data.vertices)
    min_y = min(vert.co.y for vert in triangle.data.vertices)
    max_x = max(vert.co.x for vert in triangle.data.vertices)
    max_y = max(vert.co.y for vert in triangle.data.vertices)
    
    # defining the vertices of the initial triangle
    vertices = [
        (vert.co.x, vert.co.y) for vert in triangle.data.vertices 
    ]
    
    for obj in bpy.data.objects:
        if obj != triangle and obj.type == 'MESH':
            obj_vertices = [
                (v.co.x, v.co.y) for v in obj.data.vertices
            ]
            # check any vertex of the triangle lies outside the initial triangle bounding box
            if any((vx < min_x or vx > max_x) or (vy < min_y or vy > max_y) for vx, vy in obj_vertices):
                # select the objects to be clipped
                obj.select_set(True)
    
    # clip aka remove the selected objects                
    bpy.ops.objects.delete()


def main():
    # set iterations
    iter = 3  # 8
    # set sizes
    size = 10
    unit = size / (2 ** iter)
    merge_threshold = unit / 2

    # offset 3d cursor
    cursor = bpy.context.scene.cursor.location
    offset = cursor + Vector((-size / 2, -size * tri_c / 2, 0))

    # create base triangle
    triangle = create_equilateral_triangle('Sierpinski Triangle', unit, offset)

    # iterations
    for i in range(iter):

        # set base transform
        base = 2 ** i

        # set tri
        triangle = bpy.data.objects['Sierpinski Triangle']

        # duplicate/move the "object" in x axis
        triangle_x = copy_cat_triangle(triangle, '-X', Vector((base * unit, 0, 0)))
        triangle_x.select_set(state=True)

        # duplicate/move the "object" on triangle direction
        triangle_t = copy_cat_triangle(triangle, '-T', Vector((base * unit / 2, base * unit * tri_h, 0)))
        triangle_t.select_set(state=True)

        # join all objects as "object"
        triangle.select_set(state=True)
        bpy.context.view_layer.objects.active = triangle
        bpy.ops.object.join()
        
        # apply the clipping algorithms to the triangle
        # grenier_hormann_clipping(triangle)
        
        # pause for 2 seconds
        # bpy.context.scene.frame_set(bpy.context.scene.frame_current + 20)
        
    clear_extra_vertices()
    
if __name__ == '__main__':
    main()