#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gestion_animation.h"
#include "ui_gestion_animation.h"
#include <QMainWindow>
#include "gestion_cage1.h"
#include"animaux.h"
#include"gestion_visiteur.h"
#include"gestion_employee.h"
#include"gestion_fournisseur.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_gestionA_clicked();

    void on_gestionV_clicked();

    void on_gestionC_clicked();

    void on_gestionAni_clicked();

    void on_gestionE_clicked();

    void on_gestionF_clicked();

private:
    Ui::MainWindow *ui;
    gestion_animation *ga;
    gestion_cage1* gc;
    animaux * gan;
    gestion_visiteur *gv;
    gestion_employee* ge;
    gestion_fournisseur* gf;
};
#endif // MAINWINDOW_H
