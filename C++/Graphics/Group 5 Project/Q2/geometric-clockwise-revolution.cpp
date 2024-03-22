#include <GL/glut.h>
#include <cmath>

class SquareAnimation
{
private:
    float centerX, centerY; // current center of rotation
    float radius;           // radius of the circular path
    float angle;            // current rotation angle
    float speed;            // angular speed of rotation

public:
    SquareAnimation(float centerX, float centerY, float radius, float speed) : centerX(centerX), centerY(centerY), radius(radius), angle(0.0f), speed(speed) {}

    // function to initialize open gl
    void init()
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-50, 50, -50, 50);
    }

    // function to draw the square
    void drawSquare(float x, float y)
    {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f((x - 5), (y - 5));
        glVertex2f((x + 5), (y - 5));
        glVertex2f((x + 5), (y + 5));
        glVertex2f((x - 5), (y + 5));
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

    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        float newX = centerX + radius * cos(angle * (M_PI / 180.0f));
        float newY = centerY + radius * sin(angle * (M_PI / 180.0f));

        glTranslatef(newX, newY, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        drawSquare(0, 0);
        glFlush();
    }
}

// initialize SquareAnimation object 'squareAnimation'
SquareAnimation(0, 0, 30, 1.0f);

// display callback function
void display()
{
    SquareAnimation.display();
}

// timer callback function for animation
void update(int value)
{
    SquareAnimation.update(value);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // initialize glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Square Animation (Geometric Transformation)");
    SquareAnimation.init();      // initialize opengl
    glutDisplayFunc(display);    // set display callback function
    glutTimerFunc(0, update, 0); // immediately start animation timer
    glutMainLoop();              // enter glut event processing loop
    return 0;
}