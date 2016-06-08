#include "Complex.h"

#include <iostream>

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex thesum = c1 + c2;
    std::cout << thesum << std::endl;
}
