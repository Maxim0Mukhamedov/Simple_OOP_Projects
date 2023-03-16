#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "rational/rational.hpp"
#include "sstream"
#include "string"

TEST_CASE("testing the rational functions") {
    Rational a(2,-4);
    std::ostringstream ost;
    ost << a;
    CHECK(ost.str() == "-1/2"); //проверка сокращения и переноса минуса
    Rational b(3);
    CHECK_NOTHROW(a += b);
    CHECK_NOTHROW(a -= b);
    CHECK_NOTHROW(a /= b);
    CHECK_NOTHROW(a *= b);
    CHECK_NOTHROW(a = a * b);
    CHECK_NOTHROW(a = a / b);
    CHECK_NOTHROW(a = a + b);
    CHECK_NOTHROW(a = a - b);
    CHECK_NOTHROW(a == b);
    CHECK_NOTHROW(b == 3);
    CHECK_NOTHROW(b >= 3);
    CHECK_NOTHROW(b < 3);
    CHECK_NOTHROW(a <= 3);
    CHECK_NOTHROW(a <= b) ;
    CHECK_NOTHROW(a++);
    CHECK_NOTHROW(--a) ;
    CHECK_NOTHROW(++a) ;
    CHECK_NOTHROW(a--) ;
    Rational c;
    std::istringstream istrm("1/3");
    istrm >> c;
    std::ostringstream ost2;
    ost2 << c;
    CHECK(ost2.str() == "1/3");
    CHECK_THROWS(Rational(1,0));
    CHECK_THROWS(Rational(1)/0);
    CHECK_THROWS(Rational(1)/Rational(0));
}

