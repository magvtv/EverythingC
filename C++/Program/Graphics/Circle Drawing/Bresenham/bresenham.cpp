#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

GLFWwindow *window;

void drawSymmetricPoints(int x, int y, int centerX, int centerY)
{
    glBegin(GL_POINTS);
    glVertex2i((x + centerX), (y + centerY));
    glVertex2i((-x + centerX), (y + centerY));
    glVertex2i((x + centerX), (-y + centerY));
    glVertex2i((-x + centerX), (-y + centerY));
    glEnd();
}

void BresenhamCircle(int centerX, int centerY, int radius)
{
    int x = 0;
    int y = radius;
    int d = 3 - (2 * radius);

    drawSymmetricPoints(x, y, centerX, centerY);

    while (x <= y)
    {
        if (d <= 0)
        {
            d = d + (4 * x) + 6;
        }
        else
        {
            d = d + (4 * (x - y)) + 10;
            y--;
        }
        x++;
        drawSymmetricPoints(x, y, centerX, centerY);
    }
}

void initOpenGL()
{
    glfwInit();
    window = glfwCreateWindow(800, 600, "Bresenham\'s Circle", NULL, NULL);
    glfwMakeContextCurrent(window);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    BresenhamCircle(300, 300, 400);
    glFlush();
}

int main () {
    initOpenGL();

    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}