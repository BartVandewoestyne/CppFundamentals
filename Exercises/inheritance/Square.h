#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

#include <iostream>
#include <string>

class Square : public Shape
{

public:

    Square(double side) : Shape(), side(side) {}

    virtual double getSurfaceArea() const { return side*side; }
    virtual std::string getType() const { return std::string("Square"); }

private:

    double side;
};

#endif // SQUARE_H
