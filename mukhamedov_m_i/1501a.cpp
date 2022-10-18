#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define _USE_MATH_DEFINES

// Доделать дома!!!!!!! Смассивом.

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i += 1) {
        int n;
        std::cin >> n;
        int timer = 0;
        int b_iLast = 0;
        int a_i,b_i;
        for (int j = 0; j < n; j += 1) {
            std::cin >> a_i >> b_i;
            timer += (-b_iLast + a_i) + (b_i + 1 - a_i)/2;
            b_iLast = b_i;
        } 
        timer -=  (b_i + 1 - a_i)/2;
        int tm_i;
        for (int j = 0; j < n; j += 1) {
            std::cin >> tm_i;
            timer += tm_i;
        }
        std::cout << timer << '\n';
    }
} 
