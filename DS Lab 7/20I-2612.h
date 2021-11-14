#pragma once
#include<iostream>
using namespace std;

template<class T>
class Node
{

public:

	T data;
	Node* next;

	//defalult constructor.
	Node<T>()
	{
		data = 0;
		next = NULL;
	}

	//parameterized construcor.
	Node<T>(T val)
	{
		data = val;
		next = NULL;
	}

	//getter
	T getData()
	{
		return data;
	}
};

template<class T>
class Queue
{

private:

	Node<T>* rear;
	Node<T>* front;

public:

	//default constructor.
	Queue<T>()
	{
		rear = NULL;
		front = NULL;
	}

	//getters
	Node<T>* getRear()
	{
		return rear;
	}

	T Front()
	{
		return front->data;
	}

	//Enqueue Function
	void enqueue(T val)
	{
		Node<T>* Current = new Node<T>();
		Current->data = val;
		Current->next = NULL;

		if (rear == NULL)
		{
			rear = Current;
			front = rear;
		}
		else
		{
			while (rear != NULL)
			{
				rear = rear->next;
			}

			rear = Current;
		}
	}

	//dequeue function
	void dequeue()
	{
		Node<T>* current = front;
		front = front->next;
		delete current;

	}


	//isEmpty
	bool isEmpty()
	{
		if (front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	
};

template<class T>
void roundRobin(Queue<T> queue, int val)
{
	int remainingTime;

	while (!queue.isEmpty())
	{
		remainingTime = queue.Front() - val;


		cout << "Execution Time: " << val << endl;
		cout << "Remaining Time: " << remainingTime << endl;

		if (remainingTime > 0)
		{
			queue.dequeue();
			queue.enqueue(remainingTime);
			cout << "Task is not completed, it is being re-scheduled." << endl;
		}
		else
		{
			queue.dequeue();
			cout << "Task is completed, it is removed from queue." << endl;
		}

	}
}


Queue<char> queueConcat(string str)
{
	Queue<char> queue;
	Queue<char> queue1;
	Queue<char> queue2;
	Queue<char> queue3;
	Queue<char> queue4;

	int i = 0;
	while (queue.isEmpty() && i < str.length())
	{
		queue.enqueue(str[i]);
		i++;
	}


	int length = 0;
	while (str[i] != '\0')
	{
		queue4.enqueue(queue.Front());
		if (str[i] == ' ')
		{
			while (str[i+1] != '\0')
			{
				queue3.enqueue(queue.Front());
				if (str[i] == ' ')
				{
					while (str[i + 1] != '\0')
					{
						queue2.enqueue(queue.Front());
						if (str[i] == ' ')
						{
							while (str[i + 1] != '\0')
							{
								queue1.enqueue(queue.Front());
							
							}
						}
					
					}
				}
			}
		}
		
		


	}

	return queue;
}

