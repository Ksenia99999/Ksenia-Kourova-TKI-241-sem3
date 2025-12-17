#pragma once
#include "Generator.h"
#include <random>

namespace MATRIX
{
    class RandomGenerator : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution;  // Распределение чисел
        std::mt19937 generator; // Генератор случайных чисел

    public:
        // Конструктор - задает диапазон случайных чисел
        RandomGenerator(const int min, const int max);
        
        // Генерирует случайное число в заданном диапазоне
        int generate() override;
    };
}
