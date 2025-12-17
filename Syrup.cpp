#include "Syrup.h"

Syrup::Syrup(const std::string& name, const std::string& form,
    const std::string& expirationDate, const std::string& annotation,
    double price, const std::string& manufacturer,
    const std::vector<std::string>& diseases,
    double volume, const std::string& flavor)
    : Medicine(name, form, expirationDate, annotation, price, manufacturer, diseases),
    volume(volume), flavor(flavor) {}

double Syrup::getVolume() const { return volume; }
std::string Syrup::getFlavor() const { return flavor; }

std::string Syrup::getInfo() const {
    return Medicine::getInfo() +
        ", §´§Ú§á: §³§Ú§â§à§á" +
        ", §°§Ò§ì§Ö§Þ: " + std::to_string(volume) + " §Þ§Ý" +
        ", §£§Ü§å§ã: " + flavor;
}