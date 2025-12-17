#pragma once
#include <string>
#include <vector>
#include <memory>

// Базовый класс для всех лекарств
class Medicine {
protected:
    std::string name;           // Название лекарства
    std::string form;           // Форма выпуска (таблетки, сироп и т.д.)
    std::string expirationDate; // Срок годности
    std::string annotation;     // Описание/показания
    double price;               // Цена
    std::string manufacturer;   // Производитель
    std::vector<std::string> diseases; // Болезни, которые лечит

public:
    // Конструктор
    Medicine(const std::string& name, const std::string& form,
             const std::string& expirationDate, const std::string& annotation,
             double price, const std::string& manufacturer,
             const std::vector<std::string>& diseases = {});

    // Виртуальный деструктор для полиморфизма
    virtual ~Medicine() = default;

    // Геттеры
    std::string getName() const;
    std::string getForm() const;
    std::string getExpirationDate() const;
    std::string getAnnotation() const;
    double getPrice() const;
    std::string getManufacturer() const;
    std::vector<std::string> getDiseases() const;

    // Проверка, лечит ли лекарство конкретную болезнь
    bool isForDisease(const std::string& disease) const;

    // Виртуальный метод для получения информации
    virtual std::string getInfo() const;
};
