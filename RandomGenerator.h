#pragma once
#include "Generator.h"
#include <random>

namespace MATRIX
{
    template <class Type>
    class RandomGenerator : public Generator<Type>
    {
    private:
        std::mt19937 generator;
        std::uniform_int_distribution<int> distribution;

    public:
        RandomGenerator(int min, int max);
        Type generate() override;
    };
}
