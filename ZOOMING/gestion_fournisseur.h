#ifndef GESTION_FOURNISSEUR_H
#define GESTION_FOURNISSEUR_H
#include"fournisseur.h"
#include <QWidget>

namespace Ui {
class gestion_fournisseur;
}

class gestion_fournisseur : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_fournisseur(QWidget *parent = nullptr);
    ~gestion_fournisseur();

private slots:
    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_Modifier_clicked();

    void on_Gestion_Fournisseur_tabBarClicked(int index);

    void on_recherche_clicked();

    void on_triC_clicked();

    void on_pushButton_triN_clicked();

    void on_pushButton_triA_clicked();

    void on_inprimer_clicked();

    void on_statistique_clicked();

private:
    Ui::gestion_fournisseur *ui;
    fournisseur f;
};

#endif // GESTION_FOURNISSEUR_H
