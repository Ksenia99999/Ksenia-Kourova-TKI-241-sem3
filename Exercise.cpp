#include "Exercise.h"

namespace MATRIX
{
    template <class Type>
    Exercise<Type>::Exercise(Generator<Type>* gen, size_t size) 
        : generator(gen), array(size)
    {
        for (size_t i = 0; i < size; ++i) {
            array[i] = generator->generate();
        }
    }
    
    template <class Type>
    Matrix<Type> Exercise<Type>::get_array() const
    {
        return array;
    }

    template class Exercise<int>;
}
