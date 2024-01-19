#include <iostream>
#include "Vecto.h"
using namespace std;

Vecto::Vecto(int _dimension) : dimension(_dimension)
{
    arr = new int[this->dimension];
    for (int i = 0; i < this->dimension; i++)
        *(arr + i) = 0;
}

Vecto::~Vecto()
{
    delete[] arr;
}

Vecto &Vecto::operator+(const Vecto &_v)
{
    int max_dimension = (this->dimension >= _v.dimension) ? this->dimension : _v.dimension;
    Vecto tmp(max_dimension);
    for (int i = 0; i < max_dimension; i++)
        *(tmp.arr + i) = *(this->arr + i) + *(_v.arr + i);
    delete[] this->arr;
    this->dimension = max_dimension;
    *this = tmp;
    return *this;
}

Vecto &Vecto::operator-(const Vecto &_v)
{
    int max_dimension = (this->dimension >= _v.dimension) ? this->dimension : _v.dimension;
    Vecto tmp(max_dimension);
    for (int i = 0; i < max_dimension; i++)
        *(tmp.arr + i) = *(this->arr + i) - *(_v.arr + i);
    delete[] this->arr;
    this->dimension = max_dimension;
    *this = tmp;
    return *this;
}

double Vecto::operator*(const Vecto &v)
{   
    double mul=0;
    for(int i = 0; i < this->dimension; i++){
        mul += *(this->arr + i) * (*(v.arr + i));
    }
    return mul;
}

double Vecto::operator^(int) const
{
 double sum = 0;
    for (int i = 0; i < this->dimension; ++i) {
        sum += arr[i] * arr[i];
    }
    return sqrt(sum);
}


int& Vecto::operator[](const int i)
{
    return arr[i];
}
