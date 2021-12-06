#include "animaux.h"
#include "ui_animaux.h"
#include "animale.h"
#include "notification.h"
#include <QString>
#include <QTabWidget>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QObject>
#include <iostream>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QSqlQuery>
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
#include <QDesktopServices>
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
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QDate>
#include<QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>
#include <string>
#include <vector>
#include<QDirModel>
#include <qrcode.h>
#include <string>
#include <iostream>
#include <fstream>
#include <QtSvg/QSvgRenderer>
#include "arduino.h"


using qrcodegen::QrCode;

using namespace std;

animaux::animaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::animaux)
{
    ui->setupUi(this);

       ui->lineEdit_ID->setValidator(new QIntValidator(1000, 99999999, this));
       ui->lineEdit_Numcage->setValidator(new QIntValidator(1000, 99999999, this));

       ui->lineEdit_Espece->setMaxLength(15);

       ui->lineEdit_ID_3->setValidator(new QIntValidator(1000, 99999999, this));
       ui->lineEdit_Numcage_3->setValidator(new QIntValidator(1000, 99999999, this));

       ui->lineEdit_Espece_3->setMaxLength(15);




                       QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                     QRegularExpression::CaseInsensitiveOption);
                           ui->lineEdit_Espece->setValidator(new QRegularExpressionValidator(rx1, this));
     ui->lineEdit_Espece_3->setValidator(new QRegularExpressionValidator(rx1, this));


     Model_Completer=new QCompleter(this);
                                    Model_Completer->setModel(A.wombo_combo());
                         ui->id_supp->setCompleter(Model_Completer);



    ui->table_animaux->setModel(A.afficher());

/***************************************arduino********************************/
    ui->setupUi(this);
    int ret=Ard.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< Ard.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<Ard.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(Ard.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
/***********************************************************************/
}

animaux::~animaux()
{
    delete ui;
}





void animaux::on_pushButton_valider_a_clicked()
{
    Notification N;
    //animale a;
    //(int id,QString espece,QString etat,int numcage,QString date)

    int id=ui->lineEdit_ID_3->text().toInt();
    QString espece=ui->lineEdit_Espece_3->text();
    QString etat=ui->lineEdit_Etat_3->text();
    int numcage=ui->lineEdit_Numcage_3->text().toInt();
    QString date=ui->lineEdit_Date_3->text();
    int age=ui->lineEdit_Age_3->text().toInt();


    if (id==NULL)
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id!!!!") ;
                 QMessageBox::critical(0, qApp->tr("Ajout"),

                                 qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

                /* ui->lineEdit_ID->clear();
                ui->lineEdit_Etat->clear();
                 ui->lineEdit_Espece->clear();
                ui->lineEdit_Numcage->clear();
                ui->lineEdit_Date->clear();*/

             }

          else if (espece==NULL)
           {

               QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP espece!!!!") ;
               QMessageBox::critical(0, qApp->tr("Ajout"),

                               qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

              /* ui->lineEdit_ID->clear();
              ui->lineEdit_Etat->clear();
               ui->lineEdit_Espece->clear();
              ui->lineEdit_Numcage->clear();
              ui->lineEdit_Date->clear();*/

           }
        else if (etat==NULL)
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP etat!!!!") ;
             QMessageBox::critical(0, qApp->tr("Ajout"),

                             qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

             /*ui->lineEdit_ID->clear();
            ui->lineEdit_Etat->clear();
             ui->lineEdit_Espece->clear();
            ui->lineEdit_Numcage->clear();
            ui->lineEdit_Date->clear();*/

         }


       else if (numcage==NULL)
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP numcage!!!!") ;
                 QMessageBox::critical(0, qApp->tr("Ajout"),

                                 qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);
                /* ui->lineEdit_ID->clear();
                ui->lineEdit_Etat->clear();
                 ui->lineEdit_Espece->clear();
                ui->lineEdit_Numcage->clear();
                ui->lineEdit_Date->clear();*/

             }
    else if (age==NULL)
          {

              QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP age!!!!") ;
              QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);
             /* ui->lineEdit_ID->clear();
             ui->lineEdit_Etat->clear();
              ui->lineEdit_Espece->clear();
             ui->lineEdit_Numcage->clear();
             ui->lineEdit_Date->clear();*/

         }


else {

    animale a (id,espece,etat,numcage,date,age);

    bool test=a.ajouter();

    if(test)
    {
        N.notification_ajout();

        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("ajout effectue\n""click cancel to exit."),
                                 QMessageBox::Cancel);
        ui->table_animaux->setModel(A.afficher());


    }

    /*else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                 QObject::tr("ajout non effectue\n""click cancel to exit."),
                                 QMessageBox::Cancel);*/


}
}



void animaux::on_bt_supp_clicked()
{
    Notification N;
    animale a1;
    a1.setid(ui->lineEdit_ID->text().toInt());
    bool test=a1.supprimer(a1.get_id());
    QString cls = ui->lineEdit_ID->text();
        /*ui->table_animaux->setModel(A.recherche(cls));*/
    if(test )/*&& A.recherche(cls)!=nullptr*/
    {
        N.notification_supprimer();
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectue\n""click cancel to exit."),
                                 QMessageBox::Cancel);
        ui->table_animaux->setModel(A.afficher());

    }

    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                 QObject::tr("suppression non effectue\n""click cancel to exit."),
                                 QMessageBox::Cancel);


}

void animaux::on_pushButton_modifier_a_clicked()
{
    Notification N;
    int id,numcage,age;
    QString etat,espece,date;

    id=A.get_id();
    cout<<"id is"<<id;
    numcage=A.get_numcage();
    etat=A.get_etat();
    espece=A.get_espece();
    date=A.get_date();
    age=A.get_age();



    int id1=ui->lineEdit_ID->text().toInt();
    QString espece1=ui->lineEdit_Espece->text();
    QString etat1=ui->lineEdit_Etat->text();
    int numcage1=ui->lineEdit_Numcage->text().toInt();
    QString date1=ui->lineEdit_Date->text();
    int age1=ui->lineEdit_Age->text().toInt();
    //animale a;//(id,espece,etat,numcage,date);
    animale a;//(id,espece,etat,numcage,date);
    bool test=a.modifier(id1,espece1,etat1,numcage1,date1,age1);
    //bool test=a.modifier(id,espece,etat,numcage,date);
/*

if(id1==0)
{
     id1=id;
   }

  if(espece1==NULL)
  {
     espece1=espece;

  }


  if(etat1=="")
  {
     etat1=etat;
  }

    if(numcage1==0)
    {
     numcage1=numcage;
    }

    if(date1=="00/00/0000")
    {
     date1=date;
    }*/
    if (id1==NULL)
             {
                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id!!!!") ;
                 QMessageBox::critical(0, qApp->tr("Ajout"),

                                 qApp->tr("Probleme de modification"), QMessageBox::Cancel);

                /*ui->lineEdit_6->clear();
                ui->lineEdit_7->clear();
                ui->lineEdit_8->clear();
                ui->lineEdit_9->clear();
                ui->lineEdit_10->clear();*/


             }

          else if (etat1==NULL)
           {

               QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP etat!!!!") ;
               QMessageBox::critical(0, qApp->tr("Ajout"),

                               qApp->tr("Probleme de modification"), QMessageBox::Cancel);

               /*ui->lineEdit_6->clear();
               ui->lineEdit_7->clear();
               ui->lineEdit_8->clear();
               ui->lineEdit_9->clear();
               ui->lineEdit_10->clear();*/

           }
        else if (espece1==NULL)
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP espece!!!!") ;
             QMessageBox::critical(0, qApp->tr("Ajout"),

                             qApp->tr("Probleme de modification"), QMessageBox::Cancel);

             /*ui->lineEdit_6->clear();
             ui->lineEdit_7->clear();
             ui->lineEdit_8->clear();
             ui->lineEdit_9->clear();
             ui->lineEdit_10->clear();*/

         }


       else if (date1==NULL)
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP date!!!!") ;
                 QMessageBox::critical(0, qApp->tr("Ajout"),

                                 qApp->tr("Probleme de modification"), QMessageBox::Cancel);



                 /**ui->lineEdit_6->clear();
                 ui->lineEdit_7->clear();
                 ui->lineEdit_8->clear();
                 ui->lineEdit_9->clear();
                 ui->lineEdit_10->clear();*/

             }
    else if (numcage1==NULL)
          {

              QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP num cage!!!!") ;
              QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme de modification"), QMessageBox::Cancel);



              /**ui->lineEdit_6->clear();
              ui->lineEdit_7->clear();
              ui->lineEdit_8->clear();
              ui->lineEdit_9->clear();
              ui->lineEdit_10->clear();*/

          }
    else if (age1==NULL)
          {

              QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP age!!!!") ;
              QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme de modification"), QMessageBox::Cancel);



              /**ui->lineEdit_6->clear();
              ui->lineEdit_7->clear();
              ui->lineEdit_8->clear();
              ui->lineEdit_9->clear();
              ui->lineEdit_10->clear();*/

          }




    else if(test)
    {
        N.notification_modifier();
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("midification effectue\n""click cancel to exit."),
                                 QMessageBox::Cancel);
                               ui->table_animaux->setModel(A.afficher());
                               ui->lineEdit_ID->clear();
                                             ui->lineEdit_Espece->clear();
                                             ui->lineEdit_Etat->clear();
                                             ui->lineEdit_Numcage->clear();
                                             ui->lineEdit_Date->clear();
                                             ui->lineEdit_Age->clear();

    }

    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                 QObject::tr("modification non effectue\n""click cancel to exit."),
                                 QMessageBox::Cancel);

}













void animaux::on_pushButton_tri_clicked()
{
     ui->table_animaux->setModel(A.tricroissant());

}

void animaux::on_pushButton_recherche_clicked()
{
   /* QString cls = ui->id_supp->text();
        ui->table_animaux->setModel(A.recherche(cls));*/
    QString id=ui->id_supp->text();

                    Model_Completer=new QCompleter(this);
                        Model_Completer->setModel(A.wombo_combo());
                        ui->id_supp->setCompleter(Model_Completer);
                          QSqlQueryModel* Model_Complete=A.recherche(id);
                          if (Model_Complete != nullptr)
                                                 {
                                                     ui->table_animaux->setModel(Model_Complete);
                                                 }
}

void animaux::on_pushButton_stat_clicked()
{
    ui->table_animaux->setModel(A.stat());
}

void animaux::on_table_animaux_activated(const QModelIndex &index)
{
    ui->lineEdit_ID->setText(ui->table_animaux->model()->data(ui->table_animaux->model()->index(index.row(),0)).toString());
    ui->lineEdit_Espece->setText(ui->table_animaux->model()->data(ui->table_animaux->model()->index(index.row(),1)).toString());
    ui->lineEdit_Etat->setText(ui->table_animaux->model()->data(ui->table_animaux->model()->index(index.row(),2)).toString());
    ui->lineEdit_Numcage->setText(ui->table_animaux->model()->data(ui->table_animaux->model()->index(index.row(),3)).toString());
    // ui->lineEdit_Date->setDate(ui->table_animaux->model()->data(ui->table_animaux->model()->index(index.row(),4)).toString());
    ui->lineEdit_Age->setText(ui->table_animaux->model()->data(ui->table_animaux->model()->index(index.row(),5)).toString());
}



void animaux::on_pushButton_tri_espece_croi_clicked()
{
    ui->table_animaux->setModel(A.tricroissant_e());
}

void animaux::on_pushButton_tri_tri_espece_dec_clicked()
{
    ui->table_animaux->setModel(A.tridecroissant_e());
}





void animaux::on_pushButton_chart_clicked()
{

    QSqlQueryModel * model= new QSqlQueryModel();
                    model->setQuery("select * from ANIMALE where AGE < 5 ");
                    float age=model->rowCount();
                    model->setQuery("select * from ANIMALE where AGE  between 5 and 12 ");
                    float agee=model->rowCount();
                    model->setQuery("select * from ANIMALE where AGE>12 ");
                    float ageee=model->rowCount();
                    float total=age+agee+ageee;
                    QString a=QString("moins de 5 ans "+QString::number((age*100)/total,'f',2)+"%" );
                    QString b=QString("entre 5 et 12 Ans"+QString::number((agee*100)/total,'f',2)+"%" );
                    QString c=QString("+12 Ans"+QString::number((ageee*100)/total,'f',2)+"%" );
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
                    chart->setTitle("Pourcentage Par Age :Nombre Des animaux "+ QString::number(total));
                    chart->legend()->hide();
                    // Used to display the chart
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(1000,500);
                    chartView->show();
}

void animaux::on_pushButton_clicked()
{

    if(ui->table_animaux->currentIndex().row()==-1)
              QMessageBox::information(nullptr, QObject::tr("QrCode"),
                                       QObject::tr("Veuillez Choisir un(e) visiteur(e) du Tableau.\n"
                                                   "Click Ok to exit."), QMessageBox::Ok);
          else
          {
               int id=ui->table_animaux->model()->data(ui->table_animaux->model()->index(ui->table_animaux->currentIndex().row(),0)).toInt();
               const QrCode qr = QrCode::encodeText(std::to_string(id).c_str(), QrCode::Ecc::LOW);
               std::ofstream myfile;
               myfile.open ("qrcode.svg") ;
               myfile << qr.toSvgString(1);
               myfile.close();
               QSvgRenderer svgRenderer(QString("qrcode.svg"));
               QPixmap pix( QSize(90, 90) );
               QPainter pixPainter( &pix );
               svgRenderer.render( &pixPainter );
               ui->label_5->setPixmap(pix);
          }

}

void animaux::on_id_supp_textChanged(const QString &arg1)
{
    QString id=ui->id_supp->text();

                    Model_Completer=new QCompleter(this);
                        Model_Completer->setModel(A.wombo_combo());
                        ui->id_supp->setCompleter(Model_Completer);
                          QSqlQueryModel* Model_Complete=A.recherche(id);
                          if (Model_Complete != nullptr)
                                                 {
                                                     ui->table_animaux->setModel(Model_Complete);
                                                 }

}

void animaux::on_pushButton_imprimer_clicked()
{
    QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = ui->table_animaux->model()->rowCount();
                         const int columnCount = ui->table_animaux->model()->columnCount();
                         QString TT = QDateTime::currentDateTime().toString();
                         out <<"<html>\n"
                               "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             << "<title>ERP - COMmANDE LIST<title>\n "
                             << "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                             "<h1 style=\"text-align: center;\"><strong> *****LISTE DES  licence commerciale *****"+TT+" </strong></h1>"
                                +"<img src=C://Users//MOLKA//OneDrive//Bureau//logo//logo />"
                             "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                               "</br> </br>";
                         // headers
                         out << "<thead><tr bgcolor=#d6e5ff>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->table_animaux->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->table_animaux->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->table_animaux->isColumnHidden(column)) {
                                     QString data =ui->table_animaux->model()->data(ui->table_animaux->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);

                         QPrinter printer;

                         QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                         if (dialog->exec() == QDialog::Accepted) {
                             document->print(&printer);
                         }

                         delete document;
}

void animaux::on_pushButton_pdf_clicked()
{

    QString strStream;
                                 QTextStream out(&strStream);

                                  const int rowCount = ui->table_animaux->model()->rowCount();
                                  const int columnCount = ui->table_animaux->model()->columnCount();
                                 out <<  "<html>\n"
                                 "<head>\n"
                                                  "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                                  <<  QString("<title>%1</title>\n").arg("strTitle")
                                                  <<  "</head>\n"
                                                  "<body bgcolor=#ffffff link=#5000A0>\n"

                                                 //     "<align='right'> " << datefich << "</align>"
                                                  "<center> <H1>Liste des Animaux</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                              // headers
                                              out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                              out<<"<cellspacing=10 cellpadding=3>";
                                              for (int column = 0; column < columnCount; column++)
                                                  if (!ui->table_animaux->isColumnHidden(column))
                                                      out << QString("<th>%1</th>").arg(ui->table_animaux->model()->headerData(column, Qt::Horizontal).toString());
                                              out << "</tr></thead>\n";

                                              // data table
                                              for (int row = 0; row < rowCount; row++) {
                                                  out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                                  for (int column = 0; column < columnCount; column++) {
                                                      if (!ui->table_animaux->isColumnHidden(column)) {
                                                          QString data = ui->table_animaux->model()->data(ui->table_animaux->model()->index(row, column)).toString().simplified();
                                                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                                      }
                                                  }
                                                  out << "</tr>\n";
                                              }
                                              out <<  "</table> </center>\n"
                                                  "</body>\n"
                                                  "</html>\n";

                                        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                          if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                                         QPrinter printer (QPrinter::PrinterResolution);
                                          printer.setOutputFormat(QPrinter::PdfFormat);
                                         printer.setPaperSize(QPrinter::A4);
                                        printer.setOutputFileName(fileName);

                                         QTextDocument doc;
                                          doc.setHtml(strStream);
                                          doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                          doc.print(&printer);
}

void animaux::on_pushButton_reset_clicked()
{
    animale a1;

            bool test=a1.supprimerTout();

            QMessageBox msgBox;

            if(test)
               { msgBox.setText("reset  avec succes.");
                ui->table_animaux->setModel(a1.afficher());
               }
            else
                msgBox.setText("Echec de reset.!!!");
                msgBox.exec();

                ui->lineEdit_ID->clear();
                ui->lineEdit_Espece->clear();
                ui->lineEdit_Etat->clear();
                ui->lineEdit_Numcage->clear();
                ui->lineEdit_Date->clear();
                ui->lineEdit_Age->clear();
}

void animaux::on_Localisation_clicked()
{
    QString p="belvedere";
    QDesktopServices::openUrl(QUrl("https://www.google.fr/maps/place/Parc+du+Belvedere/@36.8219964,10.1695377,17z/data=!3m1!4b1!4m5!3m4!1s0x12fd34819aa171bf:0x77a533be27aa925d!8m2!3d36.8219921!4d10.1717264"));
}


void animaux::update_label()
{
    data=Ard.read_from_arduino();

    if(data=="4")

        ui->label_3->setText("distance sup a 20 cm"); // si les données reçues de arduino via la liaison série sont égales à 1*/
     //alors afficher ON

    else if (data=="5")

        ui->label_3->setText("capteur de distance est arrete");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
    else if (data=="3")

        ui->label_3->setText("distance inf a 20 cm");

}


void animaux::on_pushButton_2_clicked()//capteur on
{
    Ard.write_to_arduino("1");
}

void animaux::on_pushButton_3_clicked()//capteur off
{
    Ard.write_to_arduino("5");
}

void animaux::on_pushButton_4_clicked()
{
    Ard.write_to_arduino("2");
}

void animaux::on_pushButton_5_clicked()
{
    Ard.write_to_arduino("0");
}
