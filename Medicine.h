#pragma once
#include <string>
#include <vector>
#include <memory>

// §¢§Ñ§Ù§à§Ó§í§Û §Ü§Ý§Ñ§ã§ã §­§Ö§Ü§Ñ§â§ã§ä§Ó§à
class Medicine {
protected:
    std::string name;           // §¯§Ñ§Ù§Ó§Ñ§ß§Ú§Ö
    std::string form;           // §¶§à§â§Þ§Ñ §Ó§í§á§å§ã§Ü§Ñ (§ä§Ñ§Ò§Ý§Ö§ä§Ü§Ú, §ã§Ú§â§à§á §Ú §ä.§Õ.)
    std::string expirationDate; // §³§â§à§Ü §Ô§à§Õ§ß§à§ã§ä§Ú
    std::string annotation;     // §¡§ß§ß§à§ä§Ñ§è§Ú§ñ (§à§á§Ú§ã§Ñ§ß§Ú§Ö, §á§à§Ü§Ñ§Ù§Ñ§ß§Ú§ñ)
    double price;               // §¸§Ö§ß§Ñ
    std::string manufacturer;   // §ª§Ù§Ô§à§ä§à§Ó§Ú§ä§Ö§Ý§î
    std::vector<std::string> diseases; // §¢§à§Ý§Ö§Ù§ß§Ú, §Õ§Ý§ñ §Ü§à§ä§à§â§í§ç §á§â§Ú§Þ§Ö§ß§ñ§Ö§ä§ã§ñ

public:
    // §¬§à§ß§ã§ä§â§å§Ü§ä§à§â
    Medicine(const std::string& name, const std::string& form,
        const std::string& expirationDate, const std::string& annotation,
        double price, const std::string& manufacturer,
        const std::vector<std::string>& diseases = {});

    // §£§Ú§â§ä§å§Ñ§Ý§î§ß§í§Û §Õ§Ö§ã§ä§â§å§Ü§ä§à§â §Õ§Ý§ñ §á§à§Ý§Ú§Þ§à§â§æ§Ú§Ù§Þ§Ñ
    virtual ~Medicine() = default;

    // §¤§Ö§ä§ä§Ö§â§í
    std::string getName() const;
    std::string getForm() const;
    std::string getExpirationDate() const;
    std::string getAnnotation() const;
    double getPrice() const;
    std::string getManufacturer() const;
    std::vector<std::string> getDiseases() const;

    // §±§â§à§Ó§Ö§â§Ü§Ñ, §á§â§Ú§Þ§Ö§ß§ñ§Ö§ä§ã§ñ §Ý§Ú §Õ§Ý§ñ §Ò§à§Ý§Ö§Ù§ß§Ú
    bool isForDisease(const std::string& disease) const;

    // §£§Ú§â§ä§å§Ñ§Ý§î§ß§í§Û §Þ§Ö§ä§à§Õ §Õ§Ý§ñ §á§à§Ý§å§é§Ö§ß§Ú§ñ §Ú§ß§æ§à§â§Þ§Ñ§è§Ú§Ú (§Ò§Ö§Ù §Ó§í§Ó§à§Õ§Ñ!)
    virtual std::string getInfo() const;
};