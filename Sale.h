#pragma once
#include <string>
#include <memory>
#include "Medicine.h"

// §±§â§à§Õ§Ñ§Ø§Ñ §Ý§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ
class Sale {
private:
    std::shared_ptr<Medicine> medicine;
    std::string date;           // §¥§Ñ§ä§Ñ §á§â§à§Õ§Ñ§Ø§Ú 
    int quantity;               // §¬§à§Ý§Ú§é§Ö§ã§ä§Ó§à §á§â§à§Õ§Ñ§ß§ß§à§Ô§à
    double totalPrice;          // §°§Ò§ë§Ñ§ñ §ã§å§Þ§Þ§Ñ

public:
    Sale(std::shared_ptr<Medicine> medicine, const std::string& date, int quantity);

    // §¤§Ö§ä§ä§Ö§â§í
    std::shared_ptr<Medicine> getMedicine() const;
    std::string getDate() const;
    int getQuantity() const;
    double getTotalPrice() const;

    // §±§â§à§Ó§Ö§â§Ü§Ñ, §á§à§á§Ñ§Õ§Ñ§Ö§ä §Ý§Ú §Õ§Ñ§ä§Ñ §Ó §á§Ö§â§Ú§à§Õ
    bool isInPeriod(const std::string& startDate, const std::string& endDate) const;
};