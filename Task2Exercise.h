#pragma once
#include "Exercise.h"

namespace MATRIX
{
    // Упражнение 2: Вставка максимального элемента перед элементами, содержащими цифру 1
    class Task2Exercise : public Exercise
    {
    public:
        // Используем конструктор базового класса
        using Exercise::Exercise;

        // Выполняет задание 2
        void task() override;

    private:
        // Вспомогательные методы
        void insertMaxBeforeOnes();                // Основной алгоритм задания 2
        bool containsDigitOne(int number) const;   // Проверяет, содержит ли число цифру 1
        int findMax() const;                       // Находит максимальный элемент в матрице
    };
}
