#ifndef MATRICES_MATRIX_H
#define MATRICES_MATRIX_H

#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    double** data;

public:
    Matrix(int r, int c);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();
    void fill() const;
    Matrix  add (const Matrix& other) const;
    Matrix  multiply (const Matrix& other) const;
    void print() const;
};


#endif //MATRICES_MATRIX_H
