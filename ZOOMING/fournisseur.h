#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include<QString>
#include<QSqlQueryModel>

class fournisseur
{
public:

    void setNOMF(QString n);
       void setPRENOMF(QString n);
       void setCINF(int n);
       void setADRESSEF(QString n);
       void setMARCHANDISE(QString n);
       QString get_NOMF(){return NOMF;}
       QString get_PRENOMF(){return PRENOMF;}
       int get_CINF(){return CINF;}
       QString get_ADRESSEF(){return ADRESSEF;}
         QString get_MARCHANDISE(){return MARCHANDISE;}
       fournisseur();
       fournisseur(int,QString,QString,QString,QString,int);
       bool ajouter();
       QSqlQueryModel * afficher();
       bool supprimer(int);
       bool modifier(int,QString,QString,QString,QString,int);
       QSqlQueryModel * rechercherM(QString);

       QSqlQueryModel * triC();
       QSqlQueryModel * triN();
       QSqlQueryModel * triA();






   private:
           QString NOMF,PRENOMF,ADRESSEF,MARCHANDISE;
           int CINF,PRIX;
};
#endif // FOURNISSEUR_H
