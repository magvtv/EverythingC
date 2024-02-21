#include <GL/glut.h>

// initializing the opengl settings
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // set the color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10); // set the co-ordinate system
}

// function that does that
void drawSquare()
{
    glColor3f(0.0f, 0.0f, 1.0f); // set the color to blue
    glBegin(GL_QUADS);
    glVertex2f(-3, 5);
    glVertex2f(0, -4);
    glVertex2f(3, 7);
    glVertex2f(6, -2);
    glEnd();
}

// functions that renders the graphics of the square above
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawSquare();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Blue Square");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}