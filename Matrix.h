#pragma once
#include <iostream>
#include <memory>
#include <cmath>
#include <stdexcept>

namespace MATRIX
{
    template <class Type>
    class Matrix
    {
    private:
        std::unique_ptr<Type[]> data;  // Умный указатель на массив
        size_t arraySize;              // Размер массива

        // Вспомогательные методы
        bool containsDigitOne(Type number) const;
        size_t findLastPositive() const;
        Type findMax() const;

    public:
        // Конструкторы
        Matrix();
        Matrix(const size_t size);
        Matrix(const Matrix& matrix);
        ~Matrix() = default;

        // Операторы
        Matrix& operator=(const Matrix& other);
        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const double coef) const;

        // Дружественные операторы
        template <class T>
        friend Matrix<T> operator*(const double coef, const Matrix<T>& other);

        template <class T>
        friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& other);

        // Методы доступа
        size_t getSize() const;
        Type& operator[](size_t index);
        const Type& operator[](size_t index) const;

        // Методы для трех задач
        void replaceLastPositiveWithSecond();
        void insertMaxBeforeOnes();
        Matrix createNewArray() const;
    };

    // Дружественные операторы
    template <class Type>
    std::ostream& operator<<(std::ostream& os, const Matrix<Type>& other);
}
