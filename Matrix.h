#pragma once
#include <iostream>
using namespace std;
class Matrix
{
private:
    int row, column;
    int **arr;

public:
    Matrix(int, int, int = 0);
    ~Matrix();
    Matrix &operator+(const Matrix &);
    Matrix &operator-(const Matrix &);
    int* operator[](int);
    Matrix operator*(Matrix&);
    friend istream &operator>>(istream &, Matrix &);
    friend ostream &operator<<(ostream &, const Matrix &);
};