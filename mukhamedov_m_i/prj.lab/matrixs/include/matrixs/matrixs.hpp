#include <cstddef>
#include "iosfwd"

class MatrixS
{
public:
    // Конструкторы
    MatrixS(int rows = 0, int cols = 0);
    MatrixS(const MatrixS& other);
    MatrixS& operator=(const MatrixS& other);
    //Деструктор
    ~MatrixS() = default;
    //Оператор итерирования
    const int& at(int index_row, int index_col) const;
    int& at(int index_row, int index_col);
    //Взятие размера
    const int cols() const;
    const int rows() const;
    void resize(int rows, int cols);
    //Изменение размера
    //void resize(const int& size);
private:
    int* data = nullptr;
    int col = 0;
    int row = 0;
};

