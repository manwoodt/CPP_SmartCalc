#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
// #include <QDoubleValidator>
// #include <QMessageBox>
// #include <qcustomplot.h>

#include "../controller/controller.h"
// #include "credit_calc.h"
// #include "deposit_calc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {
class View : public QMainWindow {
  Q_OBJECT

 public:
  View(QWidget *parent = nullptr);
  View(s21::Controller *c) : controller(c){};
  ~View();

 private:
  Ui::View *ui;
  s21::Controller *controller;
  //    Credit_calc *credit_Window;
  //    Deposit_calc *deposit_Window;

 private slots:
      void digits_numbers();
  //    void math_func();
  //    void delete_all_text();
  //    void backspace();
  //    void equal();
  //    void credit_window();
  //    void deposit_window();
  //    void draw_graph();
};
}  // namespace s21
#endif  // VIEW_H
