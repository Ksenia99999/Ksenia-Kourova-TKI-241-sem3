#pragma once
#include "Generator.h"

namespace MATRIX
{
    // Специальный генератор, который всегда возвращает 0
    class ZeroGenerator : public Generator
    {
    public:
        ZeroGenerator() = default;

        // Всегда возвращает 0
        int generate() override;
    };
}
