#include <gtest/gtest.h>

#include "headers/controller.h"
s21::CalcModel calc;
s21::CreditCalcModel credit;

TEST(CalculatorControllerTest, Test_1) {
  calc.CalculateAnswer("(2+3)*5^2", "");
  ASSERT_DOUBLE_EQ(calc.GetAnswer(), 125.0);
}

TEST(CalculatorControllerTest, Test_2) {
  calc.CalculateAnswer("1/2+(2+3)/(sin(9-2)^2-6/7)", "");
  ASSERT_NEAR(calc.GetAnswer(), -11.250565, 1e-6);
}

TEST(CalculatorControllerTest, Test_3) {
  calc.CalculateAnswer("(-12.3)+4", "");
  ASSERT_NEAR(calc.GetAnswer(), -8.3, 1e-6);
}

TEST(CalculatorControllerTest, Test_4) {
  calc.CalculateAnswer("(12)+(-12.00006)", "");
  ASSERT_NEAR(calc.GetAnswer(), -0.00006, 1e-6);
}

TEST(CalculatorControllerTest, Test_5) {
  calc.CalculateAnswer("(-(-(-10)))-(-(-10))", "");
  ASSERT_NEAR(calc.GetAnswer(), -20, 1e-6);
}

TEST(CalculatorControllerTest, Test_6) {
  calc.CalculateAnswer("(-1.2)-1.2-2.4-4.8", "");
  ASSERT_NEAR(calc.GetAnswer(), -9.6, 1e-6);
}

TEST(CalculatorControllerTest, Test_7) {
  calc.CalculateAnswer("(12)*(-1.0006)", "");
  ASSERT_NEAR(calc.GetAnswer(), -12.0072, 1e-6);
}

TEST(CalculatorControllerTest, Test_8) {
  calc.CalculateAnswer("2^2.3^0.5^3.456", "");
  ASSERT_NEAR(calc.GetAnswer(), 2.11235741575, 1e-6);
}

TEST(CalculatorXTest, Test_9) {
  calc.CalculateAnswer("256-x", "1.5e+2");
  ASSERT_NEAR(calc.GetAnswer(), 106, 1e-6);
}

TEST(CreditCalcTest, AnnuityTest1) {
  s21::Controller controller(&calc, &credit);
  std::vector<double> answer =
      controller.CalculateCredit("1000000", "12", 0, "15", 1);
  double monthlyPayment = answer[0];
  double totalPayment = answer[1];
  double overpayment = answer[2];
  EXPECT_DOUBLE_EQ(monthlyPayment, 90258.309999999998);
  EXPECT_DOUBLE_EQ(totalPayment, 1083099.75);
  EXPECT_DOUBLE_EQ(overpayment, 83099.75);
}

TEST(CreditCalcTest, AnnuityTest2) {
  s21::Controller controller(&calc, &credit);
  std::vector<double> answer =
      controller.CalculateCredit("1000000", "3", 1, "15", 1);
  double monthlyPayment = answer[0];
  double totalPayment = answer[1];
  double overpayment = answer[2];
  EXPECT_DOUBLE_EQ(monthlyPayment, 34665.33);
  EXPECT_DOUBLE_EQ(totalPayment, 1247951.83);
  EXPECT_DOUBLE_EQ(overpayment, 247951.83);
}

TEST(CreditCalcTest, DifferentiatedTest1) {
  s21::Controller controller(&calc, &credit);
  std::vector<double> answer =
      controller.CalculateCredit("1000000", "12", 0, "15", 0);
  double monthlyPayment = answer[0];
  double totalPayment = answer[1];
  double overpayment = answer[2];
  EXPECT_DOUBLE_EQ(monthlyPayment, 84375);
  EXPECT_DOUBLE_EQ(totalPayment, 1081250);
  EXPECT_DOUBLE_EQ(overpayment, 81250);
}

TEST(CreditCalcTest, DifferentiatedTest2) {
  s21::Controller controller(&calc, &credit);
  std::vector<double> answer =
      controller.CalculateCredit("1000000", "3", 1, "15", 0);
  double monthlyPayment = answer[0];
  double totalPayment = answer[1];
  double overpayment = answer[2];
  EXPECT_DOUBLE_EQ(monthlyPayment, 28125);
  EXPECT_DOUBLE_EQ(totalPayment, 1231250);
  EXPECT_DOUBLE_EQ(overpayment, 231250);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
