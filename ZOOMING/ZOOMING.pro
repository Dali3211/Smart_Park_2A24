QT       += core gui sql network  multimedia multimediawidgets printsupport charts serialport
QT       += core gui printsupport
QT       += core gui sql charts multimedia multimediawidgets printsupport charts serialport quick svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animale.cpp \
    animaux.cpp \
    arduino.cpp \
    cage.cpp \
    connection.cpp \
    employee.cpp \
    evenment.cpp \
    exportexcelobject.cpp \
    fournisseur.cpp \
    gestion_animation.cpp \
    gestion_cage1.cpp \
    gestion_employee.cpp \
    gestion_fournisseur.cpp \
    gestion_visiteur.cpp \
    history.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    qrcode.cpp \
    smtp.cpp \
    visiteur.cpp

HEADERS += \
    animale.h \
    animaux.h \
    arduino.h \
    cage.h \
    connection.h \
    employee.h \
    evenment.h \
    exportexcelobject.h \
    fournisseur.h \
    gestion_animation.h \
    gestion_cage1.h \
    gestion_employee.h \
    gestion_fournisseur.h \
    gestion_visiteur.h \
    history.h \
    mainwindow.h \
    notification.h \
    qrcode.h \
    smtp.h \
    visiteur.h

FORMS += \
    animaux.ui \
    gestion_animation.ui \
    gestion_cage1.ui \
    gestion_employee.ui \
    gestion_fournisseur.ui \
    gestion_visiteur.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
