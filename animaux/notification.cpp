#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
Notification::Notification()
{

}

void Notification::notification_ajout()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Animaux ","nouveau Animal ajoutée ",QSystemTrayIcon::Information,15000);
}

void Notification::notification_supprimer(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Animaux ","Animal Supprimée",QSystemTrayIcon::Information,15000);
}

void Notification::notification_modifier(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Animaux ","Un Animal est modifiée",QSystemTrayIcon::Information,15000);

}
