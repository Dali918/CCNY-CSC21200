// Dalitso Banda CSC21200 | Homework 2 Problem 2
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/*Write a program that uses requests the size of an array and creates an integer Array(e.g. size = 16) 
on the heap and initializes its elements to be multiples of 2
(i.e. 0,2,4,..30) */

int main(){
     string Name;
    /*****************************************/
    cout << "Student Enter Name" << endl;
    cin >> Name;
    cout << "---------  -------------------------------------" << endl;
    cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
    /*****************************************/

    
    int size;   //get array size
    cout<<"Enter the size of the array: "<<endl;
    cin >>size;
    int * array = new int[size];    //allocate memory in heap
    
    //populate array
    for(int i=0; i<size; i++){
        array[i] = (i+1)*2;
        cout<<" array ["<<i<<"] : "<<array[i]<<endl;  //print contents at position
    }
    cout<<endl;
    delete[] array; //deallocate memory
    return 0;
}
