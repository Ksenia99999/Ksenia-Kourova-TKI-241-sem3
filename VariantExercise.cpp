#include "VariantExercise.h"

namespace MATRIX
{
    template <class Type>
    VariantExercise<Type>::VariantExercise(Generator<Type>* gen, size_t size) 
        : Exercise<Type>(gen, size) 
    {
    }
    
    template <class Type>
    void VariantExercise<Type>::Task1()
    {
        this->array.replaceLastPositiveWithSecond();
    }
    
    template <class Type>
    void VariantExercise<Type>::Task2()
    {
        this->array.insertMaxBeforeOnes();
    }
    
    template <class Type>
    Matrix<Type> VariantExercise<Type>::Task3()
    {
        return this->array.createNewArray();
    }

    template class VariantExercise<int>;
}
