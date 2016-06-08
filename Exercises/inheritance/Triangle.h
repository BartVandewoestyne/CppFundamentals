#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

#include <cmath>
#include <iostream>
#include <string>

class Triangle : public Shape
{

public:

    Triangle(double side) : Shape(), side(side) {}

    virtual double getSurfaceArea() const { return side*side*std::sqrt(3.0)/4.0; }
    virtual std::string getType() const { return std::string("Triangle"); }

private:

    double side;
};

#endif // TRIANGLE_H
