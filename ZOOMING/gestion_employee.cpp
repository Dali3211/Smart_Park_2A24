#include "gestion_employee.h"
#include "ui_gestion_employee.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextDocument>
#include <QDebug>
#include <QtPrintSupport/QPrinter>
#include<QIntValidator>
#include<QRegularExpression>
/*#include <QPieSeries>
#include <QPieSlice>*/
#include <QPainter>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>
#include <QDate>
#include<QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>
#include <string>
#include <vector>
#include<QDirModel>
#include <QCoreApplication>
#include"chatserver.h"
#include <QTcpSocket>
gestion_employee::gestion_employee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestion_employee)
{
    ui->setupUi(this);
    ui->le_cin->setValidator(new QIntValidator(0, 99999999, this));
    ui->nv_cin->setValidator(new QIntValidator(0, 99999999, this));
    ui->cin_rech->setValidator(new QIntValidator(0, 99999999, this));
    ui->cin_rech->setValidator(new QIntValidator(0, 99999999, this));
    QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
    ui->le_nom->setValidator(new QRegularExpressionValidator(rx1, this));
    ui->le_prenom->setValidator(new QRegularExpressionValidator(rx1, this));
    ui->le_tache->setValidator(new QRegularExpressionValidator(rx1, this));
    ui->nv_nom->setValidator(new QRegularExpressionValidator(rx1, this));
    ui->nv_prenom->setValidator(new QRegularExpressionValidator(rx1, this));
    ui->nv_tache->setValidator(new QRegularExpressionValidator(rx1, this));
    ui->tab_employee->setModel(E.afficher());
}

gestion_employee::~gestion_employee()
{
    delete ui;
}

void gestion_employee::on_pb_ajouter_clicked()
{
    QString nom = ui->le_nom->text();
        QString prenom = ui->le_prenom->text();
        int cin = ui->le_cin->text().toInt();
        QString id = ui->le_id->text();
        QString tache = ui->le_tache->text();
        int age = ui->le_age->text().toInt();
                if (E.testCin(ui->le_cin->text())==false)
                {

                QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP CIN!!!!") ;
                QMessageBox::critical(0, qApp->tr("Ajout"), qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

                 }
                 if (nom==NULL)
                 {
                     QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom!!!!") ;
                     QMessageBox::critical(0, qApp->tr("Ajout"),

                                     qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

                    /* ui->le_nom->clear();
                    ui->le_prenom->clear();
                     ui->le_cin->clear();
                    ui->le_id->clear();
                    ui->le_tache->clear();*/
                 }
               else if (prenom==NULL)
               {
                   QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prenom!!!!") ;
                   QMessageBox::critical(0, qApp->tr("Ajout"),

                                   qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);
               }
              /*else if (cin==NULL)
               {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP cin!!!!") ;
                 QMessageBox::critical(0, qApp->tr("Ajout"),

                                 qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);
              }*/

              else if (id==NULL)
              {
                     QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id!!!!") ;
                     QMessageBox::critical(0, qApp->tr("Ajout"),

                                     qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);
              }

              else if (tache==NULL)
              {
                        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP tache!!!!") ;
                        QMessageBox::critical(0, qApp->tr("Ajout"),

                                        qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);
               }

                 else if (age==NULL)
                 {
                     QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP age!!!!") ;
                     QMessageBox::critical(0, qApp->tr("Ajout"),

                                     qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);
                 }

              else {

        Employee E(nom,prenom,tache,id,cin,age);
        bool test = E.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectué\n"
                                                                           "Click Cancel to exist."), QMessageBox::Cancel);
            ui->tab_employee->setModel(E.afficher());
            ui->le_nom->clear();
            ui->le_prenom->clear();
            ui->le_cin->clear();
            ui->le_id->clear();
            ui->le_tache->clear();
            ui->le_age->clear();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Ajout non effectuè.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
       }
}


void gestion_employee::on_pb_supprimer_clicked()
{
    if(ui->tab_employee->currentIndex().row()==-1)
                   QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                            QObject::tr("Veuillez Choisir un(e) employee(e) du Tableau.\n"
                                                        "Click Ok to exit."), QMessageBox::Ok);
        else
        {
            Employee E1;E1.setCINE(ui->nv_cin->text().toInt());
            bool test=E1.supprimer(E1.getCINE());
            QString str = " Vous voulez vraiment supprimer \n l'employee :";
            int ret = QMessageBox::question(this, tr("employee"),str,QMessageBox::Ok|QMessageBox::Cancel);

                   switch (ret)
                   {
                   case QMessageBox::Ok:
                       if (E.supprimer(E1.getCINE())){

                           QMessageBox::information(0, qApp->tr("Suppression"),qApp->tr("employee suprimée"), QMessageBox::Ok);

                       }
                       else
                       {

                           QMessageBox::critical(0, qApp->tr("Suppression"), qApp->tr("employee non trouvé "), QMessageBox::Ok);
                       }
                       break;
                   case QMessageBox::Cancel:

                       break;
                   default:

                       break;
                   }
           }
           ui->tab_employee->setModel(E.afficher());
           ui->nv_nom->clear();
           ui->nv_prenom->clear();
            ui->nv_cin->clear();
           ui->nv_id->clear();
           ui->nv_tache->clear();
           ui->nv_age->clear();
}


void gestion_employee::on_pb_modifier_clicked()
{
    /*QString nom = ui->nv_nom->text();
        QString prenom = ui->nv_prenom->text();
        int cin = ui->cin_emp->text().toInt();
        QString id = ui->nv_id->text();
        QString tache = ui->nv_tache->text();
        int cine = ui->nv_cin->text().toInt();

           Employee E1;
           bool test=E1.modifier(nom,prenom,tache,id,cine,cin);

           if(test)
           {
               QMessageBox::information(nullptr,QObject::tr("ok"),
                                        QObject::tr("modification effectue\n""click cancel to exit."),
                                        QMessageBox::Cancel);
                                        ui->tab_employee->setModel(E.afficher());
           }

           else
               QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                        QObject::tr("modification non effectue\n""click cancel to exit."),
                                        QMessageBox::Cancel);*/



        QString nom = ui->nv_nom->text();
        QString prenom = ui->nv_prenom->text();
        QString id = ui->nv_id->text();
        QString tache = ui->nv_tache->text();
        int cin = ui->nv_cin->text().toInt();
        int age = ui->nv_age->text().toInt();
        /*if (E.testCin(ui->nv_cin->text())==false)
        {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP CIN!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"), qApp->tr("Probleme de modifiaction"), QMessageBox::Cancel);

         }*/
         if (nom==NULL)
        {
            QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom!!!!") ;
            QMessageBox::critical(0, qApp->tr("modifiaction"),

                            qApp->tr("Probleme de modifiaction"), QMessageBox::Cancel);

           /* ui->le_nom->clear();
           ui->le_prenom->clear();
            ui->le_cin->clear();
           ui->le_id->clear();
           ui->le_tache->clear();*/
        }
         else if (prenom==NULL)
         {
          QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prenom!!!!") ;
          QMessageBox::critical(0, qApp->tr("modifiaction"),

                          qApp->tr("Probleme de modifiaction"), QMessageBox::Cancel);
         }
        else if (cin==NULL )
        {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP cin!!!!") ;
        QMessageBox::critical(0, qApp->tr("modifiaction"),

                        qApp->tr("Probleme de modifiaction"), QMessageBox::Cancel);
        }
       else if (id==NULL)
       {
            QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id!!!!") ;
            QMessageBox::critical(0, qApp->tr("modifiaction"),

                            qApp->tr("Probleme de modifiaction"), QMessageBox::Cancel);
       }
       else if (tache==NULL)
       {
               QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP tache!!!!") ;
               QMessageBox::critical(0, qApp->tr("modifiaction"),

                               qApp->tr("Probleme de modifiaction"), QMessageBox::Cancel);
       }
         else if (age==NULL)
         {
          QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP age!!!!") ;
          QMessageBox::critical(0, qApp->tr("modifiaction"),

                          qApp->tr("Probleme de modifiaction"), QMessageBox::Cancel);
         }
        else
        {
        Employee E(nom,prenom,tache,id,cin,age);
               bool test = E.modifier();
               if(test){
                   QMessageBox::information(nullptr, QObject::tr("modification"),
                               QObject::tr("employee modifié.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                   ui->tab_employee->setModel(E.afficher());
                   ui->nv_nom->clear();
                   ui->nv_prenom->clear();
                    ui->nv_cin->clear();
                   ui->nv_id->clear();
                   ui->nv_tache->clear();
                   ui->nv_age->clear();

               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("modification"),
                               QObject::tr("problème de modification.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
        }
}


void gestion_employee::on_pb_rech_clicked()
{
    QString cls = ui->cin_rech->text();
        ui->tab_employee->setModel(E.recherche(cls));
        ui->cin_rech->clear();
}


void gestion_employee::on_pb_tri_clicked()
{
    if(ui->comboBox->currentText() == "par nom")
         ui->tab_employee->setModel(E.trier_nom());
        else if (ui->comboBox->currentText() == "par prenom")
         ui->tab_employee->setModel(E.trier_prenom());
        else if (ui->comboBox->currentText() == "par age")
         ui->tab_employee->setModel(E.trier_age());
}


void gestion_employee::on_tab_employee_activated(const QModelIndex &index)
{
    ui->nv_nom->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),0)).toString());
       ui->nv_prenom->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),1)).toString());
       ui->nv_tache->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),2)).toString());
       ui->nv_cin->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),3)).toString());
       ui->nv_id->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),4)).toString());
       ui->nv_age->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),5)).toString());
}


void gestion_employee::on_pb_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                        model->setQuery("select * from employee where AGEE < 5 ");
                        float age=model->rowCount();
                        model->setQuery("select * from employee where AGEE  between 20 and 45 ");
                        float agee=model->rowCount();
                        model->setQuery("select * from employee where AGEE>45 ");
                        float ageee=model->rowCount();
                        float total=age+agee+ageee;
                        QString a=QString("moins de 5 ans "+QString::number((age*100)/total,'f',2)+"%" );
                        QString b=QString("entre 20 et 45 Ans"+QString::number((agee*100)/total,'f',2)+"%" );
                        QString c=QString("+45 Ans"+QString::number((ageee*100)/total,'f',2)+"%" );
                        QPieSeries *series = new QPieSeries();
                        series->append(a,age);
                        series->append(b,agee);
                        series->append(c,ageee);
                if (age!=0)
                {QPieSlice *slice = series->slices().at(0);
                 slice->setLabelVisible();
                 slice->setPen(QPen());}
                if ( agee!=0)
                {
                         // Add label, explode and define brush for 2nd slice
                         QPieSlice *slice1 = series->slices().at(1);
                         //slice1->setExploded();
                         slice1->setLabelVisible();
                }
                if(ageee!=0)
                {
                         // Add labels to rest of slices
                         QPieSlice *slice2 = series->slices().at(2);
                         //slice1->setExploded();
                         slice2->setLabelVisible();
                }
                        // Create the chart widget
                        QChart *chart = new QChart();
                        // Add data to chart with title and hide legend
                        chart->addSeries(series);
                        chart->setTitle("Pourcentage Par Age :Nombre D'employees "+ QString::number(total));
                        chart->legend()->hide();
                        // Used to display the chart
                        QChartView *chartView = new QChartView(chart);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        chartView->resize(1000,500);
                        chartView->show();
}


void gestion_employee::on_cin_rech_textChanged(const QString &arg1)
{
    QString id=ui->cin_rech->text();

         Model_Completer=new QCompleter(this);
         Model_Completer->setModel(E.wombo_combo());
          ui->cin_rech->setCompleter(Model_Completer);
          QSqlQueryModel* Model_Complete=E.recherche(id);
          if (Model_Complete != nullptr)
         {
             ui->tab_employee->setModel(Model_Complete);
         }
}

