#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
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


void MainWindow::on_pushButton_clicked()
{
    Employee e;
    e.setnom(ui->lineEdit_nom->text());
    e.setprenom(ui->lineEdit_nom->text());
    e.setcin(ui->lineEdit_cin->text());
    e.setage(ui->lineEdit_age->int);

}
