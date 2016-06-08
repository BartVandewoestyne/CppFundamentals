

#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

int main(int argc, char** argv)
{
    if (argc != 3){
        cerr << "Please provide me with: file file city" << argc << endl;
        return -1;
    }

    string city(argv[2]);
    algorithm::to_lower(city);

    map<string, vector<int> > areacodes;

    ifstream f(argv[1]);
    string firstline;
    getline(f, firstline);

    for (string line; getline(f, line); )
    {
        tokenizer<escaped_list_separator<char> > tok(line);
        tokenizer<escaped_list_separator<char> >::iterator it = tok.begin();
        int code = lexical_cast<int>(*it++);
        string city(*it);
        algorithm::to_lower(city);  // prefer this to std::transform with std::to_lower or for_each and a handcrafted function
        areacodes[city].push_back(code);
    }

    vector<int>::const_iterator it, end;
    const vector<int>& codes = areacodes[city];
    it = codes.begin();
    end = codes.end();

    while (it!=end)
        cout << *it++ << endl;
}
