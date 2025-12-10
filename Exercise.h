#pragma once
#include "Matrix.h"    
#include "Generator.h"  

namespace MATRIX
{
    // Базовый абстрактный класс для упражнений
    template <class Type>
    class Exercise
    {
    protected:
        Matrix<Type> array;        // Массив для работы
        Generator<Type>* generator; // Указатель на генератор
        
    public:
        Exercise(Generator<Type>* gen, size_t size);  // Конструктор
        virtual ~Exercise() = default;                // Виртуальный деструктор
        
        virtual void execute() = 0;  // Чисто виртуальный метод выполнения
        
        Matrix<Type> get_array() const;  // Получить массив
    };
}
