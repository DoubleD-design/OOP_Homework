#pragma once

class Polynomial {
    int degree;
    double* coefficients;

public:
    Polynomial(int degree);
    ~Polynomial();

    double& operator[](int);
    double operator()(double x) const;
    Polynomial operator+(const Polynomial& p) const;
    Polynomial operator-(const Polynomial& p) const;
    Polynomial operator*(const Polynomial& p) const;
    Polynomial& operator=(const Polynomial& p);
};
