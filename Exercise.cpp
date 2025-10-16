#include "Exercise.h"

namespace MATRIX
{
    template <class Type>
    Exercise<Type>::Exercise(Generator<Type>* gen, size_t rows, size_t columns)
        : generator(gen), matrix(rows, columns)
    {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                matrix(i, j) = generator->generate();
            }
        }
    }

    template <class Type>
    Matrix<Type> Exercise<Type>::get_matrix() const
    {
        return matrix;
    }

    template class Exercise<int>;
}
