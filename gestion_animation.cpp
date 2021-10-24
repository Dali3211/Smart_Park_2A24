#include "gestion_animation.h"
#include "ui_gestion_animation.h"


Gestion_animation::Gestion_animation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_animation)
{
    ui->setupUi(this);
}

Gestion_animation::~Gestion_animation()
{
    delete ui;
}

void evenment::setevenment(evenment e)
{
    ui->lineEdit_nom->setText(c.get_nom());
    //ui->dateEdit->setdateEv(c.get_dateEv());
    ui->lineEdit_ID->setText(c.get_ID());
}

//test tuto git



bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet-evenment");//inserer le nom de la source de données ODBC
db.setUserName("Soumaya");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
}
