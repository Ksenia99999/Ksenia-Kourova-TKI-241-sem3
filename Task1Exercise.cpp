// Реализация задания 1: замена последнего положительного элемента на второй
#include "Task1Exercise.h"

// Выполняет задание 1
void MATRIX::Task1Exercise::task()
{
    replaceLastPositiveWithSecond();
}

// Находит индекс последнего положительного элемента
size_t MATRIX::Task1Exercise::findLastPositive() const
{
    const auto& mat = *matrix;

    // Ищем с конца массива
    for (int i = static_cast<int>(mat.get_size()) - 1; i >= 0; --i)
    {
        if (mat[i] > 0)
        {
            return i;  // Возвращаем индекс найденного элемента
        }
    }

    return static_cast<size_t>(-1);  // Если положительных элементов нет
}

// Заменяет последний положительный элемент на второй
void MATRIX::Task1Exercise::replaceLastPositiveWithSecond()
{
    auto& mat = *matrix;
    size_t lastPositive = findLastPositive();

    // Если нашли положительный и есть второй элемент
    if (lastPositive != static_cast<size_t>(-1) && mat.get_size() > 1)
    {
        mat[lastPositive] = mat[1];  // Заменяем на второй элемент
    }
}
