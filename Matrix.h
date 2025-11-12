#pragma once
#include <iostream>
#include <vector>

namespace MATRIX
{
    template <class Type>
    class Matrix
    {
    private:
        std::vector<Type> data;

        // Вспомогательные методы
        bool containsDigitOne(Type number) const;
        size_t findLastPositive() const;
        Type findMax() const;

    public:
        // Конструкторы и деструктор
        Matrix();
        Matrix(const size_t size);
        Matrix(const Matrix& matrix);
        ~Matrix() = default;

        // Операторы
        Matrix operator=(const Matrix& other);
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

        // Методы для задач
        void replaceLastPositiveWithSecond();
        void insertMaxBeforeOnes();
        Matrix createNewArray() const;
    };
}
