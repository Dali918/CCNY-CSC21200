#include <iostream>
using namespace std;

//function printing sum and product
void sumAndProduct(int a, int b)
{
    cout << "Sum: " << a + b << endl;
    cout << "Product: " << a * b << endl;
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
    //print sum and product
    sumAndProduct(x, y);
    return 0;
}