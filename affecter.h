#ifndef AFFECTER_H
#define AFFECTER_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class affecter
{ private:
    QString nom;
    QString nomcad;
    QString prenom;
    int cin;
public:
    affecter();
    affecter(QString,QString,QString,int);
    bool affectercad();
    QSqlQueryModel *afficher(QString r);

};

#endif // AFFECTER_H
