#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QMessageBox>
#include <QWidget>

#include "controller.h"
namespace Ui {
class Credit_calc;
}

namespace s21 {

class Credit_calc : public QWidget {
  Q_OBJECT

 public:
  Credit_calc(s21::Controller *controller, QWidget *parent = nullptr);
  ~Credit_calc();

 signals:
  void firstWindow();

 private:
  Ui::Credit_calc *ui;
  Controller *controller_;

 private slots:
  void back();
  void equal();
};
}  // namespace s21
#endif  // CREDIT_CALC_H
