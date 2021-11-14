#include<iostream>
using namespace std;

template<class T>

T Smallest(T first, T second, T third)
{
	if (first < second)
	{
		if (first < third)
		{
			return first;
		}		
	}
	else if (second < first)
	{
		if (second < third)
		{
			return second;
		}
	}

	return third;
}

int main()
{

	cout << Smallest(2, 3, 1) << endl;
	cout << Smallest('d', 'g', 'a') << endl;
	cout << Smallest(12.3, 43.5, 1.2) << endl;

}