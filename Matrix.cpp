#include "Matrix.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace MATRIX
{
    // Конструкторы
    template <class Type>
    Matrix<Type>::Matrix()
    {
    }

    template <class Type>
    Matrix<Type>::Matrix(const size_t size)
    {
        data.resize(size);
        for (size_t i = 0; i < size; ++i) {
            data[i] = Type();
        }
    }

    template <class Type>
    Matrix<Type>::Matrix(const Matrix& matrix)
        : data(matrix.data)
    {
    }

    // Операторы
    template <class Type>
    Matrix<Type> Matrix<Type>::operator=(const Matrix& other)
    {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::operator+(const Matrix& other) const
    {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Array sizes must match for addition");
        }

        Matrix result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::operator-(const Matrix& other) const
    {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Array sizes must match for subtraction");
        }

        Matrix result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::operator*(const double coef) const
    {
        Matrix result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = static_cast<Type>(data[i] * coef);
        }
        return result;
    }

    // Методы доступа
    template <class Type>
    size_t Matrix<Type>::getSize() const
    {
        return data.size();
    }

    template <class Type>
    Type& Matrix<Type>::operator[](size_t index)
    {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    template <class Type>
    const Type& Matrix<Type>::operator[](size_t index) const
    {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Методы для задач
    template <class Type>
    void Matrix<Type>::replaceLastPositiveWithSecond()
    {
        size_t lastPositive = findLastPositive();
        if (lastPositive != static_cast<size_t>(-1) && data.size() > 1) {
            data[lastPositive] = data[1];
        }
    }

    template <class Type>
    void Matrix<Type>::insertMaxBeforeOnes()
    {
        Type maxVal = findMax();
        for (size_t i = 0; i < data.size(); ++i) {
            if (containsDigitOne(data[i])) {
                data[i] = maxVal;
            }
        }
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::createNewArray() const
    {
        Matrix result(data.size());

        for (size_t i = 0; i < data.size(); ++i) {
            if ((i + 1) % 3 == 0) {
                result.data[i] = static_cast<Type>(i) * data[i];
            }
            else {
                result.data[i] = -data[i] * static_cast<Type>(i + 1);
            }
        }
        return result;
    }

    // Вспомогательные методы
    template <class Type>
    bool Matrix<Type>::containsDigitOne(Type number) const
    {
        int num = static_cast<int>(std::abs(number));
        while (num > 0) {
            if (num % 10 == 1) return true;
            num /= 10;
        }
        return false;
    }

    template <class Type>
    size_t Matrix<Type>::findLastPositive() const
    {
        for (size_t i = data.size(); i > 0; --i) {
            size_t index = i - 1;
            if (data[index] > 0) {
                return index;
            }
        }
        return static_cast<size_t>(-1);
    }

    template <class Type>
    Type Matrix<Type>::findMax() const
    {
        Type maxVal = data[0];
        for (size_t i = 1; i < data.size(); ++i) {
            if (data[i] > maxVal) {
                maxVal = data[i];
            }
        }
        return maxVal;
    }

    // Реализация дружественных функций
    template <class Type>
    Matrix<Type> operator*(const double coef, const Matrix<Type>& other)
    {
        return other * coef;
    }

    template <class Type>
    std::ostream& operator<<(std::ostream& os, const Matrix<Type>& other)
    {
        for (size_t i = 0; i < other.data.size(); ++i) {
            os << other.data[i] << " ";
        }
        return os;
    }

    template class Matrix<int>;
    
    template std::ostream& operator<<(std::ostream& os, const Matrix<int>& other);
}
