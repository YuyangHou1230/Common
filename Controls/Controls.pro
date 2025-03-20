QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = control

TEMPLATE = lib
CONFIG += c++11 shared
DESTDIR = $${OUT_PWD}/../lib

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    $$PWD/Lineedit \
    $$PWD/SecondaryList

SOURCES += \
    Lineedit/searchlineedit.cpp \
    ipedit.cpp \
    loginform.cpp \
    SecondaryList/secondarylistwidget.cpp \
    SecondaryList/itemwidget.cpp \
    nofocusitemdelegate.cpp \
    tablemenu.cpp

HEADERS += \
    Lineedit/searchlineedit.h \
    ipedit.h \
    loginform.h \
    SecondaryList/secondarylistwidget.h \
    SecondaryList/itemwidget.h \
    nofocusitemdelegate.h \
    tablemenu.h

FORMS += \
    loginform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
