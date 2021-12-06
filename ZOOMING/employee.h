#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Employee
{
public:
    Employee();
    Employee(QString,QString,QString,QString,int,int);
    void setNOME(QString );
    void setPRENOME(QString );
    void setTACHE(QString );
    void setIDE(QString );
    void setCINE(int );
    void setAGEE(int );
    QString getNOME();
    QString getPRENOME();
    QString getTACHE();
    QString getIDE();
    int getCINE();
    int getAGEE();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    //bool modifier(QString,QString,QString,QString,int/*int*/);
    bool modifier();
    QSqlQueryModel* displayClause(QString);
    QSqlQueryModel* stat();

    QSqlQueryModel*  rechercher_id(QString id);
    QSqlQueryModel* wombo_combo();

    QSqlQueryModel * recherche(QString);
    QSqlQueryModel* trier_nom();
    QSqlQueryModel* trier_prenom();
    QSqlQueryModel* trier_age();
    bool testCin(QString);

private:
    QString NOME,PRENOME,TACHE,IDE;
    int CINE,AGEE;
};

#endif // EMPLOYEE_H
