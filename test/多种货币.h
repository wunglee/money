#ifndef MONEY_TDD_测试环境_H
#define MONEY_TDD_测试环境_H
#include "gtest/gtest.h"
#include "../src/Money.h"
class 多种货币 : public testing::Test{
public:
protected:
    void SetUp() override {
        Test::SetUp();
        Money::addRate(USD,CNY,0.2);
        Money::addRate(CNY,USD,5);
    }
    void TearDown() override {
        Money::clearRates();
        Test::TearDown();
    }
};


#endif //MONEY_TDD_测试环境_H
