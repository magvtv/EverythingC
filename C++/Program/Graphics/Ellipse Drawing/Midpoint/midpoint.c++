#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

GLFWwindow *window;

void drawSymmerticPoints(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glVertex2i(-x, y);
    glVertex2i(x, -y);
    glVertex2i(-x, -y);
    glEnd();
}

void BresenhamEllipse(int a, int b)
{
    float d2;
    int x = 0;
    int y = b;

    float d1 = (b * b) - (a * a * b) + (0.25 * a * a);
    drawSymmerticPoints(x, y);

    // 1st Region
    while ((pow(a, 2) * (y - 0.5)) > (pow(b, 2) * (x + 1)))
    {
        if (d1 < 0)
        {
            d1 += (pow(b, 2) * ((2 * x) + 3));
        }
        else
        {
            d1 += (pow(b, 2) * ((2 * x) + 3) + (pow(a, 2) * ((-2 * y) + 2)));
            y--;
        }

        x++;
        drawSymmerticPoints(x, y);
    }

    // 2nd Region
    d2 = (pow(b, 2) * pow((x + 0.5), 2)) + (pow(a, 2) * pow((y - 1), 2)) - (pow(a, 2) * pow(b, 2));
    while (y > 0)
    {
        if (d2 < 0)
        {
            d2 += (pow(b, 2) * ((2 * x) + 2)) + (pow(a, 2) * ((-2 * y) + 3));
            x++;
        }
        else
        {
            d2 += (pow(a, 2) * ((-2 * y) + 3));
        }
        y--;
        drawSymmerticPoints(x, y)
    }
}

void initOpenGL()
{
    glfwInit();
    window = glfwCreateWindow(1000, 800, "MidPoint Ellipse", NULL, NULL);
    glfwMakeContextCurrent(window);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);
    BresenhamEllipse(200, 100);
    glfwSwapBuffers(window);
}

int main()
{
    initOpenGL();

    while (!glfwWindowShouldClose(window))
    {
        display();
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}