#include "CNY.h"
#include "Exceptions.h"
#include "Money.h"


CNY CNY::plus(CNY cny) {
    return CNY(getAmount() + cny.getAmount());
}

CNY CNY::sub(CNY cny) {
    float a= getAmount() - cny.getAmount();
    if(a<0){
        throw InsufficientAmountException();
    }
    return CNY(a);
}

CNY CNY::muti(int times) {
    if(times<0){
        throw TimeIsNegativeException();
    }
    return CNY(getAmount() * times);
}

CNY CNY::div(int times) {
    if(times<=0){
        throw TimeIsNegativeOrZeroException();
    }
    return CNY(getAmount() / times);
}

CNY::CNY(const float amount):Money(amount) {
}
