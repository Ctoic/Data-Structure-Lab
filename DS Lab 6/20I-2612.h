#pragma once
#include <iostream>
using namespace std;

template<class T, class T1>
class node
{

public:

	//Attributes of the class node.
	T EmpId;
	T CNIC;
	T joiningDate;
	T1 Salary;
	T1 Bonus;

	//making next pointer.
	node<T, T1>* next;
	node<T, T1>* prev;

	//Default Constructor.
	node<T, T1>()
	{
		EmpId = "";
		CNIC = "";
		joiningDate = "";
		Salary = 0;
		Bonus = 0;
		next = NULL;
		prev = NULL;
	}

	//Paramterized constructor.
	node<T,T1>(T id, T cnic, T join, T1 salary, T1 bonus)
	{
		EmpId = id;
		CNIC = cnic;
		joiningDate = join;
		Salary = salary;
		Bonus = bonus;
	}

	//getters
	T getId()
	{
		return EmpId;
	}

	T getCNIC()
	{
		return CNIC;
	}

	T getJoinDate()
	{
		return joiningDate;
	}

	T1 getSal()
	{
		return Salary;
	}

	T1 getBonus()
	{
		return Bonus;
	}
};

template<class T, class T1>
class linkList
{

private:

	//making head and tail of the list.
	node<T, T1>* head;

public:

	linkList()
	{
		head = NULL;
	}

	//copy constructor.
	linkList(linkList& obj)
	{
		head = obj.head;
	}

	bool isEmpty()
	{
		if (head != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void insert(T ID, T cnic, T joinDate, T1 salary, T1 bonus)
	{
		node<T, T1>* CurrentNode = new node<T, T1>();

		//storing the data in the node.
		CurrentNode->EmpId = ID;
		CurrentNode->CNIC = cnic;
		CurrentNode->joiningDate = joinDate;
		CurrentNode->Salary = salary;
		CurrentNode->Bonus = bonus;

		node<T, T1>* CurrentPtr = head;

		if (head != NULL)
		{
			while (CurrentPtr->next != head)
			{
				CurrentPtr = CurrentPtr->next;
				CurrentPtr->next = CurrentNode;
			}
		}
		else
		{
			CurrentNode->next = NULL;
			head = CurrentNode;
		}
	}
	

	//Search function.
	node<T, T1>* search(T data)
	{
		node<T, T1>* Curr = head;

		while (Curr->next != head)
		{
			if (Curr->EmpId == data)
			{
				return Curr;
			}
			else
			{
				Curr = Curr->next;
			}
		}
	}

	bool remove(T data)
	{
		node<T, T1>* Curr = head;

		while (Curr->next != head)
		{
			if (Curr->EmpId == data)
			{
				Curr->next = Curr->next->next;
				delete Curr;

				return true;
			}
			else
			{
				Curr = Curr->next;
			}
		}

		return false;
	}

	T1 UpdateSalary(T id, T1 sal)
	{
		node<T, T1>* Curr = head;

		while (Curr->next != head)
		{
			if (Curr->EmpId == id)
			{
				Curr->Salary = sal;
				break;
			}
			else
			{
				Curr = Curr->next;
			}
		} 

		return Curr->Salary;
	}

	T1 MaxSalary()
	{
		node<T, T1>* Curr = head;
		node<T, T1>* next = head;
		node<T, T1>* prev = head;
		T1 temp;

		while (prev)
		{
			prev = prev->next;

			while (Curr)
			{
				if (Curr->Salary < Curr->next->Salary)
				{
					temp = Curr->next->Salary;
					Curr->next->Salary = Curr->Salary;
					Curr->Salary = temp;
				}
				else
				{
					Curr = Curr->next;
				}
			}
		}

		return head->Salary;
	}

	void print()
	{
		node<T, T1>* Curr = head;
		
		while (Curr->next != NULL)
		{
			cout << Curr->EmpId << endl;
			cout << Curr->CNIC << endl;
			cout << Curr->joiningDate << endl;
			cout << Curr->Salary << endl;
			cout << Curr->Bonus << endl;

			Curr = Curr->next;
		}
	}



};