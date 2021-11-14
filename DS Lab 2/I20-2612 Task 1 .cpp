#include<iostream>
#include<cmath>
using namespace std;

template<class T>
class Calculator
{

private:

	T Num1;
	T Num2;
	T* Arr1;
	T* Arr2;

public:

	Calculator()
	{
		Num1 = 0;
		Num2 = 0;
		Arr1 = new T[5];
		Arr2 = new T[5];
	}

	//parameterized constructor.
	Calculator(T n1, T n2, T* ptr1, T* ptr2)
	{
		Num1 = n1;
		Num2 = n2;
		Arr1 = ptr1;
		Arr2 = ptr2;

	}

	//Add function.
	T AddNumbers()
	{
		return Num1 + Num2;
	}

	//Subtract function.
	T SubtractNumbers()
	{
		if (Num1 > Num2)
		{
			return Num1 - Num2;
		}
		else
		{
			return Num2 - Num1;
		}
	}

	T* AddArrays()
	{
		//temprory array
		T Arr3[5];

		for (int i = 0; i < 5; i++)
		{
			Arr3[i] = Arr1[i] + Arr2[i];
		}

		return Arr3;
	}

	T DivideNumbers()
	{
		if (Num1 >= Num2)
		{
			return Num1 / Num2;
		}
		else
		{
			return Num2 / Num1;
		}
	}

	T Factorial(T num)
	{
		if (num == 0)
		{
			return 1;
		}
		else
		{
			return num * Factorial(num - 1);
		}
	}

	T squareRoot(T num)
	{
		return sqrt(num);
	}

	void PrimeNumber(T num)
	{
		for (int i = 1; i < num; i++)
		{
			if (num % i == 0)
			{
				cout << num << " is a prime number." << endl;
				break;
			}
			else
			{
				cout << num << " is not a prime number." << endl;
			}
		}
	}

};

int main()
{
	int arr1[5];
	int arr2[5];

	cout << "Enter the elements of first array: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> arr1[i];
	}

	cout << "Enter the elements of second array: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> arr2[i];
	}

	Calculator<int> obj(10, 2, arr1, arr2);


	cout << "The sum is : " << obj.AddNumbers() << endl;
	cout << "The difference is: " << obj.SubtractNumbers() << endl;
	cout << "The division of the numbers is: " << obj.DivideNumbers() << endl;
	cout << "The sum of arrays is: ";

	int* ArraysSum = obj.AddArrays();

	for (int i = 0; i < 5; i++)
	{
		cout << ArraysSum[i] << ", ";
	}

	int PrimeNumber;

	cout << "\nEnter a number to check whether it is prime or not: ";
	cin >> PrimeNumber;

	obj.PrimeNumber(PrimeNumber);

	int fact;

	cout << "Enter a number to find the factorial: ";
	cin >> fact;

	cout << "The factorial of " << fact << " is: " << obj.Factorial(fact);
	
	int SquareRoot;

	cout << "\nEnter a number to find the square root: ";
	cin >> SquareRoot;
	cout << "The square root of " << SquareRoot << " is: " << obj.squareRoot(SquareRoot) << endl;;
}