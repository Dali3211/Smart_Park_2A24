#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QString>
class Employee
{
public:
    Employee();
    void setnom(QString n);
    void setprenom(QString n);
    void setcin(QString n);
    void setage(int n);
    void settache(QString n);
    QString get_cin();
    QString get_prenom();
    QString get_nom();
    int get_age();
    QString get_tache();

private:
     QString cin, prenom ,nom,tache;
     int age;
};

#endif // EMPLOYEE_H
