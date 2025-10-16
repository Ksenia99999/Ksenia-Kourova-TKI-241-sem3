#include "VariantExercise.h"

namespace MATRIX
{
    template <class Type>
    VariantExercise<Type>::VariantExercise(Generator<Type>* gen, size_t rows, size_t columns)
        : Exercise<Type>(gen, rows, columns)
    {
    }

    template <class Type>
    void VariantExercise<Type>::Task1()
    {
        this->matrix.replaceLastPositiveWithSecond();
    }

    template <class Type>
    void VariantExercise<Type>::Task2()
    {
        this->matrix.insertMaxBeforeOnes();
    }

    template <class Type>
    Matrix<Type> VariantExercise<Type>::Task3()
    {
        return this->matrix.createNewArray();
    }

    template class VariantExercise<int>;
}
