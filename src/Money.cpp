#include "Exceptions.h"
#include "Money.h"

bool Money::operator==(const Money& money) const {
    float rate=getRate(this->getType(),money.getType());
    return this->amount_==money.amount_*rate;
}

Money::Money(Type type, const float amount):type_(type),amount_(amount) {
    if(amount<0){
        throw AmountIsNegativeException();
    }
}

float Money::getAmount() const{
    return this->amount_;
}
const Type Money::getType() const{
    return this->type_;
}

Money Money::plus(Money money) {
    float rate =getRate(this->getType(),money.getType());
    return Money(this->getType(),getAmount() + money.getAmount()*rate);
}

Money Money::sub(Money money) {
    float rate =getRate(this->getType(),money.getType());
    float a= getAmount() - money.getAmount()*rate;
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
RatesMap Money::ratesMap;
float Money::getRate(Type from, Type to) {
    if(from==to){
        return 1;
    }
    float rate=ratesMap[MoneyPair(from,to)];
    if(rate==0){
        throw RateNotFoundException();
    }
    return rate;
}

void Money::addRate(Type from, Type to, float rate) {
    ratesMap[MoneyPair(from,to)]=rate;
}

void Money::clearRates() {
    ratesMap.clear();
}
