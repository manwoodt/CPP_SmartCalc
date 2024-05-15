#include "headers/model.h"
using namespace s21;

void printVector(const std::vector<double>& vec) {
  for (const auto& element : vec) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

int main() {
  CalcModel calc;
  // calc.CalculateAnswer("cos(0", "");
  calc.CalculateGraph("cos(0)", 0.5, 1, 3);
  printVector(calc.GetGraph().first);
  printVector(calc.GetGraph().second);
  std::cout << "calc.GetAnswer().first.;";
}