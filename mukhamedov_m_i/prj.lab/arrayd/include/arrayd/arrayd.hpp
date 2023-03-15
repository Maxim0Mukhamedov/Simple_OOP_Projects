#include <initializer_list>
#include <cstddef>
#include "iosfwd"

class ArrayD
{
public:
    // Конструкторы
    ArrayD(int s = 0);
    ArrayD(const ArrayD& other);
    ArrayD(std::initializer_list<double> list);
    ArrayD& operator=(const ArrayD& other);
    //Копирование
    ArrayD(ArrayD&& other);
    //Деструктор
    ~ArrayD() = default;
    //Оператор итерирования
    double& operator[](int index) const;
    //Взятие размера
    ptrdiff_t ssize() const;
    //Изменение размера
    void resize(const int& size);
    void insert(const int& i, const double& elem);
    void remove(const int& i);
    //Ввод/вывод
    std::istream& ReadFrom(std::istream& istrm);
    std::ostream& WriteTo(std::ostream& ostrm);
private:
    double *data = nullptr;
    std::ptrdiff_t ssize_ = 0;
    std::ptrdiff_t capacity_ = 0;
};

std::ostream& operator<<(std::ostream& ostrm, ArrayD& array);
std::istream& operator>>(std::istream& istrm, ArrayD& array);
//insert remove
