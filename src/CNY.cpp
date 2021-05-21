#include "CNY.h"
#include "Exceptions.h"

CNY::CNY(const float amount) : amount(amount) {
    if(amount<0){
        throw AmountIsNegativeException();
    }
}

bool CNY::operator==(const CNY &cny) const {
    return this->amount==cny.amount;
}

CNY CNY::plus(CNY cny) {
    return CNY(this->amount+cny.amount);
}

CNY CNY::sub(CNY cny) {
    float a=this->amount-cny.amount;
    if(a<0){
        throw InsufficientAmountException();
    }
    return CNY(a);
}

CNY CNY::muti(int times) {
    return CNY(this->amount * times);
}

CNY CNY::div(int times) {
    return CNY(this->amount / times);
}
