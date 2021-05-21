#include "CNY.h"

CNY::CNY(const float amount) : amount(amount) {
    if(amount<0){
        throw "金额不可是负数";
    }
}

bool CNY::operator==(const CNY &cny) const {
    return this->amount==cny.amount;
}

CNY CNY::plus(CNY cny) {
    return CNY(this->amount+cny.amount);
}

CNY CNY::sub(CNY cny) {
    return CNY(this->amount-cny.amount);
}
