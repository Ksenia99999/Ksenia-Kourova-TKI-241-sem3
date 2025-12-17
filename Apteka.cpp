#include "Apteka.h"
#include <algorithm>

// §¥§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö §Ý§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ
void Apteka::addMedicine(const std::shared_ptr<Medicine>& medicine) {
    medicines.push_back(medicine);
}

// §¥§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö §á§â§à§Õ§Ñ§Ø§Ú
void Apteka::addSale(const std::shared_ptr<Medicine>& medicine,
    const std::string& date, int quantity) {
    auto sale = std::make_shared<Sale>(medicine, date, quantity);
    sales.push_back(sale);
}

// 1. §±§à§Ý§å§é§Ú§ä§î §Ó§ã§Ö §Ý§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ
std::vector<std::shared_ptr<Medicine>> Apteka::getAllMedicines() const {
    return medicines;
}

// 1. §±§à§Ý§å§é§Ú§ä§î §Ú§ß§æ§à§â§Þ§Ñ§è§Ú§ð §à §Ó§ã§Ö§ç §Ý§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ§ç
std::vector<std::string> Apteka::getAllMedicineInfo() const {
    std::vector<std::string> info;
    for (const auto& med : medicines) {
        info.push_back(med->getInfo());
    }
    return info;
}

// 2. §°§ä§é§Ö§ä §á§à §á§â§à§Õ§Ñ§Ø§Ñ§Þ §Ù§Ñ §á§Ö§â§Ú§à§Õ
Apteka::SalesReport Apteka::getSalesReport(const std::string& medicineName,
    const std::string& period) const {
    SalesReport report{ medicineName, 0, 0.0 };

    // §°§á§â§Ö§Õ§Ö§Ý§ñ§Ö§Þ §á§Ö§â§Ú§à§Õ
    std::string startDate, endDate;
    if (period == "§ß§Ö§Õ§Ö§Ý§ñ") {
        // §µ§á§â§à§ë§Ö§ß§ß§Ñ§ñ §Ý§à§Ô§Ú§Ü§Ñ - §á§à§ã§Ý§Ö§Õ§ß§Ú§Ö 7 §Õ§ß§Ö§Û
        startDate = "2025-01-01"; // §±§â§Ú§Þ§Ö§â
        endDate = "2025-01-07";
    }
    else if (period == "§Þ§Ö§ã§ñ§è") {
        startDate = "2025-01-01";
        endDate = "2025-01-31";
    }
    else if (period == "§Ô§à§Õ") {
        startDate = "2025-01-01";
        endDate = "202-12-31";
    }

    // §³§é§Ú§ä§Ñ§Ö§Þ §á§â§à§Õ§Ñ§Ø§Ú
    for (const auto& sale : sales) {
        if (sale->getMedicine()->getName() == medicineName &&
            sale->isInPeriod(startDate, endDate)) {
            report.totalQuantity += sale->getQuantity();
            report.totalRevenue += sale->getTotalPrice();
        }
    }

    return report;
}

// 3. §­§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ §Õ§Ý§ñ §Ò§à§Ý§Ö§Ù§ß§Ú
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

// §±§à§Ú§ã§Ü §Ý§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ §á§à §Ú§Þ§Ö§ß§Ú
std::shared_ptr<Medicine> Apteka::findMedicineByName(const std::string& name) const {
    for (const auto& med : medicines) {
        if (med->getName() == name) {
            return med;
        }
    }
    return nullptr;
}

// §±§à§Ý§å§é§Ú§ä§î §Ó§ã§Ö §á§â§à§Õ§Ñ§Ø§Ú
const std::vector<std::shared_ptr<Sale>>& Apteka::getSales() const {
    return sales;
}