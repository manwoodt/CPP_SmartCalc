#include <QApplication>

#include "../headers/view.h"


int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  s21::CalcModel calc;
  s21::CreditCalcModel credit;
  s21::Controller controller(&calc,&credit);
  s21::View view1(&controller);
  view1.setWindowTitle("Calc");
  view1.show();
//  s21::View view2;
//  view2.show();

  return a.exec();
}
