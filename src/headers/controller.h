#ifndef CALC_CONTROLLER_H
#define CALC_CONTROLLER_H

#include <string>

#include "model.h"

namespace s21 {
class Controller {
 public:
  Controller();
  Controller(s21::CalcModel *C) : Calc_(C){};
  // ~Controller();

  void CalculateValue(std::string input_str, std::string x);
  XYGraph CalculateGraph(const std::string input_str, double step,
                         double x_start, double x_end);
  double GetAnswer();

 private:
  s21::CalcModel *Calc_;
};

}  // namespace s21

#endif
