#include "iostream"
#include "cmath"
#include "geom.hpp"
#include "limits"

const double min_delta = 10000 * std::numeric_limits<double>::epsilon();

std::ostream& operator << (std::ostream& out, const Rdec2D& v) {
    return out << v.x << ',' << v.y;
}

Rdec2D operator*(const Rdec2D& v, const double& a) {
    Rdec2D res{v.x * a, v.y * a};
    return res;
}

Rdec2D operator*(const double& a, const Rdec2D& v) {
    Rdec2D res{v.x * a, v.y * a};
    return res;
}

Rdec2D& operator*=(Rdec2D& v,const double& a) {
    v.x = v.x * a;
    v.y = v.y * a;
    return v;
}

Rdec2D operator/(const Rdec2D& v, const double& a) {
    Rdec2D res{v.x / a, v.y / a};
    return res;
}

Rdec2D& operator/=(Rdec2D& v,const double& a) {
    v.x = v.x / a;
    v.y = v.y / a;
    return v;
}

Rdec2D operator+(const Rdec2D& v1, const Rdec2D& v2) {
    Rdec2D res{v1.x + v2.x, v1.y + v2.y};
    return res;
}

Rdec2D& operator+=(Rdec2D& v,  const Rdec2D& v2) {
    v.x = v.x + v2.x;
    v.y = v.y + v2.y;
    return v;
}

Rdec2D operator-(const Rdec2D& v1, const Rdec2D& v2) {
    Rdec2D res{v1.x - v2.x, v1.y - v2.y};
    return res;
}

Rdec2D& operator-=(Rdec2D& v,  const Rdec2D& v2) {
    v.x = v.x - v2.x;
    v.y = v.y - v2.y;
    return v;
}

double Norm(const Rdec2D& v) {
    return sqrt(v.x*v.x + v.y*v.y);
}

double Dot(const Rdec2D& v1,const Rdec2D& v2) {
    return v1.x*v2.x + v2.y*v1.y;
}

bool operator==(const Rdec2D& a1, const Rdec2D& a2) {
    return ((std::abs(a1.x - a2.x) <= min_delta) && (std::abs(a1.y - a2.y) <= min_delta));
}

bool operator!=(const Rdec2D& a1, const Rdec2D& a2) {
    return ((std::abs(a1.x - a2.x) >= min_delta) || (std::abs(a1.y - a2.y) >= min_delta));
}