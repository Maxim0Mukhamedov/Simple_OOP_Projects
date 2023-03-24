//
// Created by maxim on 3/12/23.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "matrixs/matrixs.hpp"
#include "utility"
#include "doctest/doctest.h"

TEST_CASE("Test of MatrixS") {
    CHECK_NOTHROW(MatrixS(1,4));
    MatrixS a(2,4);
    MatrixS b;
    b = a;
    std::pair<int,int> nm = {b.getRows(),b.getCols()};
    for (int i = 0; i < nm.first; i++) {
        for (int j = 0; j < nm.second; j++) {
            std::cout << a.at(i,j) << ' ';
        }
        std::cout << '\n';
    }
    b.at(0,0) = 1;
    b.resize(3,5);
    nm = {b.getRows(),b.getCols()};
    for (int i = 0; i < nm.first; i++) {
        for (int j = 0; j < nm.second; j++) {
            std::cout << b.at(i,j) << ' ';
        }
        std::cout << '\n';
    }
}
