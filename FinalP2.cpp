#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;

template <typename T>
class Matrix
{
public:
    // default constructor
    Matrix() {}
    // constructor with input
    Matrix(const int row, const int column);
    // copy constructor
    Matrix(const Matrix<T> &matrix);
    // destructor
    ~Matrix();
    void operator=(const Matrix<T> &matrix);
    T &operator()(int row, int col);
    int getRowSize() { return this->row_size; }
    int getColSize() { return this->column_size; }
    bool isEmpty() { return (this->row_size == 0) && (this->column_size == 0); }

private:
    string stackUnderflow = "exception: stack is empty!";
    vector<T *> rows;
    int row_size, column_size;
};

template <typename T>
Matrix<T>::Matrix(const int row, const int column)
{
    this->row_size = row;
    this->column_size = column;
    rows.resize(this->row_size);
    for (int i = 0; i < this->row_size; i++)
    {
        rows.at(i) = new T *[this->column_size];
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &matrix)
{

    this->row_size = matrix.row_size;       // change row size
    this->column_size = matrix.column_size; // change column size
    this->rows.resize(this->row_size);      // resize matrix
    for (int i = 0; i < this->row_size; i++)
    {
        rows.at(i) = new T *[this->column_size]; // change column size
        for (int j = 0; j < this->column_size; j++)
        {
            rows.at(i)[j] = matrix.rows.at(i)[j]; // copy contents
        }
    }
}

template <typename T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < this->row_size; i++)
    {
        delete rows.at(i);
    }
}
template <typename T>
void Matrix<T>::operator=(const Matrix<T> &matrix)
{
    if (this != &matrix)
    {
        // check if matrices have equal dimensions
        if (this->row_size != matrix.row_size || this->column_size != matrix.column_size)
        {
            cout << "UNEQUAL MATRICES \n------------\n";
            return;
        }

        // check if they do not have equal dimensions
        for (int i = 0; i < this->row_size; i++)
        {
            for (int j = 0; j < this->column_size; j++)
            {
                this->rows.at(i)[j] = matrix.rows.at(i)[j]; // copy contents
            }
        }
    }
}

template <typename T>
T &Matrix<T>::operator()(int row, int col)
{
    return this->rows.at(row)[col]; // overloaded elemet access operator
}

template <typename T>
Matrix<T> &operator+(Matrix<T> &left, Matrix<T> &right)
{
    bool rowEqual = left.getRowSize() != right.getRowSize();
    bool colEqual = left.getColSize() != right.getColSize();
    int row = 0;
    int column = 0;
    Matrix<T> newMatrix;
    if (rowEqual && colEqual)
    {
        row = left.getRowSize();
        column = left.getColSize();
        newMatrix = Matrix<T>(row, column);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                newMatrix(i, j) = left(i, j) + right(i, j); // copy contents
            }
        }

        return newMatrix;
    }
    else
    {

        newMatrix = Matrix<T>(row, column);
        return newMatrix;
    }
}

template <typename T>
ostream &operator<<(ostream &out, Matrix<T> &matrix)
{

    return out;
}
int main()
{
    // string Name;
    // /*****************************************/
    // cout << "Student Enter Name" << endl;
    // cin >> Name;
    // cout << "---------  -------------------------------------" << endl;
    // cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    // cout << "Student Name: " << Name << endl;
    // cout << "----------------------------------------------" << endl;
    // /*****************************************/

    return 0;
}