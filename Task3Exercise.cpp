// Реализация задания 3: создание новой матрицы по правилу
#include "Task3Exercise.h"

// Конструктор с размером результата
MATRIX::Task3Exercise::Task3Exercise(std::unique_ptr<Matrix> matrix,
    std::unique_ptr<Generator> generator)
    : Exercise(std::move(matrix), std::move(generator)),
    result(this->matrix->get_size()) {}

// Выполняет задание 3
void MATRIX::Task3Exercise::task()
{
    result = createNewArray();  // Сохраняем результат
}

// Создает новую матрицу по правилу задания 3
MATRIX::Matrix MATRIX::Task3Exercise::createNewArray() const
{
    const auto& P = *matrix;
    Matrix M(P.get_size());  // Создаем новую матрицу такого же размера

    for (size_t i = 0; i < P.get_size(); ++i)
    {
        if ((i + 1) % 3 == 0)  // Каждый третий элемент (i=2,5,8...)
        {
            // M_i = i * P_i
            M[i] = static_cast<int>(i) * P[i];
        }
        else  // Остальные элементы
        {
            // M_i = -P_i * (i + 1)
            M[i] = -P[i] * static_cast<int>(i + 1);
        }
    }

    return M;
}
