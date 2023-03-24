#include "matrixs/matrixs.hpp"
#include <cstddef>
#include <stdexcept>
#include "iosfwd"
#include "tuple"
#include "utility"

MatrixS::MatrixS(int new_rows, int new_cols){
    std::get<0>(shape) = new_rows;
    std::get<1>(shape) = new_cols;
    data = new int[std::get<0>(shape) * std::get<1>(shape)];
    for (int i = 0; i < std::get<0>(shape) * std::get<1>(shape); i++) {
        data[i] = 0;
    }

}

MatrixS::MatrixS(const MatrixS &other) {
    std::get<0>(shape) = other.getRows();
    std::get<1>(shape) = other.getCols();
    data = new int[std::get<0>(shape) * std::get<1>(shape)];
    for (int i = 0; i < std::get<0>(shape) * std::get<1>(shape); i++) {
        data[i] = other.at(i/std::get<1>(shape),i%std::get<0>(shape));
    }
}

MatrixS& MatrixS::operator=(const MatrixS &other){
    delete[] data;
    std::get<0>(shape) = other.getRows();
    std::get<1>(shape) = other.getCols();
    data = new int[std::get<0>(shape) * std::get<1>(shape)];
    for (int i = 0; i < std::get<0>(shape) * std::get<1>(shape); i++) {
        data[i] = other.at(i/std::get<1>(shape),i%std::get<1>(shape));
    }
}

const int& MatrixS::at(int index_row, int index_col) const {
    if (index_row >= std::get<0>(shape) || index_row < 0 || index_col >= std::get<1>(shape) || index_col < 0) {throw std::invalid_argument("invalid index");}
    return data[std::get<1>(shape) * index_row + index_col];
}
int& MatrixS::at(int index_row, int index_col) {
    if (index_row >= std::get<0>(shape) || index_row < 0 || index_col >= std::get<1>(shape) || index_col < 0) {throw std::invalid_argument("invalid index");}
    return data[std::get<1>(shape) * index_row + index_col];
}

[[nodiscard]] int MatrixS::getRows() const noexcept {
    return std::get<0>(shape);
}
[[nodiscard]] int MatrixS::getCols() const noexcept {
    return std::get<1>(shape);
}

void MatrixS::resize(int getRows, int getCols) {
    int* old = data;
    data = new int[getRows * getCols];
    for (int i = 0; i < getRows*getCols; i++) {data[i] = 0;}
    for (int i = 0; i < std::get<0>(shape); i++) {
        for (int j = 0; j < std::get<1>(shape); j++) {
           data[std::get<1>(shape) * i + j] = old[std::get<1>(shape) * i + j];
        }
    }
    std::get<0>(shape) = getRows;
    std::get<1>(shape) = getCols;
    delete[] old;
}
