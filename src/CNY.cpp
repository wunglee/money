#include "CNY.h"
#include "Exceptions.h"
#include "Money.h"


Money CNY::plus(Money cny) {
    return Money(getAmount() + cny.getAmount());
}

Money CNY::sub(Money cny) {
    float a= getAmount() - cny.getAmount();
    if(a<0){
        throw InsufficientAmountException();
    }
    return Money(a);
}

Money CNY::muti(int times) {
    if(times<0){
        throw TimeIsNegativeException();
    }
    return Money(getAmount() * times);
}

Money CNY::div(int times) {
    if(times<=0){
        throw TimeIsNegativeOrZeroException();
    }
    return Money(getAmount() / times);
}

CNY::CNY(const float amount):Money(amount) {
}
