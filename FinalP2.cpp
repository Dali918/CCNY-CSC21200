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
    Matrix(const int row, const int column, T value = NULL);
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
    vector<T *> rows;
    int row_size, column_size;
};

template <typename T>
Matrix<T>::Matrix(const int row, const int column, T value)
{
    this->row_size = row;
    this->column_size = column;
    rows.resize(this->row_size);
    for (int i = 0; i < this->row_size; i++)
    {
        rows.at(i) = new T[this->column_size]; // change column size
        for (int j = 0; j < this->column_size; j++)
        {
            rows.at(i)[j] = value; // copy contents
        }
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
        rows.at(i) = new T[this->column_size]; // change column size
        for (int j = 0; j < this->column_size; j++)
        {
            rows.at(i)[j] = matrix.rows.at(i)[j]; // copy contents
        }
    }
}

template <typename T>
Matrix<T>::~Matrix()
{
    cout << "DESTRUCTING MATRIX" << endl;
    for (int i = 0; i < this->row_size; i++)
    {
        delete this->rows.at(i);
    }
}
template <typename T>
void Matrix<T>::operator=(const Matrix<T> &matrix)
{
    if (this != &matrix)
    {
        this->row_size = matrix.row_size;       // change row size
        this->column_size = matrix.column_size; // change column size
        this->rows.resize(this->row_size);      // resize matrix
        for (int i = 0; i < this->row_size; i++)
        {
            rows.at(i) = new T[this->column_size]; // change column size
            for (int j = 0; j < this->column_size; j++)
            {
                this->rows.at(i)[j] = matrix.rows.at(i)[j]; // copy contents
            }
        }
    }
}
template <typename T>
T &Matrix<T>::operator()(int row, int col) // element access overload
{
    return this->rows.at(row)[col];
}
template <typename T>
Matrix<T> operator+(Matrix<T> &left, Matrix<T> &right)
{
    bool rowEqual = left.getRowSize() == right.getRowSize();
    bool colEqual = left.getColSize() == right.getColSize();

    Matrix<T> newMatrix;
    if (rowEqual && colEqual) // ensure dimensions are equal
    {

        int row = left.getRowSize();
        int column = left.getColSize();
        newMatrix = Matrix<T>(row, column, left(1, 1)); // create new matrix
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                newMatrix(i, j) = left(i, j) + right(i, j); // copy contents
            }
        }
    }
    else
    {
        cout << "UNEQUAL, CANNOT ADD" << endl;
        newMatrix = Matrix<T>(0, 0, 0); // return empty matrix if not equal
        return newMatrix;
    }

    return newMatrix;
}

template <typename T>
ostream &operator<<(ostream &out, Matrix<T> &matrix)
{

    int row = matrix.getRowSize();
    int column = matrix.getColSize();
    cout << "***** Printing (" << row << "X" << column << ") Matrix *********" << endl;

    for (int i = 0; i < row; i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < column; j++)
        {
            cout << matrix(i, j) << " ";
        }

        cout << endl;
    }

    cout << "-------------------------" << endl;
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

    Matrix<int> matrix(5, 5, 6);
    cout << "INT MATRIX"<<matrix;

    Matrix<char> A_matrix(8, 8, 'A');
    Matrix<char> B_matrix(8, 8, 'B');
    Matrix<char> R_matrix(8, 8, ' ');
    cout<<"A MATRIX\n"<<A_matrix <<"B MATRIX\n"<<B_matrix;
    cout << "*****INCREMENT EACH ELEMENT BY i*ROW#******" << endl;
    for (int i = 0; i < A_matrix.getRowSize(); i++)
    {
        for (int j = 0; j < A_matrix.getColSize(); j++)
        {
            A_matrix(i, j) *= i + 1;
        }
    }

    for (int i = 0; i < B_matrix.getRowSize(); i++)
    {
        for (int j = 0; j < B_matrix.getColSize(); j++)
        {
            B_matrix(i, j) *= i + 1;
        }
    }
    cout <<"A MATRIX\n"<<A_matrix<<"B MATRIX\n"<< B_matrix;
    cout << "*****ADDING A MATRIX AND B MATRIX (R MATRIX)******" << endl;

    R_matrix = A_matrix + B_matrix;
    cout<<"A MATRIX\n"<<A_matrix << "B MATRIX\n"<< B_matrix << "R MATRIX\n"<<R_matrix;

    return 0;
}