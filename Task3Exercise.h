#pragma once
#include "Exercise.h"

namespace MATRIX
{
    // Упражнение 3: Создание новой матрицы M из матрицы P по правилу
    // M_i = i * P_i, если (i+1) кратно 3
    // M_i = -P_i * (i+1), в остальных случаях
    class Task3Exercise : public Exercise
    {
    private:
        Matrix result;  // Результат выполнения задания (новая матрица M)

    public:
        // Конструктор - инициализирует матрицу-результат
        Task3Exercise(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator);

        // Выполняет задание 3
        void task() override;

        // Возвращает результат (матрицу M)
        const Matrix& get_result() const { return result; }

    private:
        // Создает новую матрицу по правилам задания 3
        Matrix createNewArray() const;
    };
}
