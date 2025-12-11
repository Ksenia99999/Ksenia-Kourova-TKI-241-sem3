// Генератор чисел из входного потока (например, с клавиатуры)
// Считывает числа из std::cin или другого потока ввода
#pragma once
#include "Generator.h"
#include <iostream>

namespace MATRIX
{
    // Генератор для ручного ввода чисел
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;  // Поток ввода (обычно std::cin)

    public:
        // Конструктор - принимает поток ввода
        IStreamGenerator(std::istream& in = std::cin);
        
        // Считывает число из потока ввода и возвращает его
        int generate() override;
    };
}
