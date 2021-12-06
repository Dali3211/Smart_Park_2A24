#ifndef GESTION_VISITEUR_H
#define GESTION_VISITEUR_H
#include <QCompleter>
#include <QTimer>
#include <QWidget>
#include"arduino.h"
#include"animaux.h"
#include "gestion_cage1.h"
#include"gestion_animation.h"
#include"gestion_visiteur.h"
#include"gestion_employee.h"
#include"gestion_fournisseur.h"
namespace Ui {
class gestion_visiteur;
}

class gestion_visiteur : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_visiteur(QWidget *parent = nullptr);
    ~gestion_visiteur();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();

       void on_tableView_clicked(const QModelIndex &index);

       void on_pushButton_modifier_clicked();

       void on_pushButton_2_clicked();

       void on_pushButton_3_clicked();

       void on_pushButton_clicked();

       void on_pushButton_4_clicked();

       void on_pushButton_5_clicked();

       void on_pushButton_6_clicked();

       void on_pushButton_7_clicked();

       void on_pushButton_modifier_2_clicked();

       //void on_lineEdit_11_textChanged(const QString &arg1);

      // void myfunction();

      /* void on_pushButton_8_clicked();
       void update_label();*/

       void on_pushButton_9_clicked();


      // void on_pushButton_10_clicked();

       void on_tabWidget_currentChanged(int index);

       void on_pushButton_11_clicked();
       void update_etat();



       void on_pushButton_10_clicked();

private:
    Ui::gestion_visiteur *ui;
    QCompleter* Model_Completer;
       QTimer *timer;
       QByteArray data;
           Arduino A;
           gestion_animation *ga;
           gestion_cage1* gc;
           animaux * gan;
           gestion_employee* ge;
           gestion_fournisseur* gf;
};

#endif // GESTION_VISITEUR_H
