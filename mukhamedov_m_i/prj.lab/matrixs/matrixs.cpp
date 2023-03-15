#include "matrixs/matrixs.hpp"
#include <cstddef>
#include <stdexcept>
#include "iosfwd"
#include "utility"

MatrixS::MatrixS(int rows, int cols) : sshape_({rows,cols}){
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
    }
}

MatrixS::MatrixS(const MatrixS &other) : sshape_(other.shape()) {
    data = new double* [sshape_.first];
    for (int i  = 0; i < sshape_.first; i++){
        data[i] = new double[sshape_.second];
        for (int j = 0; j < sshape_.second; j++){
            data[i][j] = other[i][j];
        }
    }
}

MatrixS& MatrixS::operator=(const MatrixS &other){
    delete[] data;
    sshape_ = other.shape();
    data = new double* [sshape_.first];
    for (int i  = 0; i < sshape_.first; i++){
        data[i] = new double[sshape_.second];
        for (int j = 0; j < sshape_.second; j++){
            data[i][j] = other[i][j];
        }
    }
}

double *MatrixS::operator[](int index) const {
    if (index < 0 || index >= sshape_.first) throw std::invalid_argument("invalid index");
    return data[index];
}

std::pair<int, int> MatrixS::shape() const {
    return sshape_;
}
