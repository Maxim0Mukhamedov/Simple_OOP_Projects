#include <cstdint>
#include <iosfwd>


//greatest common division
int32_t GCD( int32_t a, int32_t b);
class Rational {
public:
    //Constructs
    Rational() = default;
    Rational(const Rational&) = default;
    Rational(const int32_t p, const int32_t q);
    explicit Rational(const int32_t p) noexcept;
    ~Rational() = default;
    //Algebra declaration
    Rational operator+(const Rational& rhs);
    Rational operator+(const int32_t & rhs);
    Rational operator-(const Rational& rhs);
    Rational operator-(const int32_t & rhs);
    Rational operator/(const Rational& rhs);
    Rational operator/(const int32_t & rhs);
    Rational operator*(const Rational& rhs);
    Rational operator*(const int32_t & rhs);
    Rational operator-();
    //Compare
    bool operator==(const Rational& rhs) const;
    bool operator>(const Rational& rhs) const;;
    bool operator!=(const Rational& rhs) const;
    //Input/ouput
    std::ostream& writeTo(std::ostream& ostrm) const noexcept;
    std::istream& readFrom(std::istream& istrm);
private:
    int32_t num_{0};
    int32_t denum_{1};
    static const char separator{'/'};
};
//Arithm
void operator+=(Rational& lhs, const Rational& rhs);
void operator-=(Rational& lhs, const Rational& rhs);
void operator/=(Rational& lhs, const Rational& rhs);
void operator*=(Rational& lhs, const Rational& rhs);
void operator+=(Rational& lhs, const int32_t & rhs);
void operator-=(Rational& lhs, const int32_t & rhs);
void operator/=(Rational& lhs, const int32_t & rhs);
void operator*=(Rational& lhs, const int32_t & rhs);
Rational& operator++(Rational& lhs);
Rational& operator--(Rational& lhs);
Rational operator++(Rational& lhs,int);
Rational operator--(Rational& lhs,int);
//Input/output
std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);
//Compare
bool operator<(const Rational &lhs,const Rational &rhs);
bool operator<=(const Rational &lhs,const Rational &rhs);
bool operator>=(const Rational &lhs,const Rational &rhs);
bool operator==(const Rational &lhs,const int32_t &rhs);
bool operator!=(const Rational &lhs,const int32_t &rhs);
bool operator>(const Rational &lhs,const int32_t &rhs);
bool operator<(const Rational &lhs,const int32_t &rhs);
bool operator<=(const Rational &lhs,const int32_t &rhs);
bool operator>=(const Rational &lhs,const int32_t &rhs);
