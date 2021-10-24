#include "employee.h"

Employee::Employee()
{
    cin="";
    prenom="";
    nom="";
    age=0;
    tache="";
}

void Employee::setnom(QString n)
{
    nom = n;
}
void Employee::setprenom(QString n)
{
    prenom = n;
}
void Employee::setcin(QString n)
{
    cin = n;
}
void Employee::setage(int n)
{
    age = n;
}
void Employee::settache(QString n)
{
    tache = n;
}

QString Employee::get_nom()
{return nom;}

QString Employee::get_prenom()
{return prenom;}

QString Employee::get_cin()
{return cin;}

int Employee::get_age()
{return age;}

QString Employee::get_tache()
{return tache;}
