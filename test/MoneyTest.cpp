#include "gtest/gtest.h"
#include "../src/Exceptions.h"
#include "../src/Money.h"

/**
 * 任务列表：
 * 创建CNY类型
 * 重载==运算
 * 金额为负异常
 * 加法运算
 * 减法运算
 * 被减数不足
 * 乘法运算
 * 乘数小于0异常
 * 除法运算
 * 除数小于等于0
 * 增加USD类型
 * 提取Money类型
 * 增加汇率转换方法
 * 不同币种判等计算
 * 增加汇率设置方法
 * 剥离汇率计算到Rate类型
 */
 TEST(单一货币,判等){
     Money a(CNY,10);
     Money b(CNY,10);
     ASSERT_EQ(a,b);
 }
TEST(单一货币,金额为负数异常){
    ASSERT_THROW(Money(CNY,-1),AmountIsNegativeException);
}
TEST(单一货币,加法运算){
    Money a(CNY,10);
    Money b(CNY,10);
    ASSERT_EQ(a.plus(b),Money(CNY,20));
}
TEST(单一货币,减法运算){
    Money a(CNY,10);
    Money b(CNY,5);
    ASSERT_EQ(a.sub(b),Money(CNY,5));
}
TEST(单一货币,减法运算被减数不足){
    Money a(CNY,5);
    Money b(CNY,10);
    ASSERT_THROW(a.sub(b),InsufficientAmountException);
}
TEST(单一货币,乘法运算){
    Money a(CNY,5);
    ASSERT_EQ(a.muti(2),Money(CNY,10));
}
TEST(单一货币,除法运算){
    Money a(CNY,10);
    ASSERT_EQ(a.div(2),Money(CNY,5));
}
TEST(单一货币,乘法运算乘数为负数){
    Money a(CNY,5);
    ASSERT_THROW(a.muti(-2),TimeIsNegativeException);
}
TEST(单一货币,除法运算乘数为负数或零){
    Money a(CNY,5);
    ASSERT_THROW(a.div(-2),TimeIsNegativeOrZeroException);
    ASSERT_THROW(a.div(0),TimeIsNegativeOrZeroException);
}
TEST(多种货币,货币相同时判等){
    Money a(CNY,10);
    Money b(CNY,10);
    ASSERT_EQ(a,b);
}
TEST(多种货币,货币不同时判等){
    Money a(CNY,10);
    Money b(USD,2);
    ASSERT_EQ(a,b);
}
TEST(多种货币,货币不同时相加){
    Money a(CNY,10);
    Money b(USD,2);
    ASSERT_EQ(a.plus(b),Money(CNY,20));
}
TEST(多种货币,货币不同时相减){
    Money a(CNY,15);
    Money b(USD,2);
    ASSERT_EQ(a.sub(b),Money(CNY,5));
}