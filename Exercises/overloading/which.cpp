/*
 * References:
 *
 *   [1] http://en.cppreference.com/w/cpp/language/overload_resolution
 *   [2] http://stackoverflow.com/questions/37166131/why-does-the-compiler-match-char-to-int-but-not-short
 */

#include <iostream>

int maxof(int a, int b)
{
    std::cout << "int maxof(int, int)" << std::endl;
    return a > b ? a : b;
}

short maxof(short a, short b)
{
    std::cout << "maxof(short, short)" << std::endl;
    return a > b ? a : b;
}

int main()
{
    char i = '5';
    char j = '6';
    char m = maxof(i, j);  // maxof(int, int) because:
                           //   (Integral) Promotion is preferred to (integral) conversion by overload resolution.
                           //   So, the promotion from char to int is preferred over conversion from char to short.
}
