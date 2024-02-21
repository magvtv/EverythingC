#include <GL/glut.h>
#include <iostream>
#include <cmath>

// function to draw points symmetrically around the center
void drawSymmerticPoints(int x, int y, int cx, int cy)
{
    glBegin(GL_POINTS);
    glVertex2i(cx + x, cy + y); // draw point
    glVertex2i(cx - x, cy + y); // point in the 2nd quadrant
    glVertex2i(cx + x, cy - y); // point in 3rd quadrant
    glVertex2i(cx - x, cy - y); // point in 4th quadrant
    glEnd();
}

// the main drawing algorithm function
void BresenhamEllipse(int cx, int cy, int rx, int ry)
{
    float x = 0, y = ry;
    float dx = 0, dy = (2 * pow(rx, 2) * y);

    // initial 1st region decision parameter
    float d = (pow(ry, 2) - (pow(rx, 2) * ry) + (0.25 * pow(rx, 2)));

    while (dx < dy)
    {
        drawSymmerticPoints(x, y, cx, cy);
        x++;
        dx += 2 * pow(ry, 2);
        if (d < 0)
        {
            d += dx + pow(ry, 2);
        }
        else
        {
            y--;
            dy -= 2 * pow(rx, 2);
            d += dx - dy + pow(ry, 2);
        }
    }

    // inital 2nd region decision parameter
    d = (pow(ry, 2) * pow((x + 0.5), 2)) + (pow(rx, 2) * pow((y - 1), 2)) - (pow(rx, 2) * pow(ry, 2));
    while (y >= 0)
    {
        y--;
        dy -= 2 * pow(rx, 2);
        if (d > 0)
        {
            d += pow(rx, 2) - dy;
        }
        else
        {
            dx += 2 * pow(ry, 2);
            d += dx - dy + pow(rx, 2);
        }
    }
}

// initialize the glut opengl settings to white background
void initOpenGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, -6, 6); // setting the co-ordinate system
}

// display the graphics rendered by the bresenham ellipse algorithm
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);  // set the color to green
    BresenhamEllipse(0, 0, 5, 3); // center (0, 0) with rx = 5 and ry = 3
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);     // set the window size
    glutInitWindowPosition(100, 100); // set the window position
    glutCreateWindow("Bresenham Ellipse Algorithm");

    initOpenGL();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}