#include "model/model.h"
using namespace s21;

void printVector(const std::vector<double>& vec) {
  for (const auto& element : vec) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

int main() {
  CalcModel calc;
  // calc.CalculateAnswer("2^2.3^0.5^3.456", "");
  calc.CalculateGraph("x-5", 0.5, 1, 3);
  printVector(calc.GetGraph().first);
  printVector(calc.GetGraph().second);
  std::cout << "calc.GetGraph().first.;";
}