QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
CONFIG += c++11 shared
DESTDIR = $${OUT_PWD}/../lib

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ColorsSelect/colorblock.cpp \
    ColorsSelect/colorbutton.cpp \
    ColorsSelect/colormenu.cpp \
    framelesswidget.cpp \
    helper.cpp \
    windowmovehelper.cpp \
    windowresizehelper.cpp

HEADERS += \
    ColorsSelect/colorblock.h \
    ColorsSelect/colorbutton.h \
    ColorsSelect/colormenu.h \
    framelesswidget.h \
    helper.h \
    windowmovehelper.h \
    windowresizehelper.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
