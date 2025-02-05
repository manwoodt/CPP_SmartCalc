#include "../../headers/credit_calc_view.h"

#include "ui_credit_calc_view.h"

s21::Credit_calc::Credit_calc(s21::Controller *controller, QWidget *parent)
    : QWidget(parent), ui(new Ui::Credit_calc), controller_(controller) {
  ui->setupUi(this);
  connect(ui->pushButton_back, SIGNAL(clicked()), this, SLOT(back()));
  connect(ui->pushButton_calc, SIGNAL(clicked()), this, SLOT(equal()));
}

void s21::Credit_calc::back() {
  this->close();
  emit firstWindow();
}

void s21::Credit_calc::equal() {
  std::string loanAmount = ui->lineEdit_loanAmount->text().toStdString();
  std::string term = ui->lineEdit_term->text().toStdString();
  std::string interestRate = ui->lineEdit_interestRate->text().toStdString();

  bool isAnnuity = ui->comboBox_diff_or_ann->currentIndex() ? false : true;
  bool isYear = ui->comboBox_year_or_month->currentIndex() ? false : true;

  if (loanAmount.empty()) {
    QMessageBox::warning(this, "Внимание!", "Введите сумму кредита!");
  } else if (term.empty()) {
    QMessageBox::warning(this, "Внимание!", "Введите срок кредита!");
  } else if (interestRate.empty()) {
    QMessageBox::warning(this, "Внимание!", "Введите процентную ставку!");
  } else {
    try {
      std::vector<double> outputData = controller_->CalculateCredit(
          loanAmount, term, isYear, interestRate, isAnnuity);
      QString monthlyPayment_str =
          QString::number(outputData[0], 'g', 15);
      QString overpayment_str =
          QString::number(outputData[2], 'g', 15);
      QString totalPayment_str =
          QString::number(outputData[1], 'g', 15);

      ui->lineEdit_monthlyPayment->setText(monthlyPayment_str);
      ui->lineEdit_totalPayment->setText(totalPayment_str);
      ui->lineEdit_overpayment->setText(overpayment_str);

    } catch (const std::exception &e) {
      QMessageBox::critical(this, "Внимание!", e.what());
    }
  }
}
s21::Credit_calc::~Credit_calc() { delete ui; }
