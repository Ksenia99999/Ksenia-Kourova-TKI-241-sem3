#include "Medicine.h"

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â
Medicine::Medicine(const std::string& name, const std::string& form,
    const std::string& expirationDate, const std::string& annotation,
    double price, const std::string& manufacturer,
    const std::vector<std::string>& diseases)
    : name(name), form(form), expirationDate(expirationDate),
    annotation(annotation), price(price), manufacturer(manufacturer),
    diseases(diseases) {}

// §¤§Ö§ä§ä§Ö§â§í
std::string Medicine::getName() const { return name; }
std::string Medicine::getForm() const { return form; }
std::string Medicine::getExpirationDate() const { return expirationDate; }
std::string Medicine::getAnnotation() const { return annotation; }
double Medicine::getPrice() const { return price; }
std::string Medicine::getManufacturer() const { return manufacturer; }
std::vector<std::string> Medicine::getDiseases() const { return diseases; }

bool Medicine::isForDisease(const std::string& disease) const {
    for (const auto& d : diseases) {
        if (d.find(disease) != std::string::npos ||
            disease.find(d) != std::string::npos) {
            return true;
        }
    }
    return false;
}

std::string Medicine::getInfo() const {
    return "§­§Ö§Ü§Ñ§â§ã§ä§Ó§à: " + name +
        ", §¶§à§â§Þ§Ñ: " + form +
        ", §¸§Ö§ß§Ñ: " + std::to_string(price) + " §â§å§Ò.";
}