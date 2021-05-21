//
// Created by 王立 on 2021/5/21.
//

#ifndef MONEY_TDD_CNY_H
#define MONEY_TDD_CNY_H
#include "Money.h"
class CNY : public Money{
public:
    CNY(const float amount);

    Money plus(Money cny);

    Money sub(Money cny);

    Money muti(int times);

    Money div(int times);
};


#endif //MONEY_TDD_CNY_H
