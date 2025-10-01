#include "Matrix.h"
#include <sstream>

namespace miit_algebra
{
    int& Matrix::operator[](size_t index)
    {
        return data[index];
    }

    const int& Matrix::operator[](size_t index) const
    {
        return data[index];
    }

    Matrix Matrix::operator<<(int shift) const
    {
        Matrix result = *this;
        for (size_t i = 0; i < result.data.size(); ++i) {
            result.data[i] <<= shift;
        }
        return result;
    }

    Matrix Matrix::operator>>(int shift) const
    {
        Matrix result = *this;
        for (size_t i = 0; i < result.data.size(); ++i) {
            result.data[i] >>= shift;
        }
        return result;
    }

    size_t Matrix::size() const
    {
        return data.size();
    }

    std::string Matrix::to_string() const
    {
        std::ostringstream oss;
        for (size_t i = 0; i < data.size(); ++i) {
            if (i > 0) oss << " ";
            oss << data[i];
        }
        return oss.str();
    }

    void Matrix::resize(size_t size)
    {
        data.resize(size);
    }

    void Matrix::push_back(int value)
    {
        data.push_back(value);
    }

    void Matrix::insert(size_t index, int value)
    {
        if (index <= data.size()) {
            data.insert(data.begin() + index, value);
        }
    }
}