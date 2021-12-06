#ifndef VISITEUR_H
#define VISITEUR_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QTime>

class Visiteur
{
public:
    Visiteur();
    Visiteur(int,QString,QString,QString,QString,int);
    int getcin();
    int getage();
    QString getnom();
    QString getprenom();
    QString getadresse();
    QString getdate_naissance();
    void setcin(int);
    void setage(int);
    void setnom(QString);
    void setprenom(QString);
    void setadresse(QString);
    void setdate_naissance(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel *displayClause(QString cls);
    QSqlQueryModel *trideccroissant();
    QSqlQueryModel *tricroissant();
    QSqlQueryModel *recherche(QString);
    bool supprimerTout();
    bool test_Cin(QString cin);
    QSqlQueryModel*  rechercher_cin(int cin);
    QSqlQueryModel* wombo_combo();
    int calculer_tot_visiteurs();


private:
 int cin,age;
 QString nom;
 QString prenom;
 QString adresse;
 QString date_naissance;
};


#endif // VISITEUR_H
