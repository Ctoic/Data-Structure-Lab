#include<iostream>
using namespace std;

template<typename T>

void Union(T arr[],int size, T arr1[], int size1)
{
    int len = size + size1;

    T arr2[len];
    int k;
    int i;

    for (i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }

    k = i;
    
    for (i = 0; i < size1; i++)
    {
        arr2[k] = arr1[i];
        k++;
    }

    for (i = 0; i < size + size1; i++)
    {
        cout << arr2[i] << ", ";
    }
}

template <typename T>
void Intersection(T arr[],int size, T arr1[], int size1)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size1; j++)
        {
            if(arr[i] == arr1[j])
            {
                cout << arr[i] << ", ";
            }
            else
            {
                continue;
            }
        }
    }
}

int main()
{
    char Arr[5] = { 'a','c','d','t','f' };
    char Arr1[4] = { 'a','m','f','g' };

    cout << "Union: ";
    Union(Arr,5, Arr1,4);
    
    cout << endl << "Intersection: ";
    Intersection(Arr,5,Arr1,4);
}