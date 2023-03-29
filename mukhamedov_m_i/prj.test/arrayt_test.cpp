#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "arrayt/arrayt.hpp"
#include "doctest/doctest.h"
TEST_CASE("testing the T functions") {
    CHECK_NOTHROW(ArrayT<int>{1, 2});
    CHECK_NOTHROW(ArrayT<int>{1, 2}.ssize());
    CHECK_NOTHROW(ArrayT<int>{1, 2});
    ArrayT<int> a{1,2};
    ArrayT<int> b;
    a.remove(1);
    a.insert(1,3);
    b = a;
    b[1] = 0;
    std::cout << a << b;
}
//A ar;
//new size == 0
//index - 0 +
//resize
//size == new ssize
//new elem ==
//index - 0 +
//a[index] = elem and then a[index] == elem
//and this with every
//empty to array

