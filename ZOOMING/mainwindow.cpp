#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"gestion_animation.h"
#include "ui_gestion_animation.h"
#include <QApplication>
#include<QDebug>
#include<QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_gestionA_clicked()
{
    QString user=ui->lineEdit_user->text();
    QString pwd=ui->lineEdit_pwd->text();
    if(((user=="admin")&&(pwd=="0000"))||((user=="employe")&&(pwd=="1111"))){
    ga= new gestion_animation(this);
    ga->show();
    }
}


void MainWindow::on_gestionV_clicked()
{
    QString user=ui->lineEdit_user->text();
    QString pwd=ui->lineEdit_pwd->text();
    if(((user=="admin")&&(pwd=="0000"))||((user=="employe")&&(pwd=="1111"))){
    gv=new gestion_visiteur(this);
    gv->show();
    }
}


void MainWindow::on_gestionC_clicked()
{
    QString user=ui->lineEdit_user->text();
    QString pwd=ui->lineEdit_pwd->text();
    if(((user=="admin")&&(pwd=="0000"))||((user=="employe")&&(pwd=="1111"))){
    gc= new gestion_cage1(this);
    gc->show();
}
}

void MainWindow::on_gestionAni_clicked()
{
    QString user=ui->lineEdit_user->text();
    QString pwd=ui->lineEdit_pwd->text();
    if(((user=="admin")&&(pwd=="0000"))||((user=="employe")&&(pwd=="1111"))){
    gan=new animaux(this);
    gan->show();
}
}
void MainWindow::on_gestionE_clicked()
{    QString user=ui->lineEdit_user->text();
     QString pwd=ui->lineEdit_pwd->text();
     if((user=="admin")&&(pwd=="0000")){
    ge=new gestion_employee(this);
    ge->show();
}
}

void MainWindow::on_gestionF_clicked()
{
    QString user=ui->lineEdit_user->text();
    QString pwd=ui->lineEdit_pwd->text();
    if(((user=="admin")&&(pwd=="0000"))||((user=="employe")&&(pwd=="1111"))){
    gf=new gestion_fournisseur(this);
    gf->show();
}
}
