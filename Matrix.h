#pragma once
#include <vector>
#include <string>

namespace miit_algebra
{
    class Matrix
    {
    private:
        std::vector<int> data;

    public:
        Matrix() = default;
        Matrix(const Matrix&) = default;
        Matrix(Matrix&&) = default;
        ~Matrix() = default;

        Matrix& operator=(const Matrix&) = default;
        Matrix& operator=(Matrix&&) = default;

        int& operator[](size_t index);
        const int& operator[](size_t index) const;

        Matrix operator<<(int shift) const;
        Matrix operator>>(int shift) const;

        size_t size() const;
        std::string to_string() const;
        void resize(size_t size);
        void push_back(int value);
        void insert(size_t index, int value);
    };
}
