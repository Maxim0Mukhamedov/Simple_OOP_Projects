#ifndef ARRAYD_HPP
#define ARRAYD_HPP

#include <cstdint>
#include <iosfwd>

class ArrayD {
 public:
    // Конструкторы
    explicit ArrayD(int s = 0);
    ArrayD(const ArrayD& other);
    ArrayD& operator=(const ArrayD& other);
    // Деструктор
    ~ArrayD() = default;
    // Оператор итерирования
    const double& operator[](const int& index) const;
    double& operator[](const int& index);
    // Взятие размера
    [[nodiscard]] int32_t ssize() const;
    // Изменение размера
    void resize(const int& size);
    void insert(const int& i, const double& elem);
    void remove(const int& i);
    // Ввод/вывод
    std::istream& ReadFrom(std::istream& istrm);
    std::ostream& WriteTo(std::ostream& ostrm); //const

 private:
    double *data = nullptr;
    std::ptrdiff_t ssize_ = 0;
    std::ptrdiff_t capacity_ = 0;
};

std::ostream& operator<<(std::ostream& ostrm, ArrayD& array);
std::istream& operator>>(std::istream& istrm, ArrayD& array);

#endif
