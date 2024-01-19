#include "Polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

Polynomial::Polynomial(int degree) : degree(degree), coefficients(new double[degree + 1]) {}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

double& Polynomial::operator[](int i) {
    return coefficients[i];
}

double Polynomial::operator()(double x) const {
    double sum = 0;
    for (int i = 0; i <= degree; ++i) {
        sum += coefficients[i] * pow(x, i);
    }
    return sum;
}

Polynomial Polynomial::operator+(const Polynomial& p) const {
    int maxDegree = (this->degree >= p.degree)? this->degree: p.degree;
    Polynomial result(maxDegree);
    for (int i = 0; i <= maxDegree; ++i) {
        result[i] = (i <= degree ? coefficients[i] : 0) + (i <= p.degree ? p.coefficients[i] : 0);
    }
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& p) const {
    int maxDegree = (this->degree >= p.degree)? this->degree: p.degree;
    Polynomial result(maxDegree);
    for (int i = 0; i <= maxDegree; ++i) {
        result[i] = (i <= degree ? coefficients[i] : 0) - (i <= p.degree ? p.coefficients[i] : 0);
    }
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& p) const {
    Polynomial result(degree + p.degree);
    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= p.degree; ++j) {
            result[i + j] += coefficients[i] * p.coefficients[j];
        }
    }
    return result;
}

Polynomial& Polynomial::operator=(const Polynomial& p) {
    if (this != &p) {
        delete[] coefficients;
        degree = p.degree;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = p.coefficients[i];
        }
    }
    return *this;
}
