#include <QApplication>

#include "../controller/controller.h"
#include "../model/model.h"
#include "../view/view.h"
// #include <QLocale>
// #include <QTranslator>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  //    QTranslator translator;
  //    const QStringList uiLanguages = QLocale::system().uiLanguages();
  //    for (const QString &locale : uiLanguages) {
  //        const QString baseName = "Calculator_" + QLocale(locale).name();
  //        if (translator.load(":/i18n/" + baseName)) {
  //            a.installTranslator(&translator);
  //            break;
  //        }
  //    }

  s21::CalcModel calc;
  s21::Controller controller(&calc);
  s21::View view1(&controller);
  view1.setWindowTitle("Calc");
  view1.show();
//  s21::View view2;
//  view2.show();

  return a.exec();
}
