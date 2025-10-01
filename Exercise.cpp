#include "Exercise.h"

namespace miit_algebra
{
    Exercise::Exercise(Generator* gen, size_t size) : generator(gen)
    {
        matrix.resize(size);
        for (size_t i = 0; i < size; ++i) {
            matrix[i] = generator->generate();
        }
    }

    Matrix Exercise::get_matrix() const
    {
        return matrix;
    }
}