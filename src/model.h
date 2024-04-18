#ifndef CALC_MODEL_H
#define CALC_MODEL_H
#include <string>
#include <cmath>
#include <functional>
#include <variant>
#include <map>
#include <queue>
#include <stack>
#include <sstream>

enum Type
{
    kNumber,
    kUnaryOperator,
    kBinaryOperator,
    kFunction,
    kOpenBracket,
    kCloseBracket,
};
enum Precedence
{
    kDefault,
    kLow,
    kMedium,
    kHigh,
};

enum Associativity
{
    kNone,
    kLeft,
    kRight,
};

using unary_function = std::function<double(double)>;
using binary_function = std::function<double(double, double)>;
using function_variant = std::variant<double, unary_function, binary_function, std::nullptr_t>;

struct Token
{
    std::string name_;
    Precedence precedence_;
    Associativity associativity_;
    Type type_;
    function_variant function_;

    // Перегрузка оператора "<<" для вывода объектов Token в поток вывода
    friend std::ostream &operator<<(std::ostream &os, const Token &token)
    {
        std::ostringstream oss;
        oss << "Name: " << token.name_ << ", "
            << "Precedence: " << token.precedence_ << ", "
            << "Associativity: " << token.associativity_ << ", "
            << "Type: " << token.type_ << ", ";

        os << oss.str();
        return os;
    }
};

// Определение шаблонной структуры overloaded для перегруженных функций
template <typename... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};

// Шаблонная функция для создания объекта overloaded с автоматическим выводом типов
template <typename... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

namespace s21
{
    class CalcModel
    {
    public:
        CalcModel();
        ~CalcModel() = default;
        // double MainCalculation(std::string &str, double x);
        //  int Validator(std::string &input_str);
        void CalculateAnswer(const std::string input_exp, const std::string input_x);
        double GetAnswer();
        void Parser(const std::string input_exp);
        void CreateTokenMap();
        std::queue<Token> tokens_;
        std::queue<Token> postfix_queue_;
        std::stack<Token> stack;
        void MakeUnary();
        void ConvertToPostfix();
        double PostfixNotationCalculation(double x_value);

    private:
        double answer_ = NAN;
        double x_ = NAN;
        std::string input_exp_;
        std::vector<double> result_;
        std::map<std::string, Token> token_map_;

        void PushToResult(double num);
        double PopFromResult();
        // void Calculation();
        //  bool IsOperator(char c);
        //  bool IsPlusMinus(char с);
        //  bool IsNumber(char с);
    };
}
#endif

/*
        class Token
        {
        public:
            Token() = default;
            ~Token() = default;

        private:
            std::string name_;
            Precedence precendence_;
            Associativity associativity_;
            Type type_;
            function_variant function_;

            void CreateTokenMap(std::map<std::string, Token> &token_map);
        };*/