#-------------------------------------------------
#
# Project created by QtCreator 2012-09-19T14:43:41
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
QT       += xml

TARGET = UnrealManifest
TEMPLATE = app


SOURCES += main.cpp\
	umanifest.cpp

HEADERS  += umanifest.h

FORMS    += umanifest.ui

RESOURCES += \
    UnrealManifest.qrc

CONFIG += static
static {
    DEFINES += STATIC
}
