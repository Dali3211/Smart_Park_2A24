#include "visiteur.h"
#include <QDebug>
Visiteur::Visiteur()
{
cin=0;
nom="";
prenom="";
adresse="";
date_naissance="";
age=0;
}
Visiteur::Visiteur(int cin,QString nom,QString prenom,QString adresse,QString date_naissance,int age)
{
  this->cin=cin;
    this->age=age;
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;
  this->date_naissance=date_naissance;

}
int Visiteur::getcin(){return cin;}
int Visiteur::getage(){return age;}
QString Visiteur::getnom(){return  nom;}
QString Visiteur::getprenom(){return  prenom;}
QString Visiteur::getadresse(){return  adresse;}
QString Visiteur::getdate_naissance(){return  date_naissance;}


bool Visiteur::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO Visiteur (cin,nom,prenom,adresse,date_naissance,age) "
                    "VALUES (:cin,:nom, :prenom,:adresse,:date_naissance,:age)");

query.bindValue(":cin", cin);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":date_naissance", date_naissance);
query.bindValue(":age", age);



return    query.exec();
}
bool test_Cin(QString cin){
    if(cin.size()!=8)
    return true;

    for(int i = 0; i < cin.size(); i++) {


    if (!(cin[i] >= '0' && cin[i] <= '9'))
        return false ;

}
    return true;
}


QSqlQueryModel * Visiteur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Visiteur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_naissance"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
    return model;
}

bool Visiteur::supprimer(int cin)
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("Delete from Visiteur where cin = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}

bool Visiteur::modifier()
{   QSqlQuery query;
    query.prepare( "UPDATE Visiteur SET  nom=:nom,prenom=:prenom,adresse=:adresse,date_naissance=:date_naissance,age=:age WHERE cin=:cin");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":age",age);

 return query.exec();
}


bool Visiteur::supprimerTout()
{ QSqlQuery query;

   query.prepare("delete from visiteur ");

  return query.exec();
}


QSqlQueryModel *Visiteur::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM Visiteur " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
    return model;
}



QSqlQueryModel * Visiteur::tricroissant()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM Visiteur ORDER BY cin ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_naissance"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));

    return model;
}
QSqlQueryModel * Visiteur::trideccroissant()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM Visiteur ORDER BY cin DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_naissance"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
return model;
}


QSqlQueryModel * Visiteur::recherche(QString cls)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM Visiteur WHERE CIN LIKE '%"+cls+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_naissance"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
return model;
}
QSqlQueryModel*  Visiteur::rechercher_cin(int cin)
 { QString res_cin=QString::number(cin);
    QSqlQuery qry;


     qry.prepare("SELECT* FROM Visiteur where cin=:cin");
     qry.bindValue(":cin",res_cin);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);


    return model;



 }
QSqlQueryModel* Visiteur::wombo_combo(){

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select cin from Visiteur");
    return model;
}
int Visiteur::calculer_tot_visiteurs()
{
    int rows=0;
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM VISITEUR");
    query.exec();

    if(query.next()){
        rows = query.value(0).toInt();
    }

    return rows;
}
