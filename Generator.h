#pragma once  

namespace MATRIX 
{
    // Базовый абстрактный класс для генераторов
    template <class Type>
    class Generator
    {
    public:
        virtual ~Generator() = default;  // Виртуальный деструктор
        
        virtual Type generate() = 0;  // Чисто виртуальный метод генерации
    };

    // Генератор, возвращающий одно константное значение
    template <class Type>
    class ConstGenerator : public Generator<Type>
    {
    private:
        Type constantValue;  // Хранимое значение
        
    public:
        ConstGenerator(Type value) : constantValue(value) {}  // Конструктор
        
        Type generate() override { return constantValue; }  // Всегда возвращает одно значение
    };
}
