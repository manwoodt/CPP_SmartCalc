// 1 добавить тесты для кредита
// 2 сделать покрытие
// 3 почистить код
// 4 убрать депозит
// 5 решить проблему с tg()

#include "headers/controller.h"
#include "headers/credit_model.h"
#include "headers/model.h"
using namespace s21;

void printVector(const std::vector<double>& vec) {
  for (const auto& element : vec) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

void printVector(const std::vector<std::string>& vec) {
  for (const auto& element : vec) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

int main() {
  // CalcModel calc;
  // // calc.CalculateAnswer("cos(0", "");
  // calc.CalculateGraph("cos(0)", 0.5, 1, 3);
  // printVector(calc.GetGraph().first);
  // printVector(calc.GetGraph().second);
  // std::cout << "calc.GetAnswer().first.;";
  CalcModel calc;
  CreditCalcModel credit;
  Controller controller(&calc, &credit);
  std::vector<std::string> answer =
      controller.CalculateCredit("1000000", "12", 0, "15", 1);
  // printVector(answer);
  // double monthlyPayment = std::stod(answer[0]);
  // double totalPayment = std::stod(answer[1]);
  // double overpayment = std::stod(answer[2]);
}