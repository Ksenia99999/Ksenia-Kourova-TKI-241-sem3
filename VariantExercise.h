#pragma once
#include "Exercise.h" 

namespace MATRIX
{
    // Промежуточный базовый класс
    template <class Type>
    class VariantExercise : public Exercise<Type>
    {
    public:
        VariantExercise(Generator<Type>* gen, size_t size);
    };
    
    // Класс для задачи 1
    template <class Type>
    class Task1Exercise : public VariantExercise<Type>
    {
    public:
        Task1Exercise(Generator<Type>* gen, size_t size);
        void execute() override;
    };
    
    // Класс для задачи 2
    template <class Type>
    class Task2Exercise : public VariantExercise<Type>
    {
    public:
        Task2Exercise(Generator<Type>* gen, size_t size);
        void execute() override;
    };
    
    // Класс для задачи 3 (сохраняет результат)
    template <class Type>
    class Task3Exercise : public VariantExercise<Type>
    {
    private:
        Matrix<Type> task3Result;  // Хранение результата
        
    public:
        Task3Exercise(Generator<Type>* gen, size_t size);
        void execute() override;
        
        Matrix<Type> getTask3Result() const { return task3Result; }
    };
}
