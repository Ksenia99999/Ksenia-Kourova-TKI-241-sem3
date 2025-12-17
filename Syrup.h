#pragma once
#include "Medicine.h"

// Сироп - другой тип лекарства
class Syrup : public Medicine {
private:
    double volume;      // Объем в мл
    std::string flavor; // Вкус

public:
    Syrup(const std::string& name, const std::string& form,
          const std::string& expirationDate, const std::string& annotation,
          double price, const std::string& manufacturer,
          const std::vector<std::string>& diseases,
          double volume, const std::string& flavor);

    // Геттеры
    double getVolume() const;
    std::string getFlavor() const;

    // Переопределение метода
    std::string getInfo() const override;
};
