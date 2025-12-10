#pragma once
#include <iostream>
#include <vector>

namespace MATRIX
{
    // Шаблонный класс для одномерного массива
    template <class Type>
    class Matrix
    {
    private:
        std::vector<Type> data;  // Внутреннее хранилище
        
        // Вспомогательные методы
        bool containsDigitOne(Type number) const;  // Проверка цифры 1
        size_t findLastPositive() const;           // Поиск последнего положительного
        Type findMax() const;                      // Поиск максимума
        
    public:
        // Конструкторы
        Matrix();                           
        Matrix(const size_t size);          // С заданным размером
        Matrix(const Matrix& matrix);       // Копирования
        ~Matrix() = default;                // Деструктор
        
        // Операторы
        Matrix operator=(const Matrix& other);     // Присваивания
        Matrix operator+(const Matrix& other) const;  // Сложения
        Matrix operator-(const Matrix& other) const;  // Вычитания
        Matrix operator*(const double coef) const;    // Умножения на скаляр
        
        // Дружественные операторы
        template <class T>
        friend Matrix<T> operator*(const double coef, const Matrix<T>& other);
        
        template <class T>
        friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& other);
        
        // Методы доступа
        size_t getSize() const;                    // Получить размер
        Type& operator[](size_t index);            // Доступ для записи
        const Type& operator[](size_t index) const; // Доступ для чтения
        
        // Методы для трех задач варианта
        void replaceLastPositiveWithSecond();  // Задача 1
        void insertMaxBeforeOnes();            // Задача 2
        Matrix createNewArray() const;         // Задача 3
    };
    
    // Глобальный оператор вывода
    template <class Type>
    std::ostream& operator<<(std::ostream& os, const Matrix<Type>& other);
}
