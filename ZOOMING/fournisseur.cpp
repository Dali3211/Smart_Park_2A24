#include"fournisseur.h"
#include <QDebug>
#include<QSqlQueryModel>
#include <QSqlQuery>
#include<QString>
#include<QMessageBox>

fournisseur::fournisseur()
{
    CINF=0;
    NOMF="";
    PRENOMF="";
    ADRESSEF="";
    MARCHANDISE="";
    PRIX=0;

}
fournisseur::fournisseur(int CINF, QString NOMF,QString PRENOMF,QString ADRESSEF,QString MARCHANDISE ,int PRIX)
{
    this->CINF=CINF;
    this->NOMF=NOMF;
    this->PRENOMF=PRENOMF;
    this->ADRESSEF=ADRESSEF;
    this->MARCHANDISE=MARCHANDISE;
    this->PRIX=PRIX;
}


bool fournisseur::ajouter()
{
    QSqlQuery query;
       QString res= QString::number(CINF);
       QString res2= QString::number(PRIX);
        query.prepare("INSERT INTO fournisseur ( CINF,NOMF, PRENOMF,ADRESSEF,MARCHANDISE,PRIX) "
                            "VALUES (:CINF,:NOMF, :PRENOMF,:ADRESSEF,:MARCHANDISE,:PRIX)");
        query.bindValue(":CINF", res);
        query.bindValue(":NOMF", NOMF);
        query.bindValue(":PRENOMF", PRENOMF);
        query.bindValue(":ADRESSEF", ADRESSEF);
        query.bindValue(":MARCHANDISE", MARCHANDISE);
        query.bindValue(":PRIX", res2);


        return    query.exec();
}



QSqlQueryModel * fournisseur::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fournisseur");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CINF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMF"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMF "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSEF "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MARCHANDISE "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX "));


        return model;
}


bool fournisseur::supprimer(int CINF)
{
    QSqlQuery query;
    QString res= QString::number(CINF);
    query.prepare("Delete from fournisseur where CINF = :CINF ");
    query.bindValue(":CINF", res);


    return    query.exec();
}

bool fournisseur::modifier(int CINF, QString NOMF,QString PRENOMF,QString ADRESSEF,QString MARCHANDISE,int PRIX )

{
    QSqlQuery query;
       query.prepare("UPDATE fournisseur SET NOMF=:NOMF,PRENOMF=:PRENOMF,ADRESSEF=:ADRESSEF,MARCHANDISE=:MARCHANDISE,PRIX=:PRIX WHERE CINF=:CINF");
       query.bindValue(":CINF", CINF);
       query.bindValue(":NOMF", NOMF);
       query.bindValue(":PRENOMF", PRENOMF);
       query.bindValue(":ADRESSEF", ADRESSEF);
       query.bindValue(":MARCHANDISE", MARCHANDISE);
       query.bindValue(":PRIX", PRIX);

       return    query.exec();
}
QSqlQueryModel* fournisseur::rechercherM(QString MARCHANDISE)
{
    QSqlQueryModel * model= new QSqlQueryModel();
            QString recher="select * from fournisseur where MARCHANDISE like '%"+MARCHANDISE+"%' ";
            model->setQuery(recher);
            return model;
}
QSqlQueryModel* fournisseur::triC()
{
    QSqlQueryModel * model= new QSqlQueryModel();
               model->setQuery("SELECT * FROM fournisseur ORDER BY CINF");
               return model;
}

QSqlQueryModel* fournisseur::triN()
{
    QSqlQueryModel * model= new QSqlQueryModel();
               model->setQuery("SELECT * FROM fournisseur ORDER BY NOMF");
               return model;
}

QSqlQueryModel* fournisseur::triA()
{
    QSqlQueryModel * model= new QSqlQueryModel();
               model->setQuery("SELECT * FROM fournisseur ORDER BY ADRESSEF");
               return model;
}









