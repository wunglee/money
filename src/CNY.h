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
};


#endif //MONEY_TDD_CNY_H