/********************************************************************************
** Form generated from reading UI file 'deposit_calc.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSIT_CALC_H
#define UI_DEPOSIT_CALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deposit_calc
{
public:
    QFrame *frame_4;
    QLineEdit *lineEdit_loanAmount;
    QLineEdit *lineEdit_term;
    QLabel *label_4;
    QLabel *label_3;
    QComboBox *yearOrMonth;
    QLineEdit *lineEdit_interestRate;
    QLabel *label_5;
    QLineEdit *lineEdit_taxRate;
    QLabel *label_10;
    QFrame *frame_2;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *lineEdit_tax;
    QLineEdit *lineEdit_totalAmount;
    QLabel *label_6;
    QLineEdit *lineEdit_accruedInterest;
    QFrame *frame_3;
    QRadioButton *Capitalization;
    QFrame *frame_5;
    QLabel *label_11;
    QLabel *label_12;
    QComboBox *periodOfPay;
    QFrame *frame;
    QPushButton *pushButton_calc;
    QPushButton *pushButton_back;
    QPushButton *pushButton_clear;
    QLabel *label_9;
    QFrame *frame_6;
    QLabel *label_13;
    QLineEdit *lineEdit_replenishment;
    QLineEdit *lineEdit_withdrawal;
    QLabel *label_14;

    void setupUi(QWidget *Deposit_calc)
    {
        if (Deposit_calc->objectName().isEmpty())
            Deposit_calc->setObjectName("Deposit_calc");
        Deposit_calc->resize(370, 449);
        Deposit_calc->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0.315044, y1:0.290136, x2:0.630542, y2:0.744318, stop:0 rgba(24, 150, 93, 219), stop:0.871921 rgba(184, 255, 104, 211));"));
        frame_4 = new QFrame(Deposit_calc);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(20, 40, 331, 131));
        frame_4->setStyleSheet(QString::fromUtf8("background:rgb(186, 255, 108)"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        lineEdit_loanAmount = new QLineEdit(frame_4);
        lineEdit_loanAmount->setObjectName("lineEdit_loanAmount");
        lineEdit_loanAmount->setGeometry(QRect(160, 10, 71, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        font.setPointSize(13);
        lineEdit_loanAmount->setFont(font);
        lineEdit_loanAmount->setStyleSheet(QString::fromUtf8("color: black;\n"
"background: rgb(69, 177, 98)"));
        lineEdit_term = new QLineEdit(frame_4);
        lineEdit_term->setObjectName("lineEdit_term");
        lineEdit_term->setGeometry(QRect(160, 40, 71, 21));
        lineEdit_term->setFont(font);
        lineEdit_term->setStyleSheet(QString::fromUtf8("color: black;\n"
"background: rgb(69, 177, 98)"));
        label_4 = new QLabel(frame_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 40, 131, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: black;"));
        label_3 = new QLabel(frame_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 11, 151, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: black;"));
        yearOrMonth = new QComboBox(frame_4);
        yearOrMonth->addItem(QString());
        yearOrMonth->addItem(QString());
        yearOrMonth->setObjectName("yearOrMonth");
        yearOrMonth->setGeometry(QRect(230, 40, 101, 21));
        yearOrMonth->setStyleSheet(QString::fromUtf8("color: black;\n"
"background: rgb(69, 177, 98)"));
        lineEdit_interestRate = new QLineEdit(frame_4);
        lineEdit_interestRate->setObjectName("lineEdit_interestRate");
        lineEdit_interestRate->setGeometry(QRect(160, 70, 71, 21));
        lineEdit_interestRate->setFont(font);
        lineEdit_interestRate->setStyleSheet(QString::fromUtf8("color: black;\n"
"background: rgb(69, 177, 98)"));
        label_5 = new QLabel(frame_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 70, 151, 21));
        label_5->setStyleSheet(QString::fromUtf8("color: black;"));
        lineEdit_taxRate = new QLineEdit(frame_4);
        lineEdit_taxRate->setObjectName("lineEdit_taxRate");
        lineEdit_taxRate->setGeometry(QRect(160, 100, 71, 21));
        lineEdit_taxRate->setFont(font);
        lineEdit_taxRate->setStyleSheet(QString::fromUtf8("color: black;\n"
"background: rgb(69, 177, 98)"));
        label_10 = new QLabel(frame_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 100, 151, 21));
        label_10->setStyleSheet(QString::fromUtf8("color: black;"));
        frame_2 = new QFrame(Deposit_calc);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(20, 330, 331, 101));
        frame_2->setStyleSheet(QString::fromUtf8("background: rgb(69, 177, 98)"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(frame_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 70, 201, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: black;"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 40, 191, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: black;"));
        lineEdit_tax = new QLineEdit(frame_2);
        lineEdit_tax->setObjectName("lineEdit_tax");
        lineEdit_tax->setGeometry(QRect(220, 40, 91, 21));
        lineEdit_tax->setFont(font);
        lineEdit_tax->setStyleSheet(QString::fromUtf8("color: black;\n"
"background:rgb(186, 255, 108)"));
        lineEdit_tax->setReadOnly(true);
        lineEdit_totalAmount = new QLineEdit(frame_2);
        lineEdit_totalAmount->setObjectName("lineEdit_totalAmount");
        lineEdit_totalAmount->setGeometry(QRect(220, 70, 91, 21));
        QFont font1;
        font1.setPointSize(13);
        lineEdit_totalAmount->setFont(font1);
        lineEdit_totalAmount->setStyleSheet(QString::fromUtf8("color: black;\n"
"background:rgb(186, 255, 108)"));
        lineEdit_totalAmount->setReadOnly(true);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 10, 201, 20));
        label_6->setStyleSheet(QString::fromUtf8("color: black;"));
        lineEdit_accruedInterest = new QLineEdit(frame_2);
        lineEdit_accruedInterest->setObjectName("lineEdit_accruedInterest");
        lineEdit_accruedInterest->setGeometry(QRect(220, 10, 91, 21));
        lineEdit_accruedInterest->setFont(font);
        lineEdit_accruedInterest->setStyleSheet(QString::fromUtf8("color: black;\n"
"background:rgb(186, 255, 108)"));
        lineEdit_accruedInterest->setReadOnly(true);
        frame_3 = new QFrame(Deposit_calc);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(20, 170, 221, 91));
        frame_3->setStyleSheet(QString::fromUtf8("background: rgb(69, 177, 98)"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        Capitalization = new QRadioButton(frame_3);
        Capitalization->setObjectName("Capitalization");
        Capitalization->setGeometry(QRect(50, 10, 121, 20));
        Capitalization->setStyleSheet(QString::fromUtf8("color: black;"));
        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(0, 30, 221, 61));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_11 = new QLabel(frame_5);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 10, 101, 21));
        label_11->setStyleSheet(QString::fromUtf8("color: black;"));
        label_12 = new QLabel(frame_5);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 30, 51, 21));
        label_12->setStyleSheet(QString::fromUtf8("color: black;"));
        periodOfPay = new QComboBox(frame_5);
        periodOfPay->addItem(QString());
        periodOfPay->addItem(QString());
        periodOfPay->setObjectName("periodOfPay");
        periodOfPay->setGeometry(QRect(100, 30, 121, 21));
        periodOfPay->setStyleSheet(QString::fromUtf8("color: black;\n"
"background:rgb(186, 255, 108)"));
        frame = new QFrame(Deposit_calc);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(240, 170, 111, 91));
        frame->setStyleSheet(QString::fromUtf8("background: rgb(69, 177, 98)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_calc = new QPushButton(frame);
        pushButton_calc->setObjectName("pushButton_calc");
        pushButton_calc->setGeometry(QRect(10, 10, 91, 21));
        pushButton_calc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background:rgb(186, 255, 108);\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 40px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(40, 231, 255)\n"
"}"));
        pushButton_back = new QPushButton(frame);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(20, 61, 71, 21));
        pushButton_back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(255, 157, 129)\n"
"}"));
        pushButton_clear = new QPushButton(frame);
        pushButton_clear->setObjectName("pushButton_clear");
        pushButton_clear->setGeometry(QRect(20, 36, 71, 20));
        pushButton_clear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(255, 157, 129)\n"
"}"));
        label_9 = new QLabel(Deposit_calc);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(70, 10, 231, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Songti TC")});
        font2.setPointSize(20);
        font2.setBold(true);
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("color: black;\n"
"background: transparent;"));
        frame_6 = new QFrame(Deposit_calc);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(20, 260, 331, 71));
        frame_6->setStyleSheet(QString::fromUtf8("background:rgb(186, 255, 108)"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(frame_6);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 10, 171, 21));
        label_13->setStyleSheet(QString::fromUtf8("color: black;"));
        lineEdit_replenishment = new QLineEdit(frame_6);
        lineEdit_replenishment->setObjectName("lineEdit_replenishment");
        lineEdit_replenishment->setGeometry(QRect(220, 10, 81, 21));
        lineEdit_replenishment->setFont(font);
        lineEdit_replenishment->setStyleSheet(QString::fromUtf8("color: black;\n"
"background: rgb(69, 177, 98)"));
        lineEdit_withdrawal = new QLineEdit(frame_6);
        lineEdit_withdrawal->setObjectName("lineEdit_withdrawal");
        lineEdit_withdrawal->setGeometry(QRect(220, 40, 81, 21));
        lineEdit_withdrawal->setFont(font);
        lineEdit_withdrawal->setStyleSheet(QString::fromUtf8("color: black;\n"
"background: rgb(69, 177, 98)"));
        label_14 = new QLabel(frame_6);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 40, 171, 21));
        label_14->setStyleSheet(QString::fromUtf8("color: black;"));

        retranslateUi(Deposit_calc);

        QMetaObject::connectSlotsByName(Deposit_calc);
    } // setupUi

    void retranslateUi(QWidget *Deposit_calc)
    {
        Deposit_calc->setWindowTitle(QCoreApplication::translate("Deposit_calc", "Form", nullptr));
        lineEdit_loanAmount->setText(QString());
        lineEdit_term->setText(QString());
        label_4->setText(QCoreApplication::translate("Deposit_calc", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217 :", nullptr));
        label_3->setText(QCoreApplication::translate("Deposit_calc", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260, \321\200\321\203\320\261. :", nullptr));
        yearOrMonth->setItemText(0, QCoreApplication::translate("Deposit_calc", "\320\273\320\265\321\202/\320\263\320\276\320\264", nullptr));
        yearOrMonth->setItemText(1, QCoreApplication::translate("Deposit_calc", "\320\274\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));

        lineEdit_interestRate->setText(QString());
        label_5->setText(QCoreApplication::translate("Deposit_calc", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260, % :", nullptr));
        lineEdit_taxRate->setText(QString());
        label_10->setText(QCoreApplication::translate("Deposit_calc", "\320\235\320\260\320\273\320\276\320\263\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260, % :", nullptr));
        label_8->setText(QCoreApplication::translate("Deposit_calc", "\320\241\321\203\320\274\320\274\320\260 \320\275\320\260 \320\262\320\272\320\273\320\260\320\264\320\265 \320\262 \320\272\320\276\320\275\321\206\320\265, \321\200\321\203\320\261. :", nullptr));
        label_7->setText(QCoreApplication::translate("Deposit_calc", "\320\241\321\203\320\274\320\274\320\260 \320\275\320\260\320\273\320\276\320\263\320\260, \321\200\321\203\320\261. :", nullptr));
        lineEdit_tax->setText(QString());
        lineEdit_totalAmount->setText(QString());
        label_6->setText(QCoreApplication::translate("Deposit_calc", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213, \321\200\321\203\320\261.  :", nullptr));
        lineEdit_accruedInterest->setText(QString());
        Capitalization->setText(QCoreApplication::translate("Deposit_calc", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label_11->setText(QCoreApplication::translate("Deposit_calc", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("Deposit_calc", "\320\262\321\213\320\277\320\273\320\260\321\202", nullptr));
        periodOfPay->setItemText(0, QCoreApplication::translate("Deposit_calc", "\320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\320\276", nullptr));
        periodOfPay->setItemText(1, QCoreApplication::translate("Deposit_calc", "\320\265\320\266\320\265\320\263\320\276\320\264\320\275\320\276", nullptr));

        pushButton_calc->setText(QCoreApplication::translate("Deposit_calc", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        pushButton_back->setText(QCoreApplication::translate("Deposit_calc", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Deposit_calc", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_9->setText(QCoreApplication::translate("Deposit_calc", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label_13->setText(QCoreApplication::translate("Deposit_calc", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\271, \321\200\321\203\320\261. :", nullptr));
        lineEdit_replenishment->setText(QString());
        lineEdit_withdrawal->setText(QString());
        label_14->setText(QCoreApplication::translate("Deposit_calc", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\201\320\275\321\217\321\202\320\270\320\271, \321\200\321\203\320\261. :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deposit_calc: public Ui_Deposit_calc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSIT_CALC_H
