#include "iosfwd"

struct Rdec2D {
    double x = 0.0;
    double y = 0.0;
};

std::ostream& operator << (std::ostream& out, const Rdec2D& v);

Rdec2D operator*(const Rdec2D& v, const double& a);

Rdec2D operator*(const double& a, const Rdec2D& v);

Rdec2D operator+(const Rdec2D& v1, const Rdec2D& v2) ;

Rdec2D operator-(const Rdec2D& v1, const Rdec2D& v2);

Rdec2D& operator*=(Rdec2D& v, const double& a);

Rdec2D& operator+=(Rdec2D& v, const Rdec2D& v2);

Rdec2D& operator-=(Rdec2D& v, const Rdec2D& v2);

double Norm(const Rdec2D& v);

double Dot(const Rdec2D& v1,const Rdec2D& v2);

bool operator==(const Rdec2D& a1, const Rdec2D& a2);

bool operator!=(const Rdec2D& a1, const Rdec2D& a2);