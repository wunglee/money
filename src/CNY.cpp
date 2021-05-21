#include "CNY.h"

CNY::CNY(const float amount) : amount(amount) {}

bool CNY::operator==(const CNY &cny) const {
    return this->amount==cny.amount;
}
