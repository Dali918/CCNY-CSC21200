#include <iostream>
#include <string>
using namespace std;

int main()
{
    string Name;
    /*****************************************/
    cout << "Student Enter Name" << endl;
    cin >> Name;
    cout << "---------  -------------------------------------" << endl;
    cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
    /*****************************************/
    const int size = 32;
    int count[size]{0}, j = 0;
    string line;
    while (getline(cin, line) && j != size)
    {
        int value = 0;
        for (int i = 0; i < line.length(); i++)
        {
            value += line[i];
        }

        count[j] = value;
        j++;
    }
    
    j = 0;
    while (count[j] != 0)
    {
        cout << "Line: " << j << " numerical value: " << count[j] << endl;
        j++;
    }

    return 0;
}