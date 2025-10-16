#pragma once
#include "Exercise.h"

namespace MATRIX
{
    template <class Type>
    class VariantExercise : public Exercise<Type>
    {
    public:
        VariantExercise(Generator<Type>* gen, size_t rows, size_t columns);

        void Task1() override;
        void Task2() override;
        Matrix<Type> Task3() override;
    };
}
