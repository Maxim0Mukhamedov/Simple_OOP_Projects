#include "geom/geom.hpp"
#include "iostream"
#include "fstream"

struct animal {
    Rdec2D r{0,0};
    Rdec2D v{0,0};
};

double dt = 0.001;


bool hole (animal cat, animal mouse, double& v) {
    bool ans = true;
    cat.v = v * (mouse.r - cat.r)  * (1 / Norm(cat.r - mouse.r));
    double last_d = Norm(cat.r - mouse.r);
    while (Norm(cat.r - mouse.r) >= dt) {
        mouse.r = mouse.r + mouse.v*dt;
        cat.r = cat.r + cat.v*dt;
        cat.v = v * (mouse.r - cat.r) * (1 / Norm(cat.r - mouse.r));
        if (Norm(cat.r - mouse.r) > last_d) {
            ans = false;
            break;
        }
        if (Norm(mouse.r) < dt) {
            ans = false;
            break;
        }
        last_d = Norm(cat.r - mouse.r);
    }
    return ans;
}

void Sprint (animal cat, animal mouse, double& v) {
    std::ofstream fout("output.csv");
    fout << "A,B,C,D" << std::endl;
    cat.v = v * (mouse.r - cat.r)  * (1 / Norm(cat.r - mouse.r));
    double last_d = Norm(cat.r - mouse.r);
    while (Norm(cat.r - mouse.r) >= dt) {
        fout << cat.r << ',' << mouse.r << std::endl;
        mouse.r = mouse.r + mouse.v*dt;
        cat.r = cat.r + cat.v*dt;
        cat.v = v * (mouse.r - cat.r) * (1 / Norm(cat.r - mouse.r));
        if (Norm(cat.r - mouse.r) > last_d) {
            break;
        }
        last_d = Norm(cat.r - mouse.r);
    }
}


int main() {

    animal Tom;
    Tom.r = {0,0};
    Tom.v = {0,0};

    animal Jerry;
    Jerry.r = {0,0};
    Jerry.v = {0,1};

    std::cin >> Jerry.r.y;
    std::cin >> Tom.r.x;

    Jerry.v = Jerry.v.y > 0 ? -1 * Jerry.v : Jerry.v;

    for (double ans = dt; ans < Norm(Tom.r - Jerry.r); ans += dt) {
        if (hole(Tom,Jerry, ans)) {
            //Sprint(Tom,Jerry, ans);
            std::cout << ans << std::endl;
            system("pause");
            break;
        }
    }
}
// 0 -70 40 0 2