#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

using namespace MATRIX;

enum Choose {
    manually = 1,
    random
};

static int input() {
    int number;
    std::cin >> number;
    return number;
}

static int positive_input() {
    int number = input();
    if (number <= 0) {
        std::cout << "Error: positive number required\n";
        exit(1);
    }
    return number;
}

static void demonstrate_manual() {
    std::cout << "=== MANUAL INPUT MODE ===\n\n";

    std::cout << "Enter matrix rows: ";
    int rows = positive_input();

    std::cout << "Enter matrix columns: ";
    int columns = positive_input();

    Matrix<int> matrix(rows, columns);

    std::cout << "\nEnter matrix elements " << rows << "x" << columns << ":\n";

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            matrix(i, j) = input();
        }
    }

    std::cout << "\nOriginal matrix:\n";
    std::cout << matrix << std::endl;

    std::cout << "TASK 1: Replace last positive element with second element...\n";
    matrix.replaceLastPositiveWithSecond();
    std::cout << "Result after task 1:\n";
    std::cout << matrix << std::endl;

    std::cout << "TASK 2: Insert max element before elements containing digit 1...\n";
    matrix.insertMaxBeforeOnes();
    std::cout << "Result after task 2:\n";
    std::cout << matrix << std::endl;

    std::cout << "TASK 3: Create new matrix by rules...\n";
    Matrix<int> newMatrix = matrix.createNewArray();
    std::cout << "New matrix (task 3 result):\n";
    std::cout << newMatrix << std::endl;
}

static void demonstrate_random() {
    std::cout << "=== RANDOM NUMBER MODE ===\n\n";

    std::cout << "Enter matrix rows: ";
    int rows = positive_input();

    std::cout << "Enter matrix columns: ";
    int columns = positive_input();

    std::cout << "Enter min value: ";
    int min = input();

    std::cout << "Enter max value: ";
    int max = input();

    if (min > max) {
        std::cout << "Error: min cannot be greater than max\n";
        return;
    }

    srand(static_cast<unsigned int>(time(0)));
    Matrix<int> matrix(rows, columns);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix(i, j) = min + rand() % (max - min + 1);
        }
    }

    std::cout << "\nOriginal matrix (filled with random numbers):\n";
    std::cout << matrix << std::endl;

    std::cout << "TASK 1: Replace last positive element with second element...\n";
    matrix.replaceLastPositiveWithSecond();
    std::cout << "Result after task 1:\n";
    std::cout << matrix << std::endl;

    std::cout << "TASK 2: Insert max element before elements containing digit 1...\n";
    matrix.insertMaxBeforeOnes();
    std::cout << "Result after task 2:\n";
    std::cout << matrix << std::endl;

    std::cout << "TASK 3: Create new matrix by rules...\n";
    Matrix<int> newMatrix = matrix.createNewArray();
    std::cout << "New matrix (task 3 result):\n";
    std::cout << newMatrix << std::endl;
}

int main() {
    std::cout << "MATRIX PROGRAM\n";
    std::cout << "Variant 13: Three matrix tasks\n\n";

    std::cout << "Choose mode:\n";
    std::cout << "1 - Manual input\n";
    std::cout << "2 - Random numbers\n";
    std::cout << "Your choice: ";

    int choice = input();

    switch (choice) {
    case manually:
        demonstrate_manual();
        break;
    case random:
        demonstrate_random();
        break;
    default:
        std::cout << "Error: invalid choice\n";
        return 1;
    }

    std::cout << "\nProgram completed successfully!\n";
    return 0;
}
