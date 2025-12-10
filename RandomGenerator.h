#pragma once
#include "Generator.h" 
#include <random>      

namespace MATRIX
{
    // Генератор случайных чисел
    template <class Type>
    class RandomGenerator : public Generator<Type>
    {
    private:
        std::mt19937 generator;  // Генератор Mersenne Twister
        std::uniform_int_distribution<int> distribution;  // Равномерное распределение
        
    public:
        RandomGenerator(int min, int max);  // Конструктор с диапазоном
        
        Type generate() override;  // Генерация случайного числа
    };
}
