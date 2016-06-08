

#include <vector>
#include <iostream>

using namespace std;


int main()
{
    vector<int> numbers(10);
    cout << numbers[5] << " C:" << numbers.capacity() << endl;

    numbers.push_back(666);
    cout << numbers[10] << " C:" << numbers.capacity() << endl;
}
