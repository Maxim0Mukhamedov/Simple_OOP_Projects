#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

int main()
{
    double x = 1;
    double s = 0;
    double f = 0;
    double a = -1, b = 1;
    double delta = 0.1;
    double epsilon = 0.001;
    double y = 0;
    double p = 1;
    int i = 0;
    std::cout.flags(std::ios::left);
    std::cout << '|' << std::setw(10) << 'x' << '|' << std::setw(10)  << "s(x)"<< '|' << std::setw(10)  << "f(x)" << '|' << '\n';
    for (a; a <= b; a += delta) {
        x = a;
        if (std::abs(x) < delta) {
            x = 0;
        }
        p = 1;
        for (i = 0; std::abs(p) > epsilon; i += 1) {
            p = std::pow(-1,i) * std::pow(x,2*i) / std::tgamma(2*i + 1);
            s += p;
        }
        f = std::cos(x);
        std::cout << '|' << std::setw(10) << x   << '|' << std::setw(10)  <<     s << '|' << std::setw(10)  << f      << '|' << '\n';
    }
}
