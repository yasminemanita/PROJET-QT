#include "affecter.h"

affecter::affecter()
{nom="";
    prenom="";
    nomcad="";
cin=0;
}
affecter::affecter(QString nom,QString prenom,QString nomcad,int cin){
    this->nom=nom;
    this->prenom=prenom;
    this->nomcad=nomcad;
    this->cin=cin;



}
bool affecter::affectercad(){



    QSqlQuery query; // naamlou biha lec commande taa ajout ou supp wala

    QString res= QString::number(cin);
    query.prepare("INSERT INTO AFFECTER (PRENOM,NOMCAD,NOM,CIN)"
                  "VALUES (:PRENOM, :NOMCAD, :NOM, :CIN)");
   query.bindValue(":PRENOM", prenom); // nsaker l valeur mte3i b hedehka
    query.bindValue(":NOMCAD", nomcad);


    query.bindValue(":NOM", nom);
    query.bindValue(":CIN", res);


    return    query.exec();




}

QSqlQueryModel * affecter ::afficher(QString r){

    QSqlQueryModel *model=new QSqlQueryModel(); // model taa affichage
    model->setQuery(r);
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOMCAD"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    return  model;



}



