#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"client.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_5_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

  //  void on_pushButton_2_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_recherchercad_clicked();

    void on_affectercad_clicked();

private:
    Ui::Dialog *ui;
    client tmpclient;
};

#endif // DIALOG_H
