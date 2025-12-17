#include "ConstGenerator.h"

MATRIX::ConstGenerator::ConstGenerator(const int value)
    : value{ value }
{
}

int MATRIX::ConstGenerator::generate()
{
    return value;
}
