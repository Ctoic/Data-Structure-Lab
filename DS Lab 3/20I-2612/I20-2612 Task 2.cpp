#include<iostream>
using namespace std;

int LeftDiagonalSum(int** arr1, int row, int col)
{
    int sum = 0;
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == j)
            {
                sum += arr1[i][j];
            }
        }
    }
    
    return sum;
}


int RightDiagonalSum(int** arr1, int row, int col)
{
    int sum = 0;
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if((i + j) == col - 1)
            {
                sum += arr1[i][j];
            }
        }
    }
    
    return sum;
}


int main()
{
    int row;
    int col;
    
    cout << "Enter the rows of the matrix: ";
    cin >> row;
    
    cout << "Enter the columns of the matrix: ";
    cin >> col;
    
    int** Array = new int*[row];
    
    for(int i = 0; i < row; i++)
    {
        Array[i] = new int[col];
    }
    
    cout << "\nEnter the elements in the array: \n" << endl;
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << "Enter Array[" << i << "][" << j << "] = ";
            cin >> Array[i][j];
        }
    }
    
    cout << "\nThe left diagonal sum of the matri is: " << LeftDiagonalSum(Array,row,col) << endl;
     cout << "The right diagonal sum of the matri is: " << RightDiagonalSum(Array,row,col) << endl;
}