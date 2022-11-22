#include "iosfwd"

struct Rdec2D {
    double x = 0.0;
    double y = 0.0;
};

std::ostream& operator << (std::ostream& out, const Rdec2D& v);

Rdec2D operator*(const Rdec2D& v, const double a);

Rdec2D operator*(const double a, const Rdec2D& v);

Rdec2D operator+(const Rdec2D& v1, const Rdec2D& v2) ;

Rdec2D operator-(const Rdec2D& v1, const Rdec2D& v2);

Rdec2D& operator*=(Rdec2D& v, double a);

double getnorm(const Rdec2D& v);

double dot(const Rdec2D& v1,const Rdec2D& v2);



struct Rpol2D {
    double r = 0.0;
    double phi = 0.0;
};

Rdec2D poly_to_coo(const Rpol2D& v);

Rpol2D coo_to_poly(const Rdec2D& v) ;

std::ostream& operator << (std::ostream& out, const Rpol2D& v);

Rpol2D operator*(const Rpol2D& v, const double a);

Rpol2D operator*(const double a, const Rpol2D& v);

Rpol2D operator+(const Rpol2D& a1, const Rpol2D& a2);

Rpol2D operator-(const Rpol2D& a1, const Rpol2D& a2);

Rpol2D& operator*=(Rpol2D& v, double a);

double getnorm(const Rpol2D& v);

double dot(const Rpol2D& a1,const Rpol2D& a2) ;