#include "ListOfShapes.h"

void ListOfShapes::addShape(Shape *shape) {
    shapes.push_back(shape);
};

void ListOfShapes::removeShape() {
    if(shapes.size() > 0)
    {
        Shape *shape = shapes.at(shapes.size() - 1);
        shapes.pop_back();
        delete shape;
    };
};

void ListOfShapes::displayShapes() {
    cout << "[Display Shapes]" << endl << endl;
    for(size_t i = 0; i < shapes.size(); i++) {
        shapes[i]->print();
    };
};

ListOfShapes::~ListOfShapes() {
    for(size_t i = 0; i < shapes.size(); i++)
    {
        delete shapes.at(i);
    };
};