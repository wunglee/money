#include "USD.h"
#include "Exceptions.h"


Money USD::plus(Money usd) {
    return Money(getAmount()+usd.getAmount());
}

Money USD::sub(Money usd) {
    float a= getAmount()-usd.getAmount();
    if(a<0){
        throw InsufficientAmountException();
    }
    return Money(a);
}

Money USD::muti(int times) {
    if(times<0){
        throw TimeIsNegativeException();
    }
    return Money(getAmount() * times);
}

Money USD::div(int times) {
    if(times<=0){
        throw TimeIsNegativeOrZeroException();
    }
    return Money(getAmount() / times);
}

USD::USD(const float amount):Money(amount) {
}
