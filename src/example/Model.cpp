#include "Model.h"

// 0 - все ок, 1 - неверный ввод, 2 - ошибка со скобками, 3 - ошибка с вводом x,
// 4 - отсутствует число/значение x, 5 - отсутствует x
int Model::Validator(std::string &input_str)
{
    // добавить проверку значения x
    bool IsThereX = 0, IsCorrectX = 1;
    int lbracket = 0, rbracket = 0;
    double value = 0;
    for (unsigned int i = 0; i < (int)input_str.length(); i++)
    {
        // возможно добавлю унарность
        if (IsOperator(input_str[i]))
        {
            if (IsOperator(input_str[i + 1]) || i == (int)input_str.length() - 1)
                return 4;
            else if ((i == 0 && !IsPlusMinus(input_str[i])))
                return 1;
        }
        // возможно сделать отдельной функции и для x тоже
        else if (input_str[i] == '.')
        {
            if (!IsNumber(input_str[i + 1]) || i == (int)input_str.size() - 1 ||
                !IsNumber(input_str[i - 1]))
                return 4;
            // отсекаем число из input_str до ближайшего знака
            value = atof(&input_str[i]);
            std::string value_str = std::to_string(value);
            // две точки в одном числе
            if (input_str[i + value_str.size() - 1] == '.')
                return 1;
        }

        else if (input_str[i] == '(')
        {
            lbracket++;
            if (i == (int)input_str.length() - 1 || input_str[i + 1] == ')')
                return 2;
        }

        else if (input_str[i] == ')')
        {
            rbracket++;
            if (input_str[i + 1] == '(')
                return 2;
        }
        else if (input_str[i] == 'x')
            IsThereX = 1;
    }

    if (IsThereX && !IsCorrectX)
        return 3;

    if (lbracket != rbracket)
        return 2;

    if (input_str.size() == 0)
        return 1;

    return 0;
}

bool Model::IsOperator(char с)
{
    return (с == '+' || с == '-' || с == '~' ||
            с == '*' || с == '%' || с == '/' ||
            с == '^')
               ? 1
               : 0;
}

bool Model::IsPlusMinus(char с)
{
    return (с == '+' || с == '-') ? 1 : 0;
}

bool Model::IsNumber(char с)
{
    return (с >= '0' && с <= '9') ? 1 : 0;
}
