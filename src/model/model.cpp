#include "model.h"

using namespace s21;

CalcModel::CalcModel() { CreateTokenMap(); }

double CalcModel::GetAnswer() const { return answer_; }

XYGraph CalcModel::GetGraph() const { return answer_graph_; }

void CalcModel::CalculateAnswer(const std::string input_str,
                                const std::string input_x) {
  ClearTokens();
  CheckX(input_x);
  Parser(input_str);
  ConvertToPostfix();
  answer_ = PostfixNotationCalculation();
}

void CalcModel::CalculateGraph(const std::string input_str, double step,
                               double x_start, double x_end) {
  ClearTokens();
  Parser(input_str);
  ConvertToPostfix();
  CalculateXY(step, x_start, x_end);
}

void CalcModel::CreateTokenMap() {
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
      {"*",
       Token{"*", kMedium, kLeft, kBinaryOperator, std::multiplies<double>()}},
      {"/",
       Token{"/", kMedium, kLeft, kBinaryOperator, std::divides<double>()}},
      {"^", Token{"^", kHigh, kRight, kBinaryOperator, powl}},
      {"%", Token{"mod", kMedium, kLeft, kBinaryOperator, fmodl}},
      {"cos", Token{"cos", kHigh, kRight, kUnaryFunction, cosl}},
      {"sin", Token{"sin", kHigh, kRight, kUnaryFunction, sinl}},
      {"tan", Token{"tan", kHigh, kRight, kUnaryFunction, tanl}},
      {"acos", Token{"acos", kHigh, kRight, kUnaryFunction, acosl}},
      {"asin", Token{"asin", kHigh, kRight, kUnaryFunction, asinl}},
      {"atan", Token{"atan", kHigh, kRight, kUnaryFunction, atanl}},
      {"sqrt", Token{"sqrt", kHigh, kRight, kUnaryFunction, sqrtl}},
      {"ln", Token{"ln", kHigh, kRight, kUnaryFunction, logl}},
      {"log", Token{"log", kHigh, kRight, kUnaryFunction, log10l}},
      {"exp", Token{"exp", kHigh, kRight, kUnaryFunction, expl}},
      {"abs", Token{"abs", kHigh, kRight, kUnaryFunction, fabsl}},
      {"round", Token{"round", kHigh, kRight, kUnaryFunction, roundl}},
      {"e", Token{"e", kDefault, kNone, kNumber, M_E}},
      {"pi", Token{"pi", kDefault, kNone, kNumber, M_PI}},
      {"inf", Token{"inf", kDefault, kNone, kNumber, INFINITY}},
  };
  token_map_.insert(list);
}

void CalcModel::CheckX(const std::string input_x) {
  std::regex x_regex(R"(^-?\d+(\.\d+)?(?:[eE][-+]?\d+)?$)");
  if (std::regex_match(input_x, x_regex)) {
    x_ = std::stod(input_x);
  }
}

void CalcModel::Parser(const std::string input_str) {
  // поменять регулярку
  std::regex token_regex(
      "[\\d\\.]+(?:[eE][-+]?[\\d]+)?|x|\\(|\\)|\\+|-|\\*|/"
      "|\\^|mod|cos|sin|tan|acos|asin|atan|sqrt|ln|log|exp|abs|round|e|pi|inf");
  std::regex number_regex(R"(-?\d+(\.\d+)?(?:[eE][-+]?\d+)?)");

  std::sregex_iterator iterator(input_str.begin(), input_str.end(),
                                token_regex);
  std::sregex_iterator end;

  while (iterator != end) {
    std::smatch match = *iterator;
    std::string token = match.str();

    bool is_number = std::regex_match(token, number_regex);
    if (is_number) {
      // Если токен - число, обрабатываем его соответственно
      std::cout << "Number found: " << token << std::endl;
      // // Дополнительные действия с числом
      Token number{token, kDefault, kNone, kNumber, std::stod(token)};
      tokens_.push(number);
    } else {
      // Если токен не число, ищем его в карте token_map
      auto it = token_map_.find(token);
      if (it != token_map_.end()) {
        std::cout << "Token found: " << token << std::endl;
        // // Дополнительные действия с найденным токеном
        tokens_.push(it->second);
      } else
        throw std::logic_error("Wrong Token " + token);
    }

    ++iterator;
  }
  MakeUnary();
}

// может быть оптимизирую на if, чтобы пропускать лишние символы
void CalcModel::MakeUnary() {
  Token unary_minus{"negate", kDefault, kNone, kUnaryOperator,
                    std::negate<double>()};

  // Создаем пустую очередь для обработки
  std::queue<Token> temp_queue;

  // Переносим элементы из текущей очереди tokens_ во временную очередь
  // temp_queue
  while (!tokens_.empty()) {
    temp_queue.push(tokens_.front());
    tokens_.pop();
  }

  // Обрабатываем каждый элемент во временной очереди и добавляем их обратно в
  // tokens_
  while (!temp_queue.empty()) {
    Token current_token = temp_queue.front();
    temp_queue.pop();

    bool is_minus = (current_token.name_ == "-");
    bool is_unary =
        (tokens_.empty() || (tokens_.back().type_ != kNumber &&
                             tokens_.back().type_ != kCloseBracket));

    if (is_minus && is_unary) {
      // Добавляем унарный минус перед соответствующими элементами
      tokens_.push(unary_minus);
    } else {
      tokens_.push(current_token);
    }
  }
}

void CalcModel::CheckTokens() {
  std::queue<Token> checked_tokens;
  if (!CheckFirstToken[tokens_.front().type_])
    throw std::logic_error("\"" + tokens_.front().name_ +
                           "\" can't be at the start of the example");
  while (tokens_.size() != 1) {
    checked_tokens.push(tokens_.front());
    tokens_.pop();
    if (!SuitableTypesMatrix_[checked_tokens.back().type_]
                             [tokens_.front().type_])
      throw std::logic_error("Wrong sequence: " + checked_tokens.back().name_ +
                             " " + tokens_.front().name_);
  }

  if (!CheckLastToken[tokens_.front().type_])
    throw std::logic_error("\"" + checked_tokens.back().name_ +
                           "\" can't be at the end of the example");
  checked_tokens.push(tokens_.front());
  tokens_ = checked_tokens;
}

void CalcModel::ConvertToPostfix() {
  CheckTokens();
  while (!tokens_.empty()) {
    switch (tokens_.front().type_) {
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
        while (stack.top().type_ != kOpenBracket) {
          postfix_queue_.push(stack.top());
          stack.pop();
        }
        if (stack.top().type_ == kOpenBracket) stack.pop();
        tokens_.pop();
        break;
      case Type::kBinaryOperator:
        while (!stack.empty() &&
               (stack.top().type_ == kUnaryFunction ||
                stack.top().precedence_ > tokens_.front().precedence_ ||
                (stack.top().precedence_ == tokens_.front().precedence_ &&
                 stack.top().associativity_ == kLeft))) {
          postfix_queue_.push(stack.top());
          stack.pop();
        }
        stack.push(tokens_.front());
        tokens_.pop();
        break;
    }
  }
  while (!stack.empty()) {
    postfix_queue_.push(stack.top());
    stack.pop();
  }
}

double CalcModel::PostfixNotationCalculation() {
  while (!postfix_queue_.empty()) {
    std::visit(
        overloaded{[&](double function) { PushToResult(function); },
                   [&](unary_function function) {
                     PushToResult(function(PopFromResult()));
                   },
                   [&](binary_function function) {
                     double right_argument = PopFromResult();
                     double left_argument = PopFromResult();
                     PushToResult(function(left_argument, right_argument));
                   },
                   [&](auto) { PushToResult(x_); }},
        postfix_queue_.front().function_);
    postfix_queue_.pop();
    std::cout << "Res:" << result_.back() << std::endl;
  }

  return PopFromResult();
}

void CalcModel::PushToResult(double num) { result_.push_back(num); }

double CalcModel::PopFromResult() {
  if (!result_.empty()) {
    double res = result_.back();
    result_.pop_back();
    return res;
  }
  return 0;
}

void CalcModel::ClearTokens() {
  while (!tokens_.empty()) {
    tokens_.pop();
  }
}

void CalcModel::CalculateXY(double step, double x_min, double x_max) {
  std::vector<double> x_values, y_values;
  std::queue<Token> const_postfix_queue = postfix_queue_;
  for (double current_x = x_min; current_x < x_max; current_x += step) {
    x_values.push_back(current_x);
    x_ = x_values.back();
    postfix_queue_ = const_postfix_queue;
    y_values.push_back(PostfixNotationCalculation());
  }
  answer_graph_ = std::make_pair(x_values, y_values);
}
