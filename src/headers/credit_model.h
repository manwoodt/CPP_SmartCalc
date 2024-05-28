#ifndef CREDIT_CALC_MODEL_H_
#define CREDIT_CALC_MODEL_H_

#include <string>
#include <vector>

namespace s21 {
class CreditCalcModel {
 public:
  CreditCalcModel();

  void SetData(const std::string& loanAmount, const std::string& term,
               const bool isYear, const std::string& interestRate,
               bool isAnnuity);

  std::vector<std::string> СalculateAnswer() const noexcept;

 private:
  std::vector<std::string> СalculateAnnuity() const noexcept;
  std::vector<std::string> СalculateDifferentiated() const noexcept;

 private:
  bool isAnnuity_;
  double loanAmount_;
  int term_;
  double monthlyInterestRate_;
};

}  // namespace s21

#endif  // CREDIT_CALC_MODEL_H_
