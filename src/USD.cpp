#include "USD.h"
#include "Exceptions.h"


USD USD::plus(USD usd) {
    return USD(getAmount()+usd.getAmount());
}

USD USD::sub(USD usd) {
    float a= getAmount()-usd.getAmount();
    if(a<0){
        throw InsufficientAmountException();
    }
    return USD(a);
}

USD USD::muti(int times) {
    if(times<0){
        throw TimeIsNegativeException();
    }
    return USD(getAmount() * times);
}

USD USD::div(int times) {
    if(times<=0){
        throw TimeIsNegativeOrZeroException();
    }
    return USD(getAmount() / times);
}

USD::USD(const float amount):Money(amount) {
}
