#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const float triangleEdgeTop = (sqrt(3) / 2);
const float triangleEdgeCenter = (sqrt(3) / 3);

const std::vector<std::string> tri_colors = {'#7DDF64', '#8EE3EF', '#BCBD8B', '#FAC748'};

// draw the equilateral triangles
void drawEquilateralTriangle(float x, float y, float scale)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f((+scale), y);
    glVertex2f((X + (scale * 0.5)), (y + (scale * triangleEdgeTop)));
    glEnd();
}

// function to convert my hex color codes to rgb
void hexToRGB(std::string hex, float &r, float &g, float &b)
{
    // format of hex '#RRGGBB'
    r = std::stoi(hex.substr(1, 2), nullptr, 16) / 255.0f;
    b = std::stoi(hex.substr(3, 4), nullptr, 16) / 255.0f;
    g = std::stoi(hex.substr(5, 6), nullptr, 16) / 255.0f;
}

void grenierHormann(float &x, float &y, float &scale)
{
    std::vector<std::pair<float, float>> vertices = {{10.0f, 0.0f, 0.0f}, {0.0f, 17.32f}, {10.0f, 0.0f}};

    for (int i = 0; i < vertices.size(); ++i)
    {
        float ix = vertices[i].first;
        float iy = vertices[i].second;

        // check if vertex is outside the viewing region
        if (ix < -10.0f)
        {
        }
    }
}

// function to draw the sierpinski with custom colors
void drawTheSierpinski()
{
    float scale = 10.0f;
    float x = 0.0f;
    float y = 0.0f;

    for (int i = 0; i < 3; ++i)
    {
        // set the new colors
        float r, g, b;
        hexToRGB(colors[i], r, g, b);
        glColor3f(r, g, b);

        // initialize the triangle
        drawEquilateralTriangle(x, y, scale);
        x += scale / 2.0f;
        y += scale * triangleEdgeTop;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawTheSierpinski();
    glFlush();
};

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Sierpinski Triangle: Level 3");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -5, 15);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
