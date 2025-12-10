#pragma once
#include "Generator.h" 
#include <iostream>     

namespace MATRIX
{
    // Генератор, читающий значения из потока ввода
    template <class Type>
    class IStreamGenerator : public Generator<Type>
    {
    private:
        std::istream& in;  // Ссылка на поток ввода
        
    public:
        IStreamGenerator(std::istream& in = std::cin);  // По умолчанию std::cin
        
        Type generate() override;  // Чтение из потока
    };
}
