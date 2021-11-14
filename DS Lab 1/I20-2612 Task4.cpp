#include<iostream>
using namespace std;

template<typename T>

class Container
{

private:

    T* values;
    int capacity;
    int counter;

public:

    Container()
    {
        values = new T[10];

        for (int i = 0; i < 10; i++)
        {
            values[i] = 0;
        }
        capacity = 0;
        counter = 0;
    }

    bool isFull()
    {
        if (capacity == 10 && counter == 10)
        {
            return true;
        }

        return false;
    }

    void insert(T val)
    {
        if (!isFull())
        {
            values[counter] = val;
            counter++;
        }
    }
    bool search(T val)
    {
        for (int i = 0; i < 10; i++)
        {
            if (values[i] == val)
            {
                return true;
            }
        }

        return false;
    }
    void print()
    {
        cout << "The values are: ";

        for (int i = 0; i < 10; i++)
        {
            cout << values[i] << ", ";
        }
    }
    T* remove(T val)
    {

    }
};

int main()
{
    Container<int> obj;

    //inserting 2 values on index 0 and 1.
    obj.insert(6);
    obj.insert(7);
    obj.print();
    if(obj.isFull)
    {
        cout << "Container is full";
    }
    else
    {
        cout << "Container is not full";
    }
}