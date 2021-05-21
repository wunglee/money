#ifndef MONEY_TDD_MONEY_H
#define MONEY_TDD_MONEY_H
#include <map>

enum Type{CNY,USD};
typedef std::pair<Type,Type> MoneyPair;
typedef std::map<MoneyPair,float> RatesMap;
class Money {
private:
    static RatesMap ratesMap;
    const float amount_;
    const Type type_;
public:
    Money(const Type type,const float amount);
    float getAmount() const;
    const Type getType() const;
    bool operator==(const Money& money) const;
    Money plus(Money& money);
    Money sub(Money& money);
    Money muti(int times);
    Money div(int times);
    static float getRate(Type from,Type to);
    static void addRate(Type from,Type to,float rate);
    static void clearRates();
};


#endif //MONEY_TDD_MONEY_H
