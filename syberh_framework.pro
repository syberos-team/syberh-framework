include (syberh_framework.pri)

QT += core network widgets

TARGET = syberh_framework

TEMPLATE = lib

CONFIG += link_pkgconfig
CONFIG += C++11

PKGCONFIG += syberos-application syberos-qt-system syberos-qt

INCLUDEPATH += $$[QT_INSTALL_HEADERS]/../syberos_application \
                           $$[QT_INSTALL_HEADERS]/../framework
