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
    notifyIcon->showMessage("ZOOMING ","un element ajoutée ",QSystemTrayIcon::Information,15000);
}

void Notification::notification_supprimer(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("ZOOMING","un element Supprimée",QSystemTrayIcon::Information,15000);
}

void Notification::notification_modifier(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("ZOOMING ","Un element est modifiée",QSystemTrayIcon::Information,15000);

}
