#pragma once
#include "Generator.h"
#include <random>

namespace miit_algebra
{
    class RandomGenerator : public Generator
    {
    private:
        std::mt19937 generator;
        std::uniform_int_distribution<int> distribution;

    public:
        RandomGenerator(int min, int max);
        int generate() override;
    };
}