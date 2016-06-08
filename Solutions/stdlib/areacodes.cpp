

#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

int main(int argc, char** argv)
{
    if (argc != 4){
        cerr << "Please provide me with: file lower upper " << argc << endl;
        return -1;
    }

    int first=0;
    try { first = lexical_cast<int>(argv[2]); }
    catch (bad_lexical_cast& e) {
        cerr << e.what() << " " << argv[2] << endl;
        return -1;
    }

    
    int second=0;
    try { second = lexical_cast<int>(argv[3]); }
    catch (bad_lexical_cast& e){
        cerr << e.what() << argv[2] << endl;
        return -1;
    }

    int upper = max(first, second);
    int lower = min(first, second);

    map<int, string> areacodes;

    ifstream f(argv[1]);
    string firstline;
    getline(f, firstline);

    for (string line; getline(f, line); )
    {
        tokenizer<escaped_list_separator<char> > tok(line);
        tokenizer<escaped_list_separator<char> >::iterator it = tok.begin();
        int code = lexical_cast<int>(*it++);
        areacodes[code] = *it;
    }

    map<int, string>::const_iterator lit, uit;
    lit = areacodes.lower_bound(lower);
    uit = areacodes.upper_bound(upper);

    while (lit!=uit)
    {
        cout << lit->first << " " << lit->second << endl;
        ++lit;
    }
}
