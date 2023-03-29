#include <initializer_list>
#include <cstddef>
#include <iostream>
#include <algorithm>
//
template<typename T>
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
    //insert remove
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

template<typename T>
ArrayT<T>::ArrayT(int s) : ssize_(s) { data = new T[ssize_]; }

template<typename T>
ArrayT<T>::ArrayT(const ArrayT<T> &other) : ssize_(other.ssize_)
{
    capacity_ = ssize_*2;
    data = new T[capacity_];
    for(int i = 0; i < ssize_; ++i)
        data[i] = other.data[i];
}

template<typename T>
ArrayT<T>::ArrayT(std::initializer_list<T> list) : ssize_(list.size())
{
    data = new T[ssize_];
    int i = 0;
    for (auto& item : list)
        data[i++] = item;
}
template<typename T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT<T> &other) {
    delete[] data;
    ssize_ = other.ssize();
    data = new T[ssize_];
    for(int i = 0; i < ssize_; ++i)
        data[i] = other.data[i];
}
template<typename T>
T &ArrayT<T>::operator[](int index) {
    if (index <= 0 || index >= ssize_) {throw std::out_of_range("invalid index");}
    return data[index];
}

template<typename T>
const T& ArrayT<T>::operator[](const int index) const {
    if (index <= 0 || index >= ssize_) {throw std::out_of_range("invalid index");}
    return data[index];
}

template<typename T>
ptrdiff_t ArrayT<T>::ssize() const { return ssize_; }

template<typename T>
void ArrayT<T>::resize(const int& new_size){
    if (new_size <= 0) { throw std::out_of_range("invalid size");}
    T* old = data;
    ssize_ = new_size;
    data = new T[new_size];
    int min_size = size_t(old) < new_size ? size_t(old) : ssize_;
    for (int i = 0; i < min_size; ++i) {
        data[i] = old[i];
    }
    delete[] old;
}

template<typename T>
void ArrayT<T>::insert(const int& i, const T& elem) {
    if (i <= 0 || i > ssize_) {throw std::out_of_range("invalid index");}
    ssize_ += 1;
    T* old = data;
    data = new T[ssize_];
    for (int j = 0; j < i; ++j) {
        data[j] = old[j];
    }
    data[i] = elem;
    for (int j = i + 1; j < ssize_; ++j) {
        data[j] = old[j - 1];
    }
    delete[] old;
}

template<typename T>
void ArrayT<T>::remove(const int& i) {
    std::rotate(data + i, data + i + 1, data + ssize_);
    (*this).resize(ssize_ - 1);
}

template<typename T>
std::istream &ArrayT<T>::ReadFrom(std::istream &istrm) {
    if (ssize_ > 0) {
        int i = 0;
        T xi = 0;
        while (!istrm.eof() && istrm.good() && i < ssize_){
            istrm >> xi;
            data[i] = xi;
            i++;
        }
    } else {
        throw std::exception();
    }
    return istrm;
}

template<typename T>
std::ostream& ArrayT<T>::WriteTo(std::ostream &ostrm) {
    if (ssize_ > 0) {
        int i = 0;
        while (ostrm.good() && i < ssize_) {
            ostrm << data[i] << " ";
            i++;
        }
    }
    return ostrm;
}

template<typename T>
std::ostream &operator<<(std::ostream &ostrm, ArrayT<T> &array) {
    return array.WriteTo(ostrm);
}

template<typename T>
std::istream &operator>>(std::istream &istrm, ArrayT<T> &array) {
    return array.ReadFrom(istrm);
}