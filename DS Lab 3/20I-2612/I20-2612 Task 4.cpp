#include <iostream>
using namespace std;
bool validate(int input)
{
    if (input % 2 != 1)
    {
        return false;
    }
    return true;
}
void display(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int rows;
    int cols;
    // Prompt For input
    cout << "Enter rows : ";
    cin >> rows;
    while (!validate(rows))
    {
        cout << "Wrong Input ! Enter Rows again : ";
        cin >> rows;
    }
    cout << "Enter cols : ";
    cin >> cols;
    while (!validate(cols))
    {
        cout << "Wrong Input ! Enter Cols again : ";
        cin >> cols;
    }
    int **array = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[cols];
    }
    // taking input in array
    cout << "Enter value of array At :- " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "\t " << i << " " << j << " : ";
            cin >> array[i][j];
        }
    }
    cout << "Dispaly Matrix: " << endl;
    display(array, rows, cols);
    // Loogic for middle row
    int middleRow = (rows / 2);
    cout << "Middle row: ";
    for (int i = 0; i < cols; i++)
    {
        cout << array[middleRow][i] << " ";
    }
    cout << endl;
    int middleCol = (cols / 2);
    cout << "Middle column: ";
    for (int i = 0; i < rows; i++)
    {
        cout << array[i][middleCol] << " ";
    }
    return 0;
}