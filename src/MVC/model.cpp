#include "../headers/model.h"

using namespace s21;
/* Сделать
- депозит
- кредит
- нормальный MVC
- make
- тесты
*/
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
                               double x_start, double x_end, double y_min,
                               double y_max) {
  ClearTokens();
  Parser(input_str);
  ConvertToPostfix();
  CalculateXY(step, x_start, x_end, y_min, y_max);
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
  std::regex number_regex(R"(-?\d+(\.\d+)?(?:[eE][-+]?\d+)?)");

  for (size_t i = 0; i < input_str.length();) {
    char current_letter = input_str[i];

    if (isalpha(current_letter))
      AddTokenWord(input_str, i);
    else if (isdigit(current_letter))
      AddTokenNumber(input_str, i);
    else {
      std::string current_letter_str(1, current_letter);
      auto it = token_map_.find(current_letter_str);
      if (it != token_map_.end()) {
        std::cout << "Token found: " << current_letter << std::endl;
        // // Дополнительные действия с найденным токеном
        tokens_.push(it->second);
      } else
        throw std::logic_error("Wrong Token " + current_letter_str);
      i++;
    }
  }
}

void CalcModel::AddTokenWord(const std::string& input_str, size_t& index) {
  std::regex word_regex("([a-z])+");
  std::sregex_iterator iterator = std::sregex_iterator(
      input_str.begin() + index, input_str.end(), word_regex);

  std::smatch match = *iterator;
  index += match.length();
  std::string token = match.str();

  auto it = token_map_.find(token);
  if (it != token_map_.end()) {
    std::cout << "Token found: " << token << std::endl;
    // // Дополнительные действия с найденным токеном
    tokens_.push(it->second);
  } else
    throw std::logic_error("Wrong Token " + token);
}

void CalcModel::AddTokenNumber(const std::string input_str, size_t& index) {
  std::regex number_regex(R"(-?\d+(\.\d+)?(?:[eE][-+]?\d+)?)");
  std::sregex_iterator iterator(input_str.begin() + index, input_str.end(),
                                number_regex);
  std::smatch match = *iterator;
  std::string token = match.str();
  index += match.length();
  // Если токен - число, обрабатываем его соответственно
  std::cout << "Number found: " << token << std::endl;
  // // Дополнительные действия с числом
  Token number{token, kDefault, kNone, kNumber, std::stod(token)};
  tokens_.push(number);
}

// void CalcModel::Parser(const std::string input_str) {
//   // поменять регулярку
//   std::regex token_regex(
//       // добавить R
//       "[\\d\\.]+(?:[eE][-+]?[\\d]+)?|x|\\(|\\)|\\+|-|\\*|/"
//       "|\\^|(a-z)+");
//   std::regex number_regex(R"(-?\d+(\.\d+)?(?:[eE][-+]?\d+)?)");
//   std::sregex_iterator iterator(input_str.begin(), input_str.end(),
//                                 token_regex);
//   std::sregex_iterator end;

//   while (iterator != end) {
//     std::smatch match = *iterator;
//     std::string token = match.str();

//     bool is_number = std::regex_match(token, number_regex);
//     if (is_number) {
//       // Если токен - число, обрабатываем его соответственно
//       std::cout << "Number found: " << token << std::endl;
//       // // Дополнительные действия с числом
//       Token number{token, kDefault, kNone, kNumber, std::stod(token)};
//       tokens_.push(number);
//     } else {
//       // Если токен не число, ищем его в карте token_map
//       auto it = token_map_.find(token);
//       if (it != token_map_.end()) {
//         std::cout << "Token found: " << token << std::endl;
//         // // Дополнительные действия с найденным токеном
//         tokens_.push(it->second);
//       } else
//         throw std::logic_error("Wrong Token " + token);
//     }

//     ++iterator;
//   }
//   MakeUnary();
// }

// новый

// void CalcModel::Parser(const std::string input_str) {
//   // поменять регулярку
//   std::regex token_regex(
//       // добавить R
//       "[\\d\\.]+(?:[eE][-+]?[\\d]+)?|(a-z)+|x|\\(|\\)|\\+|-|\\*|/"
//       "|\\^");
//   // подумать насчет минусы   std::regex
//   // number_regex(R"(-?\d+(\.\d+)?(?:[eE][-+]?\d+)?)");
//   std::regex number_regex(R"(-?\d+(\.\d+)?(?:[eE][-+]?\d+)?)");

//   for (size_t i = 0; i < input_str.length();) {
//     std::sregex_iterator iterator(input_str.begin() + i, input_str.end(),
//                                   token_regex);
//     std::smatch match = *iterator;
//     std::string token = match.str();
//     bool is_number = std::regex_match(token, number_regex);
//     if (is_number) {
//       // Если токен - число, обрабатываем его соответственно
//       std::cout << "Number found: " << token << std::endl;
//       // // Дополнительные действия с числом
//       Token number{token, kDefault, kNone, kNumber, std::stod(token)};
//       tokens_.push(number);
//       i += token.size();
//     } else {
//       // Если токен не число, ищем его в карте token_map
//       auto it = token_map_.find(token);
//       if (it != token_map_.end()) {
//         std::cout << "Token found: " << token << std::endl;
//         // // Дополнительные действия с найденным токеном
//         tokens_.push(it->second);
//       } else
//         throw std::logic_error("Wrong Token " + token);
//       i += token.size();
//     }
//   }
//   MakeUnary();
// }

void CalcModel::MakeUnaryAndCheckBrackets() {
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
  int l_brackets = 0, r_brackets = 0;
  while (!temp_queue.empty()) {
    CountBrackets(temp_queue, l_brackets, r_brackets);
    MakeUnary(temp_queue);
  }
  if (l_brackets != r_brackets)
    throw std::logic_error("You didn't close the bracket");
}

void CalcModel::MakeUnary(std::queue<Token>& temp_queue) {
  Token unary_minus{"negate", kDefault, kNone, kUnaryOperator,
                    std::negate<double>()};
  Token current_token = temp_queue.front();
  temp_queue.pop();

  bool is_plus = (current_token.name_ == "+");
  bool is_minus = (current_token.name_ == "-");
  bool is_unary = (tokens_.empty() || (tokens_.back().type_ != kNumber &&
                                       tokens_.back().type_ != kCloseBracket));

  if (is_minus && is_unary)
    tokens_.push(unary_minus);
  else if (!(is_plus && is_unary))
    tokens_.push(current_token);
}

void CalcModel::CountBrackets(std::queue<Token> temp_queue, int& l_bracket,
                              int& r_bracket) {
  Token current_token = temp_queue.front();
  if (current_token.name_ == "(") l_bracket++;
  if (current_token.name_ == ")") r_bracket++;
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
  MakeUnaryAndCheckBrackets();
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

void CalcModel::CalculateXY(double step, double x_min, double x_max,
                            double y_min, double y_max) {
  std::vector<double> x_values, y_values;
  std::queue<Token> const_postfix_queue = postfix_queue_;
  for (double current_x = x_min; current_x <= x_max; current_x += step) {
    x_values.push_back(current_x);
    x_ = x_values.back();
    postfix_queue_ = const_postfix_queue;
    double calculated_y = PostfixNotationCalculation();
    if ((calculated_y < y_min) || (calculated_y > y_max)) {
      y_values.push_back(std::numeric_limits<double>::quiet_NaN());
    } else {
      y_values.push_back(calculated_y);
    }
  }
  answer_graph_ = std::make_pair(x_values, y_values);
}
