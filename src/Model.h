#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H
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

    private:
        void Calculation();
        bool IsOperator(char c);
        bool IsPlusMinus(char с);
        bool IsNumber(char с);
    };
}
#endif