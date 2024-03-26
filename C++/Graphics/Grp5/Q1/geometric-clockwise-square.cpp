#include <GL/glut.h>
#include <cmath>

// parameters for the animation
float centerX = 0.0f;
float centerY = 0.0f;
float radius = 100.0f;
float angle = 0.0f;
float squareSize = 20.0f;

void init()
{
    // white background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // setting the viewing area
    gluOrtho2D(-200, 200, -200, 200);
}

void drawSquare(float x, float y, float size)
{
    glBegin(GL_QUADS);
    glVertex2f(((x - size) / 2), ((y - size) / 2));
    glVertex2f(((x + size) / 2), ((y - size) / 2));
    glVertex2f(((x + size) / 2), ((y + size) / 2));
    glVertex2f(((x - size) / 2), ((y + size) / 2));
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the color buffer

    // calculate the square position along the circular path
    float posX = centerX + radius * cos(angle);
    float posY = centerY + radius * sin(angle);

    // draw the black square at the calculated position
    glColor3f(0.0f, 0.0f, 0.0f);
    drawSquare(posX, posY, squareSize);
    glFlush(); // flush the buffer
}

// function to update the animation
void update(int value)
{
    angle += 0.02f;               // angle increment to move the square along the circular path
    glutPostRedisplay();          // mark the current window to be redisplayed with angle increment
    glutTimerFunc(16, update, 0); // call update function approx. 60 frames / sec
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // initialize glut
    glutInitWindowSize(400, 400);
    glutCreateWindow("Circular Animation");
    init();                      // initialize opengl
    glutDisplayFunc(display);    // set display callback function
    glutTimerFunc(0, update, 0); // immediately start the update function
    glutMainLoop();              // enter glut event processing loop
    return 0;
}

/*
    having the script encapsulated with a class 'SquareAnimation'
*/