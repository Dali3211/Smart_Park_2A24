#include "connexion.h"

Connexion::Connexion(){}

bool Connexion::createconnect()
{
    bool test=false;
 db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");//inserer le nom de la source de données ODBC
db.setUserName("molka1");//inserer nom de l'utilisateur
db.setPassword("molka");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
