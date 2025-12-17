#pragma once
#include "Medicine.h"

// §´§Ñ§Ò§Ý§Ö§ä§Ü§Ú - §Ü§à§ß§Ü§â§Ö§ä§ß§í§Û §ä§Ú§á §Ý§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ
class Tablets : public Medicine {
private:
    int count;          // §¬§à§Ý§Ú§é§Ö§ã§ä§Ó§à §ä§Ñ§Ò§Ý§Ö§ä§à§Ü
    double dosage;      // §¥§à§Ù§Ú§â§à§Ó§Ü§Ñ (§Þ§Ô)

public:
    Tablets(const std::string& name, const std::string& form,
        const std::string& expirationDate, const std::string& annotation,
        double price, const std::string& manufacturer,
        const std::vector<std::string>& diseases,
        int count, double dosage);

    // §¤§Ö§ä§ä§Ö§â§í §Õ§Ý§ñ §ã§á§Ö§è§Ú§æ§Ú§é§ß§í§ç §á§à§Ý§Ö§Û
    int getCount() const;
    double getDosage() const;

    // §±§Ö§â§Ö§à§á§â§Ö§Õ§Ö§Ý§Ö§ß§Ú§Ö §Þ§Ö§ä§à§Õ§Ñ
    std::string getInfo() const override;
};