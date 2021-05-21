//
// Created by 王立 on 2021/5/21.
//

#ifndef MONEY_TDD_CNY_H
#define MONEY_TDD_CNY_H

class CNY {
const float amount;
public:
    CNY(const float amount);
    bool operator==(const CNY &cny) const;

    CNY plus(CNY cny);

    CNY sub(CNY cny);

    CNY muti(int times);
};


#endif //MONEY_TDD_CNY_H
