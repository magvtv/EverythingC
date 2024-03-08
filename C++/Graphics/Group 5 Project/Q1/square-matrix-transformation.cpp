#include <GL/glut.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float SQUARE_SIZE = 50.0f;

class OpenGLAnimation
{
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
    void drawBlackSquare()
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

    // member function to handle the rendering
    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(float(WINDOW_WIDTH / 2), float(WINDOW_HEIGHT / 2), 0);
        glRotatef(angle, 0, 0, 1);
        drawBlackSquare();
        glutSwapBuffers();
    }

    // member function handling the animation
    void animate(int value)
    {
        angle += 1.0f;
        if (angle > 360.0f)
        {
            angle -= 360.0f;
        }
        // request for a redrawing of the square
        glutPostRedisplay();
        glutTimerFunc(16, animate, 0);
    }

private:
    float angle;
}

// global open gl animation object
OpenGLAnimation animation;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Black Square Animation");
    animation.init();
    glutDisplayFunc(animation.display);
    glutTimerFunc(0, animation.animate, 0);
    glutMainLoop();
    return 0;
}
