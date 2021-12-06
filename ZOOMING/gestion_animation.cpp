#include "gestion_animation.h"
#include "ui_gestion_animation.h"
#include"evenment.h"
#include <QString>
#include<QDateEdit>
#include <QDate>
#include <QTabWidget>
#include<QMessageBox>
#include <iostream>
#include<QFile>
#include<QFileDialog>
#include <QMediaPlayer>
#include <QSound>
#include<QTextStream>
#include"exportexcelobject.h"
#include"smtp.h"
#include <QMultimedia>
#include <QMediaPlayer>
# include "notification.h"


#include <QThread>



gestion_animation::gestion_animation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestion_animation)
{
    ui->setupUi(this);
    ui->tableView->setModel((etmp.afficher()));
    QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(myfunction()));
     timer->start();
     QTimer *timer1 = new QTimer(this);
      connect(timer1, SIGNAL(timeout()), this, SLOT(mydate()));
      timer1->start();
      player= new QMediaPlayer(this);
      //player->setMedia(QUrl::fromLocalFile("qrc:/sound/bruit-pop-up.mp3"));

      Model_Completer =new QCompleter(this);
          Model_Completer->setModel(etmp.rechercherA());
          ui->lineEdit_RECH->setCompleter(Model_Completer);

}

gestion_animation::~gestion_animation()
{
    delete ui;
}



void gestion_animation::on_Valider_clicked()
{


    int IDEV=ui->lineEdit_IDEV->text().toInt();
    QString NOMEV=ui->lineEdit_NOMEV->text();
    QString DATEEV=ui->lineEdit_DATEEV->text();
    QString HEUREEV=ui->lineEdit_HEUREEV->text();
    QString MAILEV=ui->lineEdit_MAILEV->text();
    evenment e(IDEV,NOMEV,DATEEV,HEUREEV,MAILEV);

   if(e.controlSaisieNumVide(IDEV,"IDEV")&&e.controlSaisieCharVide(NOMEV,"NOMEV")&&e.controlsaisiechar(NOMEV,"NOMEV")
            &&e.controlsaisieMail(MAILEV)&&e.controlsaisieHeure(HEUREEV)&&e.controlsaisieDate(DATEEV))
    {
        bool test=e.ajouter();
    if(test)
    {
        ui->tableView->setModel((etmp.afficher()));
        Model_Completer =new QCompleter(this);
            Model_Completer->setModel(etmp.rechercherA());
            ui->lineEdit_RECH->setCompleter(Model_Completer);

       QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Ajout effectué\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
       player->setMedia(QUrl::fromLocalFile("C:\\Users\\dhiaz\\OneDrive\\Bureau\\evenment\\événement ajouté.mp3"));
                             player->play();
                             qDebug()<<player->errorString();
                             QThread::sleep(1);
                             N.notification_ajout();
    }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                    QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);

    ui->lineEdit_IDEV->clear();
     ui->lineEdit_NOMEV->clear();
       ui->lineEdit_DATEEV->clear();
         ui->lineEdit_HEUREEV->clear();
           ui->lineEdit_MAILEV->clear();
     }
}







void gestion_animation::on_Supprimer_clicked()
{



    Model_Completer =new QCompleter(this);
        Model_Completer->setModel(etmp.rechercherA());
        ui->lineEdit_RECH->setCompleter(Model_Completer);

    int ID=ui->lineEdit_IDEV_2->text().toInt();
        bool test1=etmp.supprimer(ID);
    if(test1)
    {
        ui->tableView->setModel(etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("Suppression effevtuée\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
        player->setMedia(QUrl::fromLocalFile("C:\\Users\\dhiaz\\OneDrive\\Bureau\\evenment\\événement supprimé.mp3"));
                              player->play();
                              qDebug()<<player->errorString();
                              QThread::sleep(1);
                              N.notification_supprimer();

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("Suppression non effevtué\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    ui->lineEdit_IDEV_2->clear();
     ui->lineEdit_NOMEV_2->clear();
       ui->lineEdit_DATEEV_2->clear();
         ui->lineEdit_HEUREEV_2->clear();
           ui->lineEdit_MAILEV_2->clear();

}

    void gestion_animation::on_tableView_clicked(const QModelIndex &index)
    {
        ui->lineEdit_IDEV_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString());
            ui->lineEdit_NOMEV_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString());
              ui->lineEdit_DATEEV_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),2)).toString());
               ui->lineEdit_HEUREEV_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),3)).toString());
                ui->lineEdit_MAILEV_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString());
                 ui->rcpt->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString());
    }


void gestion_animation::on_Modifier_clicked()
{


    Model_Completer =new QCompleter(this);
        Model_Completer->setModel(etmp.rechercherA());
        ui->lineEdit_RECH->setCompleter(Model_Completer);

    int IDEV=ui->lineEdit_IDEV_2->text().toInt();
    QString NOMEV=ui->lineEdit_NOMEV_2->text();
    QString DATEEV=ui->lineEdit_DATEEV_2->text();
    QString HEUREEV=ui->lineEdit_HEUREEV_2->text();
    QString MAILEV=ui->lineEdit_MAILEV_2->text();
   evenment e(IDEV,NOMEV,DATEEV,HEUREEV,MAILEV);

    if(e.controlSaisieNumVide(IDEV,"IDEV")&&e.controlSaisieCharVide(NOMEV,"NOMEV")&&e.controlsaisiechar(NOMEV,"NOMEV")
            &&e.controlsaisieMail(MAILEV)&&e.controlsaisieHeure(HEUREEV)&&e.controlsaisieDate(DATEEV))
                              {

                    bool test=e.modifier(IDEV,NOMEV,DATEEV,HEUREEV,MAILEV);

                 if(test)
                 {
                     ui->tableView->setModel(etmp.afficher());
                     QMessageBox::information(nullptr, QObject::tr("modifier un evenment"),
                                       QObject::tr("evenment  modifié.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                     player->setMedia(QUrl::fromLocalFile("C:\\Users\\dhiaz\\OneDrive\\Bureau\\evenment\\événement modifié.mp3"));
                                           player->play();
                                           qDebug()<<player->errorString();
                                           QThread::sleep(1);
                                           N.notification_modifier();
                  }

                       else
                           QMessageBox::critical(nullptr, QObject::tr("Modifier evenment"),
                                       QObject::tr("Erreur !.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);



                 QMessageBox::information(0,qApp->tr("Verification"),qApp->tr(" L'evenment a été modifiée."),QMessageBox::Yes);
                  ui->lineEdit_IDEV_2->clear();
                   ui->lineEdit_NOMEV_2->clear();
                     ui->lineEdit_DATEEV_2->clear();
                       ui->lineEdit_HEUREEV_2->clear();
                         ui->lineEdit_MAILEV_2->clear();
                }

}


void gestion_animation::on_TRI_clicked()
{


    evenment e;
    ui->tableView->setModel(etmp.tri());
    player->setMedia(QUrl::fromLocalFile("C:\\Users\\dhiaz\\OneDrive\\Bureau\\evenment\\tri.mp3"));
                          player->play();
                          qDebug()<<player->errorString();
                          QThread::sleep(1);

}
void gestion_animation::on_TRI_2_clicked()
{
    evenment e;
    ui->tableView->setModel(etmp.triN());
    player->setMedia(QUrl::fromLocalFile("C:\\Users\\dhiaz\\OneDrive\\Bureau\\evenment\\tri.mp3"));
                          player->play();
                          qDebug()<<player->errorString();
                          QThread::sleep(1);
}


void gestion_animation::on_TRI_3_clicked()
{
    evenment e;
    ui->tableView->setModel(etmp.triI());
    player->setMedia(QUrl::fromLocalFile("C:\\Users\\dhiaz\\OneDrive\\Bureau\\evenment\\tri.mp3"));
                          player->play();
                          qDebug()<<player->errorString();
                          QThread::sleep(1);
}




void gestion_animation::on_rechEV_clicked()
{

    QString rech=ui->lineEdit_RECH->text();
    Model_Completer =new QCompleter(this);
        Model_Completer->setModel(etmp.rechercherA());
        ui->lineEdit_RECH->setCompleter(Model_Completer);
        if(etmp.controlsaisieDate(rech))
        {

          ui->tableView->setModel(etmp.rechercherD(rech));
          ui->lineEdit_RECH->clear();
          }

}





void gestion_animation::on_tabWidget_tabBarClicked(int index)
{
    index=1;
    ui->tableView->setModel(etmp.afficher());
}


void gestion_animation::on_EXCEL_clicked()
{

   QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tableView);

    //colums to export
    obj.addField(0, "NOMEV", "char(20)");
    obj.addField(1, "DATEEV", "char(20)");
    obj.addField(2, "IDEV", "char(20)");
    obj.addField(3, "HEUREEV", "char(20)");
    obj.addField(4, "MAILEV", "char(20)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
     }
}


void gestion_animation::on_browseBtn_clicked()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );
}


void gestion_animation::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp("dhia.zeddini.14@gmail.com",ui->mail_pass->text(), "Smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
//(const QString &from, const QString &to, const QString &subject, const QString &body)
    if( !files.isEmpty() )
        smtp->sendMail("dhia.zeddini.14@gmail.com", ui->rcpt->text() ,ui->sujet->text(), ui->msg->toPlainText(), files );
    else
        smtp->sendMail("dhia.zeddini.14@gmail.com", ui->rcpt->text() ,ui->sujet->text(),ui->msg->toPlainText());
}


void   gestion_animation::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    //ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}








void gestion_animation::myfunction()
{
  // qDebug() << "update..";

    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if ((time.second() % 2)==  0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ' ;
    }
    ui->label_time->setText(time_text);

}
void gestion_animation::mydate()
{
  // qDebug() << "update..";

    QDate date = QDate::currentDate();
    QString date_text = date.toString("dd/MM/yyyy");

    ui->label_date->setText(date_text);

}



void gestion_animation::on_calendarWidget_clicked(const QDate &date)
{
    QString date_t = date.toString("dd/MM/yyyy");
     ui->lineEdit_DATEEV->setText(date_t);

}





void gestion_animation::on_lineEdit_RECH_textChanged(const QString &arg1)
{
   /*QString rech=ui->lineEdit_RECH->text();
    Model_Completer=new QCompleter(this);
        Model_Completer->setModel(etmp.rechercherA());
          ui->lineEdit_RECH->setCompleter(Model_Completer);
          QSqlQueryModel* Model_Complete=etmp.rechercherD(rech);
          if (Model_Complete != nullptr)
         {
              ui->tableView->setModel(etmp.rechercherD(rech));
              ui->lineEdit_RECH->clear();
         }*/
}


/*void gestion_animation::on_pushButton_10_clicked()
{
    QString page=ui->comboBox->currentText();
    if(page=="Gestion animaux")
    {
        gan=new animaux(this);
        gan->show();
    }
    else if(page=="Gestion cage")
    {
        gc= new gestion_cage1(this);
        gc->show();
    }
    else if(page=="Gestion visiteur")
    {
        gv= new gestion_visiteur(this);
        gv->show();
    }
    else if(page=="Gestion fournisseur")
    {
        gf=new gestion_fournisseur(this);
        gf->show();
    }
    else if(page=="Gestion employes")
    {    ge=new gestion_employee(this);
        ge->show();
    }
}*/

