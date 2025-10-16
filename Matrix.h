#pragma once
#include <iostream>
#include <utility>

namespace MATRIX
{
    template <class Type>
    class Matrix
    {
    private:
        size_t rows;
        size_t columns;
        Type** array;

    public:
        // Конструкторы и деструктор
        Matrix();
        Matrix(const size_t rows, const size_t columns);
        Matrix(const Matrix& matrix);
        ~Matrix();

        // Операторы
        Matrix operator=(const Matrix& other);
        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const double coef) const;
        Matrix operator*(const Matrix& other) const;

        // Дружественные операторы
        template <class T>
        friend Matrix<T> operator*(const double coef, const Matrix<T>& other);

        template <class T>
        friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& other);

        // Методы доступа
        size_t getRows() const { return rows; }
        size_t getColumns() const { return columns; }
        Type& operator()(size_t row, size_t col) { return array[row][col]; }
        const Type& operator()(size_t row, size_t col) const { return array[row][col]; }

        // Методы для задач
        void replaceLastPositiveWithSecond();
        void insertMaxBeforeOnes();
        Matrix createNewArray() const;

    private:
        // Вспомогательные методы
        bool containsDigitOne(Type number) const;
        std::pair<size_t, size_t> findLastPositive() const;
        Type findMax() const;
        void initializeMatrix();
        void cleanupMatrix();
    };

    // Декларации дружественных функций
    template <class Type>
    Matrix<Type> operator*(const double coef, const Matrix<Type>& other);

    template <class Type>
    std::ostream& operator<<(std::ostream& os, const Matrix<Type>& other);
}
