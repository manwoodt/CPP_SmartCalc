#include <gtest/gtest.h>

#include "model.h"

s21::CalcModel calc;

// TEST(CalculatorControllerTest, test_0)
// {
//     calc.CalculateAnswer("-(1+3*(5%3+100))/50/1*20+-(50^2*(5+3^2)%(3*2)+31*20/(10*-5^(2+1)))+39^2*48*10*123-50-10",
//                          "");
//     double result = calc.GetAnswer();
//     ASSERT_EQ(result, 89799655.696);
// }

TEST(CalculatorControllerTest, Test_1)
{
    calc.CalculateAnswer("(2+3)*5^2", "");
    //  ASSERT_EQ(calculator.GetError(), 0);
    ASSERT_DOUBLE_EQ(calc.GetAnswer(), 125.0);
}

TEST(CalculatorControllerTest, Test_2)
{
    calc.CalculateAnswer("1/2+(2+3)/(sin(9-2)^2-6/7)", "");
    // ASSERT_EQ(calculator.GetError(), 0);
    ASSERT_NEAR(calc.GetAnswer(), -11.250565, 1e-6);
}

TEST(CalculatorControllerTest, Test_3)
{
    calc.CalculateAnswer("(-12.3)+4", "");
    // ASSERT_EQ(calculator.GetError(), 0);
    ASSERT_NEAR(calc.GetAnswer(), -8.3, 1e-6);
}

TEST(CalculatorControllerTest, Test_4)
{
    calc.CalculateAnswer("(12)+(-12.00006)", "");
    //  ASSERT_EQ(calculator.GetError(), 0);
    ASSERT_NEAR(calc.GetAnswer(), -0.00006, 1e-6);
}

TEST(CalculatorControllerTest, Test_5)
{
    calc.CalculateAnswer("(-(-(-10)))-(-(-10))", "");
    //  ASSERT_EQ(calculator.GetError(), 0);
    ASSERT_NEAR(calc.GetAnswer(), -20, 1e-6);
}

TEST(CalculatorControllerTest, Test_6)
{
    calc.CalculateAnswer("(-1.2)-1.2-2.4-4.8", "");
    //   ASSERT_EQ(calculator.GetError(), 0);
    ASSERT_NEAR(calc.GetAnswer(), -9.6, 1e-6);
}

TEST(CalculatorControllerTest, Test_7)
{
    calc.CalculateAnswer("(12)*(-1.0006)", "");
    //  ASSERT_EQ(calculator.GetError(), 0);
    ASSERT_NEAR(calc.GetAnswer(), -12.0072, 1e-6);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
