


#include <iostream>
#include <exception>

using namespace std;

class MyNewException : public exception
{
public:
    virtual const char* what() const throw() {
        return "MyNewException ...";
    }
};


int main()
{
    try
    {
        throw MyNewException();
    }
    catch(exception& e)
    {
        cout << e.what() << endl;
    }
}
