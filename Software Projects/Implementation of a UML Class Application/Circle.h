#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(string color, double radius);
        void print();
        virtual ~Circle();
};

#endif /* CIRCLE_H */

