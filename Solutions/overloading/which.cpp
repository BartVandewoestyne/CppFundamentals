
#include <iostream>

using namespace std;

int maxof(int a, int b)
{
    cout << "int max(int, int)" << endl;
    return a > b ? a : b;
}

short maxof(short a, short b)
{
    cout << "short max(short, short)" << endl;
    return a > b ? a : b;
}

int main()
{
    char i=42, j=44;
    char m = maxof(i, j);
    
    cout << "max of " << i << " and " << j << " is " << m << endl;
}
