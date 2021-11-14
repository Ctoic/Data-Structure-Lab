#include<iostream>
using namespace std;

int main() 
{
    string s;
    cout << "Enter a string: "
    
    //taking the complete line as input
    getline(cin, s);
    int k = 1;
    bool flag = false;
    
    //printing each queue by splitting at every space
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') 
        {
            k++;
            flag = false;
        }
        else 
        {
            //generating queue template Q[i]
            if (!flag)
            {
                cout << endl;
                cout << "Q" << k << " = ";
                flag = true;
            }
            cout << s[i];
            if ((i + 1 < s.length()) && (s[i + 1] != ' ')) 
            {
                cout << " -> ";
            }
        }
    }
    
    //concatinating all the queue
    cout << "\nQ = ";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') 
        {
            continue;
        }
        cout << s[i];
        
        if (i == s.length() - 1)
        {
            continue;
        }
        cout << " -> ";
    }
    return 0;
}