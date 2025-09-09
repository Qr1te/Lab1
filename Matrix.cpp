#include "Matrix.h"

Matrix::Matrix(int r, int c):rows(r),cols(c) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("The matrix dimensions must be positive");
    }

    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0.0;
        }
    }
}
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}


Matrix& Matrix:: operator=(const Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        rows = other.rows;
        cols = other.cols;
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}
void Matrix::fill() const{
    std::cout << "Enter matrix elements " << rows << "x" << cols << ":" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> data[i][j];
        }
    }
}
Matrix Matrix::add (const Matrix &other ) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrices must be of the same size to be added together");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}
Matrix Matrix::multiply(const Matrix &other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("The number of columns of the first matrix must be equal to the number of rows of the second matrix");
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

void Matrix::print() const{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
Matrix::~Matrix()  {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}
