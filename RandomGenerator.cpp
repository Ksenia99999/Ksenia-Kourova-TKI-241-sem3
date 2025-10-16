#include "RandomGenerator.h"

namespace MATRIX
{
    template <class Type>
    RandomGenerator<Type>::RandomGenerator(int min, int max)
        : generator(std::random_device()()), distribution(min, max)
    {
    }

    template <class Type>
    Type RandomGenerator<Type>::generate()
    {
        return static_cast<Type>(distribution(generator));
    }

    template class RandomGenerator<int>;
}
