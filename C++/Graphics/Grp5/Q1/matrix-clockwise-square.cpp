#include <GL/glut.h>
#include <cmath>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float SQUARE_SIZE = 50.0f;
const float CIRCLE_RADIUS = 200.0f;
const float ANIMATION_SPEED = 1.0f;

class OpenGLAnimation
{
private:
    static float angle;

public:
    OpenGLAnimation()
    {
        angle = 0.0f;
    }

    // member function to initialize the opengl
    void init()
    {
        // set the background color to white
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    // member function to draw the black square
    static void drawBlackSquare()
    {
        // set the square color to black
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f((-SQUARE_SIZE * 0.5), (-SQUARE_SIZE * 0.5));
        glVertex2f((SQUARE_SIZE * 0.5), (-SQUARE_SIZE * 0.5));
        glVertex2f((SQUARE_SIZE * 0.5), (SQUARE_SIZE * 0.5));
        glVertex2f((-SQUARE_SIZE * 0.5), (SQUARE_SIZE * 0.5));
        glEnd();
    }

    // member function handling the animation
    static void animate(int value)
    {
        OpenGLAnimation *animation = reinterpret_cast<OpenGLAnimation *>(value);
        animation->angle += 1.0f;
        angle += ANIMATION_SPEED;
        if (angle > 360.0f)
        {
            angle -= 360.0f;
        }

        float x = CIRCLE_RADIUS * cos((angle * M_PI) / 180.0f);
        float y = CIRCLE_RADIUS * sin((angle * M_PI) / 180.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(x, y, 0);
        glutPostRedisplay();
        glutTimerFunc(16, animate, value);
    }

    // member function to handle the rendering
    static void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(float(WINDOW_WIDTH / 2), float(WINDOW_HEIGHT / 2), 0);
        glRotatef(angle, 0, 0, 1);
        OpenGLAnimation::drawBlackSquare();
        glutSwapBuffers();
    }
};

int main(int argc, char **argv)
{
    OpenGLAnimation animation;
    animation.init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Black Square Animation");
    glutDisplayFunc(OpenGLAnimation::display);
    glutTimerFunc(0, OpenGLAnimation::animate, 0);
    glutMainLoop();
    return 0;
}
