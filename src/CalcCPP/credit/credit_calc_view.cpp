#include "../../headers/credit_calc_view.h"

//#include "../../headers/view.h"
#include "ui_credit_calc_view.h"

Credit_calc::Credit_calc(QWidget *parent)
    : QWidget(parent), ui(new Ui::Credit_calc) {
  ui->setupUi(this);
  connect(ui->pushButton_back, SIGNAL(clicked()), this, SLOT(back()));
  connect(ui->pushButton_calc, SIGNAL(clicked()), this, SLOT(equal()));
}

void Credit_calc::back() {
  this->close();
  emit firstWindow();
}

void Credit_calc::equal() {

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
        // Продолжение обработки данных, если все поля заполнены
    }


//    std::vector<std::string> outputData = controller_->apiForCreditCalc(
//        totalLoanAmount, term, interestRate, isAnnuity);

//    ui->label_loan_overpayment->setText(QString(outputData[2].c_str()));
//    ui->label_monthly_payment->setText(QString(outputData[0].c_str()));
//    ui->label_total_repayment->setText(QString(outputData[1].c_str()));
}

//    QString expr = ui->InputString->text();
//    QString x_expr = ui->insert_x->text();
//    if (expr.contains("x") && x_expr.isEmpty()) {
//      QMessageBox::warning(this, "Внимание!", "Введите значение x в поле ввода");
//      return;
//    } else if (expr.isEmpty()) {
//      QMessageBox::warning(this, "Внимание!",
//                           "Введите математическое выражение в поле ввода");
//    }

//    else {
//      try {
//        controller_->CalculateValue(expr.toStdString(), x_expr.toStdString());
//        SetAnswer(controller_->GetAnswer());
//      } catch (const std::exception &e) {
//        QMessageBox::critical(this, "Внимание!", e.what());
//      }
//    }
//  }
//}

//  double loanAmount = ui->lineEdit_loanAmount->text().toDouble();
//  double term = ui->lineEdit_term->text().toDouble();
//  if (ui->comboBox_year_or_month->currentIndex() == 0) term *= 12;

//  double interest_rate = ui->lineEdit_interestRate->text().toDouble();

//  if (ui->lineEdit_loanAmount->text().isEmpty() ||
//      ui->lineEdit_term->text().isEmpty() ||
//      ui->lineEdit_interestRate->text().isEmpty()) {
//    QMessageBox::warning(this, "Error:", "Заполни все поля");
//  }

//  double monthlyPayment = 0, totalPayment = 0, overpayment = 0;
//  int error = 0;
//  if (ui->comboBox_diff_or_ann->currentIndex() == 0)
//    error =
//        calculateDifferentiated(loanAmount, term, interest_rate,
//                                &monthlyPayment, &totalPayment, &overpayment);
//  else
//    error = calculateAnnuity(loanAmount, term, interest_rate, &monthlyPayment,
//                             &totalPayment, &overpayment);

//  if (error == -1) {
//    ui->lineEdit_monthlyPayment->setText("Error");
//    ui->lineEdit_totalPayment->setText("Error");
//    ui->lineEdit_overpayment->setText("Error");
//  } else {
//    QString monthlyPayment_str =
//        QString::number(round(monthlyPayment * 100) / 100, 'g', 15);
//    ui->lineEdit_monthlyPayment->setText(monthlyPayment_str);

//    QString totalPayment_str =
//        QString::number(round(totalPayment * 100) / 100, 'g', 15);
//    ui->lineEdit_totalPayment->setText(totalPayment_str);

//    QString overpayment_str =
//        QString::number(round(overpayment * 100) / 100, 'g', 15);
//    ui->lineEdit_overpayment->setText(overpayment_str);
//  }
//}

Credit_calc::~Credit_calc() { delete ui; }
