#pragma once

namespace MATRIX
{
    class Generator
    {
    public:
        virtual ~Generator() = default;
        virtual int generate() = 0;
    };
}
