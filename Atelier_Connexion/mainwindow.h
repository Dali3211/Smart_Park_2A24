#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMainWindow>
#include"employee.h"
#include"dialog.h"
#include <QCompleter>

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE
namespace Ui {
class MainWindow;
}
class QTcpSocket;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rech_clicked();

    void on_pb_tri_clicked();

    void on_tab_employee_activated(const QModelIndex &index);

    void on_pb_stat_clicked();


    void on_pb_server_clicked();

    void on_pb_envoyer_clicked();

    void on_pb_connecter_clicked();

    void on_cin_rech_cursorPositionChanged(int arg1, int arg2);

    void on_cin_rech_textChanged(const QString &arg1);



    void on_pb_login_clicked();

    void on_pb_envoyer_2_clicked();

    void on_pb_connecter_2_clicked();

private:
    Ui::MainWindow *ui;
    Employee E;
    QTcpSocket *mSocket;
    QCompleter* Model_Completer;
};

#endif // MAINWINDOW_H
