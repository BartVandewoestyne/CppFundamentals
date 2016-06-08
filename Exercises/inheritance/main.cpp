#include "Square.h"
#include "Circle.h"
#include "Triangle.h"

int main()
{
    const int NB_SHAPES = 3;

    Shape* shapes[NB_SHAPES];
    shapes[0] = new Circle(2.0);
    shapes[1] = new Square(3);
    shapes[2] = new Triangle(2);

    for (int i = 0; i < NB_SHAPES; ++i)
    {
        std::cout << shapes[i]->getType()
                  << ": " << shapes[i]->getSurfaceArea() << std::endl;
    }

    for (int i = 0; i < NB_SHAPES; ++i)
    {
        delete shapes[i];
    }
}
