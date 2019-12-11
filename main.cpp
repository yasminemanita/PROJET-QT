#include "mainwindow.h"
#include <QApplication>
#include<QMessageBox>
#include"connexion.h"
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
       bool test=c.ouvrirconnexion();




       if (test){
          w.showMaximized();QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                         QObject::tr("connection successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                     }
                     else
                             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                         QObject::tr("connection failed.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
