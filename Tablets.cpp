#include "Tablets.h"

Tablets::Tablets(const std::string& name, const std::string& form,
    const std::string& expirationDate, const std::string& annotation,
    double price, const std::string& manufacturer,
    const std::vector<std::string>& diseases,
    int count, double dosage)
    : Medicine(name, form, expirationDate, annotation, price, manufacturer, diseases),
    count(count), dosage(dosage) {}

int Tablets::getCount() const { return count; }
double Tablets::getDosage() const { return dosage; }

std::string Tablets::getInfo() const {
    return Medicine::getInfo() +
        ", §´§Ú§á: §´§Ñ§Ò§Ý§Ö§ä§Ü§Ú" +
        ", §¬§à§Ý§Ú§é§Ö§ã§ä§Ó§à: " + std::to_string(count) + " §ê§ä." +
        ", §¥§à§Ù§Ú§â§à§Ó§Ü§Ñ: " + std::to_string(dosage) + " §Þ§Ô";
}