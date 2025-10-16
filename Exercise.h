#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace MATRIX
{
    template <class Type>
    class Exercise
    {
    protected:
        Matrix<Type> matrix;
        Generator<Type>* generator;

    public:
        Exercise(Generator<Type>* gen, size_t rows, size_t columns);
        virtual ~Exercise() = default;

        virtual void Task1() = 0;
        virtual void Task2() = 0;
        virtual Matrix<Type> Task3() = 0;

        Matrix<Type> get_matrix() const;
    };
}
