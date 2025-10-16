#include "IStreamGenerator.h"

namespace MATRIX
{
    template <class Type>
    IStreamGenerator<Type>::IStreamGenerator(std::istream& in) : in(in)
    {
    }

    template <class Type>
    Type IStreamGenerator<Type>::generate()
    {
        Type value;
        in >> value;
        return value;
    }

    template class IStreamGenerator<int>;
}
