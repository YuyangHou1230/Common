
# 使用自定义变量定义路径 $${varName} 取值
Path = $$PWD


SOURCES += \
    $${Path}/framelesswidget.cpp \
    $${Path}/helper.cpp \
    $${Path}/widget.cpp \
    $${Path}/windowmovehelper.cpp

HEADERS += \
    $${Path}/framelesswidget.h \
    $${Path}/helper.h \
    $${Path}/widget.h \
    $${Path}/windowmovehelper.h
