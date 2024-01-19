#pragma once

class Vecto
{
private:
    int dimension;
    int *arr;

public:
    Vecto(int);
    ~Vecto();
    Vecto &operator+(const Vecto &);
    Vecto &operator-(const Vecto &);
    int& operator[](const int);
    double operator*(const Vecto &); //Ham tinh tich vo huong cua 2 vector
    double operator^(int) const;
};