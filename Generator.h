#pragma once

namespace miit_algebra
{
    class Generator
    {
    public:
        virtual ~Generator() = default;
        virtual int generate() = 0;
    };
}