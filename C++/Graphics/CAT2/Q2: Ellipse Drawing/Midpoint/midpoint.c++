#include <GL/glut.h>
#include <iostream>
#include <cmath>

void drawSymmerticPoints(int x, int y, int cx, int cy)
{
    glBegin(GL_POINTS);
    glVertex2i(cx + x, cy + y);
    glVertex2i(cx - x, cy + y);
    glVertex2i(cx + x, cy - y);
    glVertex2i(cx - x, cy - y);
    glEnd();
}

void MidpointEllipse(int cx, int cy, int rx, int ry)
{
    float x = 0, y = ry;
    float dx = 0, dy = (2 * pow(rx, 2) * ry);

    // initial 1st region parameter
    float d1 = (pow(ry, 2) - (pow(rx, 2) * ry) + (0.25 * pow(rx, 2)));

    while (dx < dy)
    {
        drawSymmerticPoints(x, y, cx, cy);
        x++;
        dx += (2 * pow(ry, 2));
        if (d1 < 0)
        {
            d1 += (dx + pow(ry, 2));
        }
        else
        {
            y--;
            dy -= 2 * pow(rx, 2);
            d1 += dx - dy + pow(ry, 2);
        }
    }

    float d2 = (pow(ry, 2) * pow((x + 0.25), 2) + (pow(rx, 2) * pow((y - 1), 2) - (pow(rx, 2) * pow(ry, 2))));

    while (y >= 0)
    {
        drawSymmerticPoints(x, y, cx, cy);
        y--;
        dy -= 2 * pow(rx, 2);
        if (d2 > 0)
        {
            d2 += pow(rx, 2) - dy;
        }
        else
        {
            x++;
            dx += 2 * pow(ry, 2);
            d2 += dx - dy + pow(rx, 2);
        }
    }
}

void initOpenGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, -6, 6);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);
    MidpointEllipse(0, 0, 5, 3);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("MidPoint Ellipse Algorithm");

    initOpenGL();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}