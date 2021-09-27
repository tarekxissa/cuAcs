#include "database.h"

using namespace std;


DataBase::DataBase(){
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));// This is the driver for SQL LITE
}

DataBase::~DataBase(){
    delete db;
}

/*
 * Launching a Database
*/
void DataBase::launchDb(){

    db->setDatabaseName("/media/sf_Z_DRIVE"); //this is the path for output database
    //Opening Database.
    db->open();

    //Checking if DB is open or not.
    if(db->isOpen())
        qDebug() << "DB is on!";
    else
        qDebug() << "DB is not opened, error caused: " << db->lastError(); // Displaying the error message.

}

/*
 *  Closing a DataBase
*/
void DataBase::closeDb(){db->close();}


/*
 * Adding an animal to DataBase
*/



//void DataBase:: saveAnimalToDb(string& name,string& type,string& colour,string& age,string& gender,string& species,string& height, string& weight){


//}

//READ
