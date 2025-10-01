#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit_algebra
{
    class Exercise
    {
    protected:
        Matrix matrix;
        Generator* generator;

    public:
        Exercise(Generator* gen, size_t size);
        virtual ~Exercise() = default;

        virtual void Task1() = 0;
        virtual void Task2() = 0;
        virtual Matrix Task3() = 0;

        Matrix get_matrix() const;
    };
}