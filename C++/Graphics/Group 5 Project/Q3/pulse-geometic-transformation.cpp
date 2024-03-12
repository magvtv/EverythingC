#include <GL/glut.h>
#include <cmath>

class SquareAnimation
{
private:
    float centerX, centerY; // center to the circular path
    float radius;           // radius of the circular path
    float angle;            // current rotation angle
    float speed;            // angular rotation speed
    bool pulse;             // flag to control pulse effect
    float pulseFactor;      // scaling factor for pulse effect

public:
    SquareAnimation(float centerX, float centerY, float radius, float speed) : centerX(centerX), centerY(centerY), radius(radius), angle(0.0f), speed(speed), pulse(false), pulseFactor(1.0f) {}

    void initialize()
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white background
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-50, 50, -50, 50); // set orthographic projection
    }

    void drawSquare(float x, float y)
    {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black color
        glVertex2f(((x - 5) * pulseFactor), ((y - 5) * pulseFactor));
        glVertex2f(((x + 5) * pulseFactor), ((y - 5) * pulseFactor));
        glVertex2f(((x + 5) * pulseFactor), ((y + 5) * pulseFactor));
        glVertex2f(((x - 5) * pulseFactor), ((y + 5) * pulseFactor));
        glEnd();
    }

    void update(int value)
    {
        angle += speed;
        if (angle >= 360.0f)
        {
            angle -= 360.0f; // ensure angle remains within 0 - 360 range
            pulse = !pulse;  // toggle pulse flag for each revolution
            pulseFactor = 1.0f;
        }

        if (pulse)
        {
            pulseFactor = 1.0f - (angle / 360.0f) * 0.5f;
        }

        glutPostRedisplay();          // request a redraw
        glutTimerFunc(30, update, 0); // recursive call animation
    }

    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        float newX = centerX + radius * cos(angle * (M_PI / 180.0f));
        float newY = centerY + radius * sin(angle * (M_PI / 180.0f));

        drawSquare(newX, newY); // draw the scaled square at the new position
        glFlush();
    }

    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(centerX, centerY, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        glTranslatef(radius, 0.0f, 0.0f);

        drawSquare();
        glFlush();
    }
}

// initialize SquareAnimation object 'squareAnimation'
SquareAnimation squareAnimation(0, 0, 30, 1.0f);

// display callback function
void display()
{
    squareAnimation.display();
}

// timer callback function for animation
void update(int value)
{
    squareAnimation.update(value);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // initialize glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pulse Effect Square Animation (Geometric Transformation)");
    squareAnimation.initialize(); // initialize opengl

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}