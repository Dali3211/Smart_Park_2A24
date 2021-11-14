#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "visiteur.h"
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
# include "notification.h"
#include "qrcode.h"
#include <QPainter>
#include <QDebug>

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




using namespace std;
using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;
Visiteur Vg;
MainWindow::MainWindow(QWidget *visiteur) :
    QMainWindow(visiteur),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_cin->setValidator(new QIntValidator(1000, 99999999, this));
    ui->le_age->setValidator(new QIntValidator(1000, 99999999, this));
    ui->lineEdit_nom->setMaxLength(15);
    ui->lineEdit_prenom->setMaxLength(15);
    ui->lineEdit_adresse->setMaxLength(15);
     ui->lineEdit_date_naissance->setMaxLength(10);

                QRegularExpression rx("\\b[0-9._%+-]+/[0-9.-]+/[0-9]+\\b",
                                              QRegularExpression::CaseInsensitiveOption);
                    ui->lineEdit_date_naissance->setValidator(new QRegularExpressionValidator(rx, this));

                    QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                  QRegularExpression::CaseInsensitiveOption);
                        ui->lineEdit_nom->setValidator(new QRegularExpressionValidator(rx1, this));
                        QRegularExpression rx2("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                      QRegularExpression::CaseInsensitiveOption);
                        ui->lineEdit_prenom->setValidator(new QRegularExpressionValidator(rx2, this));
                        QRegularExpression rx3("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                      QRegularExpression::CaseInsensitiveOption);
                        ui->lineEdit_adresse->setValidator(new QRegularExpressionValidator(rx3, this));




                        ui->lineEdit_6->setValidator(new QIntValidator(1000, 99999999, this));
                        ui->lineEdit_7->setMaxLength(15);
                        ui->lineEdit_8->setMaxLength(15);
                        ui->lineEdit_9->setMaxLength(15);

                                    QRegularExpression rx4("\\b[0-9._%+-]+/[0-9.-]+/[0-9]+\\b",
                                                                  QRegularExpression::CaseInsensitiveOption);
                                        ui->lineEdit_10->setValidator(new QRegularExpressionValidator(rx4, this));

                                        QRegularExpression rx5("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                      QRegularExpression::CaseInsensitiveOption);
                                            ui->lineEdit_7->setValidator(new QRegularExpressionValidator(rx5, this));
                                            QRegularExpression rx6("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                          QRegularExpression::CaseInsensitiveOption);
                                            ui->lineEdit_8->setValidator(new QRegularExpressionValidator(rx6, this));
                                            QRegularExpression rx7("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                          QRegularExpression::CaseInsensitiveOption);
                                            ui->lineEdit_9->setValidator(new QRegularExpressionValidator(rx7, this));




    ui->tableView->setModel(Vg.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{

    Notification N;
    int cin = ui->lineEdit_cin->text().toInt();
    int age = ui->le_age->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString date_naissance = ui->lineEdit_date_naissance->text();





    if (nom==NULL)
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom!!!!") ;
             QMessageBox::critical(0, qApp->tr("Ajout"),

                             qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

             ui->lineEdit_cin->clear();
             ui->le_age->clear();
             ui->lineEdit_nom->clear();
            ui->lineEdit_prenom->clear();
            ui->lineEdit_adresse->clear();
            ui->lineEdit_date_naissance->clear();

         }

      else if (prenom==NULL)
       {

           QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prenom!!!!") ;
           QMessageBox::critical(0, qApp->tr("Ajout"),

                           qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

            ui->lineEdit_cin->clear();
            ui->le_age->clear();
           ui->lineEdit_nom->clear();
          ui->lineEdit_prenom->clear();
           ui->lineEdit_adresse->clear();
          ui->lineEdit_date_naissance->clear();

       }
    else if (adresse==NULL)
     {

         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP adresse!!!!") ;
         QMessageBox::critical(0, qApp->tr("Ajout"),

                         qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

           ui->lineEdit_cin->clear();
           ui->le_age->clear();
         ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
         ui->lineEdit_adresse->clear();
        ui->lineEdit_date_naissance->clear();

     }


   else if (date_naissance==NULL)
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP date_naissance!!!!") ;
             QMessageBox::critical(0, qApp->tr("Ajout"),

                             qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);
             ui->lineEdit_cin->clear();
             ui->le_age->clear();
             ui->lineEdit_nom->clear();
            ui->lineEdit_prenom->clear();
            ui->lineEdit_adresse->clear();
            ui->lineEdit_date_naissance->clear();

         }



    else
    {

        Visiteur V(cin,age,nom,prenom,adresse,date_naissance);

        bool ajout = V.ajouter();
        if(ajout)
        {
            N.notification_ajouter();
            QMessageBox::information(nullptr, QObject::tr("ajout"),
                        QObject::tr("Visiteur ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(Vg.afficher());

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("ajout"),
                        QObject::tr("problème d'ajout.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_cin->clear();
        ui->le_age->clear();
          ui->lineEdit_nom->clear();
         ui->lineEdit_prenom->clear();
          ui->lineEdit_adresse->clear();
         ui->lineEdit_date_naissance->clear();

    }

    }

void MainWindow::on_pushButton_supprimer_clicked()
{
    Notification N;

    if(ui->tableView->currentIndex().row()==-1)
           QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                    QObject::tr("Veuillez Choisir un(e) visiteur(e) du Tableau.\n"
                                                "Click Ok to exit."), QMessageBox::Ok);
       else
       {   int cin=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();



           QString str = " Vous voulez vraiment supprimer \n le Visiteur :";
           int ret = QMessageBox::question(this, tr("Visiteur"),str,QMessageBox::Ok|QMessageBox::Cancel);

           switch (ret) {
           case QMessageBox::Ok:
               if (Vg.supprimer(cin)){
                   N.notification_supprimer();

                   QMessageBox::information(0, qApp->tr("Suppression"),

                                            qApp->tr("Visiteur suprimée"), QMessageBox::Ok);



                   ui->lineEdit_6->clear();
                   ui->le_afficher_age->clear();
                   ui->lineEdit_7->clear();
                   ui->lineEdit_8->clear();
                   ui->lineEdit_9->clear();
                   ui->lineEdit_10->clear();


               }
               else
               {

                   QMessageBox::critical(0, qApp->tr("Suppression"),
                                         qApp->tr("Visiteur non trouvé "), QMessageBox::Ok);
               }



               break;
           case QMessageBox::Cancel:

               break;
           default:
               // should never be reached
               break;
           }


       }
   ui->tableView->setModel(Vg.afficher());
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_6->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString());
     ui->lineEdit_7->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString());
      ui->lineEdit_8->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),2)).toString());
       ui->lineEdit_9->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),3)).toString());
        ui->lineEdit_10->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString());
        ui->le_afficher_age->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),5)).toString());
}

void MainWindow::on_pushButton_modifier_clicked()
{

    Notification N;
    int cin = ui->lineEdit_6->text().toInt();
    int age = ui->le_afficher_age->text().toInt();
    QString nom = ui->lineEdit_7->text();
    QString prenom = ui->lineEdit_8->text();
    QString adresse = ui->lineEdit_9->text();
    QString date_naissance = ui->lineEdit_10->text();

    if (nom==NULL)
         {
             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom!!!!") ;
             QMessageBox::critical(0, qApp->tr("Ajout"),

                             qApp->tr("Probleme de modification"), QMessageBox::Cancel);

            ui->lineEdit_6->clear();
            ui->le_afficher_age->clear();
            ui->lineEdit_7->clear();
            ui->lineEdit_8->clear();
            ui->lineEdit_9->clear();
            ui->lineEdit_10->clear();


         }

      else if (prenom==NULL)
       {

           QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prenom!!!!") ;
           QMessageBox::critical(0, qApp->tr("Ajout"),

                           qApp->tr("Probleme de modification"), QMessageBox::Cancel);

           ui->lineEdit_6->clear();
           ui->le_afficher_age->clear();
           ui->lineEdit_7->clear();
           ui->lineEdit_8->clear();
           ui->lineEdit_9->clear();
           ui->lineEdit_10->clear();

       }
    else if (adresse==NULL)
     {

         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP adresse!!!!") ;
         QMessageBox::critical(0, qApp->tr("Ajout"),

                         qApp->tr("Probleme de modification"), QMessageBox::Cancel);

         ui->lineEdit_6->clear();
         ui->le_afficher_age->clear();
         ui->lineEdit_7->clear();
         ui->lineEdit_8->clear();
         ui->lineEdit_9->clear();
         ui->lineEdit_10->clear();

     }


   else if (date_naissance==NULL)
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP date_naissance!!!!") ;
             QMessageBox::critical(0, qApp->tr("Ajout"),

                             qApp->tr("Probleme de modification"), QMessageBox::Cancel);



             ui->lineEdit_6->clear();
             ui->le_afficher_age->clear();
             ui->lineEdit_7->clear();
             ui->lineEdit_8->clear();
             ui->lineEdit_9->clear();
             ui->lineEdit_10->clear();

         }



    else
    {
    Visiteur V(cin,age,nom,prenom,adresse,date_naissance);

    bool ajout = V.modifier();
    if(ajout)
    {
        N.notification_modifier();
        QMessageBox::information(nullptr, QObject::tr("modification"),
                    QObject::tr("Visiteur modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_10->clear();
        ui->le_afficher_age->clear();

        ui->tableView->setModel(Vg.afficher());
    }
            else
    {



        QMessageBox::critical(nullptr, QObject::tr("modification"),
                    QObject::tr("problème de modification.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_10->clear();
        ui->le_afficher_age->clear();

    }

}
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView->setModel(Vg.tricroissant());
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView->setModel(Vg.trideccroissant());
}

void MainWindow::on_pushButton_clicked()
{
    QString cls = ui->lineEdit_11->text();
    ui->tableView->setModel(Vg.recherche(cls));

}

void MainWindow::on_pushButton_4_clicked()
{
    /*QString strStream;
                         QTextStream out(&strStream);

                          const int rowCount = ui->tableView->model()->rowCount();
                          const int columnCount = ui->tableView->model()->columnCount();
                         out <<  "<html>\n"
                         "<head>\n"
                                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                          <<  QString("<title>%1</title>\n").arg("strTitle")
                                          <<  "</head>\n"
                                          "<body bgcolor=#ffffff link=#5000A0>\n"

                                         //     "<align='right'> " << datefich << "</align>"
                                          "<center> <H1>Liste des Visiteurs</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                      // headers
                                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                      out<<"<cellspacing=10 cellpadding=3>";
                                      for (int column = 0; column < columnCount; column++)
                                          if (!ui->tableView->isColumnHidden(column))
                                              out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                      out << "</tr></thead>\n";

                                      // data table
                                      for (int row = 0; row < rowCount; row++) {
                                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                          for (int column = 0; column < columnCount; column++) {
                                              if (!ui->tableView->isColumnHidden(column)) {
                                                  QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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
*/
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView->model()->rowCount();
                     const int columnCount = ui->tableView->model()->columnCount();
                     QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                     out <<"<html>\n"
                           "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         << "<title>ERP - COMmANDE LIST<title>\n "
                         << "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                         "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  licence commerciale ******"+TT+" </strong></h1>"
                         "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                           "</br> </br>";
                     // headers
                     out << "<thead><tr bgcolor=#d6e5ff>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView->isColumnHidden(column)) {
                                 QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_5_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                    model->setQuery("select * from visiteur where AGE < 5 ");
                    float age=model->rowCount();
                    model->setQuery("select * from visiteur where AGE  between 5 and 12 ");
                    float agee=model->rowCount();
                    model->setQuery("select * from visiteur where AGE>12 ");
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
                    chart->setTitle("Pourcentage Par Age :Nombre Des enfants "+ QString::number(total));
                    chart->legend()->hide();
                    // Used to display the chart
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(1000,500);
                    chartView->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    Visiteur v1;

        bool test=v1.supprimerTout();

        QMessageBox msgBox;

        if(test)
           { msgBox.setText("reset  avec succes.");
            ui->tableView->setModel(v1.afficher());
           }
        else
            msgBox.setText("Echec de reset.!!!");
            msgBox.exec();

            ui->lineEdit_6->clear();
            ui->le_afficher_age->clear();
            ui->lineEdit_7->clear();
            ui->lineEdit_8->clear();
            ui->lineEdit_9->clear();
            ui->lineEdit_10->clear();



}
