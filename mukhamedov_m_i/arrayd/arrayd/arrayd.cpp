#include <iostream>
#include "arrayd.h"

ArrayD::ArrayD(int s) : ssize_(s) { data = new double[ssize_]; }

ArrayD::ArrayD(const ArrayD &other) : ssize_(other.ssize_)
{
    data = new double[ssize_];
    for(int i = 0; i < ssize_; ++i)
        data[i] = other.data[i];
}

ArrayD::ArrayD(std::initializer_list<double> list) : ssize_(list.size())
{
    data = new double[ssize_];
    int i = 0;
    for (auto& item : list)
        data[i++] = item;
}

ArrayD &ArrayD::operator=(const ArrayD &other) {
    delete[] data;
    *this = ArrayD(other);
    return *this;
}

ArrayD::ArrayD(ArrayD &&other) : ssize_(other.ssize_), data(other.data) //Конструктор копирования && - означает временную ссылку, как только функция закончиться объект other будет удален
{
    other.ssize_ = 0;
    other.data = nullptr;
}

double &ArrayD::operator[](int index) const {
    return data[index];
}

ptrdiff_t ArrayD::size() const { return ssize_; }

void ArrayD::resize(int size) {
    ArrayD old_data = *this;
    ssize_ = size;
    data = new double[size];
    for (int i = 0; i < old_data.size(); ++i) {
        data[i] = old_data[i];
    }
}

void ArrayD::push_back(double new_elem) {
    (*this).resize(ssize_ + 1);
    data[ssize_ - 1] = new_elem;
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
        throw std::exception();
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
