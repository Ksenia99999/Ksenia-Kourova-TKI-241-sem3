#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"
#include "Generator.h"
#include "VariantExercise.h"

using namespace MATRIX;

// Режимы работы программы
enum Choose {
    MANUALLY = 1,  // Ручной ввод
    RANDOM,        // Случайные числа
    CONSTANT       // Константные данные
};

// Тестовые данные для константного режима
const int CONSTANT_DATA[] = { 5, -3, 10, 15, -8, 20 };
const size_t CONSTANT_SIZE = 6;

// Прототипы вспомогательных функций
static int input();                // Ввод числа
static int positive_input();       // Ввод положительного числа
static void demonstrate_manual();  // Режим ручного ввода
static void demonstrate_random();  // Режим случайных чисел
static void demonstrate_constant(); // Режим константных данных

int main() {
    std::cout << "ARRAY PROGRAM\n";
    std::cout << "Variant 13: Three array tasks\n\n";
    
    std::cout << "Choose mode:\n";
    std::cout << MANUALLY << " - Manual input\n";
    std::cout << RANDOM << " - Random numbers\n";
    std::cout << CONSTANT << " - Constant data\n";
    std::cout << "Your choice: ";
    
    int choice = input();
    
    switch (choice) {
    case MANUALLY:
        demonstrate_manual();
        break;
    case RANDOM:
        demonstrate_random();
        break;
    case CONSTANT:
        demonstrate_constant();
        break;
    default:
        std::cout << "Error: invalid choice\n";
        return 1;
    }
    
    std::cout << "\nProgram completed successfully!\n";
    return 0;
}

// Функция ввода числа
static int input() {
    int number;
    std::cin >> number;
    return number;
}

// Функция ввода положительного числа
static int positive_input() {
    int number = input();
    if (number <= 0) {
        std::cout << "Error: positive number required\n";
        exit(1);
    }
    return number;
}

// Ручной режим ввода
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
    
    // Задача 1
    std::cout << "TASK 1: Replace last positive element with second element...\n";
    array.replaceLastPositiveWithSecond();
    std::cout << "Result after task 1: " << array << std::endl;
    
    // Задача 2
    std::cout << "TASK 2: Insert max element before elements containing digit 1...\n";
    array.insertMaxBeforeOnes();
    std::cout << "Result after task 2: " << array << std::endl;
    
    // Задача 3
    std::cout << "TASK 3: Create new array by rules...\n";
    Matrix<int> newArray = array.createNewArray();
    std::cout << "New array (task 3 result): " << newArray << std::endl;
}

// Режим случайных чисел
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
    
    // Задача 1
    std::cout << "TASK 1: Replace last positive element with second element...\n";
    array.replaceLastPositiveWithSecond();
    std::cout << "Result after task 1: " << array << std::endl;
    
    // Задача 2
    std::cout << "TASK 2: Insert max element before elements containing digit 1...\n";
    array.insertMaxBeforeOnes();
    std::cout << "Result after task 2: " << array << std::endl;
    
    // Задача 3
    std::cout << "TASK 3: Create new array by rules...\n";
    Matrix<int> newArray = array.createNewArray();
    std::cout << "New array (task 3 result): " << newArray << std::endl;
}

// Режим константных данных
static void demonstrate_constant() {
    std::cout << "=== CONSTANT DATA MODE ===\n\n";
    
    Matrix<int> array(CONSTANT_SIZE);
    for (size_t i = 0; i < CONSTANT_SIZE; ++i) {
        array[i] = CONSTANT_DATA[i];
    }
    
    std::cout << "Original array: " << array << std::endl;
    
    // Задача 1
    std::cout << "TASK 1: Replace last positive element with second element...\n";
    array.replaceLastPositiveWithSecond();
    std::cout << "Result after task 1: " << array << std::endl;
    
    // Задача 2
    std::cout << "TASK 2: Insert max element before elements containing digit 1...\n";
    array.insertMaxBeforeOnes();
    std::cout << "Result after task 2: " << array << std::endl;
    
    // Задача 3
    std::cout << "TASK 3: Create new array by rules...\n";
    Matrix<int> newArray = array.createNewArray();
    std::cout << "New array (task 3 result): " << newArray << std::endl;
}
