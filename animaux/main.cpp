#include "mainwindow.h"
#include"animaux.h"
#include <QApplication>
#include"connection.h"
#include"QMessageBox"
#include<QGuiApplication>
#include<QQuickView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection c;
    bool test=c.createconnection();
    animaux w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

w.show();
    return a.exec();
}