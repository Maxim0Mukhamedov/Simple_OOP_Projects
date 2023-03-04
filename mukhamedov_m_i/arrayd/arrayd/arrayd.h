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
    ptrdiff_t size() const;
    //Изменение размера
    void resize(int size);
    void push_back(double new_elem);
    //Ввод/вывод
    std::istream& ReadFrom(std::istream& istrm);;
    std::ostream& WriteTo(std::ostream& ostrm);;
private:
    double *data = nullptr;
    ptrdiff_t ssize_ = 0;
};

std::ostream& operator<<(std::ostream& ostrm, ArrayD& array);
std::istream& operator>>(std::istream& istrm, ArrayD& array);
