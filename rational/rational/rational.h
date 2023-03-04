#include <iosfwd>
#include <cstdint>

//greatest common division
int32_t GCD( int32_t a, int32_t b);
class Rational {
public:
    //Constructs
    Rational() = default;
    Rational(const Rational&) = default;
    Rational(const int32_t p, const int32_t q);
    ~Rational() = default;
    //Algebra declaration
    Rational operator+(const Rational& rhs);
    Rational operator-(const Rational& rhs);
    Rational operator/(const Rational& rhs);
    Rational operator*(const Rational& rhs);
    Rational operator-();
    //Compare
    bool operator==(const Rational& rhs) const;
    bool operator>(const Rational& rhs) const;;
    bool operator!=(const Rational& rhs) const;
    //Input/ouput
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);
private:
    int32_t num_{0};
    int32_t denum_{1};
    static const char separator{'/'};
};
//Realisation
//Input/output
std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);
//Compare
bool operator<(const Rational &lhs,const Rational &rhs);
bool operator<=(const Rational &lhs,const Rational &rhs);
bool operator>=(const Rational &lhs,const Rational &rhs);

