#include "Sale.h"

Sale::Sale(std::shared_ptr<Medicine> medicine, const std::string& date, int quantity)
    : medicine(medicine), date(date), quantity(quantity) {
    totalPrice = medicine->getPrice() * quantity;
}

std::shared_ptr<Medicine> Sale::getMedicine() const { return medicine; }
std::string Sale::getDate() const { return date; }
int Sale::getQuantity() const { return quantity; }
double Sale::getTotalPrice() const { return totalPrice; }

bool Sale::isInPeriod(const std::string& startDate, const std::string& endDate) const {
    return date >= startDate && date <= endDate;
}
