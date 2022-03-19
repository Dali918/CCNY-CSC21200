// Dalitso Banda CSC21200 | Test 1
#include <iostream>
#include <string>
using namespace std;

/*Write a program that calculates the sum of the first 15 (size)Fibonacci numbers. The generated Fibonacci
numbers should be stored in an integer array (i.e. int fib[15]). Recall from class readings that the Fibonacci series
for the first 20 number is as follows:

Fn = Fn−1 + Fn−2


The program should be organized such that it
->calls a function void fibonnaci(int * fib_ptr, int size) which generates the Fibonacci series
->followed by a second function int sum(int * fib_ptr, int size) which calculates the sum of all 15 Fibonacci
numbers.
Where int * fib_ptr = &fib[0];


*/

void fibonnaci(int *fib_ptr, int size)
{
    
    
    //populate array 
    for (int i = 0; i < size; i++)
    {
        // set the first and second elements
        if (i == 0)
        {
            fib_ptr[i] = 0;
        }
        else if (i == 1)
        {
            fib_ptr[i] = 1;
        }
        // create the other elements
        else
        {
            fib_ptr[i] = fib_ptr[i - 1] + fib_ptr[i - 2];
        }
    }
}

int sum(int *fib_ptr, int size)
{
    //loop through aray and sum values
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += fib_ptr[i];
    }

    return sum;
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
    
    int size = 15;
    //make sure an appropriate size is allocated
    if (size < 2)
    {
        size = 2;
    }
    //allocate memory 
    int *fib = new int[size];
    //populate array
    fibonnaci(fib, size);
    //calcualate sum
    int fib_sum = sum(fib, size);
    //print out sequence 
    cout<<"The first "<<size<< " fibonacci numbers are:"<<endl;
    for(int i=0; i<size;i++){
        cout<<fib[i]<<", ";
    }
    cout<<endl;
    //print sum
    cout << "The sum of the first " << size << " fibonacci numbers is: \n" << fib_sum << endl;
    //deallocate memory
    delete[] fib;

    return 0;
}