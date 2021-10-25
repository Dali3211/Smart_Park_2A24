#ifndef EVENMENT_H
#define EVENMENT_H
#include<QString>
#include<QSqlQoueryModel>

class evenment
{
public:
    void setNOM(QString n);
    void setDATEEV(QString n);
    void setID(int n);
    QString get_NOM(){return NOM;}
    QString get_DATEEV(){return DATEEV;}
    int get_ID(){return ID;}
    evenment();
    evenment(int,QString,QString);
    bool ajouter();
    QSqlQoueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();

private:
        QString NOM,DATEEV;
        int ID;
};

#endif // EVENMENT_H
