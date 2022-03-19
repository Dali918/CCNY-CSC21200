// Dalitso Banda CSC21200 | Test 1
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Array
{
private:
    int *pType; // array elements are created on the heap
    int Size;

public:
    // constructors
    Array(int Size = 1);      // write “parametrized constructor”
    Array(const Array &copy); // copy constructor
    ~Array();                 // destructor		//write “destructor”

    // accessors & mutators
    int getSize() const { return this->Size; }
    void setSize(int size) { this->Size = size; }

    // operators
    Array &operator=(const Array &rhs);
    int &operator[](int offSet);
    const int &operator[](int offSet) const; // works with const object
    // Overloaded arithmetic operator
    Array operator+(const Array &rhs);
    // overloaded output stream operator
    friend ostream &operator<<(ostream &out, const Array &rhs); 
    // friend functions
    friend Array operator+(int K, const Array &rhs);
    friend Array operator+(const Array &rhs, int K);
};

/*------------------------CLASS DEFINTIONS-----------------------------------*/
// DEFAULT CONSTRUCTOR
Array::Array(int Size)
{
    this->Size = Size;
    pType = new int[Size];
}
// COPY CONSTRCUTOR
Array::Array(const Array &copy)
{
    this->Size = copy.Size;     //resize
    pType = new int[Size];      //allocate memory
    for (int i = 0; i < Size; i++)
    {
        this->operator[](i) = copy[i];      //copy contents
    }
}
// DESTRCUTOR
Array::~Array()
{
    cout << "Destructing Array" << endl;
    delete[] pType;     //deallocate memory
}

// OVERLOADED ASSIGNMENT OPERATOR
Array &Array::operator=(const Array &rhs)
{
    if (this != &rhs)
    {
        delete[] pType;        // deallocate memory
        this->Size = rhs.Size; // resize array
        pType = new int[Size]; // reallocate memory
        for (int i = 0; i < Size; i++)
        {
            this->operator[](i) = rhs[i]; // copy contents
        }
    }

    return *this;
}

//OVERLOADED ARITHMETIC FRIEND AND MEMBER FUNCTIONS 
Array Array::operator+(const Array &rhs)
{

    if (this->Size != rhs.Size)
    {
        throw "Unequal sizes, cannot add!"; // make sure sizes are equal before addition
    }

    Array new_array(Size); // create new array
    for (int i = 0; i < Size; i++)
    {
        new_array[i] = this->operator[](i) + rhs[i]; // add array elements
    }

    return new_array;
}

Array operator+(int K, const Array &rhs)
{
    Array new_array(rhs.getSize()); // new array
    for (int i = 0; i < rhs.getSize(); i++)
    {
        new_array[i] = K + rhs[i]; // populate array elements with sums
    }

    return new_array;
}

Array operator+(const Array &rhs, int K)
{
    return K + rhs;
}

//OVERLOADED ARRAY ACCESS OPERATORS
int &Array::operator[](int offSet)
{

    if (offSet < 0 || offSet > Size)    //range check index
    {
        ostringstream out;
        out << "Invalid Access - Index out of range - Illegal Index: " << offSet << " Size: " << Size << endl;
        throw out.str(); // throw exception for illegal index access
    }

    return pType[offSet];
}

const int &Array::operator[](int offSet) const
{
    if (offSet < 0 || offSet > Size)    //range check index
    {
        ostringstream out;
        out << "Invalid Access - Index out of range - Illegal Index: " << offSet << " Size: " << Size << endl;
        throw out.str(); // throw exception for illegal index access
    }

    return pType[offSet];
}
//OVERLOADED OUTPUT STREAM OPERATOR 
ostream &operator<<(ostream &out, const Array &rhs)
{

    for (int i = 0; i < rhs.getSize(); i++)
    {
        cout << "[" << i << "] = " << rhs[i] << ", ";
    }

    return out;
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

    try
    {

        Array X(10), Y(10), Z;

        //Generate Data
        for (int i = 0; i < 10; ++i)
        {
            X[i] = i * 2;
            Y[i] = i * i;
        }
        cout << "X: " << X << endl;
        cout << "Y: " << Y << endl;
        cout << "Z: " << Z << endl;
        cout << endl;
        //Z = X+Y;
        cout << "Performing Z = X + Y" << endl;
        Z = X + Y;
        cout << "X: " << X << endl;
        cout << "Y: " << Y << endl;
        cout << "Z: " << Z << endl;
        cout << endl;
        //Z = 10+X;
        cout << "Performing Z = 10 + X" << endl;
        Z = 10 + X;
        cout << "X: " << X << endl;
        cout << "Z: " << Z << endl;
    }
    catch (const string &error)
    {
        cout << error << endl;
    }

    return 0;
}