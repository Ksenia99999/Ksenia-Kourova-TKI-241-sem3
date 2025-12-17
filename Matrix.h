#pragma once
#include <memory>
#include <string>
#include <sstream>
#include <stdexcept>

namespace MATRIX
{
    class Generator;  

    class Matrix
    {
    private:
        std::unique_ptr<int[]> data;
        size_t size;

    public:
        // Конструкторы
        Matrix();
        explicit Matrix(const size_t size);
        Matrix(const size_t size, const int& value);
        
        // Копирующий конструктор
        Matrix(const Matrix& other);
        
        // Перемещающий конструктор
        Matrix(Matrix&& other) noexcept;
        
        // Копирующий оператор присваивания
        Matrix& operator=(const Matrix& other);
        
        // Перемещающий оператор присваивания
        Matrix& operator=(Matrix&& other) noexcept;
        
        // Деструктор
        ~Matrix() = default;

        // Операторы сдвига
        Matrix operator<<(int shift) const;
        Matrix operator>>(int shift) const;
        Matrix& operator<<=(int shift);
        Matrix& operator>>=(int shift);

        // Оператор доступа к элементам
        int& operator[](const size_t index);
        const int& operator[](const size_t index) const;

        // Методы доступа
        size_t get_size() const;
        std::string to_string() const;

        // Метод заполнения
        void fill(Generator& generator);
    };
}

