#include "gtest/gtest.h"
#include "../src/CNY.h"
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
 * 增加汇率转换方法
 * 增加汇率设置方法
 * 提取Money类型
 * 剥离汇率计算到Rate类型
 */
 TEST(单一货币,判等){
     CNY a(10);
     CNY b(10);
     ASSERT_EQ(a,b);
 }
TEST(单一货币,金额为负数异常){
    ASSERT_THROW(CNY(-1),std::string);
}
TEST(单一货币,加法运算){
    CNY a(10);
    CNY b(10);
    ASSERT_EQ(a.plus(b),CNY(20));
}
TEST(单一货币,减法运算){
    CNY a(10);
    CNY b(5);
    ASSERT_EQ(a.sub(b),CNY(5));
}