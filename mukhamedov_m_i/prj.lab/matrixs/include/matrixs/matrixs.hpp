#include <cstddef>
#include "iosfwd"
#include "tuple"
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
    [[nodiscard]] int getRows() const noexcept;
    [[nodiscard]] int getCols() const noexcept;
    //Изменение размера
    void resize(int rows, int cols);
private:
    int* data = nullptr;
    std::tuple<int,int> shape{0,0};
};

