#include <GL/glut.h>
#include <cmath>

class SquareAnimation
{
private:
    float centerX, centerY;
    float radius;
    float angle;
    float speed;

public:
    SquareAnimation(float centerX, float centerY, float radius, float speed) : (centerX(centerX), centerY(centerY), radius(radius), angle(0.0f), speed(speed)) {}

    // function to initialize open gl
    void init()
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glMatrixMode(GL_PROJECTION);
        gluOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    }

    // function to draw the square
    void drawSquare()
    {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f((-5.0f), (-5.0f));
        glVertex2f((5.0f), (-5.0f));
        glVertex2f((5.0f), (5.0f));
        glVertex2f((-5.0f), (5.0f));
        glEnd();
    }

    // function to update the animation
    void update(int value)
    {
        // update angle
        angle += speed;
        if (angle >= 360.0f)
        {
            // ensure angle is within 0 to 360 range
            angle -= 360.0f;
        }
        glutPostRedisplay();
        glutTimerFunc(30, update, 0) // recursive animation call
    }

    // function to display the square and its animation
    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(centerX, centerY, 0.0f); // translate to the center of the circular path
        glRotatef(angle, 0.0f, 0.0f, 1.0f);   // rotate by the current angle around the z-axis

        // draw the square at the origin (0,0)
        drawSquare();
        glFlush();
    }
}

// initialize the SquareAnimation object
SquareAnimation squareAnimate(0, 0, 30, 1.0f)

    // display callback function
    void display()
{
    squareAnimate.display()
}

// timer callback function for animation
void update(int value)
{
    squareAnimate.update(value)
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // initialize glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Square Animation (Matrix Transformation)");
    squareAnimate.initialize();  // initialize opengl
    glutDisplayFunc(display);    // set display callback function
    glutTimerFunc(0, update, 0); // immediately start animation timer
    glutMainLoop();              // enter glut event processing loop
    return 0;
}