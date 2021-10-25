#include "gestion_animation.h"
#include "ui_gestion_animation.h"
#include"evenment.h"
#include <QString>
#include<QDateEdit>
#include <QTabWidget>
#include<QMessageBox>


//test tuto git

void Gestion_animation::on_pushButton_valider_clicked()
{
    int ID=ui->lineEdit_ID->text().toInt();
    QString NOM=ui->lineEdit_NOM->text();
    QString DATEEV=ui->dateEdit->text();

    evenment e(ID,NOM,DATEEV);
    bool test=e.ajouter();
    if(test)
    {
        ui->tableView->setModel((etmp.afficher()));
       QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Ajout effevtué\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
    }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                    QObject::tr("Ajout non effevtué\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);



}

void Gestion_animation::on_pushButton_supprimer_clicked()
{
    int id=ui->lineEdit_MS->text().toInt();
    bool test=etmp.supprimer(ID);
    if(test)
    {
        ui->tableView->setModel((etmp.afficher()));
        QMessageBox::information(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("Suppression effevtuée\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("Suppression non effevtué\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
}

Gestion_animation::Gestion_animation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_animation)
{
    ui->setupUi(this);
    ui->tableView->setModel((etmp.afficher()));
}

Gestion_animation::~Gestion_animation()
{
    delete ui;
}











