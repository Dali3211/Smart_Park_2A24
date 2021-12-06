QT       += core gui sql
    quick
QT       +=serialport

QT+=sql
QT       += core gui charts
QT+=quick
SOURCES=localisation.cpp \
    arduino.cpp \
    calcul.cpp \
    qrcode.cpp
QT += svg
QT       += core gui sql printsupport


OTHER_FILES = localisation.qml
QT +=charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animale.cpp \
    animaux.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp

HEADERS += \
    animale.h \
    animaux.h \
    arduino.h \
    connection.h \
    mainwindow.h \
    notification.h \
    qrcode.h

FORMS += \
    animaux.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    calqlatr.qml \
    content/Button.qml \
    content/Display.qml \
    content/NumberPad.qml \
    content/calculator.js \
    content/images/paper-edge-left.png \
    content/images/paper-edge-right.png \
    content/images/paper-grip.png \
    localisation.qml


TEMPLATE = app

QT += qml quick
SOURCES += calcul.cpp




OTHER_FILES = calqlatr.qml \
    content/Button.qml \
    content/Display.qml \
    content/NumberPad.qml \
    content/calculator.js \
    content/images/paper-edge-left.png \
    content/images/paper-edge-right.png \
    content/images/paper-grip.png

target.path = $$[QT_INSTALL_EXAMPLES]/quick/demos/calqlatr
INSTALLS += target

