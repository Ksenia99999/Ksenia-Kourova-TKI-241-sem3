#pragma once
#include <string>
#include <memory>
#include "Medicine.h"

// Запись о продаже лекарства
class Sale {
private:
    std::shared_ptr<Medicine> medicine;
    std::string date;           // Дата продажи (ГГГГ-ММ-ДД)
    int quantity;               // Количество проданного
    double totalPrice;          // Общая сумма

public:
    Sale(std::shared_ptr<Medicine> medicine, const std::string& date, int quantity);
    
    // Геттеры
    std::shared_ptr<Medicine> getMedicine() const;
    std::string getDate() const;
    int getQuantity() const;
    double getTotalPrice() const;
    
    // Проверка, попадает ли дата в период
    bool isInPeriod(const std::string& startDate, const std::string& endDate) const;
};
