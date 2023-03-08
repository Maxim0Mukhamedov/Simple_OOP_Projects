#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "arrayd/arrayd.hpp"
#include "doctest/doctest.h"
TEST_CASE("testing the DynamicArrays functions") {
    CHECK_NOTHROW(ArrayD{1, 2});
    CHECK_NOTHROW(ArrayD{1, 2}.size());
    CHECK_NOTHROW(ArrayD{1, 2}.push_back(3));
}
