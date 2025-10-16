#include "Matrix.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace MATRIX
{
    template <class Type>
    Matrix<Type>::Matrix() : rows(0), columns(0), array(nullptr) {}

    template <class Type>
    Matrix<Type>::Matrix(const size_t rows, const size_t columns)
        : rows(rows), columns(columns)
    {
        initializeMatrix();
    }

    template <class Type>
    Matrix<Type>::Matrix(const Matrix& matrix)
    {
        this->rows = matrix.rows;
        this->columns = matrix.columns;
        initializeMatrix();

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                array[i][j] = matrix.array[i][j];
            }
        }
    }

    template <class Type>
    Matrix<Type>::~Matrix()
    {
        cleanupMatrix();
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::operator=(const Matrix& other)
    {
        if (this != &other) {
            cleanupMatrix();
            rows = other.rows;
            columns = other.columns;
            initializeMatrix();

            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < columns; ++j) {
                    array[i][j] = other.array[i][j];
                }
            }
        }
        return *this;
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::operator+(const Matrix& other) const
    {
        if (rows != other.rows || columns != other.columns) {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }

        Matrix result(rows, columns);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                result.array[i][j] = array[i][j] + other.array[i][j];
            }
        }
        return result;
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::operator-(const Matrix& other) const
    {
        if (rows != other.rows || columns != other.columns) {
            throw std::invalid_argument("Matrix dimensions must match for subtraction");
        }

        Matrix result(rows, columns);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                result.array[i][j] = array[i][j] - other.array[i][j];
            }
        }
        return result;
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::operator*(const double coef) const
    {
        Matrix result(rows, columns);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                result.array[i][j] = static_cast<Type>(array[i][j] * coef);
            }
        }
        return result;
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::operator*(const Matrix& other) const
    {
        if (columns != other.rows) {
            throw std::invalid_argument("Matrix dimensions must match for multiplication");
        }

        Matrix result(rows, other.columns);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.columns; ++j) {
                result.array[i][j] = Type();
                for (size_t k = 0; k < columns; ++k) {
                    result.array[i][j] += array[i][k] * other.array[k][j];
                }
            }
        }
        return result;
    }

    template <class Type>
    void Matrix<Type>::replaceLastPositiveWithSecond()
    {
        auto lastPositive = findLastPositive();
        if (lastPositive.first != static_cast<size_t>(-1) && rows > 0 && columns > 1) {
            array[lastPositive.first][lastPositive.second] = array[0][1];
        }
    }

    template <class Type>
    void Matrix<Type>::insertMaxBeforeOnes()
    {
        Type maxVal = findMax();
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                if (containsDigitOne(array[i][j])) {
                    array[i][j] = maxVal;
                }
            }
        }
    }

    template <class Type>
    Matrix<Type> Matrix<Type>::createNewArray() const
    {
        Matrix result(rows, columns);
        size_t elementCounter = 0;

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                elementCounter++;

                if (elementCounter % 3 == 0) {
                    result.array[i][j] = static_cast<Type>(elementCounter) * array[i][j];
                }
                else {
                    result.array[i][j] = -array[i][j] * static_cast<Type>(elementCounter + 1);
                }
            }
        }
        return result;
    }

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
    std::pair<size_t, size_t> Matrix<Type>::findLastPositive() const
    {
        for (size_t i = rows; i > 0; --i) {
            for (size_t j = columns; j > 0; --j) {
                size_t row = i - 1;
                size_t col = j - 1;
                if (array[row][col] > 0) {
                    return { row, col };
                }
            }
        }
        return { static_cast<size_t>(-1), static_cast<size_t>(-1) };
    }

    template <class Type>
    Type Matrix<Type>::findMax() const
    {
        Type maxVal = array[0][0];
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                if (array[i][j] > maxVal) {
                    maxVal = array[i][j];
                }
            }
        }
        return maxVal;
    }

    template <class Type>
    void Matrix<Type>::initializeMatrix()
    {
        array = new Type * [rows];
        for (size_t i = 0; i < rows; ++i) {
            array[i] = new Type[columns];
            for (size_t j = 0; j < columns; ++j) {
                array[i][j] = Type();
            }
        }
    }

    template <class Type>
    void Matrix<Type>::cleanupMatrix()
    {
        if (array != nullptr) {
            for (size_t i = 0; i < rows; ++i) {
                delete[] array[i];
            }
            delete[] array;
            array = nullptr;
        }
        rows = 0;
        columns = 0;
    }

    template <class Type>
    Matrix<Type> operator*(const double coef, const Matrix<Type>& other)
    {
        return other * coef;
    }

    template <class Type>
    std::ostream& operator<<(std::ostream& os, const Matrix<Type>& other)
    {
        for (size_t i = 0; i < other.rows; ++i) {
            for (size_t j = 0; j < other.columns; ++j) {
                os << other.array[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    template class Matrix<int>;

    // Конструкторы и деструктор
    template Matrix<int>::Matrix();
    template Matrix<int>::Matrix(const size_t rows, const size_t columns);
    template Matrix<int>::Matrix(const Matrix<int>& matrix);
    template Matrix<int>::~Matrix();

    // Операторы
    template Matrix<int> Matrix<int>::operator=(const Matrix<int>& other);
    template Matrix<int> Matrix<int>::operator+(const Matrix<int>& other) const;
    template Matrix<int> Matrix<int>::operator-(const Matrix<int>& other) const;
    template Matrix<int> Matrix<int>::operator*(const double coef) const;
    template Matrix<int> Matrix<int>::operator*(const Matrix<int>& other) const;

    // Методы для задач
    template void Matrix<int>::replaceLastPositiveWithSecond();
    template void Matrix<int>::insertMaxBeforeOnes();
    template Matrix<int> Matrix<int>::createNewArray() const;

    // Вспомогательные методы
    template bool Matrix<int>::containsDigitOne(int number) const;
    template std::pair<size_t, size_t> Matrix<int>::findLastPositive() const;
    template int Matrix<int>::findMax() const;
    template void Matrix<int>::initializeMatrix();
    template void Matrix<int>::cleanupMatrix();

    // Дружественные функции
    template Matrix<int> operator*(const double coef, const Matrix<int>& other);
    template std::ostream& operator<<(std::ostream& os, const Matrix<int>& other);
}
