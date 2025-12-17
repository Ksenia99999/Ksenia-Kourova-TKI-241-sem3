#include "Matrix.h"
#include "Generator.h"
#include <algorithm>
#include <stdexcept>

namespace MATRIX
{
    // Конструктор по умолчанию
    Matrix::Matrix() : size(0), data(nullptr) {}

    // Конструктор с заданным размером
    Matrix::Matrix(const size_t size) : size(size), data(std::make_unique<int[]>(size)) {}

    // Конструктор с размером и значением
    Matrix::Matrix(const size_t size, const int& value) : size(size), data(std::make_unique<int[]>(size))
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = value;
        }
    }

    // Конструктор копирования
    Matrix::Matrix(const Matrix& other) : size(other.size), data(std::make_unique<int[]>(other.size))
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    // Конструктор перемещения
    Matrix::Matrix(Matrix&& other) noexcept : size(other.size), data(std::move(other.data))
    {
        other.size = 0;
    }

    // Оператор присваивания копированием
    Matrix& Matrix::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            auto temp = std::make_unique<int[]>(other.size);
            for (size_t i = 0; i < other.size; ++i)
            {
                temp[i] = other.data[i];
            }
            data = std::move(temp);
            size = other.size;
        }
        return *this;
    }

    // Оператор присваивания перемещением
    Matrix& Matrix::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            data = std::move(other.data);
            size = other.size;
            other.size = 0;
        }
        return *this;
    }

    // Оператор сдвига влево
    Matrix Matrix::operator<<(int shift) const
    {
        Matrix result(*this);
        result <<= shift;
        return result;
    }

    // Оператор сдвига вправо
    Matrix Matrix::operator>>(int shift) const
    {
        Matrix result(*this);
        result >>= shift;
        return result;
    }

    // Оператор сдвига влево с присваиванием
    Matrix& Matrix::operator<<=(int shift)
    {
        if (size == 0) return *this;

        shift = shift % static_cast<int>(size);
        if (shift < 0) shift += size;

        auto temp = std::make_unique<int[]>(size);
        for (size_t i = 0; i < size; ++i)
        {
            temp[(i + shift) % size] = data[i];
        }
        data = std::move(temp);
        return *this;
    }

    // Оператор сдвига вправо с присваиванием
    Matrix& Matrix::operator>>=(int shift)
    {
        return *this <<= -shift;
    }

    // Оператор доступа для записи
    int& Matrix::operator[](const size_t index)
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Оператор доступа для чтения
    const int& Matrix::operator[](const size_t index) const
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Получение размера матрицы
    size_t Matrix::get_size() const
    {
        return size;
    }

    // Преобразование матрицы в строку
    std::string Matrix::to_string() const
    {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < size; ++i)
        {
            oss << data[i];
            if (i < size - 1) oss << " ";
        }
        oss << "]";
        return oss.str();
    }

    // Заполнение матрицы через генератор
    void Matrix::fill(Generator& generator)
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = generator.generate();
        }
    }
}
