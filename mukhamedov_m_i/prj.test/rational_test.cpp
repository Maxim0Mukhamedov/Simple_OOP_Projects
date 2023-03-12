//#include <iostream>
//#include <sstream>
//#include <exception>
//#include <string>
//#include "rational/rational.h"
//
//void test_rational(const std::string& str){
//    std::istringstream istrm(str);
//    Rational g;
//    try {
//        std::cout << "START test: str = " << str << '\n';
//        istrm >> g;
//        if (!istrm.good()) {std::cout << "Error: \"READ ERROR\": " << str << " -> " << g << std::endl; return;}
//        Rational a(1,1);
//        std::cout << "Success: \"READ\" reading result = " << g << '\n';
//        std::cout << "Success: \"DIVISION\" " << a << " : " << g << " = " << a / g << '\n';
//        std::cout << "Success: \"PLUS\" " << g << " + " << a << " = " << a + g << '\n';
//        std::cout << "Success: \"MINUS\" " << g << " - " << a << " = " << a - g << '\n';
//        std::cout << "Success: \"UNO_MINUS\" " << -g << '\n';
//        std::cout << "ALL tests success \n-------------" << std::endl;
//    } catch (const std::invalid_argument &e) {
//        std::cout << "Error: \"DIVISION BY ZERO\"\n-------------"<< std::endl;
//    }
//}
//
//int main() {
//    test_rational("1/3");
//    test_rational("3/0");
//    test_rational("1 /        3");
//    test_rational("3/1");
//    test_rational("3/3");
//    test_rational("0/3");
//    test_rational("6/3");
//    return 0;
//}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "rational/rational.hpp"

TEST_CASE("testing the rational functions") {
    CHECK(Rational(1, 2) + Rational(3, 4) == Rational(5, 4));
    CHECK(Rational(3, 4) - Rational(1, 2) == Rational(1, 4));
    CHECK(Rational(3, 4) * Rational(1, 2) == Rational(3, 8));
    CHECK(Rational(3, 4) / Rational(1, 2) == Rational(3, 2));
    CHECK_NOTHROW(-Rational(1,2));
    CHECK_THROWS(Rational(3, 0));
    CHECK_NOTHROW(Rational());
}

