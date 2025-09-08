#ifndef MATRICES_MATRIX_H
#define MATRICES_MATRIX_H

#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    double** data;

public:
    Matrix(int r, int c);
    ~Matrix();
    void fill();
    Matrix add( Matrix& other);
    Matrix multiply( Matrix& other);
    void print();
};


#endif //MATRICES_MATRIX_H
