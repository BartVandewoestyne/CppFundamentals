

#include <string>
#include <iostream>

using namespace std;


int main()
{
    string s("Foo");
    cout << "Capcity: " << s.capacity() << "\tLength: " << s.size() << endl;

    string s1("**********");
    cout << "Capcity: " << s1.capacity() << "\tLength: " << s1.size() << endl;
    
    string s2("Tass Belgium NV");
    cout << "Capcity: " << s2.capacity() << "\tLength: " << s2.size() << endl;

    string s3("Tass Belgium NV ****");
    cout << "Capcity: " << s3.capacity() << "\tLength: " << s3.size() << endl;

    string s4("*************************");
    cout << "Capcity: " << s4.capacity() << "\tLength: " << s4.size() << endl;

    string s5("******************************");
    cout << "Capcity: " << s5.capacity() << "\tLength: " << s5.size() << endl;

    string s6("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    cout << "Capcity: " << s6.capacity() << "\tLength: " << s6.size() << endl;

    string t(10, 'p');
    cout << "Capcity: " << t.capacity() << "\tLength: " << t.size() << endl;

    t += "bla";
    cout << "Capcity: " << t.capacity() << "\tLength: " << t.size() << endl;

    t += "bla**********";
    cout << "Capcity: " << t.capacity() << "\tLength: " << t.size() << endl;
}
