#include "cad.h"
#include "ui_cad.h"
#include<QMessageBox>
#include"cadeaux.h"

cad::cad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cad)
{
    ui->setupUi(this);
      ui->tabetudiant->setModel(tmpcad.afficher("select *from CADEAUX"));}

cad::~cad()
{
    delete ui;
}

void cad::on_pb_ajouter_clicked()
{
    QString nom= ui->lineEdit_3->text();
    int score = ui->lineEdit->text().toInt();
    //  QString type= ui->lineEdit_22->text();

     cadeaux e(nom,score);
     bool test=e.ajouter();
     if(test)
   {ui->tabetudiant->setModel(tmpcad.afficher("select *from CADEAUX"));//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter un cadeau"),
                     QObject::tr("cadeau ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un cadeau"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void cad::on_pb_supprimer_clicked()
{
    int score= ui->lineEdit_id_supprr->text().toInt();
        bool test=tmpcad.supprimer(score);
        if(test)
        {ui->tabetudiant->setModel(tmpcad.afficher("select *from CADEAUX"));//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un cadeau"),
                        QObject::tr("cadeau supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un cadeau"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}



void cad::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString r;
    r="select *from CADEAUX where SCORE like "+arg1;
    ui->tableView->setModel(tmpcad.afficher(r));
}

void cad::on_pushButton_clicked()
{
       ui->tabetudiant->setModel(tmpcad.triecin());
}

void cad::on_comboBox_activated(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(arg1=="nom")


        model->setQuery("select * from CADEAUX order by NOM");
    if(arg1=="score")
        model->setQuery("select * from CADEAUX order by SCORE");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SCORE"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
   ui->tabetudiant->setModel(model);
}
