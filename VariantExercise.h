#pragma once
#include "Exercise.h"

namespace miit_algebra
{
    class VariantExercise : public Exercise
    {
    public:
        VariantExercise(Generator* gen, size_t size);

        void Task1() override;
        void Task2() override;
        Matrix Task3() override;

    private:
        bool contains_digit_one(int number) const;
        size_t find_last_positive() const;
        int find_max() const;
    };
}