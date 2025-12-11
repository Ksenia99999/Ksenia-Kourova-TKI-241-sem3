#include "IStreamGenerator.h"

MATRIX::IStreamGenerator::IStreamGenerator(std::istream& in)
    : in{in}
{
}

int MATRIX::IStreamGenerator::generate()
{
    int value = 0;
    this->in >> value;
    return value;
}
