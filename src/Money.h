//
// Created by 王立 on 2021/5/21.
//

#ifndef MONEY_TDD_MONEY_H
#define MONEY_TDD_MONEY_H
enum Type{CNY,USD};
class Money {
private:
    const float amount_;
    const Type type_;
public:
    Money(const Type type,const float amount);
    float getAmount();
    const Type getType();
    bool operator==(const Money& money) const;
    Money plus(Money cny);
    Money sub(Money cny);
    Money muti(int times);
    Money div(int times);
};


#endif //MONEY_TDD_MONEY_H
