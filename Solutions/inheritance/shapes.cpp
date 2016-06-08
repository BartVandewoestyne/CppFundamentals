
#include <iostream>
using namespace std;
//------------------------------------------------------------
class Shape
{
protected:
    Shape(){}
public: 
    virtual double surfaceArea() const =0;
    virtual const char* what() const =0;
};

//------------------------------------------------------------
#define PI 3.141592

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double radius): Shape(), radius(radius) {}
    virtual double surfaceArea() const {
        return PI*radius*radius;
    }
    virtual const char* what() const {
        return "Circle";
    }
};
//------------------------------------------------------------
class Square : public Shape
{
private:
    double side;
public:
    Square(double side): Shape(), side(side){}
    virtual double surfaceArea() const {
        return side*side;
    }
    virtual const char* what() const {
        return "Square";
    }
};
//------------------------------------------------------------
class Triangle : public Shape
{
private:
    double side;
public:
    Triangle(double side): Shape(), side(side){}
    virtual double surfaceArea() const {
        return side*side/2.0;
    }
    virtual const char* what() const {
        return "Triangle";
    }
};
//------------------------------------------------------------
int main()
{
    Shape* shapes[3];
    Circle c(5);
    Square s(6);
    Triangle t(9);

    shapes[0] = &c;
    shapes[1] = &s;
    shapes[2] = &t;

    for (int i=0; i<3; i++)
    {
        cout << "Surface area of the " << shapes[i]->what() << " is " 
             << shapes[i]->surfaceArea() << endl;
    }
}
