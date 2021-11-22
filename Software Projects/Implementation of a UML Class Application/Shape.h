#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

using namespace std;

class Shape {
    private:
        string color;
    public:
        Shape(string color);
        string getColor() const;
        virtual void print() = 0;
        virtual ~Shape();
};

#endif /* SHAPE_H */

