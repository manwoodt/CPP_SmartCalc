#include <gtest/gtest.h>

#include "headers/controller.h"
#include "headers/credit_model.h"
#include "headers/model.h"
s21::CalcModel calc;
s21::CreditCalcModel credit;

TEST(CalculatorControllerTest, Test_1) {
  calc.CalculateAnswer("(2+3)*5^2", "");
  //  ASSERT_EQ(calculator.GetError(), 0);
  ASSERT_DOUBLE_EQ(calc.GetAnswer(), 125.0);
}

TEST(CalculatorControllerTest, Test_2) {
  calc.CalculateAnswer("1/2+(2+3)/(sin(9-2)^2-6/7)", "");
  // ASSERT_EQ(calculator.GetError(), 0);
  ASSERT_NEAR(calc.GetAnswer(), -11.250565, 1e-6);
}

TEST(CalculatorControllerTest, Test_3) {
  calc.CalculateAnswer("(-12.3)+4", "");
  // ASSERT_EQ(calculator.GetError(), 0);
  ASSERT_NEAR(calc.GetAnswer(), -8.3, 1e-6);
}

TEST(CalculatorControllerTest, Test_4) {
  calc.CalculateAnswer("(12)+(-12.00006)", "");
  //  ASSERT_EQ(calculator.GetError(), 0);
  ASSERT_NEAR(calc.GetAnswer(), -0.00006, 1e-6);
}

TEST(CalculatorControllerTest, Test_5) {
  calc.CalculateAnswer("(-(-(-10)))-(-(-10))", "");
  //  ASSERT_EQ(calculator.GetError(), 0);
  ASSERT_NEAR(calc.GetAnswer(), -20, 1e-6);
}

TEST(CalculatorControllerTest, Test_6) {
  calc.CalculateAnswer("(-1.2)-1.2-2.4-4.8", "");
  //   ASSERT_EQ(calculator.GetError(), 0);
  ASSERT_NEAR(calc.GetAnswer(), -9.6, 1e-6);
}

TEST(CalculatorControllerTest, Test_7) {
  calc.CalculateAnswer("(12)*(-1.0006)", "");
  //  ASSERT_EQ(calculator.GetError(), 0);
  ASSERT_NEAR(calc.GetAnswer(), -12.0072, 1e-6);
}

TEST(CalculatorControllerTest, Test_8) {
  calc.CalculateAnswer("2^2.3^0.5^3.456", "");
  ASSERT_NEAR(calc.GetAnswer(), 2.11235741575, 1e-6);
}

TEST(CalculatorXTest, Test_9) {
  calc.CalculateAnswer("256-x", "1.5e+2");
  //  ASSERT_EQ(calculator.GetError(), 0);
  ASSERT_NEAR(calc.GetAnswer(), 106, 1e-6);
}

// TEST(CreditCalcTest, AnnuityTest1) {
//   double overpayment, totalPayment, monthlyPayment;
//   credit.SetData(1000000, 12, 0, 15, 1);
//   std::vector<std::string> outputData = credit.CalculateAnnuity();
//   monthlyPayment = returnValue[0].todouble;
//   returnValue[1] = std::to_string(totalPayment);
//   returnValue[2] = std::to_string(overpayment);
//   EXPECT_DOUBLE_EQ(outputData[0], 90258);
//   EXPECT_DOUBLE_EQ(totalPayment, 1083099.7);
//   EXPECT_DOUBLE_EQ(overpayment, 83099.7);
// }

TEST(CreditrCalc1, True) {
  s21::Controller controller(&calc, &credit);
  std::vector<std::string> answer =
      controller.CalculateCredit("1000000", "12", 0, "15", 1);
  double monthlyPayment = std::stod(answer[0]);
  double totalPayment = std::stod(answer[1]);
  double overpayment = std::stod(answer[2]);
  ASSERT_DOUBLE_EQ(monthlyPayment, 90258);
  ASSERT_DOUBLE_EQ(totalPayment, 1083099.7);
  ASSERT_DOUBLE_EQ(overpayment, 83099.7);
}

// TEST(CreditCalcTest, DifferentiatedTest1) {
//   double overpayment, totalPayment, monthlyPayment;
//   credit.SetData(1000000, 12, 0, 15, 0);
//   int res = calculateDifferentiated(1000000, 12, 15, &monthlyPayment,
//                                     &totalPayment, &overpayment);
//   EXPECT_EQ(res, 0);
//   EXPECT_DOUBLE_EQ(monthlyPayment, 84375);
//   EXPECT_DOUBLE_EQ(totalPayment, 1081250);
//   EXPECT_DOUBLE_EQ(overpayment, 81250);
// }

// TEST(CreditCalcTest, NegativeInputTest) {
//   double overpayment, totalPayment, monthlyPayment;

//   int res = calculateAnnuity(-1000000, 12, 15, &monthlyPayment,
//   &totalPayment,
//                              &overpayment);
//   EXPECT_EQ(res, -1);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
