#include "../headers/view.h"
namespace s21 {
View::View(Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);

  credit_Window = new Credit_calc(controller);
  SetSignals();
}

View::~View() { delete ui; }

void View::SetSignals(){
    connect(credit_Window, &Credit_calc::firstWindow, this, &View::show);

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
}


std::string View::GetInputString() {
  return ui->InputString->text().toStdString();
}

void View::equal() {
  QString expr = ui->InputString->text();
  QString x_expr = ui->insert_x->text();
  if (expr.contains("x") && x_expr.isEmpty()) {
    QMessageBox::warning(this, "Внимание!", "Введите значение x в поле ввода");
    return;
  } else if (expr.isEmpty()) {
    QMessageBox::warning(this, "Внимание!",
                         "Введите математическое выражение в поле ввода");
  }

  else {
    try {
      controller_->CalculateValue(expr.toStdString(), x_expr.toStdString());
      SetAnswer(controller_->GetAnswer());
    } catch (const std::exception &e) {
      QMessageBox::critical(this, "Внимание!", e.what());
    }
  }
}

void View::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  ui->InputString->setText(ui->InputString->text() + button->text());
}

void View::math_func() {
  QPushButton *button = (QPushButton *)sender();
  ui->InputString->setText(ui->InputString->text() + button->text() + "(");
}

void View::delete_all_text() {
  ui->InputString->clear();
  ui->insert_x->clear();
}



void View::SetAnswer(double x) {
  ui->InputString->setText(QString::number(x, 'g', 16));
}

void View::backspace() {
  QString text = ui->InputString->text();
if (!text.isEmpty()) {
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

void View::draw_graph() {
  XYGraph result;

  ui->Graph->clearGraphs();
  double x_min = ui->doubleSpinBox_x_min->text().toDouble();
  double x_max = ui->doubleSpinBox_x_max->text().toDouble();
  double y_min = ui->doubleSpinBox_y_min->text().toDouble();
  double y_max = ui->doubleSpinBox_y_max->text().toDouble();
  double step = ui->doubleSpinBox_step->text().toDouble();
  QString expr = ui->InputString->text();
  if (expr.isEmpty())
    QMessageBox::warning(this, "Внимание!",
                         "Введите математическое выражение в поле ввода");
  else {
    ui->Graph->xAxis->setRange(x_min, x_max);
    ui->Graph->yAxis->setRange(y_min, y_max);

    try {
      result = controller_->CalculateGraph(expr.toStdString(), step, x_min,
                                           x_max, y_min, y_max);
    } catch (const std::exception &e) {
      QMessageBox::critical(this, "Внимание!", e.what());
    }

    QVector<double> vec_x(result.first.begin(), result.first.end());
    QVector<double> vec_y(result.second.begin(), result.second.end());
    ui->Graph->addGraph();
    ui->Graph->graph(0)->addData(vec_x, vec_y);
    ui->Graph->replot();
    vec_x.clear();
    vec_y.clear();
  }
}

void View::credit_window() {
  credit_Window->show();
  this->close();
}
} // namespace s21
