#ifndef ANIMAUX_H
#define ANIMAUX_H
#include "animale.h"
//#include"arduino.h"
#include <QWidget>
#include <QCompleter>
namespace Ui {
class animaux;
}

class animaux : public QWidget
{
    Q_OBJECT

public:
    explicit animaux(QWidget *parent = nullptr);
    ~animaux();
private slots:

    void on_pushButton_valider_a_clicked();

    void on_bt_supp_clicked();

    void on_pushButton_modifier_a_clicked();





    void on_pushButton_tri_clicked();



    void on_pushButton_recherche_clicked();

    void on_pushButton_stat_clicked();

    void on_table_animaux_activated(const QModelIndex &index);



    void on_pushButton_tri_espece_croi_clicked();

    void on_pushButton_tri_tri_espece_dec_clicked();

    //void on_pushButton_stat_2_clicked();



    void on_pushButton_chart_clicked();

    void on_pushButton_clicked();

    void on_id_supp_textChanged(const QString &arg1);

    void on_pushButton_imprimer_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_reset_clicked();

    void on_Localisation_clicked();





private:
    Ui::animaux *ui;
    animale A;
   // Arduino Ard;
    QCompleter* Model_Completer;
    QByteArray data; // variable contenant les données reçues

};


#endif // ANIMAUX_H
