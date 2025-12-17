#include "Apteka.h"
#include <algorithm>

// Добавление лекарства
void Apteka::addMedicine(const std::shared_ptr<Medicine>& medicine) {
    medicines.push_back(medicine);
}

// Добавление продажи
void Apteka::addSale(const std::shared_ptr<Medicine>& medicine, 
                     const std::string& date, int quantity) {
    auto sale = std::make_shared<Sale>(medicine, date, quantity);
    sales.push_back(sale);
}

// 1. Получить все лекарства
std::vector<std::shared_ptr<Medicine>> Apteka::getAllMedicines() const {
    return medicines;
}

// 1. Получить информацию о всех лекарствах
std::vector<std::string> Apteka::getAllMedicineInfo() const {
    std::vector<std::string> info;
    for (const auto& med : medicines) {
        info.push_back(med->getInfo());
    }
    return info;
}

// 2. Отчет по продажам за период
Apteka::SalesReport Apteka::getSalesReport(const std::string& medicineName,
                                           const std::string& period) const {
    SalesReport report{medicineName, 0, 0.0};
    
    // Определяем период
    std::string startDate, endDate;
    if (period == "неделя") {
        // Упрощенная логика - последние 7 дней
        startDate = "2024-01-01"; // Пример
        endDate = "2024-01-07";
    } else if (period == "месяц") {
        startDate = "2024-01-01";
        endDate = "2024-01-31";
    } else if (period == "год") {
        startDate = "2024-01-01";
        endDate = "2024-12-31";
    }
    
    // Считаем продажи
    for (const auto& sale : sales) {
        if (sale->getMedicine()->getName() == medicineName &&
            sale->isInPeriod(startDate, endDate)) {
            report.totalQuantity += sale->getQuantity();
            report.totalRevenue += sale->getTotalPrice();
        }
    }
    
    return report;
}

// 3. Лекарства для болезни
std::vector<std::shared_ptr<Medicine>> Apteka::getMedicinesForDisease(
    const std::string& disease) const {
    
    std::vector<std::shared_ptr<Medicine>> result;
    for (const auto& med : medicines) {
        if (med->isForDisease(disease)) {
            result.push_back(med);
        }
    }
    return result;
}

// Поиск лекарства по имени
std::shared_ptr<Medicine> Apteka::findMedicineByName(const std::string& name) const {
    for (const auto& med : medicines) {
        if (med->getName() == name) {
            return med;
        }
    }
    return nullptr;
}

// Получить все продажи
const std::vector<std::shared_ptr<Sale>>& Apteka::getSales() const {
    return sales;
}
