#include "matrixs/matrixs.hpp"
#include <cstddef>
#include <stdexcept>
#include "iosfwd"
#include "utility"

MatrixS::MatrixS(int new_rows, int new_cols) : row(new_rows), col(new_cols){
    data = new int[row * col];
    for (int i = 0; i < row * col; i++) {
        data[i] = 0;
    }

}

MatrixS::MatrixS(const MatrixS &other) : row(other.rows()), col(other.cols()) {
    data = new int[row * col];
    for (int i = 0; i < row * col; i++) {
        data[i] = other.at(i/col,i%row);
    }
}

MatrixS& MatrixS::operator=(const MatrixS &other){
    delete[] data;
    row = other.rows();
    col = other.cols();
    data = new int[row * col];
    for (int i = 0; i < row * col; i++) {
        data[i] = other.at(i/col,i%col);
    }
}

const int& MatrixS::at(int index_row, int index_col) const {
    if (index_row >= row || index_row < 0 || index_col >= col || index_col < 0) {throw std::invalid_argument("invalid index");}
    return data[col * index_row + index_col];
}
int& MatrixS::at(int index_row, int index_col) {
    if (index_row >= row || index_row < 0 || index_col >= col || index_col < 0) {throw std::invalid_argument("invalid index");}
    return data[col * index_row + index_col];
}

const int MatrixS::cols() const {
    return col;
}
const int MatrixS::rows() const {
    return row;
}

void MatrixS::resize(int rows, int cols) {
    int* old = data;
    data = new int[rows * cols];
    for (int i = 0; i < rows*cols; i++) {data[i] = 0;}
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
           data[col * i + j] = old[col * i + j];
        }
    }
    row = rows;
    col = cols;
    delete[] old;
}
