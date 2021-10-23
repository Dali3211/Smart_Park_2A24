#include "animale.h"


animale::animale()
{
    id="";
    espece="";
    etat="";
    numcage=0;
    date="";
}

void animale::setid(QString n)
{
    id = n;
}
void animale::setespece(QString n)
{
    espece = n;
}
void animale::setetat(QString n)
{
    etat = n;
}
void animale::setnumcage(int n)
{
    numcage = n;
}
void animale::setdate(QString n)
{
    date = n;
}

QString animale::get_id()
{return id;}

QString animale::get_espece()
{return espece;}

QString animale::get_etat()
{return etat;}

int animale::get_numcage()
{return numcage;}

QString animale::get_date()
{return date;}
