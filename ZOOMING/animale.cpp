#include "animale.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>
#include<QString>
#include<QMessageBox>



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextDocument>
#include <QDebug>
#include <QtPrintSupport/QPrinter>
#include<QIntValidator>
#include<QRegularExpression>
/*#include <QPieSeries>
#include <QPieSlice>*/
# include "notification.h"
#include <QPainter>
#include <QDebug>
#include <QSqlQueryModel>

#include <QSystemTrayIcon>

#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QDate>
#include<QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>
#include <string>
#include <vector>
#include<QDirModel>
#include <qrcode.h>
#include <string>
#include <iostream>
#include <fstream>
#include <QtSvg/QSvgRenderer>

animale::animale()
{
    id=0;
    espece="";
    etat="";
    numcage=0;
    date="";
    age=0;
}


animale::animale(int id,QString espece,QString etat,int numcage,QString date,int age)
{   this->id=id;
    this->espece=espece;
    this->etat=etat;
    this->numcage=numcage;
    this->date=date;
    this->age=age;

}



void animale::setid(int n)
{
    id = n;
}
void animale::setespece(QString n)
{
    espece = n;
}
void animale::setetat(QString n)
{
    etat = n;
}
void animale::setnumcage(int n)
{
    numcage = n;
}
void animale::setdate(QString n)
{
    date = n;
}
void animale::setage(int n)
{
    age = n;
}
int animale::get_id()
{
    return id;
}

QString animale::get_espece()
{return espece;}

QString animale::get_etat()
{return etat;}

int animale::get_numcage()
{return numcage;}

QString animale::get_date()
{return date;}

int animale::get_age()
{return age;}



bool animale::ajouter()
{
    QSqlQuery query;

    QString res= QString::number(id);
    QString num=QString::number(numcage);
    QString ag=QString::number(age);
    query.prepare("INSERT INTO ANIMALE (IDA,ESPECE,ETAT,NUMCAGE,DATEA,AGE)""Values(:id,:espece,:etat,:numcage,:date,:age)");

query.bindValue(":id",res);
query.bindValue(":espece",espece);
query.bindValue(":etat",etat);
query.bindValue(":numcage",num);
query.bindValue(":date",date);
query.bindValue(":age",ag);

if((etat !="bon") && (etat !="mauvais") )
{
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("etat doit etre bon ou mauvais\n""click cancel to exit."),
                             QMessageBox::Cancel);

return false;
}


else
return query.exec();


}


QSqlQueryModel* animale::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM ANIMALE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("espece"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_cage"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_ajout"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));

    return model;
}

bool animale::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from ANIMALE where IDA=:id");
    query.bindValue(0,id);

return query.exec();
}

bool animale::modifier(int id,QString espece, QString etat,int numcage,QString date,int age )
{
    QSqlQuery query;
    //QString id= QString::number(id_am);

    query.prepare("UPDATE ANIMALE SET ESPECE=:espece,ETAT=:etat,NUMCAGE=:numcage,DATEA=:date,AGE=:age WHERE IDA=:id");
    query.bindValue(":id", id);
    query.bindValue(":etat",etat);
    query.bindValue(":espece",espece);
    query.bindValue(":numcage",numcage);
    query.bindValue(":date",date);
    query.bindValue(":age",age);
    if((etat !="bon") && (etat !="mauvais") )
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                 QObject::tr("etat doit etre bon ou mauvais\n""click cancel to exit."),
                                 QMessageBox::Cancel);

    return false;
    }


    else


    return query.exec();
}




QSqlQueryModel * animale::tricroissant()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM ANIMALE ORDER BY IDA ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("espece"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_cage"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_ajout"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));


    return model;
}

QSqlQueryModel * animale::tricroissant_e()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM ANIMALE ORDER BY ESPECE ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("espece"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_cage"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_ajout"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));


    return model;
}

QSqlQueryModel * animale::tridecroissant_e()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM ANIMALE ORDER BY NUMCAGE ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("espece"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_cage"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_ajout"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));


    return model;
}




QSqlQueryModel *animale::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM ANIMALE " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("espece"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_cage"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_ajout"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));

    return model;
}


QSqlQueryModel * animale::recherche(QString cls)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM ANIMALE WHERE IDA LIKE '%"+cls+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("espece"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_cage"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_ajout"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));

return model;
}
QSqlQueryModel*  animale::rechercher_id(QString id)
 {

    QSqlQuery qry;


     qry.prepare("SELECT* FROM ANIMALE where IDA=:id");
     qry.bindValue(":id",id);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);


    return model;
}
QSqlQueryModel* animale::wombo_combo(){

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select IDA from ANIMALE");
    return model;
}


/*QSqlQueryModel * animale::stat()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT COUNT(ETAT) FROM ANIMALE");
    //model->setQuery("SELECT ESPECE, AVG(ETAT) FROM ANIMALE GROUP BY ESPECE");
    //model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("espece"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre"));
    //model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_cage"));
    //model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_ajout"));
    return model;
}*/

QSqlQueryModel * animale::stat()
{
    QSqlQueryModel * model=new QSqlQueryModel();
       model->setQuery("select ETAT,(count(ETAT)*100/ (select count(*)from ANIMALE)) as pourcentage from ANIMALE group by ETAT");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("etat"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("percentage"));
       return model;


}

bool animale::supprimerTout()
{ QSqlQuery query;

   query.prepare("delete from ANIMALE ");

  return query.exec();
}








