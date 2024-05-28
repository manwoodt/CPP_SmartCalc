#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QMessageBox>

#include "controller.h"
#include "credit_calc_view.h"
#include "deposit_calc.h"
#include "qcustomplot/qcustomplot.h"
#include "ui_view.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class View : public QMainWindow {
  Q_OBJECT

 public:
  // View(QWidget *parent = nullptr);
  View(s21::Controller *c, QWidget *parent = nullptr);
  ~View();

 private:
  Ui::MainWindow *ui;
  s21::Controller *controller_;
  Credit_calc *credit_Window;
  Deposit_calc *deposit_Window;

  std::string GetInputString();
  void SetAnswer(double x);

 private slots:
  void digits_numbers();
  void math_func();
  void delete_all_text();
  void backspace();
  void equal();
  void credit_window();
  void deposit_window();
  void draw_graph();
};
}  // namespace s21
#endif  // VIEW_H
