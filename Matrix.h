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
        std::unique_ptr<int[]> data;  // Умный указатель на массив чисел
        size_t size;                   // Размер массива

    public:
        // Конструкторы
        Matrix();                              // Конструктор по умолчанию (пустая матрица)
        explicit Matrix(const size_t size);    // Конструктор с заданным размером
        Matrix(const size_t size, const int& value);  // Конструктор с размером и значением
        
        // Конструктор копирования - создает копию матрицы
        Matrix(const Matrix& other);
        
        // Конструктор перемещения - перемещает данные из другой матрицы
        Matrix(Matrix&& other) noexcept;
        
        // Оператор присваивания копированием
        Matrix& operator=(const Matrix& other);
        
        // Оператор присваивания перемещением
        Matrix& operator=(Matrix&& other) noexcept;
        
        // Деструктор - автоматически освобождает память через unique_ptr
        ~Matrix() = default;

        // Операторы сдвига
        Matrix operator<<(int shift) const;    // Сдвиг влево (возвращает новую матрицу)
        Matrix operator>>(int shift) const;    // Сдвиг вправо (возвращает новую матрицу)
        Matrix& operator<<=(int shift);        // Сдвиг влево с присваиванием
        Matrix& operator>>=(int shift);        // Сдвиг вправо с присваиванием

        // Операторы доступа к элементам
        int& operator[](const size_t index);              // Доступ для записи
        const int& operator[](const size_t index) const;  // Доступ для чтения

        // Методы доступа
        size_t get_size() const;              // Возвращает размер матрицы
        std::string to_string() const;        // Преобразует матрицу в строку

        // Метод заполнения матрицы
        void fill(Generator& generator);
    };
}
