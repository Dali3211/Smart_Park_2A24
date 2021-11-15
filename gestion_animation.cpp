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
//test tuto git
#include <QThread>



Gestion_animation::Gestion_animation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_animation)
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
      player->setMedia(QUrl::fromLocalFile("qrc:/sound/bruit-pop-up.mp3"));


}

Gestion_animation::~Gestion_animation()
{
    delete ui;
}



void Gestion_animation::on_Valider_clicked()
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
       QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Ajout effectué\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
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


void Gestion_animation::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
             QSqlQuery qry;
             qry.prepare("select * from evenment where"
                         " IDEV='"+val+"' or NOMEV='"+val+"' or DATEEV='"+val+"'or HEUREEV='"+val+"' or MAILEV='"+val+"' ");
             if(qry.exec())
               {while (qry.next())
              { ui->lineEdit_IDEV_2->setText(qry.value(0).toString());
                ui->lineEdit_NOMEV_2->setText(qry.value(1).toString());
                ui->lineEdit_DATEEV_2->setText(qry.value(2).toString());
                ui->lineEdit_HEUREEV_2->setText(qry.value(3).toString());
                ui->lineEdit_MAILEV_2->setText(qry.value(4).toString());

                 }
             }
}



void Gestion_animation::on_Supprimer_clicked()
{


    int ID=ui->lineEdit_IDEV_2->text().toInt();
        bool test1=etmp.supprimer(ID);
    if(test1)
    {
        ui->tableView->setModel(etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("Suppression effevtuée\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
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

    void Gestion_animation::on_tableView_clicked(const QModelIndex &index)
    {
        ui->lineEdit_IDEV_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString());
            ui->lineEdit_NOMEV_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString());
              ui->lineEdit_DATEEV_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),2)).toString());
               ui->lineEdit_HEUREEV_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),3)).toString());
                ui->lineEdit_MAILEV_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString());
                 ui->rcpt->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString());
    }


void Gestion_animation::on_Modifier_clicked()
{



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


void Gestion_animation::on_TRI_clicked()
{
   // player->setMedia(QUrl::fromLocalFile("C:/Users/dhiaz/Bureau/evenment/bruit-pop-up.mp3"));


         if(player->state()==QMediaPlayer::PlayingState)
         {
             player->setPosition(0);
         }
         else if(player->state()==QMediaPlayer::StoppedState)
            {
                player->play();
                player->setVolume(100);
                qDebug()<<player->errorString();
                QThread::sleep(1);
         }
    evenment e;
    ui->tableView->setModel(etmp.tri());

}
void Gestion_animation::on_TRI_2_clicked()
{
    evenment e;
    ui->tableView->setModel(etmp.triN());
}
void Gestion_animation::on_rechEV_clicked()
{

    QString rech=ui->lineEdit_RECH->text();
        if(etmp.controlsaisieDate(rech))
        {
          ui->tableView->setModel(etmp.rechercherD(rech));
          ui->lineEdit_RECH->clear();
          }

}





void Gestion_animation::on_tabWidget_tabBarClicked(int index)
{
    index=1;
    ui->tableView->setModel(etmp.afficher());
}


void Gestion_animation::on_EXCEL_clicked()
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


void Gestion_animation::on_browseBtn_clicked()
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

void  Gestion_animation::browse()
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
void Gestion_animation::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp("dhia.zeddini.14@gmail.com",ui->mail_pass->text(), "Smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
//(const QString &from, const QString &to, const QString &subject, const QString &body)
    if( !files.isEmpty() )
        smtp->sendMail("dhia.zeddini.14@gmail.com", ui->rcpt->text() ,ui->sujet->text(), ui->msg->toPlainText(), files );
    else
        smtp->sendMail("dhia.zeddini.14@gmail.com", ui->rcpt->text() ,ui->sujet->text(),ui->msg->toPlainText());
}


void   Gestion_animation::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    //ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}








void Gestion_animation::myfunction()
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
void Gestion_animation::mydate()
{
  // qDebug() << "update..";

    QDate date = QDate::currentDate();
    QString date_text = date.toString("dd/MM/yyyy");

    ui->label_date->setText(date_text);

}



void Gestion_animation::on_calendarWidget_clicked(const QDate &date)
{
    QString date_t = date.toString("dd/MM/yyyy");
     ui->lineEdit_DATEEV->setText(date_t);

}







