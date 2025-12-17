#pragma once
#include "Medicine.h"
#include "Sale.h"
#include <vector>
#include <memory>
#include <string>

class Apteka {
private:
    std::vector<std::shared_ptr<Medicine>> medicines;  // §£§ã§Ö §Ý§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ
    std::vector<std::shared_ptr<Sale>> sales;          // §£§ã§Ö §á§â§à§Õ§Ñ§Ø§Ú

public:
    // §¥§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö §Ý§Ö§Ü§Ñ§â§ã§ä§Ó
    void addMedicine(const std::shared_ptr<Medicine>& medicine);

    // §²§Ö§Ô§Ú§ã§ä§â§Ñ§è§Ú§ñ §á§â§à§Õ§Ñ§Ø§Ú
    void addSale(const std::shared_ptr<Medicine>& medicine,
        const std::string& date, int quantity);

    // 1. §£§í§Õ§Ñ§Ó§Ñ§ä§î §Õ§Ñ§ß§ß§í§Ö §à §Ý§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ§ç
    std::vector<std::shared_ptr<Medicine>> getAllMedicines() const;
    std::vector<std::string> getAllMedicineInfo() const;

    // 2. §£§í§Õ§Ñ§Ó§Ñ§ä§î §Ú§ß§æ§à§â§Þ§Ñ§è§Ú§ð §à §á§â§à§Õ§Ñ§Ø§Ñ§ç §Ù§Ñ §á§Ö§â§Ú§à§Õ
    struct SalesReport {
        std::string medicineName;
        int totalQuantity;
        double totalRevenue;
    };

    SalesReport getSalesReport(const std::string& medicineName,
        const std::string& period) const;

    // 3. §£§í§Õ§Ñ§Ó§Ñ§ä§î §ã§á§Ú§ã§à§Ü §Ý§Ö§Ü§Ñ§â§ã§ä§Ó §Õ§Ý§ñ §Ò§à§Ý§Ö§Ù§ß§Ú
    std::vector<std::shared_ptr<Medicine>> getMedicinesForDisease(
        const std::string& disease) const;

    // §£§ã§á§à§Þ§à§Ô§Ñ§ä§Ö§Ý§î§ß§í§Ö §Þ§Ö§ä§à§Õ§í
    std::shared_ptr<Medicine> findMedicineByName(const std::string& name) const;

    // §±§à§Ý§å§é§Ö§ß§Ú§Ö §Ó§ã§Ö§ç §á§â§à§Õ§Ñ§Ø
    const std::vector<std::shared_ptr<Sale>>& getSales() const;
};