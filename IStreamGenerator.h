#pragma once
#include "Generator.h"
#include <iostream>

namespace MATRIX
{
    template <class Type>
    class IStreamGenerator : public Generator<Type>
    {
    private:
        std::istream& in;

    public:
        IStreamGenerator(std::istream& in = std::cin);
        Type generate() override;
    };
}
