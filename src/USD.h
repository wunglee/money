//
// Created by 王立 on 2021/5/21.
//

#ifndef MONEY_TDD_USD_H
#define MONEY_TDD_USD_H
#include "Money.h"
class USD: public Money {
public:
    USD(const float amount);

    USD plus(USD usd);

    USD sub(USD usd);

    USD muti(int times);

    USD div(int times);
};


#endif //MONEY_TDD_USD_H
