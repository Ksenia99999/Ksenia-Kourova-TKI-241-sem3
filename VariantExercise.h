#pragma once
#include "Exercise.h"

namespace MATRIX
{
    // Базовый класс для упражнений
    template <class Type>
    class VariantExercise : public Exercise<Type>
    {
    public:
        VariantExercise(Generator<Type>* gen, size_t size);
        virtual void execute() = 0;
    };

    // Конкретные реализации для каждой задачи
    template <class Type>
    class Task1Exercise : public VariantExercise<Type>
    {
    public:
        Task1Exercise(Generator<Type>* gen, size_t size);
        void execute() override;
        void Task1() override;
        void Task2() override {}
        Matrix<Type> Task3() override { return Matrix<Type>(); }
    };

    template <class Type>
    class Task2Exercise : public VariantExercise<Type>
    {
    public:
        Task2Exercise(Generator<Type>* gen, size_t size);
        void execute() override;
        void Task1() override {}
        void Task2() override;
        Matrix<Type> Task3() override { return Matrix<Type>(); }
    };

    template <class Type>
    class Task3Exercise : public VariantExercise<Type>
    {
    private:
        Matrix<Type> task3Result;
        
    public:
        Task3Exercise(Generator<Type>* gen, size_t size);
        void execute() override;
        void Task1() override {}
        void Task2() override {}
        Matrix<Type> Task3() override;
        
        Matrix<Type> getTask3Result() const { return task3Result; }
    };
}
