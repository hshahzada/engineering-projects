#ifndef LISTOFSHAPES_H
#define LISTOFSHAPES_H
#include <vector>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"


class ListOfShapes{
    private:
        vector<Shape*> shapes;
    public:
        void addShape(Shape * shape);
        void removeShape();
        void displayShapes();
        ~ListOfShapes();
};

#endif /* LISTOFSHAPES_H */

