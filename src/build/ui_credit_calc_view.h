/********************************************************************************
** Form generated from reading UI file 'credit_calc_view.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_CALC_VIEW_H
#define UI_CREDIT_CALC_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Credit_calc
{
public:
    QLabel *label_2;
    QFrame *frame;
    QPushButton *pushButton_calc;
    QPushButton *pushButton_back;
    QFrame *frame_2;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *lineEdit_overpayment;
    QLineEdit *lineEdit_totalPayment;
    QLabel *label_6;
    QLineEdit *lineEdit_monthlyPayment;
    QFrame *frame_3;
    QLabel *label;
    QComboBox *comboBox_diff_or_ann;
    QFrame *frame_4;
    QLineEdit *lineEdit_loanAmount;
    QLineEdit *lineEdit_term;
    QLabel *label_4;
    QLabel *label_3;
    QComboBox *comboBox_year_or_month;
    QLineEdit *lineEdit_interestRate;
    QLabel *label_5;

    void setupUi(QWidget *Credit_calc)
    {
        if (Credit_calc->objectName().isEmpty())
            Credit_calc->setObjectName("Credit_calc");
        Credit_calc->resize(462, 456);
        QFont font;
        font.setFamilies({QString::fromUtf8("Apple Symbols")});
        Credit_calc->setFont(font);
        Credit_calc->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0.315044, y1:0.290136, x2:0.630542, y2:0.744318, stop:0 rgba(24, 150, 93, 219), stop:0.871921 rgba(184, 255, 104, 211));"));
        label_2 = new QLabel(Credit_calc);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 10, 311, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Songti TC")});
        font1.setPointSize(24);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: black;\n"
"background: transparent"));
        frame = new QFrame(Credit_calc);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(270, 180, 171, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_calc = new QPushButton(frame);
        pushButton_calc->setObjectName("pushButton_calc");
        pushButton_calc->setGeometry(QRect(30, 10, 101, 41));
        QFont font2;
        font2.setPointSize(16);
        pushButton_calc->setFont(font2);
        pushButton_calc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(40, 231, 255)\n"
"}"));
        pushButton_back = new QPushButton(frame);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(40, 60, 81, 41));
        pushButton_back->setFont(font2);
        pushButton_back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(255, 157, 129)\n"
"}"));
        frame_2 = new QFrame(Credit_calc);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(20, 290, 421, 131));
        frame_2->setStyleSheet(QString::fromUtf8("background: rgb(181, 254, 104)"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(frame_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 90, 171, 31));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("color: black;"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 50, 211, 31));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("color: black;"));
        lineEdit_overpayment = new QLineEdit(frame_2);
        lineEdit_overpayment->setObjectName("lineEdit_overpayment");
        lineEdit_overpayment->setGeometry(QRect(270, 50, 111, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        font3.setPointSize(13);
        lineEdit_overpayment->setFont(font3);
        lineEdit_overpayment->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-top-right-radius: 15px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-right-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"color: black;\n"
"background:rgb(46, 162, 95)"));
        lineEdit_overpayment->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_totalPayment = new QLineEdit(frame_2);
        lineEdit_totalPayment->setObjectName("lineEdit_totalPayment");
        lineEdit_totalPayment->setGeometry(QRect(270, 90, 111, 31));
        QFont font4;
        font4.setPointSize(13);
        lineEdit_totalPayment->setFont(font4);
        lineEdit_totalPayment->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-top-right-radius: 15px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-right-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"color: black;\n"
"background:rgb(46, 162, 95)"));
        lineEdit_totalPayment->setInputMethodHints(Qt::ImhDigitsOnly);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 10, 211, 31));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("color: black;"));
        lineEdit_monthlyPayment = new QLineEdit(frame_2);
        lineEdit_monthlyPayment->setObjectName("lineEdit_monthlyPayment");
        lineEdit_monthlyPayment->setGeometry(QRect(270, 10, 111, 31));
        lineEdit_monthlyPayment->setFont(font3);
        lineEdit_monthlyPayment->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-top-right-radius: 15px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-right-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"color: black;\n"
"background:rgb(46, 162, 95)"));
        lineEdit_monthlyPayment->setInputMethodHints(Qt::ImhDigitsOnly);
        frame_3 = new QFrame(Credit_calc);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(20, 180, 251, 111));
        frame_3->setStyleSheet(QString::fromUtf8(""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_3);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 221, 31));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: black;\n"
"background: transparent"));
        comboBox_diff_or_ann = new QComboBox(frame_3);
        comboBox_diff_or_ann->addItem(QString());
        comboBox_diff_or_ann->addItem(QString());
        comboBox_diff_or_ann->setObjectName("comboBox_diff_or_ann");
        comboBox_diff_or_ann->setGeometry(QRect(20, 40, 191, 41));
        QFont font5;
        font5.setPointSize(14);
        comboBox_diff_or_ann->setFont(font5);
        comboBox_diff_or_ann->setStyleSheet(QString::fromUtf8("color: black;\n"
"border-top-right-radius: 15px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-right-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"background:transparent"));
        frame_4 = new QFrame(Credit_calc);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(20, 50, 421, 131));
        frame_4->setStyleSheet(QString::fromUtf8("background: rgb(181, 254, 104)"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        lineEdit_loanAmount = new QLineEdit(frame_4);
        lineEdit_loanAmount->setObjectName("lineEdit_loanAmount");
        lineEdit_loanAmount->setGeometry(QRect(270, 10, 111, 31));
        lineEdit_loanAmount->setFont(font3);
        lineEdit_loanAmount->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-top-right-radius: 15px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-right-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"color: black;\n"
"background:rgb(46, 162, 95)"));
        lineEdit_loanAmount->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_term = new QLineEdit(frame_4);
        lineEdit_term->setObjectName("lineEdit_term");
        lineEdit_term->setGeometry(QRect(270, 50, 111, 31));
        lineEdit_term->setFont(font3);
        lineEdit_term->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-top-right-radius: 15px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-right-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"color: black;\n"
"background:rgb(46, 162, 95)"));
        lineEdit_term->setInputMethodHints(Qt::ImhDigitsOnly);
        label_4 = new QLabel(frame_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 50, 121, 31));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color: black;"));
        label_3 = new QLabel(frame_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 9, 161, 31));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: black;"));
        comboBox_year_or_month = new QComboBox(frame_4);
        comboBox_year_or_month->addItem(QString());
        comboBox_year_or_month->addItem(QString());
        comboBox_year_or_month->setObjectName("comboBox_year_or_month");
        comboBox_year_or_month->setGeometry(QRect(140, 50, 101, 31));
        comboBox_year_or_month->setFont(font5);
        comboBox_year_or_month->setStyleSheet(QString::fromUtf8("color: black;\n"
"border-top-right-radius: 15px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-right-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"background:transparent"));
        lineEdit_interestRate = new QLineEdit(frame_4);
        lineEdit_interestRate->setObjectName("lineEdit_interestRate");
        lineEdit_interestRate->setGeometry(QRect(270, 90, 111, 31));
        QFont font6;
        font6.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        font6.setPointSize(14);
        lineEdit_interestRate->setFont(font6);
        lineEdit_interestRate->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-top-right-radius: 15px;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-right-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"color: black;\n"
"background:rgb(46, 162, 95)"));
        lineEdit_interestRate->setInputMethodHints(Qt::ImhDigitsOnly);
        label_5 = new QLabel(frame_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 90, 171, 31));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: black;"));

        retranslateUi(Credit_calc);

        QMetaObject::connectSlotsByName(Credit_calc);
    } // setupUi

    void retranslateUi(QWidget *Credit_calc)
    {
        Credit_calc->setWindowTitle(QCoreApplication::translate("Credit_calc", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Credit_calc", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        pushButton_calc->setText(QCoreApplication::translate("Credit_calc", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        pushButton_back->setText(QCoreApplication::translate("Credit_calc", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_8->setText(QCoreApplication::translate("Credit_calc", "\320\236\320\261\321\211\320\260\321\217 \320\262\321\213\320\277\320\273\320\260\321\202\320\260, \321\200\321\203\320\261. :", nullptr));
        label_7->setText(QCoreApplication::translate("Credit_calc", "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320\260 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203, \321\200\321\203\320\261. :", nullptr));
        lineEdit_overpayment->setText(QString());
        lineEdit_totalPayment->setText(QString());
        label_6->setText(QCoreApplication::translate("Credit_calc", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266, \321\200\321\203\320\261. :", nullptr));
        lineEdit_monthlyPayment->setText(QString());
        label->setText(QCoreApplication::translate("Credit_calc", "\320\242\320\270\320\277 \320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\321\205 \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271 :", nullptr));
        comboBox_diff_or_ann->setItemText(0, QCoreApplication::translate("Credit_calc", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\265", nullptr));
        comboBox_diff_or_ann->setItemText(1, QCoreApplication::translate("Credit_calc", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265", nullptr));

        lineEdit_loanAmount->setText(QString());
        lineEdit_term->setText(QString());
        label_4->setText(QCoreApplication::translate("Credit_calc", "\320\241\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260 :", nullptr));
        label_3->setText(QCoreApplication::translate("Credit_calc", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260, \321\200\321\203\320\261. :", nullptr));
        comboBox_year_or_month->setItemText(0, QCoreApplication::translate("Credit_calc", "\320\273\320\265\321\202/\320\263\320\276\320\264", nullptr));
        comboBox_year_or_month->setItemText(1, QCoreApplication::translate("Credit_calc", "\320\274\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));

        lineEdit_interestRate->setText(QString());
        label_5->setText(QCoreApplication::translate("Credit_calc", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260, % :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Credit_calc: public Ui_Credit_calc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_CALC_VIEW_H
