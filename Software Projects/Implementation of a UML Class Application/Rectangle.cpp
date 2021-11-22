#include "Rectangle.h"

Rectangle::Rectangle(string color, double length, double breadth) : Shape(color), length (length), breadth (breadth) {
};

void Rectangle::print() {
    double area = breadth*length;
    cout << "Rectangle L=" << length << ", B=" << breadth << ", area=" << area << ", " << getColor() << endl;
};

Rectangle::~Rectangle() {
};