#include <cstddef>
#include "iosfwd"

class MatrixS
{
public:
    // Конструкторы
    MatrixS(int row_cnt = 0, int colum_cnt = 0);
    MatrixS(const MatrixS& other);
    MatrixS(std::initializer_list<double> list);
    MatrixS& operator=(const MatrixS& other);
    //Копирование
    MatrixS(MatrixS&& other);
    //Деструктор
    ~MatrixS() = default;
    //Оператор итерирования
    double& operator[](int index) const;
    //Взятие размера
    ptrdiff_t size() const;
    //Изменение размера
    void resize(const int& size);
    void insert(const int& i, const double& elem);
    void remove(const int& i);
    //Ввод/вывод
    std::istream& ReadFrom(std::istream& istrm);;
    std::ostream& WriteTo(std::ostream& ostrm);;
private:
    double *data = nullptr;
    ptrdiff_t ssize_ = 0;
};

std::ostream& operator<<(std::ostream& ostrm, MatrixS& array);
std::istream& operator>>(std::istream& istrm, MatrixS& array);