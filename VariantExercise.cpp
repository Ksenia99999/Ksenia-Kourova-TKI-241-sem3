#include "VariantExercise.h"

namespace MATRIX
{
    // Конструктор VariantExercise
    template <class Type>
    VariantExercise<Type>::VariantExercise(Generator<Type>* gen, size_t size)
        : Exercise<Type>(gen, size) {}
    
    // Конструктор Task1Exercise
    template <class Type>
    Task1Exercise<Type>::Task1Exercise(Generator<Type>* gen, size_t size)
        : VariantExercise<Type>(gen, size) {}
    
    // Выполнение задачи 1
    template <class Type>
    void Task1Exercise<Type>::execute()
    {
        this->array.replaceLastPositiveWithSecond();
    }
    
    // Конструктор Task2Exercise
    template <class Type>
    Task2Exercise<Type>::Task2Exercise(Generator<Type>* gen, size_t size)
        : VariantExercise<Type>(gen, size) {}
    
    // Выполнение задачи 2
    template <class Type>
    void Task2Exercise<Type>::execute()
    {
        this->array.insertMaxBeforeOnes();
    }
    
    // Конструктор Task3Exercise
    template <class Type>
    Task3Exercise<Type>::Task3Exercise(Generator<Type>* gen, size_t size)
        : VariantExercise<Type>(gen, size) {}
    
    // Выполнение задачи 3
    template <class Type>
    void Task3Exercise<Type>::execute()
    {
        task3Result = this->array.createNewArray();
    }
    
    // Явные инстанциации
    template class VariantExercise<int>;
    template class Task1Exercise<int>;
    template class Task2Exercise<int>;
    template class Task3Exercise<int>;
}
