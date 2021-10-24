#include "evenment.h"

evenment::evenment()
{
    nom="";
    dateEv="";
    id="";
   }
   void evenment::setnom(QString n){nom=n;}
   void evenment::setdateEv(QString n){dateEv=n;}
   void evenment::setid(QString n){id=n;}

   QString evenment::get_nom(){return nom;}
   QString evenment::get_dateEv(){return dateEv;}
   QString evenment::get_id(){return id;}
