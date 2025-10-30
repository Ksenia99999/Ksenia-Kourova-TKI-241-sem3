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
        friend Matrix operator*(const double coef, const Matrix& other) {
            return other * coef;
        }

        friend std::ostream& operator<<(std::ostream& os, const Matrix& other) {
            for (size_t i = 0; i < other.data.size(); ++i) {
                os << other.data[i] << " ";
            }
            return os;
        }

        // Методы доступа
        size_t getSize() const { return data.size(); }
        Type& operator[](size_t index) { return data[index]; }
        const Type& operator[](size_t index) const { return data[index]; }

        // Методы для задач
        void replaceLastPositiveWithSecond();
        void insertMaxBeforeOnes();
        Matrix createNewArray() const;

    private:
        // Вспомогательные методы
        bool containsDigitOne(Type number) const;
        size_t findLastPositive() const;
        Type findMax() const;
    };
}
