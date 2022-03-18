// Dalitso Banda CSC21200 | Homework 3 Problem 1
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/*Write a program containing a base Animal class that can contains member
functions that can output (i) ”I can eat”, (ii) “I can sleep” as well as a showData()
member function that outputs the weight and age. A derived class Dog contains a
function that displays “I am a dog” and can output the dog species’ name (e.g.
“bulldog”). Both the base class and derived class must have appropriate
constructors, destructors and assignment=() operators. */

// Class declarations, see class definitions at the bottom

class Animal
{
private:
    double weight;
    int age;

public:
    // constructors and destructors
    Animal() {}
    Animal(double w, int a) : weight{w}, age{a} {}
    inline ~Animal() { cout << "Destructing Animal" << endl; }
    // Assingment Operator
    Animal &operator=(const Animal &copy);
    // functions
    void eat();
    void sleep();
    void showData();
};

class Dog : public Animal
{
public:
    //constructors and destrcutors
    Dog() {}
    Dog(double weight, int age) : Animal(weight, age) {}
    ~Dog() { cout << "Destructing dog" << endl; }
    //assignment operator
    Dog& operator=(const Dog& copy);
    //member function
    void bark();
};

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

    //testing Animal class
    cout<<"Intializing animal with weight: 212.45, age: 56"<<endl;
    Animal mammal(212.45,56);
    mammal.showData();
    cout<<"Updating dog with weight: 90.88, age: 34"<<endl;
    mammal= Animal(90.88,34);
    mammal.showData();
    cout<<endl;
    
    //testing dog class
     cout<<"Intializing dog with weight: 156.50, age: 30"<<endl;
    Dog woofin(156.50, 3);
    woofin.showData();
    cout<<"Updating dog with weight: 60, age: 7"<<endl;
    woofin = Dog(60,7);
    woofin.showData();

    return 0;
}

// Class member function definitions

void Animal::eat()
{
    cout << "I can eat" << endl;
}

void Animal::sleep()
{
    cout << "I can sleep" << endl;
}

void Animal::showData()
{
    cout << "Weight: " << this->weight << endl;
    cout << "Age: " << this->age << endl;
}

void Dog::bark()
{
    cout << "I am a dog" << endl;
}

//assignment operator definitions
Animal &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
    {
        this->weight = copy.weight;
        this->age = copy.age;
    }

    return *this;
}

Dog& Dog::operator=(const Dog& copy){
    if (this != &copy)
    {
        //call Animal operator=
        Animal::operator=(copy);
    }

    return *this;

}