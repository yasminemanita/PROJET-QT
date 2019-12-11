#include "dialog.h"
#include "ui_dialog.h"
#include "client.h"
#include<mainwindow.h>
#include<QtDebug>
#include<QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
        ui->setupUi(this);
        connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));

       // controle de saisie
        QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
            QRegExp rx1("[0-9_]+");
            QValidator *validator = new QRegExpValidator(rx, this);
            QValidator *validator2 = new QRegExpValidator(rx1, this);
            ui->lineEdit_CIN->setValidator(validator2);
            ui->lineEdit_nom->setValidator(validator);
             ui->lineEdit_prenom->setValidator(validator);
            ui->lineEdit_adresse->setValidator(validator);

    ui->tabetudiant->setModel(tmpclient.afficher("select *from CLIENT_CRUD"));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pb_ajouter_clicked()
{     int cin = ui->lineEdit_CIN->text().toInt();
    QString nom= ui->lineEdit_nom->text();
       QString prenom= ui->lineEdit_prenom->text();

       QString adresse=ui->lineEdit_adresse->text();

     client e(cin,nom,prenom,adresse);
     bool test=e.ajouter();
     if(test)
   {ui->tabetudiant->setModel(tmpclient.afficher("select *from CLIENT_CRUD"));//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                     QObject::tr("client ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pb_supprimer_clicked()
{ int cin = ui->lineEdit_id_2->text().toInt();
    bool test=tmpclient.supprimer(cin);
    if(test)
    {ui->tabetudiant->setModel(tmpclient.afficher("select * from CLIENT_CRUD"));//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_lineEdit_textChanged(const QString &arg1)
{

    QString r;
    r="select *from CLIENT_CRUD where CIN like "+arg1;
    ui->tableView->setModel(tmpclient.afficher(r));
}



/*void Dialog::on_pushButton_2_clicked()
{
    hide();
}*/




void Dialog::on_pushButton_2_clicked()
{

   // ui->tabetudiant->setModel(tmpclient.triecin());
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENT_CRUD order by CIN");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    ui->tabetudiant->setModel(model);
}


/*void Dialog::on_pushButton_clicked()
{
    int cin=ui->lineEdit_5_modif->text().toInt();
        QString nom=ui->lineEdit_2_modif->text();
        QString prenom =ui->lineEdit_3_modif->text();
        QString adresse =ui->lineEdit_4_modif->text();

       // bool test=tmpclient.modifier();
        client e(cin,nom,prenom,adresse);
        bool test=e.modifier();

        if(test){ui->tabetudiant->setModel(tmpclient.afficher("select * from CLIENT_CRUD"));
            QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
            QObject::tr("successful.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
            QObject::tr("failed.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

*/


void Dialog::on_comboBox_activated(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(arg1=="nom")
        model->setQuery("select * from CLIENT_CRUD order by NOM");
    if(arg1=="prenom")
        model->setQuery("select * from CLIENT_CRUD order by PRENOM");
    if(arg1=="adresse")
        model->setQuery("select * from CLIENT_CRUD order by ADRESSE");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    ui->tabetudiant->setModel(model);



}

/*void Dialog::on_recherchercad_clicked()
{
    int cin = ui->rechcad->text().toInt();
           client c ;
               c=tmpclient.getclient(cin);

                    ui->nomaffecter->setText("jgkfkfkk");
                    ui->prenomaffecter->setText("fjdkddjj");
                    ui->cinclientaffecter->setText(ui->rechcad->text());
                         //   ui->nomcadaffecter->setText(c.get());


}

*/

void Dialog::on_pushButton_3_clicked()
{
    close();

}

void Dialog::sendMail()
{
    Smtp* smtp = new Smtp("yasmine.manita@esprit.tn","181JFT1294", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("yasmine.manita@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void Dialog::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP articles" ), tr( "Message sent!\n\n" ) );
}


void Dialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    client c;
     QString nom=ui->lineEdit_2->text();
     ui->tabetudiant->setModel(c.rechercher(nom));
}

void Dialog::on_tabetudiant_activated(const QModelIndex &index)
{
    QString val=ui->tabetudiant->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from CLIENT_CRUD where CIN='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or ADRESSE='"+val+"' ");
    if (qry.exec( ))
    {
                  while(qry.next())
                    {
                        ui->lineEdit_nom->setText(qry.value(0).toString());
                        ui->lineEdit_prenom->setText(qry.value(1).toString());
                        ui->lineEdit_CIN->setText(qry.value(2).toString());
                        ui->lineEdit_adresse->setText(qry.value(3).toString());


                    }
                }
}



void Dialog::on_pushButton_modifierclient_clicked()
{
    int cin=ui->lineEdit_CIN->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();
    client e(cin,nom,prenom,adresse);
    bool test=e.modifier();
    if(test){ui->tabetudiant->setModel(tmpclient.afficher("select * from CLIENT_CRUD"));


    }
}
