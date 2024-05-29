#ifndef CALC_CONTROLLER_H
#define CALC_CONTROLLER_H

#include <string>
#include <vector>

#include "credit_model.h"
#include "model.h"

namespace s21 {
class Controller {
 public:
  Controller();
  Controller(CalcModel *Calc, CreditCalcModel *Credit)
      : Calc_(Calc), Credit_(Credit){};

  // ~Controller();

  void CalculateValue(std::string input_str, std::string x);
  XYGraph CalculateGraph(const std::string input_str, double step,
                         double x_min, double x_max,double y_min, double y_max);
  std::vector<double> CalculateCredit(const std::string &loanAmount,
                                      const std::string &term, bool isYear,
                                      const std::string &interestRate,
                                      bool isAnnuity);
  double GetAnswer();

 private:
  CalcModel *Calc_;
  CreditCalcModel *Credit_;
};

}  // namespace s21

#endif
