TEMPLATE = subdirs

QMAKE_CXXFLAGS += /source-charset:utf-8 /execution-charset:utf-8

SUBDIRS += \
    Controls \
    Examples \
    Helper \
    Utility

Examples.depends = Controls Helper Utility

CONFIG += qt

QT += widgets
