#include "animaux.h"
#include "ui_animaux.h"

animaux::animaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::animaux)
{
    ui->setupUi(this);
}

animaux::~animaux()
{
    delete ui;
}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_animaux");//inserer le nom de la source de données ODBC
db.setUserName("dali1");//inserer nom de l'utilisateur
db.setPassword("hammaali181201");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


return  test;
}
