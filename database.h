#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QDebug>
#include <string>

class DataBase{

    public:
        void launchDb();
        void closeDb();
        DataBase();
        ~DataBase();
        void fetchDB();  //Read all the storage in the database. THATS RETECIVe
         //void saveAnimalToDb(string&,string&,string&,string&,string&,string&,string&,string&); //SAVE ANIMAL TO DATABASE

private:

    QSqlDatabase *db;

};


#endif // DATABASE_H
