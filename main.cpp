#include <iostream>
#include <memory>

#include "Matrix.h"
#include "ConstGenerator.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ZeroGenerator.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"

using namespace MATRIX;

enum class FillMethod {
    KEYBOARD = 1,  // Ручной ввод с клавиатуры
    RANDOM = 2,    // Случайные числа
    CONSTANT = 3,  // Одно константное значение
    ZEROS = 4      // Все нули
};

enum class MenuChoice {
    TASK1 = 1,  // Задание 1
    TASK2 = 2,  // Задание 2
    TASK3 = 3,  // Задание 3
    EXIT = 0    // Выход из программы
};

// Функция выбора способа заполнения матрицы
// Показывает меню и создает соответствующий генератор
std::unique_ptr<Generator> choose_fill_method()
{
    std::cout << "\nВыберите способ заполнения матрицы:\n";
    std::cout << static_cast<int>(FillMethod::KEYBOARD) << ". С клавиатуры\n";
    std::cout << static_cast<int>(FillMethod::RANDOM) << ". Рандомно\n";
    std::cout << static_cast<int>(FillMethod::CONSTANT) << ". Константой\n";
    std::cout << static_cast<int>(FillMethod::ZEROS) << ". Нулями\n";
    std::cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;

    // Создаем генератор в зависимости от выбора пользователя
    switch (static_cast<FillMethod>(choice))
    {
        case FillMethod::KEYBOARD:
            return std::make_unique<IStreamGenerator>(std::cin);
        case FillMethod::RANDOM:
        {
            int min, max;
            std::cout << "Введите минимальное значение: ";
            std::cin >> min;
            std::cout << "Введите максимальное значение: ";
            std::cin >> max;
            return std::make_unique<RandomGenerator>(min, max);
        }
        case FillMethod::CONSTANT:
        {
            int value;
            std::cout << "Введите константное значение: ";
            std::cin >> value;
            return std::make_unique<ConstGenerator>(value);
        }
        case FillMethod::ZEROS:
            return std::make_unique<ZeroGenerator>();
        default:
            std::cout << "Неверный выбор. Используется заполнение с клавиатуры.\n";
            return std::make_unique<IStreamGenerator>(std::cin);
    }
}

// Демонстрация задания 1
// Показывает работу алгоритма замены последнего положительного элемента
void demonstrate_task1() {
    std::cout << "\n=== ЗАДАНИЕ 1 ===\n";
    std::cout << "Замена последнего положительного элемента на второй элемент\n";

    // Запрашиваем размер матрицы
    std::cout << "\nВведите размер матрицы: ";
    size_t size;
    std::cin >> size;

    // Создаем матрицу указанного размера
    auto matrix = std::make_unique<Matrix>(size);

    // Выбираем способ заполнения
    std::cout << "\nВыбор способа заполнения матрицы:\n";
    auto generator = choose_fill_method();

    // Заполняем матрицу с помощью выбранного генератора
    std::cout << "\nЗаполнение матрицы:\n";
    matrix->fill(*generator);

    // Если выбран ручной ввод, показываем что ввели
    if (dynamic_cast<IStreamGenerator*>(generator.get()))
    {
        std::cout << "Матрица заполнена следующими значениями:\n";
        std::cout << matrix->to_string() << std::endl;
    }

    // Создаем упражнение и выполняем его
    Task1Exercise exercise(std::move(matrix), std::move(generator));

    std::cout << "\nИсходная матрица: " << exercise.get_matrix().to_string() << std::endl;
    exercise.task();  // Выполняем задание 1
    std::cout << "Результат: " << exercise.get_matrix().to_string() << std::endl;
}

// Демонстрация задания 2
// Показывает работу алгоритма вставки максимума перед элементами с цифрой 1
void demonstrate_task2() {
    std::cout << "\n=== ЗАДАНИЕ 2 ===\n";
    std::cout << "Вставка максимального элемента перед элементами, содержащими цифру 1\n";

    // Запрашиваем размер матрицы
    std::cout << "\nВведите размер матрицы: ";
    size_t size;
    std::cin >> size;

    // Создаем матрицу указанного размера
    auto matrix = std::make_unique<Matrix>(size);

    // Выбираем способ заполнения
    std::cout << "\nВыбор способа заполнения матрицы:\n";
    auto generator = choose_fill_method();

    // Заполняем матрицу с помощью выбранного генератора
    std::cout << "\nЗаполнение матрицы:\n";
    matrix->fill(*generator);

    // Если выбран ручной ввод, показываем что ввели
    if (dynamic_cast<IStreamGenerator*>(generator.get()))
    {
        std::cout << "Матрица заполнена следующими значениями:\n";
        std::cout << matrix->to_string() << std::endl;
    }

    // Создаем упражнение и выполняем его
    Task2Exercise exercise(std::move(matrix), std::move(generator));

    std::cout << "\nИсходная матрица: " << exercise.get_matrix().to_string() << std::endl;
    exercise.task();  // Выполняем задание 2
    std::cout << "Результат: " << exercise.get_matrix().to_string() << std::endl;
}

// Демонстрация задания 3
// Показывает создание новой матрицы по правилу
void demonstrate_task3() {
    std::cout << "\n=== ЗАДАНИЕ 3 ===\n";
    std::cout << "Создание матрицы M из матрицы P по правилу:\n";
    std::cout << "M_i = i * P_i, если (i+1) кратно 3\n";
    std::cout << "M_i = -P_i * (i+1), в остальных случаях\n";

    // Запрашиваем размер матрицы
    std::cout << "\nВведите размер матрицы: ";
    size_t size;
    std::cin >> size;

    // Создаем матрицу указанного размера
    auto matrix = std::make_unique<Matrix>(size);

    // Выбираем способ заполнения
    std::cout << "\nВыбор способа заполнения матрицы:\n";
    auto generator = choose_fill_method();

    // Заполняем матрицу с помощью выбранного генератора
    std::cout << "\nЗаполнение матрицы:\n";
    matrix->fill(*generator);

    // Если выбран ручной ввод, показываем что ввели
    if (dynamic_cast<IStreamGenerator*>(generator.get()))
    {
        std::cout << "Матрица заполнена следующими значениями:\n";
        std::cout << matrix->to_string() << std::endl;
    }

    // Создаем упражнение и выполняем его
    Task3Exercise exercise(std::move(matrix), std::move(generator));

    std::cout << "\nМатрица P: " << exercise.get_matrix().to_string() << std::endl;
    exercise.task();  // Выполняем задание 3
    std::cout << "Матрица M (результат): " << exercise.get_result().to_string() << std::endl;
}

// Главная функция программы - точка входа
int main() {
    try {
        // Заголовок программы
        std::cout << "ПРОГРАММА ДЛЯ РАБОТЫ С МАССИВАМИ\n";
        std::cout << "Вариант 13: Три задания с массивами\n";

        MenuChoice choice;
        // Основной цикл программы
        do {
            // Показываем главное меню
            std::cout << "\n=== ГЛАВНОЕ МЕНЮ ===\n";
            std::cout << static_cast<int>(MenuChoice::TASK1) << ". Задание 1 (замена последнего положительного)\n";
            std::cout << static_cast<int>(MenuChoice::TASK2) << ". Задание 2 (вставка максимума перед элементами с цифрой 1)\n";
            std::cout << static_cast<int>(MenuChoice::TASK3) << ". Задание 3 (создание новой матрицы)\n";
            std::cout << static_cast<int>(MenuChoice::EXIT) << ". Выход\n";
            std::cout << "Ваш выбор: ";
            
            // Считываем выбор пользователя
            int input;
            std::cin >> input;
            choice = static_cast<MenuChoice>(input);

            // Выполняем выбранное действие
            switch (choice) {
                case MenuChoice::TASK1:
                    demonstrate_task1();  // Задание 1
                    break;
                case MenuChoice::TASK2:
                    demonstrate_task2();  // Задание 2
                    break;
                case MenuChoice::TASK3:
                    demonstrate_task3();  // Задание 3
                    break;
                case MenuChoice::EXIT:
                    std::cout << "Выход из программы.\n";
                    break;
                default:
                    std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        } while (choice != MenuChoice::EXIT);  // Продолжаем пока не выберут выход

        std::cout << "\nПрограмма завершена!\n";

    } catch (const std::exception& e) {
        // Обработка исключений
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;  // Успешное завершение программы
}
