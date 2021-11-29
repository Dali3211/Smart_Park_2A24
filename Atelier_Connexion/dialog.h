#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "employee.h"
#include "mainwindow.h"
#include<QFileInfo>
#include<QDebug>
#include<QtSql>
#include<QMainWindow>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pb_login_clicked();

private:
    Ui::Dialog *ui;
    Dialog *mDialog;

};

#endif // DIALOG_H
