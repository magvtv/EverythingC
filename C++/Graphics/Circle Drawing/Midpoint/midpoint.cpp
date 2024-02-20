#include <iostream>
#include <vector>
void drawSymmetricalPoints(int x, int y, int centerX, int centerY)
{
    // draw a given point with x, y cartesian 1st octant
    std::cout << "(" << (x + centerX) << ", " << (y + centerY) << ")\n";
    // draw given point with x, y in 2nd octant
    std::cout << "(" << (-x + centerX) << ", " << (y + centerY) << ")\n";
    // draw given point with x, y in 3rd octant
    std::cout << "(" << (x + centerX) << ", " << (-y + centerY) << ")\n";
    // draw given point with x, y in 4th octant
    std::cout << "(" << (-x + centerX) << ", " << (-y + centerY) << ")\n";
}

void MidPointCircle(int centerX, int centerY, int radius)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    drawSymmetricalPoints(x, y, centerX, centerY);

    while (x < y)
    {
        x++;

        if (p < 0)
        {
            p += ((2 * x) + 1);
        }
        else
        {
            y--;
            p += (2 * (x - y)) + 1;
        }

        drawSymmetricalPoints(x, y, centerX, centerY);
    }
}

int main()
{
    int centerX = 3;
    int centerY = 3;
    int radius = 4;

    std::cout << "Points along circumference of the circle: \n";
    MidPointCircle(centerX, centerY, radius);

    return 0;
}