#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    virtual ~Shape() {}

    virtual double getSurfaceArea() const = 0;
    virtual std::string getType() const = 0;
};

#endif  // SHAPE_H
