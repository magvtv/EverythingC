#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

const float xFactor = cos(-M_PI / 3) * 0.6f;
const float yFactor = sin(-M_PI / 3) * 0.6f;

// create the corners of the triangle
float vertices[] = {
    0.0f, 0.6f, 0.0f,                                          // top corner
    0.0f, -0.6f, 0.0f,                                         // bottom left corner
    xFactor, 0.0f, 0.0f,                                       // bottom right corner
    float(xFactor / sqrt(3)), float(yFactor / sqrt(3)), 0.6f,  // top left vertex
    float(xFactor / sqrt(3)), float(yFactor / sqrt(3)), -0.6f, // top right vertex

};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3fv(&vertices[0]);
    glVertex3fv(&vertices[1]);
    glVertex3fv(&vertices[2]);
    glVertex3fv(&vertices[3]);
    glVertex3fv(&vertices[4]);
    glVertex3fv(&vertices[5]);
    glEnd();
};

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Sierpinski Triangle: Level 2 ");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
