#include <iostream>
using namespace std;


//function calculating average of two integers
int average(int X, int Y)
{
    return (X + Y) / 2;
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

    //rest of code
    //initialize values
    int x = 10;
    int y = 20;
    cout << "Variables: "
         << "X: " << x << " Y: " << y << endl;
    //calculate  average
    int calculatedAverage = average(x,y);
    //print average
    cout << "Average: " << calculatedAverage  << endl;

    return 0;
}