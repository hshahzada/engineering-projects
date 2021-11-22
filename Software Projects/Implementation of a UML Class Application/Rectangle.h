#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape {
    private :
        double breadth;
        double length;
    public:
        Rectangle(string color, double length, double breadth);
        void print();
        virtual ~Rectangle();
};

#endif /* RECTANGLE_H */

