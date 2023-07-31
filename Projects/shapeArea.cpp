#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Shape {
public:
    virtual float area() const = 0;
    virtual void display() const = 0;
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    float area() const override {
        return M_PI * pow(radius, 2);
    }

    void display() const override {
        cout << "Circle - Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
        cout << "   *****   " << endl;
        cout << " *       * " << endl;
        cout << "*         *" << endl;
        cout << "*         *" << endl;
        cout << " *       * " << endl;
        cout << "   *****   " << endl;
    }
};

class Rectangle : public Shape {
private:
    float width;
    float height;

public:
    Rectangle(float w, float h) : width(w), height(h) {}

    float area() const override {
        return width * height;
    }

    void display() const override {
        cout << "Rectangle - Width: " << width << ", Height: " << height << endl;
        cout << "Area: " << area() << endl;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

class Triangle : public Shape {
private:
    float base;
    float height;

public:
    Triangle(float b, float h) : base(b), height(h) {}

    float area() const override {
        return 0.5 * base * height;
    }

    void display() const override {
        cout << "Triangle - Base: " << base << ", Height: " << height << endl;
        cout << "Area: " << area() << endl;
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= 2 * height - 1; j++) {
                if (j >= height - i + 1 && j <= height + i - 1)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    float circleRadius, rectangleWidth, rectangleHeight, triangleBase, triangleHeight;

    cout << "Enter the radius of the circle: ";
    cin >> circleRadius;

    cout << "Enter the width of the rectangle: ";
    cin >> rectangleWidth;

    cout << "Enter the height of the rectangle: ";
    cin >> rectangleHeight;

    cout << "Enter the base of the triangle: ";
    cin >> triangleBase;

    cout << "Enter the height of the triangle: ";
    cin >> triangleHeight;

    Circle circle(circleRadius);
    Rectangle rectangle(rectangleWidth, rectangleHeight);
    Triangle triangle(triangleBase, triangleHeight);

    cout << "Shape details:\n";
    cout << "\nCircle:\n";
    circle.display();

    cout << "\nRectangle:\n";
    rectangle.display();

    cout << "\nTriangle:\n";
    triangle.display();

    return 0;
}
