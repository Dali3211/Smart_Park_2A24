#include "gestion_animation.h"
#include "ui_gestion_animation.h"
#include"evenment.h"
#include <QString>
#include<QDateEdit>
#include <QTabWidget>
#include<QMessageBox>
#include <iostream>
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include"exportexcelobject.h"
#include"smtp.h"
//test tuto git



Gestion_animation::Gestion_animation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_animation)
{
    ui->setupUi(this);
    ui->tableView->setModel((etmp.afficher()));
}

Gestion_animation::~Gestion_animation()
{
    delete ui;
}



void Gestion_animation::on_Valider_clicked()
{
    int IDEV=ui->lineEdit_IDEV->text().toInt();
    QString NOMEV=ui->lineEdit_NOMEV->text();
    QString DATEEV=ui->lineEdit_DATREV->text();
    QString HEUREEV=ui->lineEdit_HEUREEV->text();
    QString MAILEV=ui->lineEdit_MAILEV->text();
    evenment e(IDEV,NOMEV,DATEEV,HEUREEV,MAILEV);
   /* bool idev,nomev,dateev,heureev,mailev;
    idev=e.controlSaisieNumVide(IDEV,"IDEV");*/

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
       ui->lineEdit_DATREV->clear();
         ui->lineEdit_HEUREEV->clear();
           ui->lineEdit_MAILEV->clear();
     }
}


void Gestion_animation::on_tableView_activated(const QModelIndex &index)
{
     ui->tableView->setModel((etmp.afficher()));
}


void Gestion_animation::on_Supprimer_clicked()
{
    int ID=ui->lineEdit_Supp->text().toInt();

    if(etmp.controlSaisieNumVide(ID,"ID"))
     {
        bool test1=etmp.supprimer(ID);
        bool test2=etmp.rechercherID(ID);
    if(test1&&test2)
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
    ui->lineEdit_Supp->clear();
    }
   /* else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("evenment n'existe pas\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);*/
}


void Gestion_animation::on_Modifier_clicked()
{
    int IDEV=ui->lineEdit_IDEV_2->text().toInt();
    QString NOMEV=ui->lineEdit_NOMEV_2->text();
    QString DATEEV=ui->lineEdit_DATREV_2->text();
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



                 QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr(" L'evenment a été modifiée."),QMessageBox::Yes);
                  ui->lineEdit_IDEV_2->clear();
                   ui->lineEdit_NOMEV_2->clear();
                     ui->lineEdit_DATREV_2->clear();
                       ui->lineEdit_HEUREEV_2->clear();
                         ui->lineEdit_MAILEV_2->clear();
                }

}


void Gestion_animation::on_TRI_clicked()
{
    evenment e;
    ui->tableView->setModel(etmp.tri());

}


void Gestion_animation::on_rechEV_clicked()
{
    QString rech=ui->lineEdit_RECH->text();
    if(etmp.controlsaisieDate(rech))
    {
      ui->tableView->setModel(etmp.rechercher(rech));
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
    evenment e;
    QSqlQueryModel * model=new QSqlQueryModel();
    model=e.Find_EV();
    QString textData= "IDEV;NOMEV;DATEEV;HEUREEV;MAILEV \n";
    int rows= model->rowCount();
    int columns=model->columnCount();
    // QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "Export Excel");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            textData += model->data(model->index(i,j)).toString();
            textData +=" ; ";
        }
        textData += "\n";
    }
    QString fileName = QFileDialog::getSaveFileName(this, "Export Excel", QString(), "*.csv");
    if (!fileName.isEmpty())
        if (QFileInfo(fileName).suffix().isEmpty())
            fileName.append(".csv");
    QFile csvfile(fileName);
    if(csvfile.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
       QTextStream out (&csvfile);
        out<<textData;
    }
    csvfile.close();
   /* QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tableView);

    //colums to export
    obj.addField(0, "entier", "char(20)");
    obj.addField(1, "combobox", "char(20)");
    obj.addField(2, "lineedit", "char(20)");
    obj.addField(3, "textedit", "char(20)");
    obj.addField(4, "dateedit", "char(20)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }*/
}


/*void Gestion_animation::on_browseBtn_clicked()
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
void Gestion_animation::sendMail()
{
    Smtp* smtp = new Smtp("zeddini.mohameddhiaa@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("zeddini.mohameddhiaa@esprit.tn", ui->rcpt->text() ,"mail de confirmation", ui->msg->toPlainText(), files );
    else
        smtp->sendMail("zeddini.mohameddhiaa@esprit.tn", ui->rcpt->text() ,"mail de confirmation",ui->msg->toPlainText());
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
*/
