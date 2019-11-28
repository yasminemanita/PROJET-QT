#include "connexion.h"

connexion::connexion()
{

}
bool connexion::ouvrirconnexion(){
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");

     db.setDatabaseName("Projet_2A");

     db.setUserName("yasmine");

     db.setPassword("esprit19");

     if (db.open())
           test=true;
       return test;

}
void connexion ::fermerconnexion(){db.close();}
