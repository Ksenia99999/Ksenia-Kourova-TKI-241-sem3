#include "VariantExercise.h"

namespace MATRIX
{
    template <class Type>
    VariantExercise<Type>::VariantExercise(Generator<Type>* gen, size_t size)
        : Exercise<Type>(gen, size)
    {
    }

    // Task1Exercise
    template <class Type>
    Task1Exercise<Type>::Task1Exercise(Generator<Type>* gen, size_t size)
        : VariantExercise<Type>(gen, size)
    {
    }

    template <class Type>
    void Task1Exercise<Type>::execute()
    {
        Task1();
    }

    template <class Type>
    void Task1Exercise<Type>::Task1()
    {
        this->array.replaceLastPositiveWithSecond();
    }

    // Task2Exercise
    template <class Type>
    Task2Exercise<Type>::Task2Exercise(Generator<Type>* gen, size_t size)
        : VariantExercise<Type>(gen, size)
    {
    }

    template <class Type>
    void Task2Exercise<Type>::execute()
    {
        Task2();
    }

    template <class Type>
    void Task2Exercise<Type>::Task2()
    {
        this->array.insertMaxBeforeOnes();
    }

    // Task3Exercise
    template <class Type>
    Task3Exercise<Type>::Task3Exercise(Generator<Type>* gen, size_t size)
        : VariantExercise<Type>(gen, size)
    {
    }

    template <class Type>
    void Task3Exercise<Type>::execute()
    {
        task3Result = Task3();
    }

    template <class Type>
    Matrix<Type> Task3Exercise<Type>::Task3()
    {
        return this->array.createNewArray();
    }

    template class VariantExercise<int>;
    template class Task1Exercise<int>;
    template class Task2Exercise<int>;
    template class Task3Exercise<int>;
}
