#include <GL/glut.h>
#include <iostream>
#include <cmath>
void drawSymmetricalPoints(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glVertex2i(-x, y);
    glVertex2i(x, -y);
    glVertex2i(-x, -y);
    glEnd();
}

// implementing the midpoint circle algorithm with (cx, cy) c for 'center'
void MidPointCircle(int cx, int cy, int radius)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    drawSymmetricalPoints(cx, cy);

    while (x < y)
    {
        x++;

        if (p < 0)
        {
            p += ((2 * x) + 1);
        }
        else
        {
            y--;
            p += (2 * (x - y)) + 1;
        }

        drawSymmetricalPoints((cx + x), (cy + y));
        drawSymmetricalPoints((cx - x), (cy + y));
        drawSymmetricalPoints((cx + x), (cy - y));
        drawSymmetricalPoints((cx - x), (cy - y));

        drawSymmetricalPoints((cx + y), (cy + x));
        drawSymmetricalPoints((cx - y), (cy + x));
        drawSymmetricalPoints((cx + y), (cy - x));
        drawSymmetricalPoints((cx - y), (cy - x));
    }
}

// rendering the actual grpahics
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    MidPointCircle(3, 3, 4);
    glFlush();
}

// initializing opengl settings
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 6, 0, 6); // setting the coordinate system
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}