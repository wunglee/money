#include "Exceptions.h"
#include "Money.h"

bool Money::operator==(const Money& money) const {
    return this->amount_==money.amount_;
}

Money::Money(Type type, const float amount):type_(type),amount_(amount) {
    if(amount<0){
        throw AmountIsNegativeException();
    }
}

float Money::getAmount() {
    return this->amount_;
}
const Type Money::getType() {
    return this->type_;
}

Money Money::plus(Money money) {
    return Money(this->getType(),getAmount() + money.getAmount());
}

Money Money::sub(Money money) {
    float a= getAmount() - money.getAmount();
    if(a<0){
        throw InsufficientAmountException();
    }
    return Money(this->getType(),a);
}

Money Money::muti(int times) {
    if(times<0){
        throw TimeIsNegativeException();
    }
    return Money(this->getType(),getAmount() * times);
}

Money Money::div(int times) {
    if(times<=0){
        throw TimeIsNegativeOrZeroException();
    }
    return Money(this->getType(),getAmount() / times);
}
