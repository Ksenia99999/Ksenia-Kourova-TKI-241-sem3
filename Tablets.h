#pragma once
#include "Medicine.h"

// Таблетки - конкретный тип лекарства
class Tablets : public Medicine {
private:
    int count;          // Количество таблеток
    double dosage;      // Дозировка (мг)

public:
    Tablets(const std::string& name, const std::string& form,
            const std::string& expirationDate, const std::string& annotation,
            double price, const std::string& manufacturer,
            const std::vector<std::string>& diseases,
            int count, double dosage);

    // Геттеры для специфичных полей
    int getCount() const;
    double getDosage() const;

    // Переопределение метода
    std::string getInfo() const override;
};
