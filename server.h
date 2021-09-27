#ifndef SERVER_H
#define SERVER_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QLineEdit>
#include <cstdlib>
#include <QGroupBox>
#include "animalheaders.h"
#include "client.h"
#include "linkedlist.h"


//Salim Erradi - Database
class Server
{
public:
    //To specify specific database to load
    Server();
    ~Server();
    void update(LinkedList<Animal>& listForA,LinkedList<Client>& listForC);
    void retrieve(LinkedList<Animal>& listForA,LinkedList<Client>& listForC);
    void openDataBase(const QString path);
    void closeDataBase();
    void editAnimal(QSqlQuery &db,Animal *a);
    void editClient(QSqlQuery &db,Client *c);
    void addAnimal(QSqlQuery &db,Animal *a);
    void addClient(QSqlQuery &db,Client *c);



private:
    QSqlDatabase db;
    QString firstName,lastName,age1,email1,phoneNumber1,gender1,playfulness,individualism,intelligence,discipline,assertiveness,spaciousness,energetic,appetite,clientActiveness,clientAffectionism,clientHabitatPreference,clientDiurnalNocturnal;
    QString name1,activeness,affectionism,diurnalNocturnal,habitatPreference,spec1,height1,weight1,type1,colour1,finnsSize,bodyLength,bodyPattern,build,wingSpan,beakColour,beakLength,mammalHairLength,mammalHairColour,scaleType;
    int ID,rank;

};

#endif // SERVER_H
