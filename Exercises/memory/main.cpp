#include "TString.h"

#include <iostream>

int main()
{
    TString s1;
    std::cout << "s1 = " << s1 << std::endl;

    TString s2("FooBar");
    std::cout << "s2 = " << s2 << std::endl;

    TString s3(s2, 3, 2);
    std::cout << "s3 = " << s3 << std::endl;

    TString s4(5, 'X');
    std::cout << "s4 = " << s4 << std::endl;

    s4 = s2;
    std::cout << "s4 = " << s4 << std::endl;
}
