#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include"dialog.h"
#include <QCoreApplication>
#include"chatserver.h"
#include "DuMessengerConnectionDialog.h"
#include <QFile>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Connection c;
    bool test= c.createconnect();
    MainWindow W;
    W.show();

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else

        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    return app.exec();
}
