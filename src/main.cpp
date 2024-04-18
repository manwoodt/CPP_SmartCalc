#include "model.h"
using namespace s21;
int main()
{
    CalcModel calc;
    calc.CalculateAnswer("1/2+(2+3)/(sin(9-2)^2-6/7)", "");
    //  ASSERT_EQ(calculator.GetError(), 0);
    std::cout << calc.GetAnswer();
}