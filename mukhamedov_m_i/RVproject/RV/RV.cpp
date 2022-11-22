#include "iostream"
#include "cmath"
#include "RV.hpp"

std::ostream& operator << (std::ostream& out, const Rdec2D& v) {
    return out << '(' << v.x << ',' << v.y << ')';
}

Rdec2D operator*(const Rdec2D& v, const double a) {
    Rdec2D res{v.x * a, v.y * a};
    return res;
}

Rdec2D operator*(const double a, const Rdec2D& v) {
    Rdec2D res{v.x * a, v.y * a};
    return res;
}

Rdec2D operator+(const Rdec2D& v1, const Rdec2D& v2) {
    Rdec2D res{v1.x + v2.x, v1.y + v2.y};
    return res;
}

Rdec2D operator-(const Rdec2D& v1, const Rdec2D& v2) {
    Rdec2D res{v1.x - v2.x, v1.y - v2.y};
    return res;
}

Rdec2D& operator*=(Rdec2D& v, double a) {
    v.x = v.x * a;
    v.y = v.y * a;
    return v;
}

double getnorm(const Rdec2D& v) {
    return sqrt(v.x*v.x + v.y*v.y);
}

double dot(const Rdec2D& v1,const Rdec2D& v2) {
    return v1.x*v2.x + v2.y*v1.y;
}

Rdec2D poly_to_coo(const Rpol2D& v) {
    Rdec2D res;
    res.x = std::cos(v.phi) * v.r;
    res.x = std::sin(v.phi) * v.r;
    return res;
}

Rpol2D coo_to_poly(const Rdec2D& v) {
    Rpol2D res{0,0};
    res.r = getnorm(v);
    res.phi = acos(v.x / res.r);
    return res;
}

std::ostream& operator << (std::ostream& out, const Rpol2D& v) {
    return out << '(' << v.r << ',' << v.phi << ')';
}

Rpol2D operator*(const Rpol2D& v, const double a) {
    Rpol2D res{v.r * a, v.phi};
    return res;
}

Rpol2D operator*(const double a, const Rpol2D& v) {
    Rpol2D res{v.r * a, v.phi};
    return res;
}

Rpol2D operator+(const Rpol2D& a1, const Rpol2D& a2) {
    Rdec2D v1 = poly_to_coo(a1);
    Rdec2D v2 = poly_to_coo(a2);
    Rdec2D res{v1.x + v2.x, v1.y + v2.y};
    return coo_to_poly(res);
}

Rpol2D operator-(const Rpol2D& a1, const Rpol2D& a2) {
    Rdec2D v1 = poly_to_coo(a1);
    Rdec2D v2 = poly_to_coo(a2);
    Rdec2D res{v1.x - v2.x, v1.y - v2.y};
    return coo_to_poly(res);
}

Rpol2D& operator*=(Rpol2D& v, double a) {
    v.r = v.r * a;
    return v;
}

double getnorm(const Rpol2D& v) {
    return v.r;
}

double dot(const Rpol2D& a1,const Rpol2D& a2) {
    Rdec2D v1 = poly_to_coo(a1);
    Rdec2D v2 = poly_to_coo(a2);
    return v1.x*v2.x + v2.y*v1.y;
}
