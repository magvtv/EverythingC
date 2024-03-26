#include <GL/glut.h>
#include <cmath>
class SquareAnimation
{
private:
    float centerX, centerY;
    float radius;
    float angle;
    float speed;
    bool pulse;
    float pulseFactor;

public:
    SquareAnimation(float centerX, float centerY, float radius, float speed) : centerX(centerX), centerY(centerY), radius(radius), angle(0.0f), speed(speed), pulse(false), pulseFactor(1.0f) {}

    void initialize()
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white background
        glMatrixMode(GL_PROJECTION);
        glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0); // set orthographic projection
    }

    void drawSquare()
    {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f((-5.0f * pulseFactor), (-5.0f * pulseFactor));
        glVertex2f((5.0f * pulseFactor), (-5.0f * pulseFactor));
        glVertex2f((5.0f * pulseFactor), (5.0f * pulseFactor));
        glVertex2f((-5.0f * pulseFactor), (5.0f * pulseFactor));
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
            pulseFactor = 0.5f * (1.0f - (angle / 360.0f));
        }

        glutPostRedisplay(); // request a redraw
    }

    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(centerX, centerY, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        drawSquare();
        glFlush();
    }

    static void updateWrapper(int value)
    {
        SquareAnimation *instance = static_cast<SquareAnimation *>(glutGetWindow());
        if (instance)
        {
            instance->update();
            glutTimerFunc(30, updateWrapper, 0)
        }
        squareAnimation.display();
    }
}

// initialize SquareAnimation object 'squareAnimation'
SquareAnimation squareAnimation(0, 0, 30, 1.0f);

// display callback function
void display()
{

    SquareAnimation *instance = static_cast<SquareAnimation *>(glutGetWindow());
    if (instance)
    {
        instance->update();
        glutTimerFunc(30, updateWrapper, 0)
    }
    squareAnimation.display();
}

SquareAnimation *createSquareAnimation()
{
    return new SquareAnimation(0, 0, 30, 1.0f);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // initialize glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pulse Effect Square Animation (Matrix Transformation)");

    SquareAnimation *squareAnimation = createSquareAnimation();
    glutSetWindow(squareAnimation);
    squareAnimation->initialize(); // initialize opengl

    glutDisplayFunc(display);
    glutTimerFunc(0, SquareAnimation::updateWrapper, 0);

    glutMainLoop();
    delete squareAnimation;
}