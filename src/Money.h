#ifndef MONEY_TDD_MONEY_H
#define MONEY_TDD_MONEY_H
enum Type{CNY,USD};
class Money {
private:
    const float amount_;
    const Type type_;
public:
    Money(const Type type,const float amount);
    float getAmount() const;
    const Type getType() const;
    bool operator==(const Money& money) const;
    Money plus(Money cny);
    Money sub(Money cny);
    Money muti(int times);
    Money div(int times);
    static float getRate(Type from,Type to);
};


#endif //MONEY_TDD_MONEY_H
