#include <iostream>
using namespace std;
void sorting(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
void display(int array[], int size)
{
    if (size == 0)
    {
        cout << "Empty Set" << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}
int main()
{
    int SIZE;
    cout << "Enter Size : ";
    cin >> SIZE;

    if (SIZE <= 0)
    {
        cout << "Wrong Input Program Ended" << endl;
        return 0;
    }
    int* array = new int[SIZE];
    cout << "Enter Array: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cin >> array[i];
    }
    cout << "Entered Array : ";
    display(array, SIZE);
    cout << endl;
    int size1 = 0;
    int size2 = 0;
    if (SIZE % 2 == 0)
    {
        size1 = SIZE / 2;
        size2 = SIZE / 2;
    }
    else
    {
        size1 = SIZE / 2 + 1;
        size2 = SIZE / 2;
    }
    int* split1 = new int[size1];
    int* split2 = new int[size2];

    sorting(array, SIZE);
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        split1[i] = array[k];
        k++;
    }
    for (int i = 0; i < size1; i++)
    {
        split2[i] = array[k];
        k++;
    }
    cout << "Splited Array 1 : ";
    display(split1, size1);
    cout << endl;
    cout << "Splited Array 2 : ";
    display(split2, size2);
    return 0;
}