#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
struct Alpha
{
    char alp;
    int ascii;
    void display()
    {
        cout << alp << " " << ascii << endl;
    }
};
void Assing(Alpha *array)
{
    for (int i = 0; i < 26; i++)
    {
        array[i].alp = 65 + i;
        array[i].ascii = (90 - i) - 65 + 1;
    }
}
int frequency(string str, char check)
{
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (str[i] == check)
        {
            count++;
        }
    }
    return count;
}
int finding(Alpha array[], char deli)
{
    for (int i = 0; i < 26; i++)
    {
        if (array[i].alp == deli)
        {
            return array[i].ascii;
        }
    }
    return -1;
}
int main()
{
    Alpha *array = new Alpha[26];
    Assing(array);
    for (int i = 0; i < 26; i++)
    {
        array[i].display();
    }
    string str;
    cout << "Enter Upper Case String : ";
    cin >> str;
    int itr = 0;
    int i = 0;
    bool condition = true;
    while (str[i] != '\0')
    {
        int freq = frequency(str, str[i]);
        int assci = finding(array, str[i]);
        if (freq != assci)
        {
            condition = false;
            break;
        }
        i++;
    }
    if (condition == true)
    {
        cout << "Given is super string" << endl;
    }
    else
    {
        cout << "Given is not a Super String" << endl;
    }
    return 0;
}