#ifndef GESTION_EMPLOYEE_H
#define GESTION_EMPLOYEE_H
#include"employee.h"

#include <QCompleter>
#include <QWidget>

namespace Ui {
class gestion_employee;
}

class gestion_employee : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_employee(QWidget *parent = nullptr);
    ~gestion_employee();




private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rech_clicked();

    void on_pb_tri_clicked();

    void on_tab_employee_activated(const QModelIndex &index);

    void on_pb_stat_clicked();

    void on_cin_rech_textChanged(const QString &arg1);

private:
    Ui::gestion_employee *ui;
    Employee E;
   // QTcpSocket *mSocket;
    QCompleter* Model_Completer;
};

#endif // GESTION_EMPLOYEE_H
