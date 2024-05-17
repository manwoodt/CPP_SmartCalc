/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QDoubleSpinBox *doubleSpinBox_step;
    QDoubleSpinBox *doubleSpinBox_y_min;
    QDoubleSpinBox *doubleSpinBox_x_max;
    QLabel *frame_step;
    QLabel *frame_y_min;
    QLabel *frame_x_min;
    QDoubleSpinBox *doubleSpinBox_x_min;
    QLabel *frame_y_max;
    QDoubleSpinBox *doubleSpinBox_y_max;
    QLabel *frame_x_max;
    QCustomPlot *Graph;
    QFrame *frame_2;
    QPushButton *pushButton_deposit;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_div;
    QPushButton *pushButton_graph;
    QPushButton *pushButton_credit;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_0;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_1;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_3;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_6;
    QPushButton *pushButton_del;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_deg;
    QPushButton *pushButton_x;
    QPushButton *pushButton_mul;
    QLineEdit *InputString;
    QPushButton *pushButton_C;
    QLineEdit *insert_x;
    QPushButton *pushButton_log;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_leftBracket;
    QLabel *label;
    QPushButton *pushButton_rightBracket;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(793, 523);
        MainWindow->setStyleSheet(QString::fromUtf8("background: rgb(236, 255, 251)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(410, 430, 371, 81));
        frame->setStyleSheet(QString::fromUtf8("background: qradialgradient(spread:repeat, cx:0.0470936, cy:0.841136, radius:0.5, fx:0.546554, fy:0.847448, stop:0.512315 rgba(145, 228, 32, 255), stop:0.827586 rgba(215, 246, 106, 255))"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        doubleSpinBox_step = new QDoubleSpinBox(frame);
        doubleSpinBox_step->setObjectName(QString::fromUtf8("doubleSpinBox_step"));
        doubleSpinBox_step->setGeometry(QRect(300, 40, 61, 31));
        doubleSpinBox_step->setStyleSheet(QString::fromUtf8("color:black;"));
        doubleSpinBox_step->setMinimum(0.100000000000000);
        doubleSpinBox_step->setMaximum(10.990000000000000);
        doubleSpinBox_step->setSingleStep(0.100000000000000);
        doubleSpinBox_step->setValue(0.500000000000000);
        doubleSpinBox_y_min = new QDoubleSpinBox(frame);
        doubleSpinBox_y_min->setObjectName(QString::fromUtf8("doubleSpinBox_y_min"));
        doubleSpinBox_y_min->setGeometry(QRect(150, 40, 61, 31));
        doubleSpinBox_y_min->setStyleSheet(QString::fromUtf8("color:black;"));
        doubleSpinBox_y_min->setMinimum(-1000.000000000000000);
        doubleSpinBox_y_min->setMaximum(1000.990000000000009);
        doubleSpinBox_y_min->setValue(-5.000000000000000);
        doubleSpinBox_x_max = new QDoubleSpinBox(frame);
        doubleSpinBox_x_max->setObjectName(QString::fromUtf8("doubleSpinBox_x_max"));
        doubleSpinBox_x_max->setGeometry(QRect(80, 40, 61, 31));
        doubleSpinBox_x_max->setStyleSheet(QString::fromUtf8("color:black;"));
        doubleSpinBox_x_max->setMinimum(-1000.000000000000000);
        doubleSpinBox_x_max->setMaximum(1000.990000000000009);
        doubleSpinBox_x_max->setValue(10.000000000000000);
        frame_step = new QLabel(frame);
        frame_step->setObjectName(QString::fromUtf8("frame_step"));
        frame_step->setGeometry(QRect(300, 16, 51, 21));
        frame_step->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
" border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}"));
        frame_step->setAlignment(Qt::AlignCenter);
        frame_y_min = new QLabel(frame);
        frame_y_min->setObjectName(QString::fromUtf8("frame_y_min"));
        frame_y_min->setGeometry(QRect(150, 16, 51, 21));
        frame_y_min->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
" border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}"));
        frame_y_min->setAlignment(Qt::AlignCenter);
        frame_x_min = new QLabel(frame);
        frame_x_min->setObjectName(QString::fromUtf8("frame_x_min"));
        frame_x_min->setGeometry(QRect(10, 16, 51, 21));
        frame_x_min->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
" border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}"));
        frame_x_min->setAlignment(Qt::AlignCenter);
        doubleSpinBox_x_min = new QDoubleSpinBox(frame);
        doubleSpinBox_x_min->setObjectName(QString::fromUtf8("doubleSpinBox_x_min"));
        doubleSpinBox_x_min->setGeometry(QRect(10, 40, 61, 31));
        doubleSpinBox_x_min->setStyleSheet(QString::fromUtf8("color:black;"));
        doubleSpinBox_x_min->setMinimum(-1000.000000000000000);
        doubleSpinBox_x_min->setMaximum(1000.000000000000000);
        doubleSpinBox_x_min->setValue(-5.000000000000000);
        frame_y_max = new QLabel(frame);
        frame_y_max->setObjectName(QString::fromUtf8("frame_y_max"));
        frame_y_max->setGeometry(QRect(220, 16, 51, 21));
        frame_y_max->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
" border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}"));
        frame_y_max->setAlignment(Qt::AlignCenter);
        doubleSpinBox_y_max = new QDoubleSpinBox(frame);
        doubleSpinBox_y_max->setObjectName(QString::fromUtf8("doubleSpinBox_y_max"));
        doubleSpinBox_y_max->setGeometry(QRect(220, 40, 61, 31));
        doubleSpinBox_y_max->setStyleSheet(QString::fromUtf8("color:black;"));
        doubleSpinBox_y_max->setMinimum(-1000.000000000000000);
        doubleSpinBox_y_max->setMaximum(1000.990000000000009);
        doubleSpinBox_y_max->setValue(10.000000000000000);
        frame_x_max = new QLabel(frame);
        frame_x_max->setObjectName(QString::fromUtf8("frame_x_max"));
        frame_x_max->setGeometry(QRect(80, 16, 51, 21));
        frame_x_max->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
" border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius: 10px;\n"
"}"));
        frame_x_max->setAlignment(Qt::AlignCenter);
        Graph = new QCustomPlot(centralwidget);
        Graph->setObjectName(QString::fromUtf8("Graph"));
        Graph->setGeometry(QRect(410, 10, 371, 411));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 381, 501));
        frame_2->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0.315044, y1:0.290136, x2:0.630542, y2:0.744318, stop:0 rgba(24, 150, 93, 219), stop:0.871921 rgba(184, 255, 104, 211));"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButton_deposit = new QPushButton(frame_2);
        pushButton_deposit->setObjectName(QString::fromUtf8("pushButton_deposit"));
        pushButton_deposit->setGeometry(QRect(250, 430, 121, 61));
        QFont font;
        font.setPointSize(18);
        pushButton_deposit->setFont(font);
        pushButton_deposit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_mod = new QPushButton(frame_2);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(250, 370, 61, 61));
        pushButton_mod->setFont(font);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_tan = new QPushButton(frame_2);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(10, 370, 61, 61));
        pushButton_tan->setFont(font);
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(78, 214, 20);\n"
"}"));
        pushButton_dot = new QPushButton(frame_2);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(190, 370, 61, 61));
        pushButton_dot->setFont(font);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_div = new QPushButton(frame_2);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(310, 370, 61, 61));
        pushButton_div->setFont(font);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_graph = new QPushButton(frame_2);
        pushButton_graph->setObjectName(QString::fromUtf8("pushButton_graph"));
        pushButton_graph->setGeometry(QRect(10, 430, 121, 61));
        pushButton_graph->setFont(font);
        pushButton_graph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_credit = new QPushButton(frame_2);
        pushButton_credit->setObjectName(QString::fromUtf8("pushButton_credit"));
        pushButton_credit->setGeometry(QRect(130, 430, 121, 61));
        pushButton_credit->setFont(font);
        pushButton_credit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_atan = new QPushButton(frame_2);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(70, 370, 61, 61));
        pushButton_atan->setFont(font);
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"\n"
"border-bottom-right-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(78, 214, 20);\n"
"}"));
        pushButton_0 = new QPushButton(frame_2);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(130, 370, 61, 61));
        pushButton_0->setFont(font);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_cos = new QPushButton(frame_2);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(10, 310, 61, 61));
        pushButton_cos->setFont(font);
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(78, 214, 20);\n"
"}"));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 310, 61, 61));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 250, 61, 61));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(190, 250, 61, 61));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_minus = new QPushButton(frame_2);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(310, 250, 61, 61));
        pushButton_minus->setFont(font);
        pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_1 = new QPushButton(frame_2);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(130, 310, 61, 61));
        pushButton_1->setFont(font);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_sin = new QPushButton(frame_2);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(10, 250, 61, 61));
        pushButton_sin->setFont(font);
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"\n"
"border-top-left-radius: 30px;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(78, 214, 20);\n"
"}"));
        pushButton_acos = new QPushButton(frame_2);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(70, 310, 61, 61));
        pushButton_acos->setFont(font);
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(78, 214, 20);\n"
"}"));
        pushButton_asin = new QPushButton(frame_2);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(70, 250, 61, 61));
        pushButton_asin->setFont(font);
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(78, 214, 20);\n"
"}"));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 310, 61, 61));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_plus = new QPushButton(frame_2);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(310, 310, 61, 61));
        pushButton_plus->setFont(font);
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_6 = new QPushButton(frame_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(250, 250, 61, 61));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_del = new QPushButton(frame_2);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setGeometry(QRect(310, 130, 61, 61));
        pushButton_del->setFont(font);
        pushButton_del->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
"background: rgb(167, 255, 129);\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(255, 77, 108);\n"
"}"));
        pushButton_equal = new QPushButton(frame_2);
        pushButton_equal->setObjectName(QString::fromUtf8("pushButton_equal"));
        pushButton_equal->setGeometry(QRect(250, 130, 61, 61));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        pushButton_equal->setFont(font1);
        pushButton_equal->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_equal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
"background: rgb(167, 255, 129);\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_sqrt = new QPushButton(frame_2);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(70, 130, 61, 61));
        pushButton_sqrt->setFont(font);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-bottom-right-radius: 30px;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(190, 250, 126);\n"
"}"));
        pushButton_deg = new QPushButton(frame_2);
        pushButton_deg->setObjectName(QString::fromUtf8("pushButton_deg"));
        pushButton_deg->setGeometry(QRect(10, 130, 61, 61));
        pushButton_deg->setFont(font);
        pushButton_deg->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(190, 250, 126);\n"
"}"));
        pushButton_x = new QPushButton(frame_2);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setGeometry(QRect(130, 70, 61, 61));
        pushButton_x->setFont(font);
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_mul = new QPushButton(frame_2);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setGeometry(QRect(310, 190, 61, 61));
        QFont font2;
        font2.setPointSize(25);
        pushButton_mul->setFont(font2);
        pushButton_mul->setLayoutDirection(Qt::LeftToRight);
        pushButton_mul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        InputString = new QLineEdit(frame_2);
        InputString->setObjectName(QString::fromUtf8("InputString"));
        InputString->setGeometry(QRect(10, 10, 361, 61));
        InputString->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid gray;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"background: transparent;\n"
"\n"
"}\n"
"//rgb(185, 255, 104);\n"
"\n"
""));
        InputString->setMaxLength(255);
        InputString->setFrame(true);
        pushButton_C = new QPushButton(frame_2);
        pushButton_C->setObjectName(QString::fromUtf8("pushButton_C"));
        pushButton_C->setGeometry(QRect(10, 190, 121, 61));
        pushButton_C->setFont(font);
        pushButton_C->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
"background: rgb(167, 255, 129);\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(178, 17, 17)\n"
"}"));
        insert_x = new QLineEdit(frame_2);
        insert_x->setObjectName(QString::fromUtf8("insert_x"));
        insert_x->setGeometry(QRect(230, 70, 141, 61));
        insert_x->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid gray;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"background: transparent;\n"
"}\n"
"\n"
""));
        insert_x->setMaxLength(10);
        insert_x->setFrame(true);
        pushButton_log = new QPushButton(frame_2);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(10, 70, 61, 61));
        pushButton_log->setFont(font);
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"\n"
"border-top-left-radius: 30px;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(190, 250, 126);\n"
"}\n"
"rgb(136, 255, 243)"));
        pushButton_ln = new QPushButton(frame_2);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(70, 70, 61, 61));
        pushButton_ln->setFont(font);
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(190, 250, 126);\n"
"}"));
        pushButton_7 = new QPushButton(frame_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(130, 190, 61, 61));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_9 = new QPushButton(frame_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(250, 190, 61, 61));
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_8 = new QPushButton(frame_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(190, 190, 61, 61));
        pushButton_8->setFont(font);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        pushButton_leftBracket = new QPushButton(frame_2);
        pushButton_leftBracket->setObjectName(QString::fromUtf8("pushButton_leftBracket"));
        pushButton_leftBracket->setGeometry(QRect(130, 130, 61, 61));
        pushButton_leftBracket->setFont(font);
        pushButton_leftBracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(200, 90, 21, 21));
        label->setLayoutDirection(Qt::RightToLeft);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"\n"
"color: black;\n"
"background:transparent\n"
"}\n"
""));
        label->setFrameShape(QFrame::NoFrame);
        label->setAlignment(Qt::AlignCenter);
        pushButton_rightBracket = new QPushButton(frame_2);
        pushButton_rightBracket->setObjectName(QString::fromUtf8("pushButton_rightBracket"));
        pushButton_rightBracket->setGeometry(QRect(190, 130, 61, 61));
        pushButton_rightBracket->setFont(font);
        pushButton_rightBracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid grey;\n"
" background-color:  transparent;\n"
"color: black;\n"
"border-top-right-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-bottom-right-radius: 30px;\n"
"border-bottom-left-radius: 30px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(11, 213, 131)\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        frame_step->setText(QCoreApplication::translate("MainWindow", "step", nullptr));
        frame_y_min->setText(QCoreApplication::translate("MainWindow", "y_min", nullptr));
        frame_x_min->setText(QCoreApplication::translate("MainWindow", "x_min", nullptr));
        frame_y_max->setText(QCoreApplication::translate("MainWindow", "y_max", nullptr));
        frame_x_max->setText(QCoreApplication::translate("MainWindow", "x_max", nullptr));
        pushButton_deposit->setText(QCoreApplication::translate("MainWindow", "deposit", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_graph->setText(QCoreApplication::translate("MainWindow", "graph", nullptr));
        pushButton_credit->setText(QCoreApplication::translate("MainWindow", "credit", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_deg->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        InputString->setText(QString());
        pushButton_C->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_leftBracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_rightBracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
