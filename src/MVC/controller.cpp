#include "../headers/controller.h"
namespace s21 {
void Controller::CalculateValue(const std::string& input_str,
                                     const std::string x) {
  Calc_->CalculateAnswer(input_str, x);
}

XYGraph Controller::CalculateGraph(const std::string& input_str,
                                        const double step, const double x_min,
                                        const double x_max, const double y_min,
                                        const double y_max) {
  Calc_->CalculateGraph(input_str, step, x_min, x_max, y_min, y_max);
  return Calc_->GetGraph();
}

double Controller::GetAnswer() const { return Calc_->GetAnswer(); }

std::vector<double> Controller::CalculateCredit(
    const std::string loanAmount, const std::string term, bool isYear,
    const std::string interestRate, bool isAnnuity) {
  Credit_->SetData(loanAmount, term, isYear, interestRate, isAnnuity);
  return Credit_->СalculateAnswer();
}
} // namespace s21
