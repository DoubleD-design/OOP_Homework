#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int _row, int _column, int _default) : row(_row), column(_column)
{
    arr = new int *[this->row];
    for (int i = 0; i < this->row; i++)
    {
        *(arr + i) = new int[this->column];
        for (int j = 0; j < this->column; j++)
            *(*(arr + i) + j) = _default;
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < this->row; i++)
        delete[] * (arr + i);
    delete[] arr;
}

int* Matrix::operator[](int i){
        return arr[i];
}

Matrix &Matrix::operator+(const Matrix &input)
{
    if (this->row != input.row || this->column != input.column)
        throw string("Cannot plus matrix");
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->column; j++)
            *(*(this->arr + i) + j) += *(*(input.arr + i) + j);
    return *this;
}

Matrix &Matrix::operator-(const Matrix &input)
{
    if (this->row != input.row || this->column != input.column)
        throw string("Cannot minus matrix");
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->column; j++)
            *(*(this->arr + i) + j) -= *(*(input.arr + i) + j);
    return *this;
}

Matrix Matrix::operator*(Matrix& m) {
    if (this->column != m.row) {
        throw std::invalid_argument("Number of columns in first matrix must be equal to number of rows in second matrix");
    }

    Matrix result(this->row, m.column);
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < m.column; ++j) {
            for (int k = 0; k < this->column; ++k) {
                result[i][j] += this->arr[i][k] * m[k][j];
            }
        }
    }

    return result;
}

istream &operator>>(istream &inp, Matrix &_m)
{
    for (int i = 0; i < _m.row; i++)
        for (int j = 0; j < _m.column; j++)
        {
            cout << "Input value of index [" << i << "][" << j << "]: ";
            inp >> *(*(_m.arr + i) + j);
        }
    return inp;
}

ostream &operator<<(ostream &out, const Matrix &_m)
{
    out << "Print matrix: " << endl;
    for (int i = 0; i < _m.row; i++)
    {
        for (int j = 0; j < _m.column; j++)
            out << *(*(_m.arr + i) + j) << " ";
        out << endl;
    }
    return out;
}