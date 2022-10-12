    #include <iostream>
    #include <string>
     
    int main() {
        int t;
        std::cin >> t;
        for (int i = 0; i < t; i += 1) {
            int n,m;
            std::cin >> n >> m;
            int l = 100;
            int hl = 0;
            int h = 1000;
            std::string s;
            for (int j = 0; j < n; j += 1) {
                std::cin >> s;
                for (int k = 0; k < m; k += 1) {
                    if (s[k] == 'R') {
                        if (k < l) {
                            l = k;
                            hl = j;
                        }
                        if (n < h) {
                            h = j;
                        }
                    }
                }
            }
                        if (hl == h) {
                    std::cout << "YES" << '\n';
                } else {
                    std::cout << "NO" << '\n';
                }
            
        }
    }
