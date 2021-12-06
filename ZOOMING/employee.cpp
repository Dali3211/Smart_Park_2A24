#include "employee.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include<QMessageBox>
#include<string>
#include<QSqlQueryModel>

Employee::Employee()
{
    NOME="";
    PRENOME="";
    TACHE="";
    IDE="";
    CINE=0;
    AGEE=0;
}

Employee::Employee(QString NOM,QString PRENOM,QString TACH,QString ID,int CIN,int AGE)
{
    NOME = NOM;
    PRENOME = PRENOM;
    TACHE = TACH;
    IDE = ID;
    CINE = CIN;
    AGEE = AGE;
}


void Employee::setNOME(QString n){NOME = n;}

void Employee::setPRENOME(QString n){PRENOME = n;}

void Employee::setTACHE(QString n){TACHE = n;}

void Employee::setIDE(QString n){IDE = n;}

void Employee::setCINE(int n){CINE = n;}

void Employee::setAGEE(int n){AGEE = n;}

QString Employee::getNOME(){return NOME;}

QString Employee::getPRENOME(){return PRENOME;}

QString Employee::getTACHE(){return TACHE;}

QString Employee::getIDE(){return IDE;}

int Employee::getCINE(){return CINE ;}

int Employee::getAGEE(){return AGEE ;}

bool Employee::ajouter()
{
    QSqlQuery query;
    QString CINE_string= QString::number(CINE);
    QString AGEE_string= QString::number(AGEE);
          query.prepare("INSERT INTO EMPLOYEE (NOME, PRENOME, TACHE, CINE, IDE,AGEE) "
                        "VALUES (:forename, :surname, :tache, :cin, :id, :age)");
          query.bindValue(":forename", NOME);
          query.bindValue(":surname", PRENOME);
          query.bindValue(":tache", TACHE);
          query.bindValue(":cin", CINE_string);
          query.bindValue(":id", IDE);
          query.bindValue(":age", AGEE_string);
          return query.exec();
}

QSqlQueryModel* Employee::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT* FROM employee");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Tache"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Carte d'identité"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
          return model;
}

bool Employee::supprimer(int cin)
{
    QSqlQuery query;
    QString res2= QString::number(cin);
          query.prepare("Delete from EMPLOYEE where CINE=:cin");
          query.bindValue(":cin", res2);
          return query.exec();
}

//bool Employee::modifier(QString nom,QString prenom,QString tache,QString id,int cin/*int cine*/)
/*{
    QSqlQuery query;
   QString CIN_string= QString::number(cin);
    //QString CINE_string= QString::number(cine);
        query.prepare("UPDATE EMPLOYEE SET NOME =:forename, PRENOME =:surname, TACHE =:tache,CINE =:cin, IDE =:id  WHERE CINE = :cine");
        query.bindValue(":forename", nom);
        query.bindValue(":surname", prenom);
        query.bindValue(":tache", tache);
        query.bindValue(":cin", CIN_string);
        query.bindValue(":id", id);
        //query.bindValue(":cine", CINE_string);

        return query.exec();
}*/

bool Employee::modifier()
{   QSqlQuery query;
            query.prepare( "UPDATE EMPLOYEE SET  NOME =:forename, PRENOME =:surname, TACHE =:tache,CINE = :cin, IDE =:id,AGEE =:age  WHERE CINE = :cin");
            query.bindValue(":forename", NOME);
            query.bindValue(":surname", PRENOME);
            query.bindValue(":tache", TACHE);
            query.bindValue(":cin", CINE);
            query.bindValue(":id", IDE);
            query.bindValue(":age", AGEE);
         return query.exec();
}


QSqlQueryModel * Employee::recherche(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * FROM employee WHERE CINE LIKE '%"+cls+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Tache"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Carte d'identité"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
return model;
}



QSqlQueryModel * Employee::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM EMPLOYEE ORDER BY NOME ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Tache"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Carte d'identité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
    return model;
}

QSqlQueryModel * Employee::trier_prenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM EMPLOYEE ORDER BY PRENOME ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Tache"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Carte d'identité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
    return model;
}

QSqlQueryModel * Employee::trier_age()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM EMPLOYEE ORDER BY AGEE ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Tache"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Carte d'identité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
    return model;
}
QSqlQueryModel *Employee::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM employee " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Tache"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Carte d'identité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
    return model;
}

bool Employee::testCin(QString cin){
    if(cin.size()!=8)
    return false;

    for(int i = 0; i < cin.size(); i++) {


    if (!(cin[i] >= '0' && cin[i] <= '9'))
        return false;

}
    return true;
}

QSqlQueryModel*  Employee::rechercher_id(QString cin)
 {
    QSqlQuery qry;


     qry.prepare("SELECT* FROM EMPLOYEE where CINE=:cin");
     qry.bindValue(":cin",cin);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);


    return model;
}
QSqlQueryModel* Employee::wombo_combo(){

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select CINE from EMPLOYEE");
    return model;
}
