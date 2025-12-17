#include <gtest/gtest.h>
#include "Medicine.h"
#include "Tablets.h"
#include "Syrup.h"
#include "Apteka.h"

TEST(MedicineTest, BasicFunctionality) {
    Medicine med("Ибупрофен", "таблетки", "2024-12-31", 
                 "Обезболивающее", 200.0, "Новартис",
                 {"головная боль", "воспаление"});
    
    EXPECT_EQ(med.getName(), "Ибупрофен");
    EXPECT_EQ(med.getPrice(), 200.0);
    EXPECT_TRUE(med.isForDisease("головная боль"));
    EXPECT_FALSE(med.isForDisease("кашель"));
}

TEST(TabletsTest, Inheritance) {
    auto tablets = std::make_shared<Tablets>(
        "Анальгин", "таблетки", "2024-12-31", 
        "Обезболивающее", 100.0, "Фармстандарт",
        {"боль", "жар"},
        20, 500.0
    );
    
    EXPECT_EQ(tablets->getName(), "Анальгин");
    EXPECT_EQ(tablets->getCount(), 20);
    EXPECT_EQ(tablets->getDosage(), 500.0);
    EXPECT_TRUE(tablets->getInfo().find("Таблетки") != std::string::npos);
}

TEST(SyrupTest, Inheritance) {
    auto syrup = std::make_shared<Syrup>(
        "Лазолван", "сироп", "2024-08-15",
        "От кашля", 320.0, "Берингер Ингельхайм",
        {"кашель", "бронхит"},
        150.0, "апельсиновый"
    );
    
    EXPECT_EQ(syrup->getName(), "Лазолvan");
    EXPECT_EQ(syrup->getVolume(), 150.0);
    EXPECT_EQ(syrup->getFlavor(), "апельсиновый");
    EXPECT_TRUE(syrup->getInfo().find("Сироп") != std::string::npos);
}

TEST(AptekaTest, AddAndFindMedicines) {
    Apteka apteka;
    
    auto med1 = std::make_shared<Tablets>("Парацетамол", "таблетки", "2024-12-31", 
                                         "Жаропонижающее", 150.0, "Фармстандарт",
                                         {"простуда", "грипп"}, 20, 500.0);
    
    auto med2 = std::make_shared<Syrup>("Синекод", "сироп", "2024-10-31",
                                       "От кашля", 350.0, "Новартис",
                                       {"кашель"}, 200.0, "клубничный");
    
    apteka.addMedicine(med1);
    apteka.addMedicine(med2);
    
    EXPECT_EQ(apteka.getAllMedicines().size(), 2);
    
    auto found = apteka.getMedicinesForDisease("простуда");
    EXPECT_EQ(found.size(), 1);
    EXPECT_EQ(found[0]->getName(), "Парацетамол");
}

TEST(AptekaTest, SalesReporting) {
    Apteka apteka;
    
    auto med = std::make_shared<Tablets>("Аспирин", "таблетки", "2024-12-31", 
                                        "Обезболивающее", 120.0, "Байер",
                                        {"боль"}, 30, 100.0);
    
    apteka.addMedicine(med);
    apteka.addSale(med, "2024-01-05", 3);
    apteka.addSale(med, "2024-01-06", 2);
    
    auto report = apteka.getSalesReport("Аспирин", "неделя");
    EXPECT_GT(report.totalQuantity, 0);
    EXPECT_GT(report.totalRevenue, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
