#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <memory>

namespace MATRIX
{
    class Exercise
    {
    protected:
        std::unique_ptr<Matrix> matrix;      // Указатель на матрицу
        std::unique_ptr<Generator> generator; // Указатель на генератор

    public:
        // Конструктор - принимает матрицу и генератор
        Exercise(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator);
        
        virtual ~Exercise() = default;  // Виртуальный деструктор
        
        // Основной метод выполнения упражнения
        virtual void task() = 0;
        
        // Методы доступа к матрице
        Matrix& get_matrix();                    // Для изменения матрицы
        const Matrix& get_matrix() const;        // Для чтения матрицы
    };
}
