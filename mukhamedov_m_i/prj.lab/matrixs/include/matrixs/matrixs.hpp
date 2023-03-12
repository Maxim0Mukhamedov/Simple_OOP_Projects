#include <cstddef>
#include "iosfwd"
#include "utility"

class MatrixS
{
public:
    // Конструкторы
    MatrixS(int rows = 0, int cols = 0);;
    MatrixS(const MatrixS& other);;
    MatrixS& operator=(const MatrixS& other);;
    //Деструктор
    ~MatrixS() = default;
    //Оператор итерирования
    double* operator[](int index) const;;
    //Взятие размера
    std::pair<int,int> shape() const;;
    //Изменение размера
    //void resize(const int& size);
private:
    double** data = nullptr;
    std::pair<int,int> sshape_{0,0};
};

