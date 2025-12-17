#pragma once
#include "Exercise.h"

namespace MATRIX
{
    // Упражнение 1: Замена последнего положительного элемента на второй элемент
    class Task1Exercise : public Exercise
    {
    public:
        // Используем конструктор базового класса
        using Exercise::Exercise;

        // Выполняет задание 1
        void task() override;

    private:
        // Вспомогательные методы
        size_t findLastPositive() const;          // Находит индекс последнего положительного элемента
        void replaceLastPositiveWithSecond();     // Заменяет найденный элемент на второй
    };
}
