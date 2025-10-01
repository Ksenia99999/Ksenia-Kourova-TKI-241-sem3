#include "VariantExercise.h"
#include <cmath>

namespace miit_algebra
{
    VariantExercise::VariantExercise(Generator* gen, size_t size)
        : Exercise(gen, size)
    {
    }

    void VariantExercise::Task1()
    {
        size_t last_positive = find_last_positive();
        if (last_positive != (size_t)-1 && matrix.size() > 1) {
            matrix[last_positive] = matrix[1];
        }
    }

    void VariantExercise::Task2()
    {
        int max_val = find_max();
        size_t original_size = matrix.size();

        for (size_t i = 0; i < original_size; ++i) {
            if (contains_digit_one(matrix[i])) {
                matrix.insert(i, max_val);
                ++i;
                original_size = matrix.size();
            }
        }
    }

    Matrix VariantExercise::Task3()
    {
        Matrix result;
        size_t n = matrix.size();

        for (size_t i = 0; i < n; ++i) {
            if ((i + 1) % 3 == 0) {
                result.push_back((int)i * matrix[i]);
            }
            else {
                result.push_back(-matrix[i] * (int)(i + 1));
            }
        }

        return result;
    }

    bool VariantExercise::contains_digit_one(int number) const
    {
        number = abs(number);
        while (number > 0) {
            if (number % 10 == 1) return true;
            number /= 10;
        }
        return false;
    }

    size_t VariantExercise::find_last_positive() const
    {
        for (size_t i = matrix.size(); i > 0; --i) {
            size_t index = i - 1;
            if (matrix[index] > 0) return index;
        }
        return (size_t)-1;
    }

    int VariantExercise::find_max() const
    {
        int max_val = matrix[0];
        for (size_t i = 1; i < matrix.size(); ++i) {
            if (matrix[i] > max_val) max_val = matrix[i];
        }
        return max_val;
    }
}