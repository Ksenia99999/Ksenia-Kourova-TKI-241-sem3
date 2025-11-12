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

    template <class Type>
    class ConstGenerator : public Generator<Type>
    {
    private:
        Type constantValue;
        
    public:
        ConstGenerator(Type value) : constantValue(value) {}
        Type generate() override { return constantValue; }
    };
}
