#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QString>
#include"mainwindow.h"
#include"dialog.h"
#include"ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_login_clicked()
{
        QString pseudo = ui -> user->text();
        QString mdp = ui -> pass->text();
        if(pseudo=="root"  && mdp=="test")
        {   //hide();
            MainWindow w;

            QMessageBox::information(this,"se connecter","Bienvenue!");

            this->hide();
          }
        else { QMessageBox::warning(this,"se connecter","Vérifiez vos données!"); }

}
