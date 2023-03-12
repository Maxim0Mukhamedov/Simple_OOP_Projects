//
// Created by maxim on 3/12/23.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "matrixs/matrixs.hpp"
#include "utility"
#include "doctest/doctest.h"

TEST_CASE("Test of MatrixS") {
    MatrixS a(2,2);
    std::pair<int,int> nm = a.shape();
    for (int i = 0; i < nm.first; i++) {
        for (int j = 0; j < nm.second; j++) {
            std::cout << a[i][j] << ' ';
        }
        std::cout <<'\n';
    }
}
