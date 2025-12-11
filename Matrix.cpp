#include "Matrix.h"
#include <algorithm>
#include <stdexcept>

namespace MATRIX
{
    // Конструкторы
    template <class Type>
    Matrix<Type>::Matrix() : data(nullptr), arraySize(0) {}

    template <class Type>
    Matrix<Type>::Matrix(const size_t size) : arraySize(size)
    {
        if (size > 0) {
            data = std::make_unique<Type[]>(size);
            for (size_t i = 0; i < size; ++i) {
                data[i] = Type();  // Инициализация значением по умолчанию
            }
        } else {
            data = nullptr;
        }
    }

    template <class Type>
    Matrix<Type>::Matrix(const Matrix& matrix) : arraySize(matrix.arraySize)
    {
        if (arraySize > 0) {
            data = std::make_unique<Type[]>(arraySize);
            for (size_t i = 0; i < arraySize; ++i) {
                data[i] = matrix.data[i];
            }
        } else {
            data = nullptr;
        }
    }

    // Оператор присваивания
    template <class Type>
    Matrix<Type>& Matrix<Type>::operator=(const Matrix& other)
    {
        if (this != &other) {
            if (other.arraySize > 0) {
                auto newData = std::make_unique<Type[]>(other.arraySize);
                for (size_t i = 0; i < other.arraySize; ++i) {
                    newData[i] = other.data[i];
                }
                data = std::move(newData);
                arraySize = other.arraySize;
            } else {
                data = nullptr;
                arraySize = 0;
            }
        }
        return *this;
    }

    // Арифметические операции
    template <class Type>
    Matrix<Type> Matrix<Type>::operator+(const Matrix& other) const
    {
        if (arraySize != other.arraySize) {
            throw std::invalid_argument("Array sizes must match for addition");
        }

        Matrix result(arraySize);
        for (size_t i = 0; i < arraySize; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::operator-(const Matrix& other) const
    {
        if (arraySize != other.arraySize) {
            throw std::invalid_argument("Array sizes must match for subtraction");
        }

        Matrix result(arraySize);
        for (size_t i = 0; i < arraySize; ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::operator*(const double coef) const
    {
        Matrix result(arraySize);
        for (size_t i = 0; i < arraySize; ++i) {
            result.data[i] = static_cast<Type>(data[i] * coef);
        }
        return result;
    }

    // Методы доступа
    template <class Type>
    size_t Matrix<Type>::getSize() const
    {
        return arraySize;
    }

    template <class Type>
    Type& Matrix<Type>::operator[](size_t index)
    {
        if (index >= arraySize) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    template <class Type>
    const Type& Matrix<Type>::operator[](size_t index) const
    {
        if (index >= arraySize) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Задача 1: Замена последнего положительного элемента
    template <class Type>
    void Matrix<Type>::replaceLastPositiveWithSecond()
    {
        if (arraySize <= 1) return;  // Нужен как минимум второй элемент
        
        size_t lastPositive = findLastPositive();
        if (lastPositive != static_cast<size_t>(-1)) {
            data[lastPositive] = data[1];  // Заменяем на второй элемент
        }
    }

    // Задача 2: Вставка максимума перед элементами с цифрой 1
    template <class Type>
    void Matrix<Type>::insertMaxBeforeOnes()
    {
        if (arraySize == 0) return;
        
        Type maxVal = findMax();
        for (size_t i = 0; i < arraySize; ++i) {
            if (containsDigitOne(data[i])) {
                data[i] = maxVal;
            }
        }
    }

    // Задача 3: Создание нового массива
    template <class Type>
    Matrix<Type> Matrix<Type>::createNewArray() const
    {
        Matrix result(arraySize);
        for (size_t i = 0; i < arraySize; ++i) {
            if ((i + 1) % 3 == 0) {
                // Каждый третий элемент: M_i = i * P_i
                result.data[i] = static_cast<Type>(i) * data[i];
            } else {
                // Остальные: M_i = -P_i * (i + 1)
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
        if (num == 0) return false;
        
        while (num > 0) {
            if (num % 10 == 1) return true;
            num /= 10;
        }
        return false;
    }

    template <class Type>
    size_t Matrix<Type>::findLastPositive() const
    {
        for (size_t i = arraySize; i > 0; --i) {
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
        if (arraySize == 0) return Type();
        
        Type maxVal = data[0];
        for (size_t i = 1; i < arraySize; ++i) {
            if (data[i] > maxVal) {
                maxVal = data[i];
            }
        }
        return maxVal;
    }

    // Дружественные операторы
    template <class Type>
    Matrix<Type> operator*(const double coef, const Matrix<Type>& other)
    {
        return other * coef;
    }

    template <class Type>
    std::ostream& operator<<(std::ostream& os, const Matrix<Type>& other)
    {
        for (size_t i = 0; i < other.arraySize; ++i) {
            os << other.data[i] << " ";
        }
        return os;
    }

    // Явные инстанциации
    template class Matrix<int>;
    template std::ostream& operator<<(std::ostream& os, const Matrix<int>& other);
}
