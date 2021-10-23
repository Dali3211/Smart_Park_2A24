#ifndef ANIMAUX_H
#define ANIMAUX_H

#include <QDialog>

namespace Ui {
class animaux;
}

class animaux : public QDialog
{
    Q_OBJECT

public:
    explicit animaux(QWidget *parent = nullptr);
    ~animaux();

private:
    Ui::animaux *ui;
};

#endif // ANIMAUX_H
