#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

class Circle
{
public:
    float radius, area;
    float getArea()
    {
        return M_PI * radius * radius;
    };
    float getRadius()
    {
        return sqrt((area / M_PI));
    };
    float getCircumfrence()
    {
        return 2 * radius * M_PI;
    };
};

class Square
{
public:
    float side, area, perimeter;
    float getArea()
    {
        return pow(side, 2);
    };
    float getPerimeter()
    {
        return side * 4;
    };

    float getDiagonal()
    {
        float x = getArea();
        return sqrt(x * 2);
    };
    float getSideFromArea()
    {
        return sqrt(area);
    };
    float getSideFromPerimeter()
    {
        cout << "Enter perimeter of the square: ";
        cin >> perimeter;
        cout << "Side: " << (perimeter / 4) << endl;
        return 0;
    };
};

class Sphere
{
public:
    float radius;
    float getSurfaceArea()
    {
        float r2 = pow(radius, 2);
        return 4 * M_PI * r2;
    };
    float getVolume()
    {
        float r3 = pow(radius, 3);
        return ((4 * M_PI * r3) / 3);
    };
};

class Cylinder
{
public:
    float radius, height;
    float getOpenSurfaceArea()
    {
        return (radius * M_PI) * ((2 * height) + radius);
    };
    float getClosedSurfaceArea()
    {
        return (2 * radius * M_PI) * (height + radius);
    };
    float getVolume()
    {
        float r2 = pow(radius, 2);
        return (M_PI * r2 * height);
    }
};

Circle printCircle()
{
    Circle circle;
    cout << "Enter radius of circle: ";
    cin >> circle.radius;
    cout << "Circle radius: " << circle.radius << endl;
    cout << "Circumfrence: " << circle.getCircumfrence() << endl;
    cout << "Circle Area: " << circle.getArea() << endl;
    return circle;
}

Square printSquare()
{
    Square square;
    cout << "Enter side of square: ";
    cin >> square.side;
    cout << "Square Side: " << square.side << endl;
    cout << "Square Perimeter: " << square.getPerimeter() << endl;
    cout << "Square Area: " << square.getArea() << endl;
    return square;
}

Sphere printSphere()
{
    Sphere sphere;
    cout << "Enter radius of sphere: ";
    cin >> sphere.radius;
    cout << "Radius: " << sphere.radius << endl;
    cout << "Sphere Surface Area: " << sphere.getSurfaceArea() << endl;
    cout << "Sphere Volume: " << sphere.getVolume() << endl;
    return sphere;
}

Cylinder printCylinder()
{
    Cylinder cylinder;
    cout << "Enter radius of cylinder: ";
    cin >> cylinder.radius;
    cout << "Enter height of cylinder: ";
    cin >> cylinder.height;
    cout << "Cylinder radius: " << cylinder.radius << endl;
    cout << "Cylinder height: " << cylinder.height << endl;
    cout << "Cylinder Open Surface Area: " << cylinder.getOpenSurfaceArea() << endl;
    cout << "Cylinder Closed Surface Area: " << cylinder.getClosedSurfaceArea() << endl;
    cout << "Cylinder Volume: " << cylinder.getVolume() << endl;
    return cylinder;
}

void intro () {
    cout << "Name: MAGUTU PH NYARANG'O" << endl;
    cout << "Registration Number: SCT211-0030/2020" << endl;
}

int main()
{
    intro();
    int choice;
    std::cout << "Enter shape to calculate;" << endl;
    std::cout << "1: Square \n2: Circle \n3: Sphere \n4: Cylinder \n5: Exit"
              << endl;
    std::cin >> choice;
    if ((choice > 5) || (choice < 0))
    {
        std::cout << "Please enter a valid choice!" << endl;
    }
    else
    {
        switch (choice)
        {
        case 1:
            Square square1;
            square1 = printSquare();
            break;
        case 2:
            Circle circle1;
            circle1 = printCircle();
            break;
        case 3:
            Sphere sphere1;
            sphere1 = printSphere();
            break;
        case 4:
            Cylinder cylinder1;
            cylinder1 = printCylinder();
            break;
        case 5:
            std::cout << "Goodbye!" << endl;
            break;
        };
    }

    // while (choices != 5)
    // {
    //         std::cout << "Enter shape to calculate" << endl;
    //         std::cout << "1: Square, 2: Circle, 3: Sphere, 4: Cylinder, 5: Exit... " << endl;
    //         std::cin >> choices;
    // }
    return 0;
}