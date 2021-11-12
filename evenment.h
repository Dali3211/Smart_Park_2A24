#ifndef EVENMENT_H
#define EVENMENT_H
#include<QString>
#include<QSqlQueryModel>

class evenment
{
public:
    void setNOMEV(QString n);
    void setDATEEV(QString n);
    void setIDEV(int n);
    void setHEUREEV(QString n);
    void setMAILEV(QString n);
    QString get_NOMEV(){return NOMEV;}
    QString get_DATEEV(){return DATEEV;}
    int get_IDEV(){return IDEV;}
    QString get_HEUREEV(){return HEUREEV;}
      QString get_MAILEV(){return MAILEV;}
    evenment();
    evenment(int,QString,QString,QString,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();
   QSqlQueryModel *Find_EV();
  bool rechercherID(int );



   bool controlsaisiechar(QString,QString);
   bool controlSaisieNumVide(int , QString );
   bool controlSaisieCharVide (QString,QString);
   bool controlsaisieMail(QString );
   bool controlsaisieDate(QString );
   bool controlsaisieHeure(QString );

private:
        QString NOMEV,DATEEV,HEUREEV,MAILEV;
        int IDEV;
};

#endif // EVENMENT_H
