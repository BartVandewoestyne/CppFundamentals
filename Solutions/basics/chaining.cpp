#include <iostream>

using namespace std;

int main()
{
    (cout << 42) << endl;

    ostream& o = cout << 44;
    o << endl;
}
