#include <iostream>
#include <exception>
#include <string>
#include "include/rational/rational.hpp"

//greatest common division
int32_t GCD( int32_t a, int32_t b) {
    a = abs(a);
    b = abs(b);
    while (a && b) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}
Rational::Rational(const int32_t p, const int32_t q) {
    if (q == 0) throw std::invalid_argument("division by zero");
    int32_t d = GCD(p,q);
    denum_ = q/d;
    num_ = p/d;
    if (denum_ < 0) {
        denum_ = -denum_;
        num_ = -num_;
    }
}
//Input/output
std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs){
    return rhs.writeTo(ostrm);
}
std::ostream& Rational::writeTo(std::ostream& ostrm) const {
    ostrm << num_ << separator << denum_;
    return ostrm;
}
std::istream& operator>>(std::istream& istrm, Rational& rhs){
    return rhs.readFrom(istrm);
}
std::istream& Rational::readFrom(std::istream& istrm) {
    int32_t p(0);
    int32_t q(1);
    char divide(0);
    istrm >> p;
    istrm >> divide;
    istrm >> q;
    if (istrm.good() || !istrm.fail() && istrm.eof()) {
        if (Rational::separator == divide) {
            istrm.clear();
            *this = Rational(p, q);
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
//Algebra
Rational Rational::operator+(const Rational &rhs){
    return Rational(num_*rhs.denum_ + rhs.num_ * denum_,denum_ * rhs.denum_);
}
Rational Rational::operator-(const Rational &rhs) {
    return Rational(num_*rhs.denum_ - rhs.num_ * denum_,denum_ * rhs.denum_);
}
Rational Rational::operator/(const Rational &rhs) {
    return Rational(num_ * rhs.denum_,denum_*rhs.num_);
}
Rational Rational::operator*(const Rational &rhs) {
    return Rational(num_*rhs.num_,denum_ * rhs.denum_);
}
void operator+=(Rational& lhs, const Rational& rhs) {
    lhs = lhs + rhs;
}
void operator-=(Rational& lhs, const Rational& rhs) {
    lhs = lhs - rhs;
}
void operator/=(Rational& lhs, const Rational& rhs) {
    lhs = lhs / rhs;
}
void operator*=(Rational& lhs, const Rational& rhs) {
    lhs = lhs * rhs;
}

Rational Rational::operator-() {
    num_ = -num_;
    return *this;
}
//Compare
bool Rational::operator==(const Rational &rhs) const { return (num_ == rhs.num_) && (denum_ == rhs.denum_);}
bool Rational::operator!=(const Rational &rhs) const { return !operator==(rhs);}
bool Rational::operator>(const Rational &rhs) const {return ((num_ * rhs.denum_ - rhs.num_ * denum_) > 0);}
bool operator<(const Rational &lhs,const Rational &rhs) {return rhs.operator>(lhs);}
bool operator<=(const Rational &lhs,const Rational &rhs) {return !lhs.operator>(rhs);}
bool operator>=(const Rational &lhs,const Rational &rhs) {return !rhs.operator>(lhs);}

//
// Created by maxim on 2/28/23.
//
