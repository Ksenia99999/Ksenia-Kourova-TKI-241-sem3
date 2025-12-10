#include "Exercise.h"

namespace MATRIX
{
    // Конструктор Exercise - заполняет массив через генератор
    template <class Type>
    Exercise<Type>::Exercise(Generator<Type>* gen, size_t size)
        : generator(gen), array(size)
    {
        for (size_t i = 0; i < size; ++i) {
            array[i] = generator->generate();
        }
    }
    
    // Получить копию массива
    template <class Type>
    Matrix<Type> Exercise<Type>::get_array() const
    {
        return array;
    }
    
    // Явная инстанциация для int
    template class Exercise<int>;
}
