#include <iostream>
#include "Matrix.h"
#include "Vecto.h"
#include "Polynomial.h"
using namespace std;

int main() {
    Polynomial p1(2);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 1;
    cout << "Value at x = 3: " << p1(3) << endl;

    Polynomial p2(1);
    p2[0] = -1;
    p2[1] = 1;

    Polynomial p3 = p1 + p2;
    cout << "Value at x = 3: " << p3(3) << endl;

    Vecto v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    cout << "Length of vector: " << (v^2) << endl;

    Matrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    cout << "Element at (1, 1): " << m[1][1] << endl;

    Matrix m2(2, 2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    Matrix m3 = m * m2;

    cout << "Result of multiplication: " << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << m3[i][j] << " ";
        }
        cout << end;
    }

    return 0;
}