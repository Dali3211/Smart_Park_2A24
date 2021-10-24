#include "connection.h"

Connection::Connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-db");//inserer le nom de la source de données ODBC
    db.setUserName("aziz");//inserer nom de l'utilisateur
    db.setPassword("azizk");//inserer mot de passe de cet utilisateur

    if (db.open())
    test=true;
        return  test;
}

void Connection::closeConnection()
{
    db.close();
}
