#include <iostream>
#include <memory>
#include "VariantExercise.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"

using namespace miit_algebra;

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

void demonstrate_manual() {
    std::cout << "Enter array size: ";
    int n = positive_input();

    std::unique_ptr<IStreamGenerator> manual_gen = std::make_unique<IStreamGenerator>();
    VariantExercise exercise(manual_gen.get(), n);

    std::cout << "Original array: " << exercise.get_matrix().to_string() << std::endl;

    exercise.Task1();
    std::cout << "After Task 1: " << exercise.get_matrix().to_string() << std::endl;

    exercise.Task2();
    std::cout << "After Task 2: " << exercise.get_matrix().to_string() << std::endl;

    Matrix result = exercise.Task3();
    std::cout << "Task 3 result: " << result.to_string() << std::endl;
}

void demonstrate_random() {
    std::cout << "Enter array size: ";
    int n = positive_input();

    std::cout << "Enter min value: ";
    int min = input();
    std::cout << "Enter max value: ";
    int max = input();

    if (min > max) {
        std::cout << "Error: min cannot be greater than max\n";
        return;
    }

    std::unique_ptr<RandomGenerator> random_gen = std::make_unique<RandomGenerator>(min, max);
    VariantExercise exercise(random_gen.get(), n);

    std::cout << "Original array: " << exercise.get_matrix().to_string() << std::endl;

    exercise.Task1();
    std::cout << "After Task 1: " << exercise.get_matrix().to_string() << std::endl;

    exercise.Task2();
    std::cout << "After Task 2: " << exercise.get_matrix().to_string() << std::endl;

    Matrix result = exercise.Task3();
    std::cout << "Task 3 result: " << result.to_string() << std::endl;
}

int main() {
    std::cout << "Choose input method:\n";
    std::cout << "1 - manually\n";
    std::cout << "2 - random\n";
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

    return 0;
}