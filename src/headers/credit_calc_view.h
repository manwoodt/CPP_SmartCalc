#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QWidget>
#include <QMessageBox>
namespace Ui {
class Credit_calc;
}

class Credit_calc : public QWidget {
  Q_OBJECT

 public:
  explicit Credit_calc(QWidget *parent = nullptr);
  ~Credit_calc();

 signals:
  void firstWindow();

 private:
  Ui::Credit_calc *ui;

 private slots:
  void back();
  void equal();
};

#endif  // CREDIT_CALC_H
