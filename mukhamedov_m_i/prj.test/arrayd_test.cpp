#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "arrayd/arrayd.hpp"
#include "doctest/doctest.h"

TEST_CASE("Test construct and copy") {
    SUBCASE("Test with normal size") {
        CHECK_NOTHROW(ArrayD(3));
    }
    SUBCASE("Test with size = 0") {
        CHECK_NOTHROW(ArrayD(0));
    }
    SUBCASE("Test with negative size") {
        CHECK_THROWS(ArrayD(-1));
    }
    SUBCASE("Test copy") {
        ArrayD x(1);
        x[0] = 1;
        ArrayD y = x;
        y[0] = 2;
        CHECK((x[0] != y[0]));
    }
    SUBCASE("Test operator= with same ArrayD") {
        ArrayD x(1);
        CHECK_THROWS(x = x);
    }
}
TEST_CASE("Test with operator[]") {
    SUBCASE("Test with middle index") {
        ArrayD x(3);
        CHECK_NOTHROW(x[1] = 404);
        CHECK((x[1] == 404));
    }
    SUBCASE("Test with begin index") {
        ArrayD x(3);
        CHECK_NOTHROW(x[0] = 404);
        CHECK((x[0] == 404));
    }
    SUBCASE("Test with last index") {
        ArrayD x(3);
        CHECK_NOTHROW(x[2] = 404);
        CHECK((x[2] == 404));
    }
    SUBCASE("Test with out of range index > size") {
        ArrayD x(3);
        CHECK_THROWS(x[4]);
    }
    SUBCASE("Test with out of range index == size") {
        ArrayD x(3);
        CHECK_THROWS(x[3]);
    }
    SUBCASE("Test with out of range index < 0") {
        ArrayD x(3);
        CHECK_THROWS(x[-1]);
    }
}

TEST_CASE("Test of ssize, resize, insert, remove function") {
    SUBCASE("size == size") {
        CHECK((ArrayD(5).ssize() == 5));
    }
    SUBCASE("Resize to size+1") {
        ArrayD x(1);
        x.resize(x.ssize() + 1);
        CHECK_NOTHROW(x[1]);
    }
    SUBCASE("Resize to 0") {
        ArrayD x(1);
        CHECK_THROWS(x.resize(0));
    }
    SUBCASE("Resize to size < 0") {
        ArrayD x(1);
        CHECK_THROWS(x.resize(-1));
    }
    ArrayD test(3);
    ArrayD test_i(0);
    int size = test.ssize();
    for (int i = 0; i < size; i++) {
        test[i] = i + 1;
    }
    SUBCASE("insert to middle") {
        test_i = test;
        test_i.insert(1,4);
        CHECK((test_i[0] == test[0]));
        CHECK((test_i[1] == 4));
        CHECK((test_i[2] == test[1]));
        CHECK((test_i[3] == test[2]));
        CHECK((test_i.ssize() == size + 1));
    }
    SUBCASE("insert to begin") {
        test_i = test;
        test_i.insert(0,4);
        CHECK((test_i[0] == 4));
        CHECK((test_i[1] == test[0]));
        CHECK((test_i[2] == test[1]));
        CHECK((test_i[3] == test[2]));
        CHECK((test_i.ssize() == size + 1));
    }
    SUBCASE("insert to end") {
        test_i = test;
        test_i.insert(3,4);
        CHECK((test_i[0] == test[0]));
        CHECK((test_i[1] == test[1]));
        CHECK((test_i[2] == test[2]));
        CHECK((test_i[3] == 4));
        CHECK((test_i.ssize() == size + 1));
    }
    SUBCASE("insert to invalid position < 0") {
        test_i = test;
        CHECK_THROWS(test_i.insert(-1,4));
    }
    SUBCASE("insert to invalid position > size") {
        test_i = test;
        CHECK_THROWS(test_i.insert(4,4));
    }

    SUBCASE("remove from middle") {
        test_i = test;
        test_i.remove(1);
        CHECK((test_i[0] == test[0]));
        CHECK((test_i[1] == test[2]));
        CHECK((test_i.ssize() == size - 1));
    }
    SUBCASE("remove from begin") {
        test_i = test;
        test_i.remove(0);
        CHECK((test_i[0] == test[1]));
        CHECK((test_i[1] == test[2]));
        CHECK((test_i.ssize() == size - 1));
    }
    SUBCASE("remove from end") {
        test_i = test;
        test_i.remove(2);
        CHECK((test_i[0] == test[0]));
        CHECK((test_i[1] == test[1]));
        CHECK((test_i.ssize() == size - 1));
    }
    SUBCASE("remove from invalid position < 0") {
        test_i = test;
        CHECK_THROWS(test_i.remove(-1));
    }
    SUBCASE("remove from invalid position == size") {
        test_i = test;
        CHECK_THROWS(test_i.remove(3));
    }
    SUBCASE("remove from invalid position > size") {
        test_i = test;
        CHECK_THROWS(test_i.remove(4));
    }
}
//A ar;
//new size == 0
//index - 0 +
//resize
//size == new ssize
//new elem ==
//index - 0+
//a[index] = elem and then a[index] == elem
//and this with every
//empty to array
