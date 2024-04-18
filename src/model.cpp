#include "model.h"
#include <iostream>
#include <regex>
using namespace s21;

CalcModel::CalcModel()
{
    CreateTokenMap();
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
        {"^", Token{"^", kHigh, kRight, kBinaryOperator, pow}},
        {"mod", Token{"mod", kMedium, kLeft, kBinaryOperator, fmod}},
        {"cos", Token{"cos", kHigh, kRight, kUnaryFunction, cos}},
        {"sin", Token{"sin", kHigh, kRight, kUnaryFunction, sin}},
        {"tan", Token{"tan", kHigh, kRight, kUnaryFunction, tan}},
        {"acos", Token{"acos", kHigh, kRight, kUnaryFunction, acos}},
        {"asin", Token{"asin", kHigh, kRight, kUnaryFunction, asin}},
        {"atan", Token{"atan", kHigh, kRight, kUnaryFunction, atan}},
        {"sqrt", Token{"sqrt", kHigh, kRight, kUnaryFunction, sqrt}},
        {"ln", Token{"ln", kHigh, kRight, kUnaryFunction, log}},
        {"log", Token{"log", kHigh, kRight, kUnaryFunction, log10}},
        {"exp", Token{"exp", kHigh, kRight, kUnaryFunction, exp}},
        {"abs", Token{"abs", kHigh, kRight, kUnaryFunction, fabs}},
        {"round", Token{"round", kHigh, kRight, kUnaryFunction, round}},
        {"e", Token{"e", kDefault, kNone, kNumber, M_E}},
        {"pi", Token{"pi", kDefault, kNone, kNumber, M_PI}},
        {"inf", Token{"inf", kDefault, kNone, kNumber, INFINITY}},
    };
    token_map_.insert(list);
}

void CalcModel::Parser(const std::string input_exp)
{
    std::regex token_regex("[\\d\\.]+(?:[eE][-+]?[\\d]+)?|x|\\(|\\)|\\+|-|\\*|/|\\^|mod|cos|sin|tan|acos|asin|atan|sqrt|ln|log|exp|abs|round|e|pi|inf");
    std::regex number_regex(R"(-?\d+(\.\d+)?(?:[eE][-+]?\d+)?)");

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
            tokens_.push(number);
        }
        else
        {
            // Если токен не число, ищем его в карте token_map
            auto it = token_map_.find(token);
            if (it != token_map_.end())
            {
                std::cout << "Token found: " << token << std::endl;
                // Дополнительные действия с найденным токеном
                tokens_.push(it->second);
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

    // Создаем пустую очередь для обработки
    std::queue<Token> temp_queue;

    // Переносим элементы из текущей очереди tokens_ во временную очередь temp_queue
    while (!tokens_.empty())
    {
        temp_queue.push(tokens_.front());
        tokens_.pop();
    }

    // Обрабатываем каждый элемент во временной очереди и добавляем их обратно в tokens_
    while (!temp_queue.empty())
    {
        Token current_token = temp_queue.front();
        temp_queue.pop();

        bool is_minus = (current_token.name_ == "-");
        bool is_unary = (tokens_.empty() || (tokens_.back().type_ != kNumber && tokens_.back().type_ != kCloseBracket));

        if (is_minus && is_unary)
        {
            // Добавляем унарный минус перед соответствующими элементами
            tokens_.push(unary_minus);
        }
        else
        {
            tokens_.push(current_token);
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

void CalcModel::CheckTokens()
{
    std::queue<Token> checked_tokens;
    bool error = 0;
    if (!CheckFirstToken[tokens_.front().type_])
        error = 1;
    while (tokens_.size() != 1)
    {
        checked_tokens.push(tokens_.front());
        tokens_.pop();
        if (!SuitableTypesMatrix_[checked_tokens.back().type_][tokens_.front().type_])
            error = 1;
    }
    if (!CheckLastToken[tokens_.front().type_])
        error = 1;
    if (error)
        throw std::logic_error("Wrong sequence");
    tokens_ = checked_tokens;
}

void CalcModel::ConvertToPostfix()
{
    CheckTokens();
    while (!tokens_.empty())
    {
        switch (tokens_.front().type_)
        {
        case Type::kNumber:
            postfix_queue_.push(tokens_.front());
            tokens_.pop();
            break;
        case Type::kUnaryOperator:
        case Type::kUnaryFunction:
        case Type::kOpenBracket:
            stack.push(tokens_.front());
            tokens_.pop();
            break;
        case Type::kCloseBracket:
            while (stack.top().type_ != kOpenBracket)
            {
                postfix_queue_.push(stack.top());
                stack.pop();
            }
            if (stack.top().type_ == kOpenBracket)
                stack.pop();
            tokens_.pop();
            break;
        case Type::kBinaryOperator:
            while (!stack.empty() &&
                   (stack.top().type_ == kUnaryFunction &&
                    (stack.top().precedence_ > tokens_.front().precedence_ ||
                     (stack.top().precedence_ == tokens_.front().precedence_ && stack.top().associativity_ == kLeft))))
            {
                postfix_queue_.push(stack.top());
                stack.pop();
            }
            stack.push(tokens_.front());
            tokens_.pop();
            break;
        }
        // std::cout << "Stack" << stack.top() << "\n";
    }
    while (!stack.empty())
    {
        postfix_queue_.push(stack.top());
        stack.pop();
    }
}

double CalcModel::PostfixNotationCalculation(double x_value)
{
    while (!postfix_queue_.empty())
    {
        std::visit(
            overloaded{[&](double function)
                       { PushToResult(function); },
                       [&](unary_function function)
                       {
                           PushToResult(function(PopFromResult()));
                       },
                       [&](binary_function function)
                       {
                           double right_argument = PopFromResult();
                           double left_argument = PopFromResult();
                           PushToResult(function(left_argument, right_argument));
                       },
                       [&](auto)
                       { PushToResult(x_value); }},
            postfix_queue_.front().function_);
        postfix_queue_.pop();
        std::cout << "Res:" << result_.back() << std::endl;
    }

    return PopFromResult();
}

void CalcModel::PushToResult(double num)
{
    result_.push_back(num);
}

double CalcModel::PopFromResult()
{
    if (!result_.empty())
    {
        double res = result_.back();
        result_.pop_back();
        return res;
    }
    return 0;
}

// 2+ cos(0.5)*5.6
int main()
{
    CalcModel calc_model;
    std::string str = ")2+ 3-4";
    calc_model.Parser(str);
    calc_model.ConvertToPostfix();
    std::queue<Token> temp_queue{calc_model.postfix_queue_};
    while (!temp_queue.empty())
    {
        std::cout << temp_queue.front().name_ << " "; // Выводим значение в начале очереди
        temp_queue.pop();                             // Удаляем значение из очереди
    }
    double res = calc_model.PostfixNotationCalculation(0);
    std::cout << "\n"
              << res << std::endl;
    return 0;
}
// ответ 0.9