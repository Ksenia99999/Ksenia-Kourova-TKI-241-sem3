#include <iostream>
#include <memory>
#include <vector>
#include "Medicine.h"
#include "Tablets.h"
#include "Syrup.h"
#include "Apteka.h"

int main() {
    // §³§à§Ù§Õ§Ñ§Ö§Þ §Ñ§á§ä§Ö§Ü§å
    Apteka apteka;

    // §³§°§©§¥§¡§¦§® §¬§°§­§­§¦§¬§¸§ª§À §°§¢§¼§¦§¬§´§°§£ §¢§¡§©§°§£§°§¤§° §´§ª§±§¡
    std::vector<std::shared_ptr<Medicine>> medicinesCollection;

    // §³§°§©§¥§¡§¦§® §°§¢§¼§¦§¬§´§½ §´§ª§±§°§£-§¯§¡§³§­§¦§¥§¯§ª§¬§°§£

    // 1. §´§Ñ§Ò§Ý§Ö§ä§Ü§Ú (§ß§Ñ§ã§Ý§Ö§Õ§ß§Ú§Ü Medicine)
    auto tablets1 = std::make_shared<Tablets>(
        "§±§Ñ§â§Ñ§è§Ö§ä§Ñ§Þ§à§Ý",
        "§ä§Ñ§Ò§Ý§Ö§ä§Ü§Ú",
        "2025-12-31",
        "§¨§Ñ§â§à§á§à§ß§Ú§Ø§Ñ§ð§ë§Ö§Ö §Ú §à§Ò§Ö§Ù§Ò§à§Ý§Ú§Ó§Ñ§ð§ë§Ö§Ö §ã§â§Ö§Õ§ã§ä§Ó§à",
        150.0,
        "§¶§Ñ§â§Þ§ã§ä§Ñ§ß§Õ§Ñ§â§ä",
        std::vector<std::string>{"§Ô§à§Ý§à§Ó§ß§Ñ§ñ §Ò§à§Ý§î", "§á§â§à§ã§ä§å§Õ§Ñ", "§Ô§â§Ú§á§á"},
        20,  // §Ü§à§Ý§Ú§é§Ö§ã§ä§Ó§à
        500.0 // §Õ§à§Ù§Ú§â§à§Ó§Ü§Ñ
    );

    // 2. §¦§ë§Ö §ä§Ñ§Ò§Ý§Ö§ä§Ü§Ú
    auto tablets2 = std::make_shared<Tablets>(
        "§¡§ã§á§Ú§â§Ú§ß",
        "§ä§Ñ§Ò§Ý§Ö§ä§Ü§Ú",
        "2025-06-30",
        "§±§â§à§ä§Ú§Ó§à§Ó§à§ã§á§Ñ§Ý§Ú§ä§Ö§Ý§î§ß§à§Ö §Ú §à§Ò§Ö§Ù§Ò§à§Ý§Ú§Ó§Ñ§ð§ë§Ö§Ö",
        120.0,
        "§¢§Ñ§Û§Ö§â",
        std::vector<std::string>{"§Ô§à§Ý§à§Ó§ß§Ñ§ñ §Ò§à§Ý§î", "§Ó§à§ã§á§Ñ§Ý§Ö§ß§Ú§Ö", "§Ø§Ñ§â"},
        30,
        100.0
    );

    // 3. §³§Ú§â§à§á (§ß§Ñ§ã§Ý§Ö§Õ§ß§Ú§Ü Medicine)
    auto syrup1 = std::make_shared<Syrup>(
        "§¡§Þ§Ò§â§à§Ò§Ö§ß§Ö",
        "§ã§Ú§â§à§á",
        "2025-09-15",
        "§®§å§Ü§à§Ý§Ú§ä§Ú§é§Ö§ã§Ü§à§Ö §ã§â§Ö§Õ§ã§ä§Ó§à §á§â§Ú §Ü§Ñ§ê§Ý§Ö",
        280.0,
        "§®§Ö§â§Ü§Ý§Ö",
        std::vector<std::string>{"§Ü§Ñ§ê§Ö§Ý§î", "§Ò§â§à§ß§ç§Ú§ä", "§á§â§à§ã§ä§å§Õ§Ñ"},
        100.0, // §à§Ò§ì§Ö§Þ
        "§Þ§Ñ§Ý§Ú§ß§à§Ó§í§Û" // §Ó§Ü§å§ã
    );

    // 4. §¦§ë§Ö §ã§Ú§â§à§á
    auto syrup2 = std::make_shared<Syrup>(
        "§¯§å§â§à§æ§Ö§ß",
        "§ã§å§ã§á§Ö§ß§Ù§Ú§ñ",
        "2025-11-20",
        "§¨§Ñ§â§à§á§à§ß§Ú§Ø§Ñ§ð§ë§Ö§Ö §Õ§Ý§ñ §Õ§Ö§ä§Ö§Û",
        320.0,
        "§²§Ö§Ü§Ú§ä§ä §¢§Ö§ß§Ü§Ú§Ù§Ö§â",
        std::vector<std::string>{"§Ø§Ñ§â", "§á§â§à§ã§ä§å§Õ§Ñ", "§Ù§å§Ò§ß§Ñ§ñ §Ò§à§Ý§î"},
        150.0,
        "§Ñ§á§Ö§Ý§î§ã§Ú§ß§à§Ó§í§Û"
    );

    // §©§¡§±§°§­§¯§Á§¦§® §¬§°§­§­§¦§¬§¸§ª§À §¢§¡§©§°§£§°§¤§° §´§ª§±§¡ §à§Ò§ì§Ö§Ü§ä§Ñ§Þ§Ú §ß§Ñ§ã§Ý§Ö§Õ§ß§Ú§Ü§à§Ó
    medicinesCollection.push_back(tablets1);
    medicinesCollection.push_back(tablets2);
    medicinesCollection.push_back(syrup1);
    medicinesCollection.push_back(syrup2);

    // §´§Ñ§Ü§Ø§Ö §Õ§à§Ò§Ñ§Ó§Ý§ñ§Ö§Þ §Ó §Ñ§á§ä§Ö§Ü§å
    apteka.addMedicine(tablets1);
    apteka.addMedicine(tablets2);
    apteka.addMedicine(syrup1);
    apteka.addMedicine(syrup2);

    // §¥§à§Ò§Ñ§Ó§Ý§ñ§Ö§Þ §á§â§à§Õ§Ñ§Ø§Ú §Õ§Ý§ñ §Õ§Ö§Þ§à§ß§ã§ä§â§Ñ§è§Ú§Ú
    apteka.addSale(tablets1, "2024-01-05", 5);
    apteka.addSale(tablets1, "2024-01-06", 3);
    apteka.addSale(syrup1, "2024-01-07", 2);
    apteka.addSale(tablets2, "2024-01-08", 4);

    std::cout << "=== §¥§¦§®§°§¯§³§´§²§¡§¸§ª§°§¯§¯§¡§Á §±§²§°§¤§²§¡§®§®§¡ '§¡§±§´§¦§¬§¡' ===\n" << std::endl;

    // §±§²§°§ª§´§¦§²§ª§²§µ§¦§® §¬§°§­§­§¦§¬§¸§ª§À §¬§¡§¬ §¬§°§­§­§¦§¬§¸§ª§À §¢§¡§©§°§£§°§¤§° §¬§­§¡§³§³§¡
    std::cout << "1. §£§½§£§°§¥ §£§³§¦§· §­§¦§¬§¡§²§³§´§£ (§á§à§Ý§Ú§Þ§à§â§æ§ß§à §é§Ö§â§Ö§Ù §Ò§Ñ§Ù§à§Ó§í§Û §Ü§Ý§Ñ§ã§ã):\n"
        << std::endl;

    for (const auto& medicine : medicinesCollection) {
        // §£§í§Ù§í§Ó§Ñ§Ö§Þ §Þ§Ö§ä§à§Õ §Ò§Ñ§Ù§à§Ó§à§Ô§à §Ü§Ý§Ñ§ã§ã§Ñ (§ß§à §â§Ñ§Ò§à§ä§Ñ§Ö§ä §á§à§Ý§Ú§Þ§à§â§æ§ß§à!)
        std::cout << medicine->getInfo() << std::endl;
    }

    std::cout << "\n" << std::string(50, '=') << "\n" << std::endl;

    // === §£§½§±§°§­§¯§¦§¯§ª§¦ §©§¡§¥§¡§¯§ª§« §ª§© §´§¦§·§¯§ª§¹§¦§³§¬§°§¤§° §©§¡§¥§¡§¯§ª§Á ===

    // §©§¡§¥§¡§¯§ª§¦ 1: §£§í§Õ§Ñ§Ó§Ñ§ä§î §Õ§Ñ§ß§ß§í§Ö §à §Ý§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ§ç
    std::cout << "2. §©§¡§¥§¡§¯§ª§¦ 1: §¥§¡§¯§¯§½§¦ §° §£§³§¦§· §­§¦§¬§¡§²§³§´§£§¡§·:\n" << std::endl;
    auto allMedicines = apteka.getAllMedicines();
    for (const auto& med : allMedicines) {
        std::cout << "§¯§Ñ§Ù§Ó§Ñ§ß§Ú§Ö: " << med->getName() << std::endl;
        std::cout << "§¶§à§â§Þ§Ñ: " << med->getForm() << std::endl;
        std::cout << "§³§â§à§Ü §Ô§à§Õ§ß§à§ã§ä§Ú: " << med->getExpirationDate() << std::endl;
        std::cout << "§¡§ß§ß§à§ä§Ñ§è§Ú§ñ: " << med->getAnnotation() << std::endl;
        std::cout << "§¸§Ö§ß§Ñ: " << med->getPrice() << " §â§å§Ò." << std::endl;
        std::cout << "§ª§Ù§Ô§à§ä§à§Ó§Ú§ä§Ö§Ý§î: " << med->getManufacturer() << std::endl;
        std::cout << "---" << std::endl;
    }

    std::cout << "\n" << std::string(50, '=') << "\n" << std::endl;

    // §©§¡§¥§¡§¯§ª§¦ 2: §±§â§à§Õ§Ñ§Ø§Ú §Ù§Ñ §á§Ö§â§Ú§à§Õ
    std::cout << "3. §©§¡§¥§¡§¯§ª§¦ 2: §ª§¯§¶§°§²§®§¡§¸§ª§Á §° §±§²§°§¥§¡§¨§¡§·:\n" << std::endl;

    auto reportWeek = apteka.getSalesReport("§±§Ñ§â§Ñ§è§Ö§ä§Ñ§Þ§à§Ý", "§ß§Ö§Õ§Ö§Ý§ñ");
    std::cout << "§±§â§à§Õ§Ñ§Ø§Ú '§±§Ñ§â§Ñ§è§Ö§ä§Ñ§Þ§à§Ý' §Ù§Ñ §ß§Ö§Õ§Ö§Ý§ð:" << std::endl;
    std::cout << "  §¬§à§Ý§Ú§é§Ö§ã§ä§Ó§à: " << reportWeek.totalQuantity << " §å§á§Ñ§Ü§à§Ó§à§Ü" << std::endl;
    std::cout << "  §£§í§â§å§é§Ü§Ñ: " << reportWeek.totalRevenue << " §â§å§Ò." << std::endl;

    auto reportMonth = apteka.getSalesReport("§¡§Þ§Ò§â§à§Ò§Ö§ß§Ö", "§Þ§Ö§ã§ñ§è");
    std::cout << "\n§±§â§à§Õ§Ñ§Ø§Ú '§¡§Þ§Ò§â§à§Ò§Ö§ß§Ö' §Ù§Ñ §Þ§Ö§ã§ñ§è:" << std::endl;
    std::cout << "  §¬§à§Ý§Ú§é§Ö§ã§ä§Ó§à: " << reportMonth.totalQuantity << " §å§á§Ñ§Ü§à§Ó§à§Ü" << std::endl;
    std::cout << "  §£§í§â§å§é§Ü§Ñ: " << reportMonth.totalRevenue << " §â§å§Ò." << std::endl;

    std::cout << "\n" << std::string(50, '=') << "\n" << std::endl;

    // §©§¡§¥§¡§¯§ª§¦ 3: §­§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ §Õ§Ý§ñ §Ò§à§Ý§Ö§Ù§ß§Ú
    std::cout << "4. §©§¡§¥§¡§¯§ª§¦ 3: §­§¦§¬§¡§²§³§´§£§¡ §¥§­§Á §¢§°§­§¦§©§¯§ª '§±§²§°§³§´§µ§¥§¡':\n" << std::endl;

    auto coldMedicines = apteka.getMedicinesForDisease("§á§â§à§ã§ä§å§Õ§Ñ");
    if (coldMedicines.empty()) {
        std::cout << "§­§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ §à§ä §á§â§à§ã§ä§å§Õ§í §ß§Ö §ß§Ñ§Û§Õ§Ö§ß§í." << std::endl;
    }
    else {
        std::cout << "§¯§Ñ§Û§Õ§Ö§ß§à " << coldMedicines.size() << " §Ý§Ö§Ü§Ñ§â§ã§ä§Ó:\n" << std::endl;
        for (const auto& med : coldMedicines) {
            std::cout << "- " << med->getName() << " (" << med->getForm() << ")"
                << ", §¸§Ö§ß§Ñ: " << med->getPrice() << " §â§å§Ò." << std::endl;
        }
    }

    std::cout << "\n" << std::string(50, '=') << "\n" << std::endl;

    std::cout << "5. §­§¦§¬§¡§²§³§´§£§¡ §¥§­§Á §¢§°§­§¦§©§¯§ª '§¤§°§­§°§£§¯§¡§Á §¢§°§­§¾':\n" << std::endl;

    auto headacheMedicines = apteka.getMedicinesForDisease("§Ô§à§Ý§à§Ó§ß§Ñ§ñ §Ò§à§Ý§î");
    if (headacheMedicines.empty()) {
        std::cout << "§­§Ö§Ü§Ñ§â§ã§ä§Ó§Ñ §à§ä §Ô§à§Ý§à§Ó§ß§à§Û §Ò§à§Ý§Ú §ß§Ö §ß§Ñ§Û§Õ§Ö§ß§í." << std::endl;
    }
    else {
        std::cout << "§¯§Ñ§Û§Õ§Ö§ß§à " << headacheMedicines.size() << " §Ý§Ö§Ü§Ñ§â§ã§ä§Ó:\n" << std::endl;
        for (const auto& med : headacheMedicines) {
            std::cout << "- " << med->getName() << " (" << med->getForm() << ")"
                << ", §¸§Ö§ß§Ñ: " << med->getPrice() << " §â§å§Ò." << std::endl;
        }
    }

    std::cout << "\n" << std::string(50, '=') << "\n" << std::endl;

    // §¥§Ö§Þ§à§ß§ã§ä§â§Ñ§è§Ú§ñ §â§Ñ§Ò§à§ä§í §ã §Ü§à§ß§Ü§â§Ö§ä§ß§í§Þ§Ú §ä§Ú§á§Ñ§Þ§Ú
    std::cout << "6. §¥§°§±§°§­§¯§ª§´§¦§­§¾§¯§°: §²§¡§¢§°§´§¡ §³ §¬§°§¯§¬§²§¦§´§¯§½§®§ª §´§ª§±§¡§®§ª:\n" << std::endl;

    std::cout << "§£§ã§Ö §ä§Ñ§Ò§Ý§Ö§ä§Ü§Ú §Ó §Ñ§á§ä§Ö§Ü§Ö:" << std::endl;
    for (const auto& med : medicinesCollection) {
        if (auto tablets = std::dynamic_pointer_cast<Tablets>(med)) {
            std::cout << "  " << tablets->getName()
                << ", §¥§à§Ù§Ú§â§à§Ó§Ü§Ñ: " << tablets->getDosage() << " §Þ§Ô"
                << ", §¬§à§Ý§Ú§é§Ö§ã§ä§Ó§à §Ó §å§á§Ñ§Ü§à§Ó§Ü§Ö: " << tablets->getCount() << " §ê§ä."
                << std::endl;
        }
    }

    std::cout << "\n§£§ã§Ö §ã§Ú§â§à§á§í §Ó §Ñ§á§ä§Ö§Ü§Ö:" << std::endl;
    for (const auto& med : medicinesCollection) {
        if (auto syrup = std::dynamic_pointer_cast<Syrup>(med)) {
            std::cout << "  " << syrup->getName()
                << ", §°§Ò§ì§Ö§Þ: " << syrup->getVolume() << " §Þ§Ý"
                << ", §£§Ü§å§ã: " << syrup->getFlavor()
                << std::endl;
        }
    }

    std::cout << "\n§±§²§°§¤§²§¡§®§®§¡ §©§¡§£§¦§²§º§¦§¯§¡" << std::endl;

    return 0;
}