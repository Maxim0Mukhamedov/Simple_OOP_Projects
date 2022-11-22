#include <iostream>
#include "iomanip"
#include "cmath"
#include "RV.hpp"



int main() {
    system("chcp 65001");
    Rdec2D v1{3, 7};
    std::left(std::cout);
    std::cout << std::endl << "Векторы в координатах" << std::endl << std::endl;
    std::cout << v1 << " - Координаты вектора1" << std::endl;
    std::cout << 2 * v1 << " - Вектор1 * 2" << std::endl;
    v1 *= 3;
    std::cout << v1 << " - Вектор *= 3" << std::endl;
    Rdec2D v2{1, 1};
    std::cout << v2 << "- Координаты вектора2" << std::endl;
    std::cout << v1 - v2 << " - Вектор1 - Вектор2" << std::endl;
    std::cout << v1 + v2 << " - Вектор1 + Вектор2" << std::endl;
    std::cout << getnorm(v1) << " - Длина вектора1" << std::endl;
    std::cout << getnorm(v2) << " - Длина вектора2" << std::endl;
    std::cout << dot(v1, v2) << " - Скалярное произведение векторов 1 и 2" << std::endl;
    std::cout << std::endl << "Полярное представление векторов" << std::endl;
    Rpol2D a1{0, 0};
    v1 = {3,7};
    a1 = coo_to_poly(v1);
    std::cout << a1 << " - Координаты вектора1" << std::endl;
    std::cout << 2 * a1 << " - Вектор1 * 2" << std::endl;
    a1 *= 3;
    std::cout << a1 << " - Вектор *= 3" << std::endl;
    Rpol2D a2{0, 0};
    a2 = coo_to_poly(v2);
    std::cout << a2 << "- Координаты вектора2" << std::endl;
    std::cout << a1 - a2 << " - Вектор1 - Вектор2" << std::endl;
    std::cout << a1 + a2 << " - Вектор1 + Вектор2" << std::endl;
    std::cout << getnorm(a1) << " - Длина вектора1" << std::endl;
    std::cout << getnorm(a2) << " - Длина вектора2" << std::endl;
    std::cout << dot(a1, a2) << " - Скалярное произведение векторов 1 и 2" << std::endl;
}