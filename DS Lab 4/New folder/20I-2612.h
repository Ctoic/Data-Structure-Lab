#pragma once
#include<iostream>
using namespace std;


template<class T>
class List
{

public:

	T* values;
	int totalCapacity;
	int counter;

public:

	//Default constructor.
	List()
	{
		values = NULL;
		totalCapacity = 0;
		counter = 0;
	}

	//parameterized constructor.
	List(int cap)
	{
		values = new T[cap];
		totalCapacity = cap;
		counter = 0;
	}

	bool insert(T item)
	{
		if (isFull() == false)
		{
			values[counter] = item;
			counter++;

			return true;
		}

		return false;
	}	
	bool insertAt(T item, int index)
	{
		if (isFull() == false && index < counter)
		{
			values[index] = item;
			counter++;

			return true;
		}

		return false;
	}
	bool insertAfter(T itemToBeInserted, T item)
	{
		for (int i = 0; i < totalCapacity; i++)
		{
			if (item == values[i])
			{
				values[i + 1] = itemToBeInserted;
				counter++;

				return true;
			}
		}

		return false;
	}
	bool insertBefore(T itemToBeInserted, T item)
	{
		for (int i = 0; i < totalCapacity; i++)
		{
			if (item == values[i])
			{
				values[i] = itemToBeInserted;
				counter++;

				return true;
			}
		}

		return false;
	}
	bool isEmpty()
	{
		if (counter == 0)
		{
			return true;
		}

		return false;
	}
	bool isFull()
	{
		if (counter == totalCapacity)
		{
			return true;
		}

		return false;
	}
	void remove(T item)
	{
		for (int i = 0; i < totalCapacity; i++)
		{
			if (item == values[i])
			{
				for (int j = i; j < totalCapacity - 1; j++)
				{
					values[j] = values[j + 1];
				}
				
				counter--;
			}
		}
	}
	void removeBefore(T item)
	{
		for (int i = 0; i < totalCapacity; i++)
		{
			if (item == values[i])
			{
				for (int j = 0; j < i; j++)
				{
					values[j] = values[j + 1];
				}

				counter--;
			}
		}
	}
	void removeAfter(T item)
	{
		for (int i = 0; i < totalCapacity; i++)
		{
			if (item == values[i])
			{
				for (int j = i + 1; j < totalCapacity - 1; j++)
				{
					values[j] = values[j + 1];
				}

				counter--;
			}
		}
	}
	void print()
	{
		for (int i = 0; i < counter; i++)
		{
			cout << values[i] << endl;
		}
	}

	bool operator==(List& obj)
	{
		
		if (totalCapacity != obj.totalCapacity)
		{
			return false;
		}
		else
		{
			int count = 0;

			for (int i = 0; i < totalCapacity; i++)
			{
				if (values[i] == obj.values[i])
				{
					count++;
				}
			}

			if (count == totalCapacity)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	int search(T item)
	{
		for (int i = 0; i < totalCapacity; i++)
		{
			if (item == values[i])
			{
				return i;
			}
			else
			{
				return -1;
			}
		}
	}
	void reverse()
	{
		T* arr = new T[totalCapacity];

		int temp = 0;

		for (int i = totalCapacity - 1; i >= 0; i--)
		{
			arr[temp] = values[i];
			temp++;
		}

		for (int i = 0; i < totalCapacity; i++)
		{
			values[i] = arr[i];
		}
	}
};

//Password validation
bool PasswordValidation(string str)
{
	int digitCount = 0;
	int specialCharCount = 0;
	int Uppercase = 0;

	//password length
	if (str.length() < 5 && str.length() > 11)
	{
		return false;
	}

	//caharacters in the password.
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 0 && str[i] <= 9)
		{
			digitCount++;
		}
		if (str[i] >= 65 && str[i] <= 90)
		{
			Uppercase++;
		}
		if (str[i] >= 32 && str[i] < 64)
		{
			specialCharCount++;
		}

		//checking the characters count.
		if (specialCharCount > 0 && Uppercase > 0 && digitCount > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

//Email validation.
bool EmailValidation(string str)
{
	return true;
}
//{
//	int i = 0;
//	int lowerCase = 0;
//	int specialCharCount = 0;
//
//
//	while (str[i] != '@')
//	{
//		if (str[i] >= 97 && str[i] <= 122)
//		{
//			lowerCase++;
//		}
//		if (str[i] == '-' || str[i] == '.' || str[i] == '_')
//		{
//			specialCharCount++;
//		}
//
//		i++;
//	}
//
//	if (str[0] >= 97 && str[0] < 122)
//	{
//		if (lowerCase > 0)
//		{
//			if (specialCharCount > 0)
//			{
//				return false;
//			}
//		}
//	}
//
//	return false;
//}

