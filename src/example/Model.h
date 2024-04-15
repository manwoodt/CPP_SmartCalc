#ifndef CALC_MODEL_H
#define CALC_MODEL_H
#include <cstdlib>
#include <string>
#include <stack>

namespace s21
{
    class Model
    {
    public:
        Model() {}
        ~Model() {}
        double MainCalculation(std::string &str, double x);
        int Validator(std::string &input_str);
        void CalculateAnswer(const std::string input_exp, const std::string input_x);
        double GetAnswer();

    private:
        void Calculation();
        bool IsOperator(char c);
        bool IsPlusMinus(char с);
        bool IsNumber(char с);
    };
}
#endif