#include "../headers/controller.h"

void s21::Controller::CalculateValue(std::string input_str, std::string x) {
  Calc_->CalculateAnswer(input_str, x);
}

XYGraph s21::Controller::CalculateGraph(const std::string input_str,
                                        double step, double x_start,
                                        double x_end) {
  Calc_->CalculateGraph(input_str, step, x_start, x_end);
  return Calc_->GetGraph();
}

double s21::Controller::GetAnswer() { return Calc_->GetAnswer(); }

std::vector<double> s21::Controller::CalculateCredit(const std::string &loanAmount, const std::string &term,bool isYear, const std::string &interestRate, bool isAnnuity){
    Credit_->SetData(loanAmount,term,isYear,interestRate, isAnnuity);
    return Credit_->СalculateAnswer();
}

