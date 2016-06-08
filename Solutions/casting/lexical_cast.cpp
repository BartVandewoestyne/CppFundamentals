

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template<typename out_t, typename in_t>
out_t lexical_cast(const in_t& in)
{
    stringstream s;
    s << in;
    out_t out;
    s >> out;
    return out;
}


int main()
{
    string s("44");
    int i = lexical_cast<int>(s);
    cout << i << endl;

    short j = lexical_cast<short>(s);
    cout << j << endl;
    
    s = lexical_cast<string>(88);
    cout << s << endl;
}
