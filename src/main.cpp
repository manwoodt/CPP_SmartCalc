#include "model.h"
using namespace s21;
int main()
{
    CalcModel calc;
    calc.CalculateAnswer("(-1.2)-1.2-2.4-4.8", "");
    std::cout << calc.GetAnswer();
}