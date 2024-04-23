#include "model.h"
using namespace s21;
int main()
{
    CalcModel calc;
    calc.CalculateAnswer("2^2.3^0.5^3.456", "");
    std::cout << calc.GetAnswer();
}