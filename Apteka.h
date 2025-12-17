#pragma once
#include "Medicine.h"
#include "Sale.h"
#include <vector>
#include <memory>
#include <string>

class Apteka {
private:
    std::vector<std::shared_ptr<Medicine>> medicines;  // Все лекарства
    std::vector<std::shared_ptr<Sale>> sales;          // Все продажи

public:
    // Добавление лекарств
    void addMedicine(const std::shared_ptr<Medicine>& medicine);
    
    // Регистрация продажи
    void addSale(const std::shared_ptr<Medicine>& medicine, 
                 const std::string& date, int quantity);
    
    // === МЕТОДЫ ПО ЗАДАНИЮ ===
    
    // 1. Выдавать данные о лекарствах
    std::vector<std::shared_ptr<Medicine>> getAllMedicines() const;
    std::vector<std::string> getAllMedicineInfo() const;
    
    // 2. Выдавать информацию о продажах за период
    struct SalesReport {
        std::string medicineName;
        int totalQuantity;
        double totalRevenue;
    };
    
    SalesReport getSalesReport(const std::string& medicineName,
                               const std::string& period) const;
    
    // 3. Выдавать список лекарств для болезни
    std::vector<std::shared_ptr<Medicine>> getMedicinesForDisease(
        const std::string& disease) const;
    
    // Вспомогательные методы
    std::shared_ptr<Medicine> findMedicineByName(const std::string& name) const;
    
    // Получение всех продаж
    const std::vector<std::shared_ptr<Sale>>& getSales() const;
};
