#include <iostream>

const int thisyear = 2016;

int main()
{
    std::cout << "Please enter your age: ";

    int age = -1;
    std::cin >> age;


    int year_of_birth = thisyear - age;
    std::cout << "You were born in " << year_of_birth << std::endl;
}
