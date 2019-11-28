#ifndef CAD_H
#define CAD_H

#include <QDialog>
#include "cadeaux.h"
namespace Ui {
class cad;
}

class cad : public QDialog
{
    Q_OBJECT

public:
    explicit cad(QWidget *parent = nullptr);
    ~cad();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::cad *ui;
     cadeaux tmpcad;
};

#endif // CAD_H
