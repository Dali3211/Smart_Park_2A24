#ifndef EVENMENT_H
#define EVENMENT_H
#include<QString>

class evenment
{
public:
    void setnom(QString n);
    void setdateEv(QString n);
    void setid(QString n);
    QString get_nom();
    QString get_dateEv();
    QString get_id();
    evenment();
private:
        QString nom,dateEv,id;
};

#endif // EVENMENT_H
