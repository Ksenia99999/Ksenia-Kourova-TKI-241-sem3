#include "IStreamGenerator.h"

namespace miit_algebra
{
    IStreamGenerator::IStreamGenerator(std::istream& in) : in(in)
    {
    }

    int IStreamGenerator::generate()
    {
        int value;
        in >> value;
        return value;
    }
}