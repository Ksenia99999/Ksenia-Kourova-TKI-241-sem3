// Генератор постоянных значений
#pragma once
#include "Generator.h"

namespace MATRIX
{
    // Генератор, который всегда возвращает одинаковое значение
    // Полезен для тестирования и заполнения массива одним числом
    class ConstGenerator : public Generator
    {
    private:
        int value;  // Значение, которое всегда возвращается

    public:
        // Конструктор - задает значение, которое будет возвращаться
        ConstGenerator(const int value);
        
        // Всегда возвращает одно и то же значение
        int generate() override;
    };
}
