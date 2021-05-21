//
// Created by 王立 on 2021/5/21.
//

#include "CNY.h"
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

Money Money::plus(Money cny) {
    return Money(getAmount() + cny.getAmount());
}

Money Money::sub(Money cny) {
    float a= getAmount() - cny.getAmount();
    if(a<0){
        throw InsufficientAmountException();
    }
    return Money(a);
}

Money Money::muti(int times) {
    if(times<0){
        throw TimeIsNegativeException();
    }
    return Money(getAmount() * times);
}

Money Money::div(int times) {
    if(times<=0){
        throw TimeIsNegativeOrZeroException();
    }
    return Money(getAmount() / times);
}