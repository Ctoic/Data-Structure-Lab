#include <iostream>  
using namespace std;  

int** MatrixAddition(int** Arr1,int** Arr2,int row,int col)
{
    int sum = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            Arr1[i][j] = Arr1[i][j] + Arr2[i][j];
        }
    }
    
    return Arr1;
}

int main()  
{  
    int mul[10][10],r,c,i,j,k;   
    
    cout<<"enter the number of row=";    
    cin>>r;    
    cout<<"enter the number of column=";    
    cin>>c;    
    cout<<"enter the first matrix element=\n";    

    int** a = new int*[r];
    
    for(int i = 0; i < r; i++)
    {
        a[i] = new int[c];
    }
    
    int** b = new int*[r];
    
    for(int i = 0; i < r; i++)
    {
        b[i] = new int[c];
    }

    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {       
            cin>>a[i][j];  
        }    
    }    

    cout<<"enter the second matrix element=\n";    

    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            cin>>b[i][j];    
        }    
    }
    
    int ** Sum = MatrixAddition(a,b,r,c);
    cout << "The sum of matrices is: " << endl;
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << Sum[i][j] << " ";
        }
        
        cout << endl;
    }
    
    
    cout<<"\nMultiply of the matrix=\n";    

    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            mul[i][j]=0;    

            for(k=0;k<c;k++)    
            {    
                mul[i][j]+=a[i][k]*b[k][j];    
            }               
        }    
    }    

    //for printing result    
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            cout<<mul[i][j]<<" ";    
        }    
    
        cout<<endl;    
    }    
    
    
return 0;  
}