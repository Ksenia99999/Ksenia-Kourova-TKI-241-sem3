#include "Exercise.h"

// Конструктор
MATRIX::Exercise::Exercise(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator)
    : matrix(std::move(matrix)), generator(std::move(generator)) {}

// Получение матрицы для записи
MATRIX::Matrix& MATRIX::Exercise::get_matrix()
{
    return *matrix;
}

// Получение матрицы для чтения
const MATRIX::Matrix& MATRIX::Exercise::get_matrix() const
{
    return *matrix;
}
