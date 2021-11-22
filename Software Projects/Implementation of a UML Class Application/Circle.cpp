#include "Circle.h"

Circle::Circle(string color, double radius) : Shape(color), radius(radius) {
};

void Circle::print() {
    double area = 3.14 * radius * radius;
    cout << "Circle R=" << radius << ", area=" << area << ", " << getColor() << endl;
};

Circle::~Circle() {
};

