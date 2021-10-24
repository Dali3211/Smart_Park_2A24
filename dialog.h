#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-db");//inserer le nom de la source de données ODBC
db.setUserName("aziz");//inserer nom de l'utilisateur
db.setPassword("azizk");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

#endif // DIALOG_H
