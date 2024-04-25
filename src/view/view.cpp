#include "view.h"

#include "./ui_view.h"

//s21::View::View(QWidget *parent) : QMainWindow(parent)

s21::View::View(s21::Controller *controller) : QMainWindow(), ui(new Ui::MainWindow) {
    this->controller_ = controller;
  ui->setupUi(this);

  // QDoubleValidator double_validator;
  // ui->insert_x->setValidator(&double_validator);

  //  credit_Window = new Credit_calc();
  //  connect(credit_Window, &Credit_calc::firstWindow, this,
  //  &MainWindow::show); deposit_Window = new Deposit_calc();
  //  connect(deposit_Window, &Deposit_calc::firstWindow, this,
  //  &MainWindow::show);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(math_func()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(math_func()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(math_func()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(math_func()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(math_func()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(math_func()));

  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_leftBracket, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_rightBracket, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_deg, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));

  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(math_func()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(math_func()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(math_func()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));

  connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(delete_all_text()));
  connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(backspace()));

  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(equal()));
  connect(ui->pushButton_graph, SIGNAL(clicked()), this, SLOT(draw_graph()));
  connect(ui->pushButton_credit, SIGNAL(clicked()), this,
          SLOT(credit_window()));
  connect(ui->pushButton_deposit, SIGNAL(clicked()), this,
          SLOT(deposit_window()));
}

s21::View::~View() { delete ui; }

std::string s21::View::GetInputString(){
return ui->InputString->text().toStdString();
}


void s21::View::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  ui->InputString->setText(ui->InputString->text() + button->text());
}

 void s21::View::math_func() {
   QPushButton *button = (QPushButton *)sender();
   ui->InputString->setText(ui->InputString->text() + button->text() + "(");
 }

 void s21::View::delete_all_text() {
   ui->InputString->clear();
   ui->insert_x->clear();
 }

 void s21::View::equal() {
     QString expr = ui->InputString->text();
          QString x_expr = ui->insert_x->text();
     if (expr.contains("x") && x_expr.isEmpty()) {
       QMessageBox::warning(this, "Внимание!", "Введите значение x в поле ввода");
       return;
     } else {
         try{
    controller_->CalculateValue(expr.toStdString(), x_expr.toStdString());
    SetAnswer(controller_->GetAnswer());
         } catch (const std::exception &e){
             QMessageBox::critical(this, "Внимание!", e.what());
         }
}

}
 void s21::View::SetAnswer(double x){
   ui->InputString->setText(QString::number(x,'g',16));
 }

//   int is_there_x = 0;
//   int good_exp_with_x = 0;
//   QByteArray expression = ui->InputString->text().toLocal8Bit();
//   QByteArray x_value = ui->insert_x->text().toLocal8Bit();
//   char *input_x = x_value.data();
//   if (expression.contains('x')) is_there_x = 1;
//   if (!x_value.isEmpty()) {
//     good_exp_with_x = is_good_expression(input_x);
//   }
//   char *input_expr = expression.data();
//   char changed_input_expr[255]{0};

//  int is_correct =
//      validator(input_expr, changed_input_expr, is_there_x, good_exp_with_x);
//  double res_num = 0;

//  if (is_correct == 0) {
//    res_num = parser(changed_input_expr, input_x);
//    QString InputString_value = QString::number(res_num, 'g', 15);
//    ui->InputString->setText(InputString_value);
//  } else {
//    QString err_str = "";
//    if (is_correct == 1)
//      err_str = "Ошибка: Неверный ввод";
//    else if (is_correct == 2)
//      err_str = "Ошибка: Ошибка со скобками";
//    else if (is_correct == 3)
//      err_str = "Ошибка: Ошибка с вводом х";
//    else if (is_correct == 4)
//      err_str = "Ошибка: Отсутствует число/значение x";

//    QMessageBox::warning(this, "error", err_str);
//  }


 void s21::View::backspace() {
   QString text = ui->InputString->text();
   if (text == "error")
     ui->InputString->setText("");
   else if (!text.isEmpty()) {
     QString lastChar = text.right(4);
     if (lastChar == "asin" || lastChar == "acos" || lastChar == "atan" ||
         lastChar == "sqrt") {
       text = text.left(text.length() - 4);
     } else {
       lastChar = text.right(3);
       if (lastChar == "sin" || lastChar == "cos" || lastChar == "tan" ||
           lastChar == "log") {
         text = text.left(text.length() - 3);
       } else {
         lastChar = text.right(2);
         if (lastChar == "ln")
           text = text.left(text.length() - 2);
         else
           text = text.left(text.length() - 1);
       }
     }
     ui->InputString->setText(text);
   }
 }

// void MainWindow::credit_window() {
//   credit_Window->show();
//   this->close();
// }

// void MainWindow::deposit_window() {
//   deposit_Window->show();
//   this->close();
// }

// void MainWindow::draw_graph() {
//   ui->widget->clearGraphs();
//   double x_min = ui->doubleSpinBox_x_min->text().toDouble();
//   double x_max = ui->doubleSpinBox_x_max->text().toDouble();
//   double y_min = ui->doubleSpinBox_y_min->text().toDouble();
//   double y_max = ui->doubleSpinBox_y_max->text().toDouble();
//   double step = ui->doubleSpinBox_step->text().toDouble();
//   ui->widget->xAxis->setRange(x_min, x_max);
//   ui->widget->yAxis->setRange(y_min, y_max);

//  QVector<double> x, y;

//  int is_there_x = 0;
//  int good_exp_with_x = 0;
//  QByteArray expression = ui->InputString->text().toLocal8Bit();
//  QByteArray x_value = ui->insert_x->text().toLocal8Bit();
//  char *input_x = x_value.data();
//   char *input_expr = expression.data();
//   if (expression.contains('x')) is_there_x = 1;
//   if (!x_value.isEmpty()) {
//     good_exp_with_x = is_good_expression(input_x);
//   }
//  char changed_input_expr[255]{0};

//  int is_correct = validator(input_expr, changed_input_expr, is_there_x,
//  good_exp_with_x); char current_x_c[255];

// double y_res = 0;
//   if (is_correct == 0 || is_correct == 3) {
//      for (double current_x = x_min; current_x < x_max; current_x += step) {
//        // перевод числа в строку
//        snprintf(current_x_c, sizeof current_x_c, "%f", current_x);
//            if (is_there_x && good_exp_with_x)
//                y_res = parser(changed_input_expr, input_x);
//            else
//                y_res = parser(changed_input_expr, current_x_c);
//        x.push_back(current_x);
//        y.push_back(y_res);
//      }

//      ui->widget->addGraph();
//      ui->widget->graph(0)->addData(x, y);
//      ui->widget->replot();
//      x.clear();
//      y.clear();
//   }else {
//       QString err_str = "";
//       if (is_correct == 1)
//         err_str = "Ошибка: Неверный ввод";
//       else if (is_correct == 2)
//         err_str = "Ошибка: Ошибка со скобками";
//       else if (is_correct == 4)
//         err_str = "Ошибка: Отсутствует число/x";

//       QMessageBox::warning(this, "error", err_str);
//     }

//}
