#include "iostream"
#include "cmath"
#include "geom.hpp"
#include "limits"

const double min_delta =  100 * std::numeric_limits<double>::epsilon();

std::ostream& operator << (std::ostream& out, const Rdec2D& v) {
    return out << v.x << ',' << v.y;
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

double Norm(const Rdec2D& v) {
    return sqrt(v.x*v.x + v.y*v.y);
}

double Dot(const Rdec2D& v1,const Rdec2D& v2) {
    return v1.x*v2.x + v2.y*v1.y;
}

Rdec2D ToDec(const Rpol2D& v) {
    Rdec2D res;
    res.x = std::cos(v.phi) * v.r;
    res.y = std::sin(v.phi) * v.r;
    return res;
}

Rpol2D ToPol(const Rdec2D& v) {
    Rpol2D res{0,0};
    res.r = Norm(v);
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
    Rdec2D v1 = ToDec(a1);
    Rdec2D v2 = ToDec(a2);
    Rdec2D res{v1.x + v2.x, v1.y + v2.y};
    return ToPol(res);
}

Rpol2D operator-(const Rpol2D& a1, const Rpol2D& a2) {
    Rdec2D v1 = ToDec(a1);
    Rdec2D v2 = ToDec(a2);
    Rdec2D res{v1.x - v2.x, v1.y - v2.y};
    return ToPol(res);
}

Rpol2D& operator*=(Rpol2D& v, double a) {
    v.r = v.r * a;
    return v;
}

double Norm(const Rpol2D& v) {
    return v.r;
}

double Dot(const Rpol2D& a1,const Rpol2D& a2) {
    Rdec2D v1 = ToDec(a1);
    Rdec2D v2 = ToDec(a2);
    return v1.x*v2.x + v2.y*v1.y;
}

bool operator==(const Rpol2D& a1, const Rpol2D& a2) {
    return ((std::abs(a1.r - a2.r) <= min_delta) && (std::abs(a1.phi - a2.phi) <= min_delta));
}

bool operator==(const Rdec2D& a1, const Rdec2D& a2) {
    return ((std::abs(a1.x - a2.x) <= min_delta) && (std::abs(a1.y - a2.y) <= min_delta));
}

bool operator!=(const Rpol2D& a1, const Rpol2D& a2) {
    return ((std::abs(a1.r - a2.r) >= min_delta) || (std::abs(a1.phi - a2.phi) >= min_delta));
}

bool operator!=(const Rdec2D& a1, const Rdec2D& a2) {
    return ((std::abs(a1.x - a2.x) >= min_delta) || (std::abs(a1.y - a2.y) >= min_delta));
}