#include "evenment.h"
#include <QDebug>
#include<QSqlQueryModel>
#include <QSqlQuery>
#include<QString>
#include<QMessageBox>

evenment::evenment()
{
    NOMEV="";
    DATEEV="";
    IDEV=0;
    HEUREEV="";
    MAILEV="";
}
evenment::evenment(int IDEV,QString NOMEV,QString DATEEV,QString HEUREEV,QString MAILEV)
{
   this->IDEV=IDEV;
   this->NOMEV=NOMEV;
    this->DATEEV=DATEEV;
    this->HEUREEV=HEUREEV;
    this->MAILEV=MAILEV;

 }
/*QString evenment::get_NOM(){return NOM;}
QString evenment::get_DATEEV(){return DATEEV;}
int evenment::get_ID(){return ID;}*/

/*---------*/


bool evenment::ajouter()
{
    QSqlQuery query;
   QString res= QString::number(IDEV);
    query.prepare("INSERT INTO evenment ( IDEV,NOMEV, DATEEV,HEUREEV,MAILEV) "
                        "VALUES (:IDEV,:NOMEV, :DATEEV,:HEUREEV,:MAILEV)");
    query.bindValue(":IDEV", res);
    query.bindValue(":NOMEV", NOMEV);
    query.bindValue(":DATEEV", DATEEV);
    query.bindValue(":HEUREEV", HEUREEV);
    query.bindValue(":MAILEV", MAILEV);


    return    query.exec();
}



QSqlQueryModel * evenment::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from evenment");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEV"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMEV"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEEV "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEUREEV "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAILEV "));


        return model;
}


bool evenment::supprimer(int IDEV)
{
    QSqlQuery query;
    QString res= QString::number(IDEV);
    query.prepare("Delete from evenment where IDEV = :IDEV ");
    query.bindValue(":IDEV", res);


    return    query.exec();
}


bool evenment::modifier(int ID,QString NOMEV,QString DATEEV,QString HEUREEV,QString MAILEV)
{
    QSqlQuery query;
  // QString res= QString::number(IDEV);
    query.prepare("UPDATE evenment SET NOMEV=:NOMEV,DATEEV=:DATEEV,HEUREEV=:HEUREEV,MAILEV=:MAILEV WHERE IDEV=:IDEV");
   query.bindValue(":IDEV", ID);
    query.bindValue(":NOMEV", NOMEV);
    query.bindValue(":DATEEV", DATEEV);
    query.bindValue(":HEUREEV", HEUREEV);
    query.bindValue(":MAILEV", MAILEV);

    return    query.exec();

}

QSqlQueryModel* evenment::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM evenment ORDER BY DATEEV");
           return model;
}
QSqlQueryModel* evenment::triN()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM evenment ORDER BY NOMEV");
           return model;
}

QSqlQueryModel* evenment::rechercherD(QString DATEEV)
{
    QSqlQueryModel * model= new QSqlQueryModel();
        QString recher="select * from evenment where DATEEV like '%"+DATEEV+"%' ";
        model->setQuery(recher);
        return model;
}


QSqlQueryModel* evenment::rechercherID(int IDEV)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(IDEV);
       QString recher="select * from evenment where IDEV like '%"+res+"%' ";
       model->setQuery(recher);
       return model;
}



QSqlQueryModel * evenment::Find_EV()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT IDEV,NOMEV,DATEEV,HEUREEV,MAILEV FROM evenment");

    query.exec();
    model->setQuery(query);
    return model;
}
bool evenment::controlsaisieMail(QString saisi){
    int i,test1=0,test2=0;


            for (i=0;i<saisi.length();i++)
            {
     if( saisi[i]=="@")
          test1=1;
     if( saisi[i]==".")
         test2=1;
            }
    if((test1==1)&&(test2==1)){
        return true;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Email"),
                    QObject::tr("L'adresse Mail non valid.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }


}
bool evenment::controlsaisiechar(QString saisi,QString type){
    if(saisi.contains(QRegExp("^[A-Za-z ]+$")))
    {
        return true;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ID"),
                    QObject::tr("Le %1 contient un Caractére non valid.\n"
                                "Click Cancel to exit.").arg(type), QMessageBox::Cancel);
        return false;
    }


}
bool evenment::controlSaisieNumVide(int num,QString numm)
{

       if(std::to_string(num).length()==8)
               {
         return true;
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Numéro"),
                    QObject::tr("Le %1 doit avoir 8 chiffre .\n"
                                "Click Cancel to exit.").arg(numm), QMessageBox::Cancel);
        return false;
    }

}

bool evenment::controlSaisieCharVide(QString prenom,QString prenomm){

 if(prenom.length()!=0)
 {
         return true;
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ID"),
                    QObject::tr("Le champs de %1 est vide.\n"
                                "Click Cancel to exit.").arg(prenomm), QMessageBox::Cancel);
        return false;
    }

}

bool evenment::controlsaisieHeure(QString heure)
{
    int i,test1=0,test2=0;


            for (i=0;i<heure.length();i++)
            {
     if( heure[i]==":")
          test1=1;
     if( heure.length()==5)
         test2=1;
            }
    if((test1==1)&&(test2==1)){
        return true;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Email"),
                    QObject::tr("L'Heure non valid.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

}

bool evenment::controlsaisieDate(QString date)
{
    int i,test1=0,test2=0;
    for (i=0;i<date.length();i++)
    {
        if(date[2]=="/")
            test1=1;
          if(date[5]=="/")
              test2=1;

     }
    if((test1==1)&&(test2==1)&&(date.length()==10))
    {
        return true;
    }
      else {

                QMessageBox::critical(nullptr, QObject::tr("Email"),
                            QObject::tr("Date non valid.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                return false;
           }

}







