#include <iostream>
using namespace std;

//display function
void Display(int** arr, int row, int col)
{
    cout << "\n Entered Array: " << endl;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        
        cout << endl;
    }
}

//sum function
int ArraySum(int** arr, int row, int col)
{
    int sum = 0;
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
    }
    
    return sum;
}

//row wise sum
void row_sum(int** arr, int m, int n)
{
 
    int sum = 0;
 
    cout << "\nFinding Sum of each row:\n\n";
 
    // finding the row sum
    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            // Add the element
            sum = sum + arr[i][j];
        }
 
        // Print the row sum
        cout << "Sum of the row " << i << " = " << sum << endl;
 
        // Reset th
        sum = 0;
    }
}
//column wise sum
void column_sum(int** arr, int m, int n)
{
 
    int sum = 0;
 
    cout << "\nFinding Sum of each column:\n\n";
 
    // finding the column sum
    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j)
        {
            sum = sum + arr[j][i];
        }
 
        // Print the column sum
        cout << "Sum of the column " << i << " = " << sum << endl;
 
        // Reset the sum
        sum = 0;
    }
}

void Transpose(int **arr,int row,int column)
{
    int transpose[row][column];
    // Computing transpose of the matrix
   for (int i = 0; i < row; ++i)
   {
      for (int j = 0; j < column; ++j) 
      {
         transpose[j][i] = arr[i][j];
      }
   }

   // Printing the transpose
   cout << "\nTranspose of Matrix: " << endl;
   
   for (int i = 0; i < column; ++i)
   {
      for (int j = 0; j < row; ++j) 
      {
        cout << " " << transpose[i][j];
        
        if (j == row - 1)
        {
            cout  << endl;
        }
      }  
    }

}

int main()
{
    int rows;
    int columns;
    
    cout << "Enter the rows of the matrix: ";
    cin >> rows;
    
    cout << "Enter the columns of the matrix: ";
    cin >> columns;
    
    int** Array = new int*[rows];
    
    for(int i = 0; i < rows; i++)
    {
        Array[i] = new int[columns];
    }
    
    cout << "Enter the elements in the matrix. " << endl;
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << "Enter Array[" << i << "][" << j << "] = ";
            cin >> Array[i][j];
        }
    }
    
    Display(Array,rows,columns);
    
    cout << "\nThe sum of the elements is: " << ArraySum(Array,rows,columns) << endl;
    row_sum(Array,rows,columns);
    column_sum(Array,rows,columns);
    Transpose(Array,rows,columns);
}
