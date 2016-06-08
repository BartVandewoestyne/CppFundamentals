#include <iostream>
#include <utility>
using namespace std;


template<typename T>
T my_max(T first, T second)
{
	return (first > second) ? first : second;
}

template<typename T>
void my_swap(T& first, T& second)
{
	T tmp = first;
	first = second;
	second = tmp;
}

template<typename T>
T sum_of(const T* array, size_t start_idx, size_t stop_idx, T start_value)
{
	const T* stop=array+stop_idx;
	T sum = start_value;
	for (array = array+start_idx;
	     array <= stop; 
	     ++array)
	{
		sum += *array;
	}
	return sum;
}
	


int main()
{
	int mi = my_max(42, 44);
	double md = my_max(3.14, 2.71);

	cout << "mi: " << mi << "; md: " << md << endl;

	int a=5, b=7;
	swap(a,b);

	cout << "a,b: " << a << "," << b << endl;

	int ai[] = { 42, 44, 88 };	
	int ais = sum_of(ai, 0, 2, 0);
	cout << "ais: " << ais << endl;

	double ad[] = {3.14, 2.71};
	double ads = sum_of(ad, 0, 1, 2.0);
	cout << "ads: " << ads << endl;

}
