#include <GL/glut.h>
#include <iostream>
#include <cmath>

void drawSymmetricPoints(int x, int y, int cx, int cy)
{
    glBegin(GL_POINTS);
    glVertex2i((cx + x), (cy + y));
    glVertex2i((cx - x), (cy + y));
    glVertex2i((cx + x), (cy - y));
    glVertex2i((cx - x), (cy - y));
    glEnd();
}

// implementing the bresenham's circle algorithm
void BresenhamCircle(int cx, int cy, int radius)
{
    int x = 0;
    int y = radius;
    int d = 3 - (2 * radius);

    drawSymmetricPoints(x, y, cx, cy);

    while (x <= y)
    {
        if (d <= 0)
        {
            d += (4 * x) + 6;
        }
        else
        {
            d += (4 * (x - y)) + 10;
            y--;
        }
        x++;
        drawSymmetricPoints(x, y, cx, cy);
    }
}
// function that draws the black diameter
void drawLine(int x1, int y1, int x2, int y2)
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    BresenhamCircle(3, 3, 4);
    drawLine((3 - 4), 3, (3 + 4), 3);
    glFlush();
}

void initOpenGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 6, 0, 6);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham\'s Circle & Black Diameter");

    initOpenGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}