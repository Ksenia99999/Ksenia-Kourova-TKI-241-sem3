#include "RandomGenerator.h"

namespace miit_algebra
{
    RandomGenerator::RandomGenerator(int min, int max)
        : generator(std::random_device()()), distribution(min, max)
    {
    }

    int RandomGenerator::generate()
    {
        return distribution(generator);
    }
}