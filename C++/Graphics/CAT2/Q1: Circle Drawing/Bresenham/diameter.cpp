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

void drawDiameter(int centerX, int centerY, int radius)
{
    int x1 = centerX - radius;
    int y1 = centerY;
    int x2 = centerX + radius;
    int y2 = centerY;

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(x1, x2);
    glVertex2i(y1, y2);
    glEnd();
}

void initOpenGL()
{
    glfwInit();
    window = glfwCreateWindow(800, 600, "Red Circle and Black Diameter", NULL, NULL);
    glfwMakeContextCurrent(window);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    BresenhamCircle(300, 300, 400); // center of (300, 300) radius of 400
    drawDiameter(300, 300, 400);
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