#include <initializer_list>
#include <cstddef>
#include "iosfwd"
//
template<typename  T>
class ArrayT
{
public:
    // Конструкторы
    ArrayT(int s = 0);
    ArrayT(const ArrayT<T>& other);
    ArrayT(std::initializer_list<T> list);
    ArrayT& operator=(const ArrayT<T>& other);
    //Деструктор
    ~ArrayT() = default;
    //Оператор итерирования
    const T& operator[](const int index) const;
    T& operator[](const int index);
    //Взятие размера
    ptrdiff_t ssize() const;
    //Изменение размера
    void resize(const int& size);
    void insert(const int& i, const T& elem);
    void remove(const int& i);
    //Ввод/вывод
    std::istream& ReadFrom(std::istream& istrm);
    std::ostream& WriteTo(std::ostream& ostrm);
private:
    T* data = nullptr;
    std::ptrdiff_t ssize_ = 0;
    std::ptrdiff_t capacity_ = 0;
};
//
template<typename T>
std::ostream& operator<<(std::ostream& ostrm, ArrayT<T>& array);
template<typename T>
std::istream& operator>>(std::istream& istrm, ArrayT<T>& array);
////insert remove
