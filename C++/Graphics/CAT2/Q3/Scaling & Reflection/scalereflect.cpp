#include <GL/glut.h>
#include <iostream>
#include <cmath>

// square corners
float square[4][2] = {
    {-1.5f, -1.5f},
    {-1.5f, 1.5f},
    {1.5f, 1.5f},
    {1.5f, -1.5f}};

void drawSquare()
{
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 4; ++i)
    {
        glVertex2f(square[i][0], square[i][1]);
    }
    glEnd();
}

void scaleSquare(float factor)
{
    for (int i = 0; i < 4; ++i)
    {
        square[i][0] *= factor;
        square[i][1] *= factor;
    }
}

void reflectSquare()
{
    for (int i = 0; i < 4; ++i)
    {
        square[i][0] *= -1;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    scaleSquare(2.0f);
    drawSquare();

    reflectSquare();
    drawSquare();

    glFlush();
}

// initializing opengl settings
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5, 5, -5, 5); // setting the coordinate system
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scaling & Reflection");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}