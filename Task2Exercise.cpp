// Реализация задания 2: вставка максимума перед элементами с цифрой 1
#include "Task2Exercise.h"
#include <cmath>

// Выполняет задание 2
void MATRIX::Task2Exercise::task()
{
    insertMaxBeforeOnes();
}

// Проверяет, содержит ли число цифру 1
bool MATRIX::Task2Exercise::containsDigitOne(int number) const
{
    number = std::abs(number);  // Работаем с абсолютным значением

    while (number > 0)
    {
        if (number % 10 == 1) return true;  // Нашли цифру 1
        number /= 10;  // Убираем последнюю цифру
    }

    return false;  // Цифра 1 не найдена
}

// Находит максимальный элемент в матрице
int MATRIX::Task2Exercise::findMax() const
{
    const auto& mat = *matrix;
    if (mat.get_size() == 0) return 0;

    int maxVal = mat[0];

    // Ищем максимум
    for (size_t i = 1; i < mat.get_size(); ++i)
    {
        if (mat[i] > maxVal)
        {
            maxVal = mat[i];
        }
    }

    return maxVal;
}

// Заменяет элементы с цифрой 1 на максимальный
void MATRIX::Task2Exercise::insertMaxBeforeOnes()
{
    auto& mat = *matrix;
    int maxVal = findMax();  // Находим максимум

    // Проходим по всем элементам
    for (size_t i = 0; i < mat.get_size(); ++i)
    {
        // Если элемент содержит цифру 1
        if (containsDigitOne(mat[i]))
        {
            mat[i] = maxVal;  // Заменяем на максимальный
        }
    }
}
