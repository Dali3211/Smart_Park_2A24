#ifndef GESTION_ANIMATION_H
#define GESTION_ANIMATION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDialog>
#include"evenment.h"
namespace Ui {
class Gestion_animation;
}

class Gestion_animation : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion_animation(QWidget *parent = nullptr);
    ~Gestion_animation();
private slots:
     void on_pushButton_valider_clicked() ;
private:
    Ui::Gestion_animation *ui;
    evenment etmp;
};

#endif // GESTION_ANIMATION_H
