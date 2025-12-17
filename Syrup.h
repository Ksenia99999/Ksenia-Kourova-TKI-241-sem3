#pragma once
#include "Medicine.h"

// 妊我把抉扭 - 忱把批忍抉抄 找我扭 抖快抗忘把扼找志忘
class Syrup : public Medicine {
private:
    double volume;      // 妍忌抓快技 志 技抖
    std::string flavor; // 圾抗批扼

public:
    Syrup(const std::string& name, const std::string& form,
        const std::string& expirationDate, const std::string& annotation,
        double price, const std::string& manufacturer,
        const std::vector<std::string>& diseases,
        double volume, const std::string& flavor);

    // 坐快找找快把抑
    double getVolume() const;
    std::string getFlavor() const;

    // 妤快把快抉扭把快忱快抖快扶我快 技快找抉忱忘
    std::string getInfo() const override;
};