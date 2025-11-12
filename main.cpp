#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"
#include "Generator.h"
#include "VariantExercise.h"

using namespace MATRIX;

enum Choose {
    MANUALLY = 1,
    RANDOM
};

static int input();
static int positive_input();
static void demonstrate_manual();
static void demonstrate_random();

int main() {
    std::cout << "ARRAY PROGRAM\n";
    std::cout << "Variant 13: Three array tasks\n\n";

    std::cout << "Choose mode:\n";
    std::cout << MANUALLY << " - Manual input\n";
    std::cout << RANDOM << " - Random numbers\n"; 
    std::cout << "Your choice: ";

    int choice = input();

    switch (choice) {
    case MANUALLY:
        demonstrate_manual();
        break;
    case RANDOM:
        demonstrate_random();
        break;
    default:
        std::cout << "Error: invalid choice\n";
        return 1;
    }

    std::cout << "\nProgram completed successfully!\n";
    return 0;
}

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

    std::cout << "Enter array size: ";
    int size = positive_input();

    Matrix<int> array(size);

    std::cout << "\nEnter " << size << " elements:\n";

    for (int i = 0; i < size; ++i) {
        std::cout << "Element [" << i << "]: ";
        array[i] = input();
    }

    std::cout << "\nOriginal array: " << array << std::endl;

    std::cout << "TASK 1: Replace last positive element with second element...\n";
    array.replaceLastPositiveWithSecond();
    std::cout << "Result after task 1: " << array << std::endl;

    std::cout << "TASK 2: Insert max element before elements containing digit 1...\n";
    array.insertMaxBeforeOnes();
    std::cout << "Result after task 2: " << array << std::endl;

    std::cout << "TASK 3: Create new array by rules...\n";
    Matrix<int> newArray = array.createNewArray();
    std::cout << "New array (task 3 result): " << newArray << std::endl;
}

static void demonstrate_random() {
    std::cout << "=== RANDOM NUMBER MODE ===\n\n";

    std::cout << "Enter array size: ";
    int size = positive_input();

    std::cout << "Enter min value: ";
    int min = input();

    std::cout << "Enter max value: ";
    int max = input();

    if (min > max) {
        std::cout << "Error: min cannot be greater than max\n";
        return;
    }

    srand(static_cast<unsigned int>(time(0)));
    Matrix<int> array(size);

    for (int i = 0; i < size; ++i) {
        array[i] = min + rand() % (max - min + 1);
    }

    std::cout << "\nOriginal array (filled with random numbers): " << array << std::endl;

    std::cout << "TASK 1: Replace last positive element with second element...\n";
    array.replaceLastPositiveWithSecond();
    std::cout << "Result after task 1: " << array << std::endl;

    std::cout << "TASK 2: Insert max element before elements containing digit 1...\n";
    array.insertMaxBeforeOnes();
    std::cout << "Result after task 2: " << array << std::endl;

    std::cout << "TASK 3: Create new array by rules...\n";
    Matrix<int> newArray = array.createNewArray();
    std::cout << "New array (task 3 result): " << newArray << std::endl;
}
