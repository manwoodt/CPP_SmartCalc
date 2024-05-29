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

  void CalculateValue(const std::string &input_str, const std::string x);
  XYGraph CalculateGraph(const std::string &input_str, const double step,
                         const double x_min, const double x_max,
                         const double y_min, const double y_max);
  std::vector<double> CalculateCredit(const std::string loanAmount,
                                      const std::string term, bool isYear,
                                      const std::string interestRate,
                                      bool isAnnuity);
  double GetAnswer() const;

 private:
  CalcModel *Calc_;
  CreditCalcModel *Credit_;
};

}  // namespace s21

#endif
