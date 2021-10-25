#include "evenment.h"
#include <QDebug>

evenment::evenment()
{
    NOM="";
    DATEEV="";
    ID=0;
}
evenment::evenment(QString NOM,QString DATEEV,int ID)
{
   this->NOM=NOM;
    this->DATEEV=DATEEV;
    this->ID=ID;
 }

/*---------*/


bool evenment::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO evenment ( NOM, DATEEV,ID) "
                        "VALUES (:NOM, :DATEEV, :ID)");
    query.bindValue(":NOM", NOM);
    query.bindValue(":DATEEV", DATEEV);
    query.bindValue(":ID", ID);

    return    query.exec();
}



QSqlQoueryModel * evenment::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from evenment");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEEV "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));

        return model;
}


bool evenment::supprimer(int ID)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from evenment where ID = :ID ");
    query.bindValue(":ID", res);


    return    query.exec();
}


bool client::modifier(int ID)
{
    QSqlQuery query;
    QString res= QString::number(ID);
    query.prepare("UPDATE evenment SET ID=:ID,NOM=:NOM,DATEEV=:DATEEV WHERE ID=:ID");
    query.bindValue(":ID", ID);
    query.bindValue(":NOM", NOM);
    query.bindValue(":DATEEV", DATEEV);

    return    query.exec();

}


















