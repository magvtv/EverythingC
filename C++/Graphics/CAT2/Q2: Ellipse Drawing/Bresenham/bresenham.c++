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
    int x = 0;
    int y = b;
    double d1 = (pow(b, 2) - (pow(a, 2) * b) + (0.25 * pow(a, 2)));
    int dx = 2 * pow(a, 2) * x;
    int dy = 2 * pow(b, 2) * y;

    while (dx < dy)
    {
        drawSymmerticPoints(x, y);
        x++;
        dx = 2 * pow(b, 2);

        if (d1 < 0)
        {
            d1 += dx + pow(b, 2);
        }
        else
        {
            y--;
            dy -= 2 * pow(b, 2);
            d1 += (dx + pow(b, 2)) - dy;
        }
    }

    double d2 = (pow(b, 2) * pow((x + 0.25), 2)) + (pow(a, 2) * pow((y - 1), 2)) - (pow(a, 2) * pow(b, 2));
    while (y >= 0)
    {
        drawSymmerticPoints(x, y);
        y--;
        dy -= (2 * pow(a, 2));
        if (d2 > 0)
        {
            d2 += (pow(a, 2) - dy)
        }
        else
        {
            x++;
            dx += (2 * pow(b, 2));
            d2 += ((pow(a, 2) - dy) + dx);
        }
    }
}

void initOpenGL()
{
    glfwInit();
    window = glfwCreateWindow(800, 1000, "Breseham Ellipse", NULL, NULL);
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