#ifndef ANIMALE_H
#define ANIMALE_H
#include<QString>

class animale
{
public:
    animale();
    void setid(QString n);
    void setespece(QString n);
    void setetat(QString n);
    void setnumcage(int n);
    void setdate(QString n);
    QString get_id();
    QString get_espece();
    QString get_etat();
    int get_numcage();
    QString get_date();

private:
     QString id, espece ,etat,date;
     int numcage;
};

#endif // ANIMALE_H
