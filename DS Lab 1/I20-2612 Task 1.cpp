#include<iostream>
using namespace std;

template<class T>

T Smaller(T first, T second)
{
	if (first < second)
	{
		return first;
	}

	return second;
}

int main()
{

	cout << Smaller(2, 3) << endl;
	cout << Smaller('d', 'g') << endl;
	cout << Smaller(12.3, 43.5) << endl;

}