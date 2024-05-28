QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TEMPLATE = app
TARGET = CalcCPP

SOURCES += \
    ../MVC/controller.cpp \
    ../MVC/credit_model.cpp \
    ../MVC/model.cpp \
    ../MVC/view.cpp \
    credit/credit_calc_view.cpp \
    deposit/deposit_calc.cpp \
    main.cpp \
    qcustomplot/qcustomplot.cpp

HEADERS += \
    ../headers/controller.h \
    ../headers/credit_calc_view.h \
    ../headers/credit_model.h \
    ../headers/deposit_calc.h \
    ../headers/model.h \
    qcustomplot/qcustomplot.h \
    ../headers/view.h \

FORMS += \
    credit/credit_calc_view.ui \
    deposit/deposit_calc.ui \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
