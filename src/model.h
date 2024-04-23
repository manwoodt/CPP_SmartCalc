#ifndef CALC_MODEL_H
#define CALC_MODEL_H
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <sstream>
#include <stack>
#include <string>
#include <variant>

enum Type {
  kNumber,
  kUnaryOperator,
  kBinaryOperator,
  kUnaryFunction,
  kOpenBracket,
  kCloseBracket,
};
enum Precedence {
  kDefault,
  kLow,
  kMedium,
  kHigh,
};

enum Associativity {
  kNone,
  kLeft,
  kRight,
};

using XYGraph = std::pair<std::vector<double>, std::vector<double>>;

using unary_function = std::function<double(double)>;
using binary_function = std::function<double(double, double)>;
using function_variant =
    std::variant<double, unary_function, binary_function, std::nullptr_t>;

struct Token {
  std::string name_;
  Precedence precedence_;
  Associativity associativity_;
  Type type_;
  function_variant function_;
};

// Определение шаблонной структуры overloaded для перегруженных функций
template <typename... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};

// Шаблонная функция для создания объекта overloaded с автоматическим выводом
// типов
template <typename... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

namespace s21 {
class CalcModel {
 public:
  CalcModel();
  ~CalcModel() = default;

  void CalculateAnswer(const std::string input_str, const std::string input_x);
  double GetAnswer() const;
  XYGraph GetGraph() const;

 private:
  void Parser(const std::string input_str);
  void CheckX(const std::string input_x);
  void CreateTokenMap();
  void MakeUnary();
  void ConvertToPostfix();
  double PostfixNotationCalculation();
  void CalcModel::CalculateXY(int number_of_points, double x_start,
                              double x_end, double y_min, double y_max);
  std::queue<Token> tokens_;
  std::queue<Token> postfix_queue_;
  std::stack<Token> stack;
  std::string input_exp_;
  std::vector<double> result_;
  std::map<std::string, Token> token_map_;

  double answer_ = NAN;
  double x_ = NAN;
  XYGraph answer_graph_;

  void CheckTokens();
  void ClearTokens();
  void PushToResult(double num);
  double PopFromResult();

  bool CheckFirstToken[6] = {1, 1, 0, 1, 1, 0};
  bool CheckLastToken[6] = {1, 0, 0, 0, 0, 1};
  bool SuitableTypesMatrix_[6][6] = {
      {0, 0, 1, 0, 0, 1},  // kNumber ./
      {1, 0, 0, 1, 1, 0},  // kUnaryOperator ./
      {1, 0, 0, 1, 1, 0},  // kBinaryOperator ./
      {0, 0, 0, 0, 1, 0},  // kUnaryFunction ./
      {1, 1, 0, 1, 1, 0},  // kOpenBracket ./
      {0, 0, 1, 0, 0, 1},  // kCloseBracket ./
  };
};
}  // namespace s21
#endif
