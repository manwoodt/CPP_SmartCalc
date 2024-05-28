#include "../headers/credit_model.h"

#include <cmath>
#include <iostream>
#include <string>
// Вход: сумма вклада, срок размещения, процентная ставка, налоговая ставка,
// периодичность выплат, капитализация процентов, список пополнений, список
// частичных снятий Выход: начисленные проценты, сумма налога, сумма на вкладе к
// концу срока

// Вход: общая сумма кредита, срок, процентная ставкаgit , тип (аннуитетный,
// дифференцированный) rate -%, loan - кредит, term - срок (в годах)
// Выход: ежемесячный платеж, переплата по кредиту, общая выплата
namespace s21 {

CreditCalcModel::CreditCalcModel(){};

void CreditCalcModel::SetData(const std::string& loanAmount,
                              const std::string& term, const bool isYear,
                              const std::string& interestRate, bool isAnnuity) {
  try {
    loanAmount_ = std::stod(loanAmount);
    term_ = std::stoi(term);
    double interestRateDouble = std::stod(interestRate);
    monthlyInterestRate_ = interestRateDouble / 100 / 12;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Ошибка преобразования строки в число: " << e.what() << '\n';
  }
  // if (loanAmount < 0.01 || term < 0.01 || interestRate < 0.01) return -1;
  if (isYear) term_ *= 12;
  isAnnuity_ = isAnnuity;
}

std::vector<std::string> CreditCalcModel::СalculateAnswer() const noexcept {
  if (isAnnuity_)
    return СalculateAnnuity();
  else
    return СalculateDifferentiated();
}

std::vector<std::string> CreditCalcModel::СalculateAnnuity() const noexcept {
  double monthlyPayment =
      loanAmount_ *
      (monthlyInterestRate_ * pow(1 + monthlyInterestRate_, term_)) /
      (pow(1 + monthlyInterestRate_, term_) - 1);
  double totalPayment = monthlyPayment * term_;
  double overpayment = totalPayment - loanAmount_;
  monthlyPayment = round(monthlyPayment * 100) / 100;
  totalPayment = round(totalPayment * 100) / 100;
  overpayment = round(overpayment * 100) / 100;
  std::cout << monthlyPayment << '\n' << totalPayment << '\n' << overpayment;
  std::vector<std::string> returnValue(3);
  returnValue[0] = std::to_string(monthlyPayment);
  returnValue[1] = std::to_string(totalPayment);
  returnValue[2] = std::to_string(overpayment);
  return returnValue;
}

std::vector<std::string> CreditCalcModel::СalculateDifferentiated()
    const noexcept {
  double loanBalance = 0, monthlyPayment = 0, totalPayment = 0, overpayment = 0;
  for (int i = 1; i <= term_; i++) {
    loanBalance = (loanAmount_ - ((loanAmount_ / term_) * (i - 1)));
    monthlyPayment = (loanAmount_ / term_) + loanBalance * monthlyInterestRate_;
    totalPayment += monthlyPayment;
    overpayment += monthlyPayment - loanAmount_ / term_;
  }
  monthlyPayment = round(monthlyPayment * 100) / 100;
  totalPayment = round(totalPayment * 100) / 100;
  overpayment = round(overpayment * 100) / 100;

  std::vector<std::string> returnValue(3);
  returnValue[0] = std::to_string(monthlyPayment);
  returnValue[1] = std::to_string(totalPayment);
  returnValue[2] = std::to_string(overpayment);
  return returnValue;
}
}  // namespace s21
