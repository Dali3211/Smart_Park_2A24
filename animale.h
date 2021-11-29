#ifndef ANIMALE_H
#define ANIMALE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class animale
{
public:
    animale();
    animale(int,QString,QString,int,QString,int);
    void setid(int n);
    void setespece(QString n);
    void setetat(QString n);
    void setnumcage(int n);
    void setdate(QString n);
    void setage(int n);

    int get_id();
    QString get_espece();
    QString get_etat();
    int get_numcage();
    QString get_date();
    int get_age();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int id,QString espece, QString etat,int numcage,QString date,int age );
    QSqlQueryModel *tricroissant();
    QSqlQueryModel *tricroissant_e();
    QSqlQueryModel *tridecroissant_e();
    QSqlQueryModel *recherche(QString);
    QSqlQueryModel *displayClause(QString cls);
    QSqlQueryModel *stat();
QSqlQueryModel*  rechercher_id(QString id);
QSqlQueryModel* wombo_combo();
bool supprimerTout();

private:
     QString  espece ,etat,date;
     int numcage, id,age;
};

#endif // ANIMALE_H
