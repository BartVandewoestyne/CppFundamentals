

#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <numeric>

#include <boost/lexical_cast.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;


int main(int argc, char** argv)
{
    if (argc < 3) {
        cerr << "Please provide me with at least 2 numbers" << endl;
        return 1;
    }

    vector<int> args;
    args.reserve(argc-1);
    for (int i=1; i<argc; ++i)
        try{
            args.push_back(lexical_cast<int>(argv[i]));
        } catch (std::exception& e) {
            cout << e.what() << endl;
        }

    cout << "Size: " << args.size() << "\tCapacity: " << args.capacity() << endl << endl;;

    vector<int>::const_reverse_iterator rit;
    for (rit = args.rbegin(); rit!=args.rend(); ++rit)
        cout << *rit << endl;

    cout << endl;

    cout << "Min: " << *min_element(args.begin(), args.end()) << endl;
    cout << "Max: " << *max_element(args.begin(), args.end()) << endl << endl;

    sort(args.begin(), args.end(), std::less<int>());
    vector<int>::const_iterator it;
    for (it = args.begin(); it!=args.end(); ++it)
        cout << *it << endl;
    cout << endl;
    
    args.erase(remove_if(args.begin(), args.end(), bind(less<int>(), _1, 10)), args.end());

    transform(args.begin(), args.end(), args.begin(), bind(plus<int>(), 1, _1));

    for (it = args.begin(); it!=args.end(); ++it)
        cout << *it << endl;
    
    cout << "Sum: " << accumulate(args.begin(), args.end(), 0) << endl;
}
