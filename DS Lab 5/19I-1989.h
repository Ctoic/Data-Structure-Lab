#pragma once
#include<iostream>

using namespace std;

template<class T>
class Node
{

public:

	T data;
	Node<T>* next;

	//default constructor.
	Node()
	{
		data = 0;
		next = NULL;
	}

	//Parameterized constructor.
	Node(T Data, Node<T>* Next)
	{
		data = Data;
		next = Next;
	}

	//Setters
	void setData(T Data)
	{
		data = Data;
	}
	void setNext(Node<T>* nxt)
	{
		next = nxt;
	}

	//Getters.
	T getData()
	{
		return data;
	}

	Node<T>* getNext()
	{
		return next;
	}

};

template<class T>
class SLinkedList
{

public:

	Node<T>* head;
	Node<T>* sorted;

	//default constructor.
	SLinkedList()
	{
		head = NULL;
	}

	//Insert function.
	void insert(T Data)
	{
		if (head)
		{
			Node<T>* CurrNode = new Node<T>();
			CurrNode = head;

			//traversing the list until last node.
			while (CurrNode->next != NULL)
			{
				CurrNode = CurrNode->next;
			}

			//creating a last node and inserting the data in the last node.
			CurrNode->next = new Node<T>();
			CurrNode->next->data = Data;
			CurrNode->next->next = NULL;

		}
		else
		{
			//creating head and assigning the data to head.
			head = new Node<T>();
			head->data = Data;
			head->next = NULL;
		}
		
	}

	void insertAtHead(T Data)
	{
		if (head == NULL)
		{
			//creating head and assigning the data to head.
			head = new Node<T>();
			head->data = Data;
			head->next = NULL;

		}
		else
		{
			//creating a new node and making it head.
			Node<T>* Temp = new Node<T>();
			Temp->data = Data;
			Temp->next = head;
			head = Temp;
		}
	}


	Node<T>* InsertAtIndex(T Data, int index)
	{

		if (index == 0)
		{
			return NULL;
		}

		int CurrIndex = 1;
		Node<T>* CurrNode = new Node<T>();

		while (CurrNode && index > CurrIndex)
		{
			CurrNode = CurrNode->next;
			CurrIndex++;
		}

		if (index > 0 && CurrNode == NULL)
		{
			return NULL;
		}
		else
		{
			Node<T>* newNode = new Node<T>();
			newNode->data = Data;

			if (index == 0)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				newNode->next = CurrNode->next;
				CurrNode->next = newNode;

				return newNode;
			}
		}

	}

	int search(T Data) {

		Node<T>* currNode = head;
		int currIndex = 0;
		while (currNode && currNode->data != Data) {

			currNode = currNode->next;
			currIndex++;
		}

		if (currNode) return currIndex;

		return 0;

	}

	void update(int index, T Data)
	{
		int currIndex = 0;
		Node<T>* temp = new Node<T>();
		temp = head;

		while (temp->next != NULL)
		{
			if (currIndex == index)
			{
				temp->data = Data;
				break;
			}
			else
			{
				currIndex++;
				temp = temp->next;
			}
		}
	}

	void print()
	{
		Node<T>* temp = new Node<T>();
		temp = head;

		while (temp->next != NULL)
		{
			break;
		}
	}

	int remove(T x) 
	{
		Node<T>* prevNode = NULL;
		Node<T>* currNode = head;
		int currIndex = 1;
		
		while (currNode && currNode->data != x) {

			prevNode = currNode;
			currNode = currNode->next;
			currIndex++;

		}
		if (currNode) 
		{

			if (prevNode) 
			{

				prevNode->next = currNode->next;
				delete currNode;

			}
			else 
			{

				head = currNode->next;
				delete currNode;

			}
			return currIndex;

		}
		return 0;

	}

	void mysort(Node<T>*&head, Node<T> *p1, Node<T>* p2)
	{
		if (p2 == NULL)
		{
			return;
		}
		Node<T>* p3 = p1->next;

		while (p3 != NULL)
		{
			if (p1->data > p3->data)
			{
				swap(p1->data, p3->data);
			}
			p3 = p3->next;
		}
		mysort(head, p2, p2->next);
	}

	void mergeLists(SLinkedList<T> second)
	{
		Node<T>* firstRef = this->head;
		while (firstRef->next != NULL)
		{
			firstRef = firstRef->next;
		}

		firstRef->next = second.head;

		mysort(head, head, head->next);

	}

	bool isPalindrom()
	{
		Node<T>* current;
		current = head;
		int i = 0, n = 0;
		while (current != NULL)
		{
			arr1[i] = current->data;
			i++;
			n++;
			current = current->next;
		}
		int j = 0;
		for (i = n - 1; i >= 0; i--)
		{
			arr2[j] = arr1[i];
			j++;
		}

		for (i = 0; i <= n; i++)
		{
			if (arr1[i] != arr2[i])
			{
				return false;
			}

		}

		return true;

	}


};