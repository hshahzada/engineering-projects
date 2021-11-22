#include "Shape.h"

Shape::Shape(string color) : color (color) {
};

string Shape::getColor() const {
    return color;
};

Shape::~Shape() {
};