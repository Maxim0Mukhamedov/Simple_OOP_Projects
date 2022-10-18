#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i += 1) {
        std::string s;
        std::vector<int> a;
        int cntStar = 0;
        int ans = 0;
        for (int j = 0; j < 8; ++j) {
            std::cin >> s;
            cntStar = 0;
            for (int k = 0; k < 8; ++k) {
                if (s[j] == '#') {
                    cntStar += 1;
                }
            }
            ans = 0;
            if (cntStar == 1) {
                for (int k = 0; k < 8; ++k) {
                    if (s[j] == '#') {
                        ans = (j+1)*10 + (k + 1);
                    }
                }
            }
        }
        std::cout << ans/10 << ' ' << ans % 10 << '\n';
    }
}
