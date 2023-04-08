#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cstdint>
#include "arrayd/arrayd.hpp"

ArrayD::ArrayD(int s) : ssize_(s) {
    if (s < 0) { throw std::invalid_argument("invalid size");}
    capacity_ = ssize_ * 2;
    data = new double[capacity_];
}

ArrayD::ArrayD(const ArrayD &other) : ssize_(other.ssize_)
{
    capacity_ = ssize_*2;
    data = new double[capacity_];
}

ArrayD& ArrayD::operator=(const ArrayD &other) {
    if (other.data == data) {throw std::invalid_argument("You can't use operator= with same ArrayD");}
    delete[] data;
    ssize_ = other.ssize();
    capacity_ = ssize_ * 2;
    data = new double[capacity_];
    for(int i = 0; i < ssize_; ++i)
        data[i] = other.data[i];
    return *this;
}

ArrayD::ArrayD(ArrayD &&other) : ssize_(other.ssize_), data(other.data), capacity_(other.capacity_) //Конструктор копирования && - означает временную ссылку, как только функция закончиться объект other будет удален
{
    other.ssize_ = 0;
    other.capacity_ = 0;
    other.data = nullptr;
}
double &ArrayD::operator[](int index) {
    if (index < 0 || index >= ssize_) {throw std::out_of_range("invalid index");}
    return data[index];
}

const double& ArrayD::operator[](const int index) const {
    if (index < 0 || index >= ssize_) {throw std::out_of_range("invalid index");}
    return data[index];
}

int32_t ArrayD::ssize() const { return ssize_; }

void ArrayD::resize(const int& new_size){
    if (new_size <= 0) { throw std::invalid_argument("invalid size");}
    if (capacity_ < new_size) {
        double* old = data;
        capacity_ = new_size * 2;
        data = new double[capacity_];
        for (int i = 0; i < new_size; i++) {
            data[i] = old[i];
        }
        delete[] old;
    }
    ssize_ = new_size;
}

void ArrayD::insert(const int& i, const double& elem) {
    if (i < 0 || i > ssize_) {throw std::out_of_range("invalid index");}
    (*this).resize(ssize_ + 1);
    for (int j = ssize_ - 1; j > i; --j) {
        data[j] = data[j - 1];
    }
    data[i] = elem;
}
void ArrayD::remove(const int& i) {
    if (i < 0 || i >= ssize_) {throw std::out_of_range("invalid index");}
    std::rotate(data + i, data + i + 1, data + ssize_);
    (*this).resize(ssize_ - 1);
}

std::istream &ArrayD::ReadFrom(std::istream &istrm) {
    if (ssize_ > 0) {
        int i = 0;
        double xi = 0;
        while (!istrm.eof() && istrm.good() && i < ssize_){
            istrm >> xi;
            data[i] = xi;
            i++;
        }
    } else {
        istrm.setstate(std::ios_base::failbit);
    }
    return istrm;
}

std::ostream &ArrayD::WriteTo(std::ostream &ostrm) {
    if (ssize_ > 0) {
        int i = 0;
        while (ostrm.good() && i < ssize_) {
            ostrm << data[i] << " ";
            i++;
        }
    }
    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, ArrayD &array) {
    return array.WriteTo(ostrm);
}

std::istream &operator>>(std::istream &istrm, ArrayD &array) {
    return array.ReadFrom(istrm);
}
