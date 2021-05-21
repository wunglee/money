//
// Created by 王立 on 2021/5/21.
//

#include "Exceptions.h"
#include "Money.h"

bool Money::operator==(const Money& money) const {
    return this->amount_==money.amount_;
}

Money::Money(const float amount) : amount_(amount) {
    if(amount<0){
        throw AmountIsNegativeException();
    }
}

float Money::getAmount() {
    return this->amount_;
}
