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
        // §¬§à§ß§ã§ä§â§å§Ü§ä§à§â§í §á§à §å§Þ§à§Ý§é§Ñ§ß§Ú§ð
        Matrix() = default;
        Matrix(const Matrix&) = default;
        Matrix(Matrix&&) = default;
        ~Matrix() = default;

        // §°§á§Ö§â§Ñ§ä§à§â§í §á§â§Ú§ã§Ó§Ñ§Ú§Ó§Ñ§ß§Ú§ñ
        Matrix& operator=(const Matrix&) = default;
        Matrix& operator=(Matrix&&) = default;

        // §°§á§Ö§â§Ñ§ä§à§â §Õ§à§ã§ä§å§á§Ñ §á§à §Ú§ß§Õ§Ö§Ü§ã§å
        int& operator[](size_t index);
        const int& operator[](size_t index) const;

        // §°§á§Ö§â§Ñ§ä§à§â§í §ã§Õ§Ó§Ú§Ô§Ñ
        Matrix operator<<(int shift) const;
        Matrix operator>>(int shift) const;

        // §°§ã§ß§à§Ó§ß§í§Ö §Þ§Ö§ä§à§Õ§í
        size_t size() const;
        std::string to_string() const;
        void resize(size_t size);
        void push_back(int value);
        void insert(size_t index, int value);
    };
}