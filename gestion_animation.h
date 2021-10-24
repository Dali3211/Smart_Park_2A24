#ifndef GESTION_ANIMATION_H
#define GESTION_ANIMATION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class Gestion_animation;
}

class Gestion_animation : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion_animation(QWidget *parent = nullptr);
    ~Gestion_animation();

private:
    Ui::Gestion_animation *ui;
};

#endif // GESTION_ANIMATION_H
