#include "VariantExercise.h"

namespace MATRIX
{
    template <class Type>
    VariantExercise<Type>::VariantExercise(Generator<Type>* gen, size_t size)
        : Exercise<Type>(gen, size)
    {
    }

    template <class Type>
    Task1Exercise<Type>::Task1Exercise(Generator<Type>* gen, size_t size)
        : VariantExercise<Type>(gen, size) {}

    template <class Type>
    void Task1Exercise<Type>::execute()
    {
        this->array.replaceLastPositiveWithSecond();  // Задача 1
    }

    template <class Type>
    Task2Exercise<Type>::Task2Exercise(Generator<Type>* gen, size_t size)
        : VariantExercise<Type>(gen, size) {}

    template <class Type>
    void Task2Exercise<Type>::execute()
    {
        this->array.insertMaxBeforeOnes();  // Задача 2
    }

    template <class Type>
    Task3Exercise<Type>::Task3Exercise(Generator<Type>* gen, size_t size)
        : VariantExercise<Type>(gen, size) {}

    template <class Type>
    void Task3Exercise<Type>::execute()
    {
        task3Result = this->array.createNewArray();  // Задача 3
    }

    template class VariantExercise<int>;
    template class Task1Exercise<int>;
    template class Task2Exercise<int>;
    template class Task3Exercise<int>;
}
