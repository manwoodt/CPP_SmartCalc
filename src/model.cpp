#include "model.h"
#include <iostream>
#include <regex>
using namespace s21;

CalcModel::CalcModel()
{
    CreateTokenMap();
    // Определение конструктора
}

double CalcModel::GetAnswer()
{
    return answer_;
}

void CalcModel::CreateTokenMap()
{
    using std::initializer_list;
    using std::pair;
    using std::string;

    initializer_list<pair<const string, Token>> list = {
        {" ", Token{"space", kDefault, kNone, kNumber, nullptr}},
        {"x", Token{"x", kDefault, kNone, kNumber, nullptr}},
        {"(", Token{"(", kDefault, kNone, kOpenBracket, nullptr}},
        {")", Token{")", kDefault, kNone, kCloseBracket, nullptr}},
        {"+", Token{"+", kLow, kLeft, kBinaryOperator, std::plus<double>()}},
        {"-", Token{"-", kLow, kLeft, kBinaryOperator, std::minus<double>()}},
        {"*", Token{"*", kMedium, kLeft, kBinaryOperator, std::multiplies<double>()}},
        {"/", Token{"/", kMedium, kLeft, kBinaryOperator, std::divides<double>()}},
        {"*", Token{"*", kHigh, kRight, kBinaryOperator, pow}},
        {"mod", Token{"mod", kMedium, kLeft, kBinaryOperator, fmod}},
        {"cos", Token{"cos", kHigh, kRight, kFunction, cos}},
        {"sin", Token{"sin", kHigh, kRight, kFunction, sin}},
        {"tan", Token{"tan", kHigh, kRight, kFunction, tan}},
        {"acos", Token{"acos", kHigh, kRight, kFunction, acos}},
        {"asin", Token{"asin", kHigh, kRight, kFunction, asin}},
        {"atan", Token{"atan", kHigh, kRight, kFunction, atan}},
        {"sqrt", Token{"sqrt", kHigh, kRight, kFunction, sqrt}},
        {"ln", Token{"ln", kHigh, kRight, kFunction, log}},
        {"log", Token{"log", kHigh, kRight, kFunction, log10}},
        {"exp", Token{"exp", kHigh, kRight, kFunction, exp}},
        {"abs", Token{"abs", kHigh, kRight, kFunction, fabs}},
        {"round", Token{"round", kHigh, kRight, kFunction, round}},
        {"e", Token{"e", kDefault, kNone, kNumber, M_E}},
        {"pi", Token{"pi", kDefault, kNone, kNumber, M_PI}},
        {"inf", Token{"inf", kDefault, kNone, kNumber, INFINITY}},
    };
    token_map_.insert(list);
}

void CalcModel::Parser(const std::string input_exp)
{
    std::regex token_regex("[\\d\\.]+(?:[eE][-+]?[\\d]+)?|x|\\(|\\)|\\+|-|\\*|/|mod|cos|sin|tan|acos|asin|atan|sqrt|ln|log|exp|abs|round|e|pi|inf");
    // std::regex unary_minus_regex(R"(\-(\d+(\.\d+)?|\w+|\(.+\)))");
    // std::regex number_regex("[\\d\\.]+(?:[eE][-+]?[\\d]+)?");
    std::regex number_regex(R"(-?\d+(\.\d+)?(?:[eE][-+]?\d+)?)");
    std::regex unary_minus_regex(R"(\-(\d+(\.\d+)?(?:[eE][-+]?\d+)?))");

    std::sregex_iterator iterator(input_exp.begin(), input_exp.end(), token_regex);
    std::sregex_iterator end;

    while (iterator != end)
    {
        std::smatch match = *iterator;
        std::string token = match.str();

        // Проверяем, является ли токен числом
        bool is_number = std::regex_match(token, number_regex);

        if (is_number)
        {
            // Если токен - число, обрабатываем его соответственно
            std::cout << "Number found: " << token << std::endl;
            // Дополнительные действия с числом
            Token number{token, kDefault, kNone, kNumber, std::stod(token)};
            tokens_.push_back(number);
        }
        else
        {
            // Если токен не число, ищем его в карте token_map
            auto it = token_map_.find(token);
            if (it != token_map_.end())
            {
                std::cout << "Token found: " << token << std::endl;
                // Дополнительные действия с найденным токеном
                tokens_.push_back(it->second);
            }
            else
            {
                std::cout << "Token not found: " << token << std::endl;
                // Дополнительные действия, если нужно
            }
        }

        ++iterator;
    }
    MakeUnary();
}

// может быть оптимизирую на if, чтобы пропускать лишние символы
void CalcModel::MakeUnary()
{
    Token unary_minus{"negate", kDefault, kNone, kNumber, std::negate<double>()};
    for (size_t i = 0; i < tokens_.size(); i++)
    {
        bool is_minus = (tokens_[i].name_ == "-");
        bool is_unary = (i == 0 || (tokens_[i - 1].type_ != kNumber && tokens_[i - 1].type_ != kCloseBracket));
        if (is_minus && is_unary)
        {
            tokens_[i] = unary_minus;
        }
    }
}

void PrintTokenMap(const std::map<std::string, Token> &token_map)
{
    std::cout << "Token Map:\n";
    for (const auto &pair : token_map)
    {
        const std::string &key = pair.first;
        const Token &token = pair.second;
        std::cout << "Key: " << key << ", "
                  << "Name: " << token.name_ << ", "
                  << "Precedence: " << token.precedence_ << ", "
                  << "Associativity: " << token.associativity_ << ", "
                  << "Type: " << token.type_ << "\n";
    }
}

int main()
{
    //  std::map<std::string, Token> token_map;
    CalcModel calc_model;
    //   calc_model.CreateTokenMap(token_map);
    std::string str = "-5.234 -x * (-  456/2)/*cos(1)- 3.14E-2";
    calc_model.Parser(str);
    std::cout << "Значения вектора:" << std::endl;
    for (std::vector<Token>::size_type i = 0; i < calc_model.tokens_.size(); ++i)
    {
        std::cout << calc_model.tokens_[i] << "\n";
    }
    std::cout << "\n"
              << std::endl;
    return 0;
}

/*
void CalcModel::Parser(const std::string input_exp)
{
    std::regex token_regex("[\\d\\.]+(?:[eE][-+]?[\\d]+)?|x|\\(|\\)|\\+|-|\\*|/|mod|cos|sin|tan|acos|asin|atan|sqrt|ln|log|exp|abs|round|e|pi|inf");
    // std::regex unary_minus_regex(R"(\-(\d+(\.\d+)?|\w+|\(.+\)))");
    // std::regex number_regex("[\\d\\.]+(?:[eE][-+]?[\\d]+)?");
    std::regex number_regex(R"(-?\d+(\.\d+)?(?:[eE][-+]?\d+)?)");
    std::regex unary_minus_regex(R"(\-(\d+(\.\d+)?(?:[eE][-+]?\d+)?))");

    std::sregex_iterator iterator(input_exp.begin(), input_exp.end(), token_regex);
    std::sregex_iterator end;

    while (iterator != end)
    {
        std::smatch match = *iterator;
        std::string token = match.str();

        // Проверяем, является ли токен числом
        bool is_number = std::regex_match(token, number_regex);
        bool is_unary_minus = (token.size() == 1 && token[0] == '-' && std::isdigit(input_exp[match.position(0) + 1]));

        if (is_number)
        {
            // Если токен - число, обрабатываем его соответственно
            std::cout << "Number found: " << token << std::endl;
            // Дополнительные действия с числом
            Token number{token, kDefault, kNone, kNumber, std::stod(token)};
            input_.push_back(number);
        }
        else if (is_unary_minus)
        {
            std::cout << "Unary minus found: " << token << std::endl;
            // Дополнительные действия с минусом
            Token unary_minus{"negate", kDefault, kNone, kNumber, std::negate<double>()};
            input_.push_back(unary_minus);
        }
        else
        {
            // Если токен не число, ищем его в карте token_map
            auto it = token_map_.find(token);
            if (it != token_map_.end())
            {
                std::cout << "Token found: " << token << std::endl;
                // Дополнительные действия с найденным токеном
                input_.push_back(it->second);
            }
            else
            {
                std::cout << "Token not found: " << token << std::endl;
                // Дополнительные действия, если нужно
            }
        }

        ++iterator;
    }
}*/