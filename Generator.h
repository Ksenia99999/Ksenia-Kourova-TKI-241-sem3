#pragma once

namespace MATRIX
{
    template <class Type>
    class Generator
    {
    public:
        virtual ~Generator() = default;
        virtual Type generate() = 0;
    };
}
