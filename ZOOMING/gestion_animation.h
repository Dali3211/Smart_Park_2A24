#ifndef GESTION_ANIMATION_H
#define GESTION_ANIMATION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QWidget>
#include <QTabWidget>
#include <QTimer>
#include <QTime>
#include <QMediaPlayer>
#include"evenment.h"
#include "smtp.h"
#include <QCompleter>
#include <QDirModel>
#include"notification.h"

namespace Ui {
class gestion_animation;
}

class gestion_animation : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_animation(QWidget *parent = nullptr);
    ~gestion_animation();
private slots:

    void on_Valider_clicked();

  //  void on_tableView_activated(const QModelIndex &index);

    void on_Supprimer_clicked();

    void on_Modifier_clicked();

    void on_TRI_clicked();

   // void on_rechEV_clicked();


    //void fill_form(int);
    void on_tabWidget_tabBarClicked(int index);

    void on_EXCEL_clicked();


//    void browse();
    void mailSent(QString);



    void on_tableView_clicked(const QModelIndex &index);

    void on_browseBtn_clicked();

    void on_sendBtn_clicked();

    void on_rechEV_clicked();
    void myfunction();
    void mydate();



    void on_calendarWidget_clicked(const QDate &date);


    void on_TRI_2_clicked();


    void on_TRI_3_clicked();






    void on_lineEdit_RECH_textChanged(const QString &arg1);



private:
   Ui::gestion_animation *ui;
   evenment etmp;
   QMediaPlayer* player;
   QCompleter * Model_Completer;
  QStringList files;
  Notification N;

};

#endif // GESTION_ANIMATION_H
