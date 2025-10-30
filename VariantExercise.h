#pragma once
#include "Exercise.h"

namespace MATRIX
{
    template <class Type>
    class VariantExercise : public Exercise<Type>
    {
    public:
        VariantExercise(Generator<Type>* gen, size_t size);
        
        void Task1() override;
        void Task2() override;
        Matrix<Type> Task3() override;
    };
}
