#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

#include <iostream>
#include <string>

class Circle : public Shape
{

public:

    Circle(double radius) : Shape(), radius(radius) {}

    virtual double getSurfaceArea() const { return radius*radius*3.14; }
    virtual std::string getType() const { return std::string("Circle"); }

private:

    double radius;
};

#endif // CIRCLE_H
