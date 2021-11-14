#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>

class Connexion
{
private:
    QSqlDatabase db;
public:
    Connexion();
    bool createconnect();
    void closeConnexion();
};

#endif // CONNEXION_H
