#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isOdd(int i) { return (i % 2) == 1; }
vector<int>::iterator Chercher(vector<int>::iterator itr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (*itr == value)
        {
            return itr;
        }

        itr++;
    }

    return itr;
}
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

    vector<int> array = {1, 3, 7, 11, 13, 17, 23, 29, 31, 37}; // initialize vector
    vector<int>::iterator P_itr;                               // iterator
    cout << "****PRINTING ARRAY*******" << endl;
    for (P_itr = array.begin(); P_itr != array.end(); P_itr++)
    {
        cout << *P_itr << " ";
    }
    cout << "\n------------------\n";
    cout << "****UPDATED (100 at 5th element) ARRAY*******" << endl;
    P_itr = array.begin() + 4;      //access fifth element
    *P_itr = 100;                   //change it
    for (P_itr = array.begin(); P_itr != array.end(); P_itr++)
    {
        cout << *P_itr << " ";      
    }
    cout << endl;
    cout << "****PRINTING NUMBER OF ODD VALUES USING isOdd*******" << endl;
    cout << "Count: " << count_if(array.begin(), array.end(), isOdd) << endl;
    cout << "****USING CHERCHER (17 = 47)*******" << endl;
    int value = 17;
    P_itr = Chercher(array.begin(), array.size(), value);
    if (*P_itr != value)
    {
        cout << "VALUE NOT IN LIST" << endl;
    }
    else
    {
        *P_itr = 47;
        for (P_itr = array.begin(); P_itr != array.end(); P_itr++)
        {
            cout << *P_itr << " ";
        }
        cout<<endl;
    }
    cout << "****FINDING FIRST 5 ODD NUMBERS*******" << endl;
    int count = 0;
    P_itr = array.begin();

    while (P_itr != array.end() && count < 5)
    {
        P_itr = find_if(P_itr, array.end(), isOdd);
        cout << *P_itr << " ";
        P_itr++;
        count++;
    }
    

    return 0;
}