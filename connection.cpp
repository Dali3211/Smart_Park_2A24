#include "connection.h"

//test tuto git

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données ODBC
db.setUserName("dali1");//inserer nom de l'utilisateur
db.setPassword("hammaali181201");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
