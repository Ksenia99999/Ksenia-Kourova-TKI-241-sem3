#include <iostream>
#include <memory>
#include <vector>
#include "Medicine.h"
#include "Tablets.h"
#include "Syrup.h"
#include "Apteka.h"

int main() {
    // Создаем аптеку
    Apteka apteka;
    
    // СОЗДАЕМ КОЛЛЕКЦИЮ ОБЪЕКТОВ БАЗОВОГО ТИПА
    std::vector<std::shared_ptr<Medicine>> medicinesCollection;
    
    // СОЗДАЕМ ОБЪЕКТЫ ТИПОВ-НАСЛЕДНИКОВ
    
    // 1. Таблетки (наследник Medicine)
    auto tablets1 = std::make_shared<Tablets>(
        "Парацетамол",
        "таблетки",
        "2025-12-31",
        "Жаропонижающее и обезболивающее средство",
        150.0,
        "Фармстандарт",
        std::vector<std::string>{"головная боль", "простуда", "грипп"},
        20,  // количество
        500.0 // дозировка
    );
    
    // 2. Еще таблетки
    auto tablets2 = std::make_shared<Tablets>(
        "Аспирин",
        "таблетки",
        "2024-06-30",
        "Противовоспалительное и обезболивающее",
        120.0,
        "Байер",
        std::vector<std::string>{"головная боль", "воспаление", "жар"},
        30,
        100.0
    );
    
    // 3. Сироп (наследник Medicine)
    auto syrup1 = std::make_shared<Syrup>(
        "Амбробене",
        "сироп",
        "2024-09-15",
        "Муколитическое средство при кашле",
        280.0,
        "Меркле",
        std::vector<std::string>{"кашель", "бронхит", "простуда"},
        100.0, // объем
        "малиновый" // вкус
    );
    
    // 4. Еще сироп
    auto syrup2 = std::make_shared<Syrup>(
        "Нурофен",
        "суспензия",
        "2024-11-20",
        "Жаропонижающее для детей",
        320.0,
        "Рекитт Бенкизер",
        std::vector<std::string>{"жар", "простуда", "зубная боль"},
        150.0,
        "апельсиновый"
    );
    
    // ЗАПОЛНЯЕМ КОЛЛЕКЦИЮ БАЗОВОГО ТИПА объектами наследников
    medicinesCollection.push_back(tablets1);
    medicinesCollection.push_back(tablets2);
    medicinesCollection.push_back(syrup1);
    medicinesCollection.push_back(syrup2);
    
    // Также добавляем в аптеку
    apteka.addMedicine(tablets1);
    apteka.addMedicine(tablets2);
    apteka.addMedicine(syrup1);
    apteka.addMedicine(syrup2);
    
    // Добавляем продажи для демонстрации
    apteka.addSale(tablets1, "2024-01-05", 5);
    apteka.addSale(tablets1, "2024-01-06", 3);
    apteka.addSale(syrup1, "2024-01-07", 2);
    apteka.addSale(tablets2, "2024-01-08", 4);
    
    std::cout << "=== ДЕМОНСТРАЦИОННАЯ ПРОГРАММА 'АПТЕКА' ===\n" << std::endl;
    
    // ПРОИТЕРИРУЕМ КОЛЛЕКЦИЮ КАК КОЛЛЕКЦИЮ БАЗОВОГО КЛАССА
    std::cout << "1. ВЫВОД ВСЕХ ЛЕКАРСТВ (полиморфно через базовый класс):\n" 
              << std::endl;
    
    for (const auto& medicine : medicinesCollection) {
        // Вызываем метод базового класса (но работает полиморфно!)
        std::cout << medicine->getInfo() << std::endl;
    }
    
    std::cout << "\n" << std::string(50, '=') << "\n" << std::endl;
    
    // === ВЫПОЛНЕНИЕ ЗАДАНИЙ ИЗ ТЕХНИЧЕСКОГО ЗАДАНИЯ ===
    
    // ЗАДАНИЕ 1: Выдавать данные о лекарствах
    std::cout << "2. ЗАДАНИЕ 1: ДАННЫЕ О ВСЕХ ЛЕКАРСТВАХ:\n" << std::endl;
    auto allMedicines = apteka.getAllMedicines();
    for (const auto& med : allMedicines) {
        std::cout << "Название: " << med->getName() << std::endl;
        std::cout << "Форма: " << med->getForm() << std::endl;
        std::cout << "Срок годности: " << med->getExpirationDate() << std::endl;
        std::cout << "Аннотация: " << med->getAnnotation() << std::endl;
        std::cout << "Цена: " << med->getPrice() << " руб." << std::endl;
        std::cout << "Изготовитель: " << med->getManufacturer() << std::endl;
        std::cout << "---" << std::endl;
    }
    
    std::cout << "\n" << std::string(50, '=') << "\n" << std::endl;
    
    // ЗАДАНИЕ 2: Продажи за период
    std::cout << "3. ЗАДАНИЕ 2: ИНФОРМАЦИЯ О ПРОДАЖАХ:\n" << std::endl;
    
    auto reportWeek = apteka.getSalesReport("Парацетамол", "неделя");
    std::cout << "Продажи 'Парацетамол' за неделю:" << std::endl;
    std::cout << "  Количество: " << reportWeek.totalQuantity << " упаковок" << std::endl;
    std::cout << "  Выручка: " << reportWeek.totalRevenue << " руб." << std::endl;
    
    auto reportMonth = apteka.getSalesReport("Амбробене", "месяц");
    std::cout << "\nПродажи 'Амбробене' за месяц:" << std::endl;
    std::cout << "  Количество: " << reportMonth.totalQuantity << " упаковок" << std::endl;
    std::cout << "  Выручка: " << reportMonth.totalRevenue << " руб." << std::endl;
    
    std::cout << "\n" << std::string(50, '=') << "\n" << std::endl;
    
    // ЗАДАНИЕ 3: Лекарства для болезни
    std::cout << "4. ЗАДАНИЕ 3: ЛЕКАРСТВА ДЛЯ БОЛЕЗНИ 'ПРОСТУДА':\n" << std::endl;
    
    auto coldMedicines = apteka.getMedicinesForDisease("простуда");
    if (coldMedicines.empty()) {
        std::cout << "Лекарства от простуды не найдены." << std::endl;
    } else {
        std::cout << "Найдено " << coldMedicines.size() << " лекарств:\n" << std::endl;
        for (const auto& med : coldMedicines) {
            std::cout << "- " << med->getName() << " (" << med->getForm() << ")" 
                      << ", Цена: " << med->getPrice() << " руб." << std::endl;
        }
    }
    
    std::cout << "\n" << std::string(50, '=') << "\n" << std::endl;
    
    std::cout << "5. ЛЕКАРСТВА ДЛЯ БОЛЕЗНИ 'ГОЛОВНАЯ БОЛЬ':\n" << std::endl;
    
    auto headacheMedicines = apteka.getMedicinesForDisease("головная боль");
    if (headacheMedicines.empty()) {
        std::cout << "Лекарства от головной боли не найдены." << std::endl;
    } else {
        std::cout << "Найдено " << headacheMedicines.size() << " лекарств:\n" << std::endl;
        for (const auto& med : headacheMedicines) {
            std::cout << "- " << med->getName() << " (" << med->getForm() << ")" 
                      << ", Цена: " << med->getPrice() << " руб." << std::endl;
        }
    }
    
    std::cout << "\n" << std::string(50, '=') << "\n" << std::endl;
    
    // Демонстрация работы с конкретными типами
    std::cout << "6. ДОПОЛНИТЕЛЬНО: РАБОТА С КОНКРЕТНЫМИ ТИПАМИ:\n" << std::endl;
    
    std::cout << "Все таблетки в аптеке:" << std::endl;
    for (const auto& med : medicinesCollection) {
        if (auto tablets = std::dynamic_pointer_cast<Tablets>(med)) {
            std::cout << "  " << tablets->getName() 
                      << ", Дозировка: " << tablets->getDosage() << " мг"
                      << ", Количество в упаковке: " << tablets->getCount() << " шт." 
                      << std::endl;
        }
    }
    
    std::cout << "\nВсе сиропы в аптеке:" << std::endl;
    for (const auto& med : medicinesCollection) {
        if (auto syrup = std::dynamic_pointer_cast<Syrup>(med)) {
            std::cout << "  " << syrup->getName() 
                      << ", Объем: " << syrup->getVolume() << " мл"
                      << ", Вкус: " << syrup->getFlavor()
                      << std::endl;
        }
    }
    
    std::cout << "\nПРОГРАММА ЗАВЕРШЕНА" << std::endl;
    
    return 0;
}
