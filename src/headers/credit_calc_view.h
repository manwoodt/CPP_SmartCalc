#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QWidget>
#include <QMessageBox>
#include "controller.h"
namespace Ui {
class Credit_calc;
}

namespace s21{

class Credit_calc : public QWidget {
  Q_OBJECT

 public:
  explicit Credit_calc(s21::Controller *controller, QWidget *parent = nullptr);
  ~Credit_calc();

 signals:
  void firstWindow();

 private:
  Ui::Credit_calc *ui;
  s21::Controller *controller_;

 private slots:
  void back();
  void equal();
};
}
#endif  // CREDIT_CALC_H
