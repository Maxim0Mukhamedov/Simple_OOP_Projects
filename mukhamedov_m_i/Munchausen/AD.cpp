#include "./geom.hpp"
#include "fstream"
#include "iostream"
#include "string"
#include "vector"
#include "cmath"

//Конфигурационные переменные
int k = 0; // Кол-во CSV файлов с результатом
double dt = 0.1;// Частота дискретизации
double g = 9.8; // Ускорение свободного падения
double distH = 10;
double distV = 0;
// Начальные координаты вектора скорости защиты
double x = 4;
double y = 7;
// Начальные координаты вектора скорости атаки
double x1 = -20;
double yy = 5.0;
int type = 1; //Тип теста
double delta = 0.1; //Шаг поиска x,y
double t = 0.1;// Задержка
// Ограничения на скорости ядер
double v_min = -10;
double v_max = 10;
std::vector<std::string> research;
// Реализация совокупности сил, действущих на ядро
struct State {
    Rdec2D a;
    Rdec2D v;
    Rdec2D r;
};

// Реализация считывания конфигурационных настроек
struct conf {
    std::string config;
    double lit;
};

std::ifstream &operator>>(std::ifstream &fin, conf &s) {
    fin >> s.config;
    std::string num = ""; // Строка в которой будет сохранён литерал настройки
    bool lite = false; // false => название параметра true => литерал
    for (int i = 1; i < s.config.size(); i += 1) {
        if (s.config[i] == '/') {
            break;
        }
        if (s.config[i - 1] == '=' || lite) {
            lite = true;
            num += s.config[i];
        }
    }
    s.lit = std::stod(num);
    return fin;
}

void read_conf() {
    std::ifstream fin("config.txt");
    // Считывание всех настроек из конфигурационного файла
    conf settings;
    fin >> settings;
    dt = settings.lit;
    fin >> settings;
    g = settings.lit;
    fin >> settings;
    distH = settings.lit;
    fin >> settings;
    distV = settings.lit;
    fin >> settings;
    x = settings.lit;
    fin >> settings;
    y = settings.lit;
    fin >> settings;
    x1 = settings.lit;
    fin >> settings;
    yy = settings.lit;
    fin >> settings;
    type = settings.lit;
    fin >> settings;
    delta = settings.lit;
    fin >> settings;
    v_min = settings.lit;
    fin >> settings;
    v_max = settings.lit;
    t = distH / 331;
}

// Вычислительная часть программы
void cors() {
    std::vector<std::string> ans; // Вектор данных о координатах радиус векторов
    ans.push_back("A,B,C,D");
    ans.push_back("0,0," + std::to_string(distH) + "," + std::to_string(distV));

    State cor{{0, -g}, // cor - сторона защиты
              {x, y},
              {0, 0}};
    State cor2{{0,     -g}, // cor2 - сторона атаки
               {x1,    yy},
               {distH, distV}};
    double tt = t;
    while (tt > 0) { // Учёт задержки
        cor2.r = cor2.r + cor2.v * tt;
        cor2.v = cor2.v + cor2.a * tt;
        tt -= dt;
        ans.push_back("0,0," + std::to_string(cor2.r.x) + "," + std::to_string(cor2.r.y));
    }

    bool hit = false; // hit = false => ядра не попали друг в друга

    while (cor.r.y >= 0 && cor2.r.y >= 0) {
        cor.r = cor.r + cor.v * dt; // Вычисление координат радиус векторов
        cor.v = cor.v + cor.a * dt;
        cor2.r = cor2.r + cor2.v * dt;
        cor2.v = cor2.v + cor2.a * dt;
        if (cor.r.y >= 0 && cor2.r.y >= 0) { // Сохраняются только реальные координаты ядер
            ans.push_back(
                    std::to_string(cor.r.x) + "," + std::to_string(cor.r.y) + "," + std::to_string(cor2.r.x) + "," +
                    std::to_string(cor2.r.y));
        }
        if (Norm(cor.r - cor2.r) < delta) { // Попадание ядер друг в друга
            hit = true;
            ans.push_back("hit");
        } else if (cor.r.y < 0 || cor2.r.y < 0) {// Падение одного из ядер
            ans.push_back("finish");
        }
    }
    if (type == 0) { // Ответ на запрос в зависимости от типа задачи
        std::string s = "file" + std::to_string(k) + ".csv";
        s = ".//Try_hit_settings//" + s;
        std::ofstream fout(s); // Создание файла в формате file(k).csv, где k - номер решения
        k++;
        for (auto i: ans) {
            if (i == "hit" || i == "finish") { break; }
            fout << i << std::endl;
        }
    } else if (type == 1 && hit) {
        std::string s = "file" + std::to_string(k) + ".csv";
        s = ".//Find_hit_settings//" + s;
        std::ofstream fout(s);
        k++;
        for (auto i: ans) {
            if (i == "hit" || i == "finish") { break; }
            fout << i << std::endl;
        }
        research.push_back(std::to_string(x) + "," + std::to_string(y)); // Сохранение в отчет подобранных координат.
    }
}

int main() {

    read_conf();

    if (type == 1) {
        std::ofstream fout_research(
                ".//Find_hit_settings//report.txt"); // Создание файла с отчетом, в нем хранятся ответы и кол-во решения
        for (x = v_min; x <= v_max; x += delta) {
            for (y = 0; y <= v_max; y += delta) {
                cors();
            }
        }
        fout_research << k << std::endl; // Для корректной обработки полученных CSV файлов требуется знать их кол-во
        for (auto j: research) {
            fout_research << j << std::endl;
        }
    } else {
        std::cout << x << ' ' << y;
        cors();
        std::ofstream fout_research(".//Try_hit_settings//report.txt");
        fout_research << k << std::endl;
        fout_research << std::to_string(x) + "," + std::to_string(y);
    }
}
