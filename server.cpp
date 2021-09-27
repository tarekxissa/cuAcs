#include "server.h"
#include "client.h"
#include "animal.h"
#include <QSqlQuery>
#include <iostream>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>
#define MAX_ANIMAL_SIZE 10
//Implementation from Salim Erradi - Persistent Storage

//SETTING NON PYHICAL ATTRIBUTES THROUGH OVERLOADING
//INCLUDING ATTRIBUTES OF EACH SUBCLASS INTO THE DATABASE

Server::Server(){}

Server::~Server(){}
/*
 This method opens an existing database that is stored in mySQL
 path - Path of where the database file is pulled up from
 */
void Server::openDataBase(const QString path){

    db = (QSqlDatabase::addDatabase("QSQLITE"));


    db.setDatabaseName(QTCUACS_ROOT + path);

    //To check if database has opened succesfully

    if (!db.open() ){
        qDebug("Database Connected : false");
    }
    else{
        qDebug("Database Connected : true");
    }


}

/*
 This method closes an existing database that is stored in mySQL
 */

void Server::closeDataBase(){
    db.close();

}


/*
 *  this function updates the animal from linked lists(animal and client) to db.
*/
void Server::update(LinkedList<Animal>& listForA, LinkedList<Client>& listForC){

    //This is going to be the table you're going to store data into. Ex. animalDbTable or clientDbTable
    QSqlQuery qryForDb(db);

    //Must call :text or :integer as placeholder so that you can bind value to that placeholder and update it to the database

     for (int i = 0; i < listForA.size(); i++){

            //If animal has been edited and it is a rexisting animal in the database called the editAnimal method to update changes

            if (listForA.get(i)->getEdited()==true && listForA.get(i)->getNewAnimal() == false){
                      editAnimal(qryForDb,listForA.get(i));

            }

            //If it is a new animal then we call addAnimal method to update new changes
            else if (listForA.get(i)->getNewAnimal() ==true ){
                      addAnimal(qryForDb,listForA.get(i));
             }

        }

     for (int i = 0; i < listForC.size();i++){
            if (listForC.get(i)->getEdited()==true){
                editClient(qryForDb,listForC.get(i));
            }
            else if (listForC.get(i)->getNewClient()==true){
                addClient(qryForDb,listForC.get(i));
            }

        }

}

/*
 * This method retrieves all the animals and clients from database and add both animal and clients into seperate linked lists
 */
void Server::retrieve(LinkedList<Animal>& listForA,LinkedList<Client>& listForC){

    string stringAge,stringGender,stringActiveness,stringPlayfulness,stringIndividualism,stringAffectionism, stringIntelligence,stringDiscipline,stringAssertiveness,stringSpaciousness,stringName,stringSpecies,stringColour,stringHeight,stringWeight,
            stringFinSize,stringBuild,stringWingSpan,stringBeakColour,stringBeakLength,stringHairColour,stringHairLength,stringScaleType,stringBodyPattern,stringBodyLength,stringType, stringEnergetic,stringNocturnal,stringHabitatPreference,stringAppetite,stringFirstName,stringLastName,stringEmail,stringPhoneNumber,holderForAttribute,holderFor2ndAttribute,holderFor3rdAttribute;

    //Traits that are the same for animal and clients
    QString qryValForFirstName,qryValForLastName,qryValForName,qryValForAge,qryValForGender,
    qryValForPlayfulness,qryValForIndividualism,qryValForIntelligence,qryValForDiscipline,
    qryValForAssertiveness,qryValForSpaciousness,qryValForEnergetic,qryValForAppetite,
    qryValForEmail,qryValForPhoneNumber,qryValForClientActiveness,qryValForClientAffectionism,
    qryValForClientHabibtatPreference,qryValForClientNocturnal,qryValForFinSize,qryValForBuild,qryValForHairLength,qryValForHairColour,qryValForWingSpan,qryValForBeakLength,qryValForBeakColour,qryValForScaleType,qryValForBodyPattern,qryValForBodyLength,
    qryValForSpecies,qryValForColour,qryValForHeight,qryValForWeight,qryValForType,qryValForActiveness,qryValForAffectionism,qryValForNocturnal,qryValForHabitatPreference;
    int rank,qryID;

    QSqlQuery qryForDbAnimalTable("SELECT * FROM animalDb",db);
    QSqlQuery qryForDbClientTable("SELECT * FROM clientDb",db);

//Used to iterate to next record in database

    while((qryForDbAnimalTable.next())){

            Animal *newAnimal;

            qryID = qryForDbAnimalTable.value(0).toInt();
            qryValForName = qryForDbAnimalTable.value(1).toString();
            qryValForSpecies = qryForDbAnimalTable.value(2).toString();
            qryValForAge = qryForDbAnimalTable.value(3).toString();
            qryValForGender = qryForDbAnimalTable.value(4).toString();
            qryValForColour = qryForDbAnimalTable.value(5).toString();
            qryValForHeight = qryForDbAnimalTable.value(6).toString();
            qryValForWeight = qryForDbAnimalTable.value(7).toString();
            qryValForType = qryForDbAnimalTable.value(8).toString();

            qryValForActiveness = qryForDbAnimalTable.value(9).toString();
            qryValForPlayfulness = qryForDbAnimalTable.value(10).toString();
            qryValForIndividualism = qryForDbAnimalTable.value(11).toString();
            qryValForAffectionism = qryForDbAnimalTable.value(12).toString();
            qryValForIntelligence = qryForDbAnimalTable.value(13).toString();
            qryValForDiscipline = qryForDbAnimalTable.value(14).toString();
            qryValForAssertiveness = qryForDbAnimalTable.value(15).toString();
            qryValForSpaciousness = qryForDbAnimalTable.value(16).toString();
            qryValForEnergetic = qryForDbAnimalTable.value(17).toString();
            qryValForNocturnal = qryForDbAnimalTable.value(18).toString();
            qryValForHabitatPreference= qryForDbAnimalTable.value(19).toString();
            qryValForAppetite = qryForDbAnimalTable.value(20).toString();

            qryValForFinSize = qryForDbAnimalTable.value(21).toString();
            qryValForBuild = qryForDbAnimalTable.value(22).toString();
            qryValForHairLength = qryForDbAnimalTable.value(23).toString();
            qryValForHairColour = qryForDbAnimalTable.value(24).toString();
            qryValForWingSpan = qryForDbAnimalTable.value(25).toString();
            qryValForBeakLength = qryForDbAnimalTable.value(26).toString();
            qryValForBeakColour = qryForDbAnimalTable.value(27).toString();
            qryValForScaleType = qryForDbAnimalTable.value(28).toString();
            qryValForBodyPattern = qryForDbAnimalTable.value(29).toString();
            qryValForBodyLength = qryForDbAnimalTable.value(30).toString();


            //Converts Qstring to string
            stringName = qryValForName.toStdString();
            stringSpecies = qryValForSpecies.toStdString();
            stringAge= qryValForAge.toStdString();
            stringGender = qryValForGender.toStdString();
            stringColour = qryValForColour.toStdString();
            stringHeight = qryValForHeight.toStdString();
            stringWeight = qryValForWeight.toStdString();
            stringType = qryValForType.toStdString();


            stringActiveness = qryValForActiveness.toStdString();
            stringPlayfulness = qryValForPlayfulness.toStdString();
            stringIndividualism = qryValForIndividualism.toStdString();
            stringAffectionism = qryValForAffectionism.toStdString();
            stringIntelligence =qryValForIntelligence.toStdString();
            stringDiscipline = qryValForDiscipline.toStdString();
            stringAssertiveness = qryValForAssertiveness.toStdString();
            stringSpaciousness = qryValForSpaciousness.toStdString();
            stringEnergetic = qryValForEnergetic.toStdString();
            stringNocturnal = qryValForNocturnal.toStdString();
            stringHabitatPreference = qryValForHabitatPreference.toStdString();
            stringAppetite = qryValForAppetite.toStdString();


            stringFinSize = qryValForFinSize.toStdString();
            stringBuild = qryValForBuild.toStdString();
            stringWingSpan = qryValForWingSpan.toStdString();
            stringBeakColour = qryValForBeakColour.toStdString();
            stringBeakLength = qryValForBeakLength.toStdString();
            stringHairColour = qryValForHairColour.toStdString();
            stringHairLength = qryValForHairLength.toStdString();
            stringScaleType = qryValForScaleType.toStdString();
            stringBodyPattern =  qryValForBodyPattern.toStdString();
            stringBodyLength = qryValForBodyLength.toStdString();

            //Dynamically allocations that new string need to call new to have different memeory address for every val

            //Check to see if its a mammal

            if (stringType == "dog" || stringType == "cat"){
                newAnimal = new Mammal(stringName,stringSpecies);
                newAnimal->setPhysCharacteristics(stringBuild,stringHairLength,stringHairColour);

            }
            else if (stringType == "finch" || stringType == "parrot"){
                newAnimal = new Bird(stringName,stringSpecies);
                newAnimal->setPhysCharacteristics(stringWingSpan,stringBeakLength,stringBeakColour);

            }
            else if (stringType == "snake" || stringType == "lizard"){

                newAnimal = new Reptile(stringName,stringSpecies);
                newAnimal->setPhysCharacteristics(stringBodyLength,stringBodyPattern,stringScaleType);
            }

            else if (stringType == "salamander" || stringType == "frog"){
                newAnimal = new Amphibian(stringName,stringSpecies);
                newAnimal->setPhysCharacteristics(stringBodyPattern,stringBodyLength,stringBuild);

            }

            else{
                newAnimal = new Fish(stringName,stringSpecies);
                newAnimal->setPhysCharacteristics(stringBodyPattern,stringBodyLength,stringFinSize);
            }
            //cout << newAnimal->getAnimalID()<<endl;
            newAnimal->setID(qryID);

            newAnimal->Animal::setBasicInfo(stringAge,stringGender,stringColour,stringHeight,stringWeight,stringType);
            newAnimal->setNonPhysicalAttributes(stringActiveness,stringPlayfulness,stringIndividualism,stringAffectionism,stringIntelligence,stringDiscipline,stringAssertiveness,stringSpaciousness,stringEnergetic,stringNocturnal,stringHabitatPreference,stringAppetite);

            listForA.add(&newAnimal);
    }


    while((qryForDbClientTable.next())){

        Client *newClient;

        //The .value method retrives the data at a speicifc index in the row
        qryID = qryForDbClientTable.value(0).toInt();
        qryValForFirstName = qryForDbClientTable.value(1).toString();
        qryValForLastName = qryForDbClientTable.value(2).toString();
        qryValForAge = qryForDbClientTable.value(3).toString();
        qryValForGender = qryForDbClientTable.value(4).toString();
        qryValForEmail = qryForDbClientTable.value(5).toString();
        qryValForPhoneNumber = qryForDbClientTable.value(6).toString();

        qryValForPlayfulness = qryForDbClientTable.value(51).toString();
        qryValForIndividualism = qryForDbClientTable.value(52).toString();
        qryValForIntelligence = qryForDbClientTable.value(53).toString();
        qryValForDiscipline = qryForDbClientTable.value(54).toString();
        qryValForAssertiveness = qryForDbClientTable.value(55).toString();
        qryValForSpaciousness = qryForDbClientTable.value(56).toString();
        qryValForEnergetic = qryForDbClientTable.value(57).toString();
        qryValForAppetite = qryForDbClientTable.value(58).toString();


        qryValForClientActiveness = qryForDbClientTable.value(7).toString();
        qryValForClientAffectionism = qryForDbClientTable.value(8).toString();
        qryValForClientHabibtatPreference = qryForDbClientTable.value(9).toString();
        qryValForClientNocturnal = qryForDbClientTable.value(10).toString();

        stringFirstName = qryValForFirstName.toStdString();
        stringLastName = qryValForLastName.toStdString();
        stringAge = qryValForAge.toStdString();
        stringGender = qryValForGender.toStdString();
        stringEmail = qryValForEmail.toStdString();
        stringPhoneNumber = qryValForPhoneNumber.toStdString();

        stringActiveness = qryValForClientActiveness.toStdString();
        stringAffectionism = qryValForClientAffectionism.toStdString();
        stringHabitatPreference= qryValForClientHabibtatPreference.toStdString();
        stringNocturnal = qryValForClientNocturnal.toStdString();

        stringPlayfulness = qryValForPlayfulness.toStdString();
        stringIndividualism = qryValForIndividualism.toStdString();
        stringIntelligence = qryValForIntelligence.toStdString();
        stringDiscipline = qryValForDiscipline.toStdString();
        stringAssertiveness = qryValForAssertiveness.toStdString();
        stringSpaciousness = qryValForSpaciousness.toStdString();
        stringEnergetic = qryValForEnergetic.toStdString();
        stringAppetite = qryValForAppetite.toStdString();


        newClient = new Client(stringFirstName,stringLastName,stringAge,stringEmail,stringPhoneNumber,stringGender);
        newClient->setCharacterTraits(stringActiveness,stringAffectionism,stringNocturnal,stringHabitatPreference);
        newClient->setNonPhysPreferences(stringIndividualism,stringIntelligence,stringDiscipline,stringAssertiveness,stringPlayfulness,stringEnergetic,stringSpaciousness,stringAppetite);
        newClient->setClientId(qryID);

        //ORDERING OF RANKS AND STORING CORRECT ANIMAL DEPENDING ON THEIR ATTRIBUTES
       for (int i = 0; i < 10; i++){

            Animal *newAnimal;

           if (i == 0){
                rank =  qryForDbClientTable.value(11).toInt();
                qryValForHairLength = qryForDbClientTable.value(12).toString();
                qryValForHairColour = qryForDbClientTable.value(13).toString();
                qryValForBuild = qryForDbClientTable.value(14).toString();
                holderForAttribute = qryValForHairLength.toStdString();
                holderFor2ndAttribute = qryValForHairColour.toStdString();
                holderFor3rdAttribute = qryValForBuild.toStdString();
                newAnimal = new Mammal("dog","dog");

            }
            else if (i == 1){
                rank =  qryForDbClientTable.value(15).toInt();
                qryValForHairLength = qryForDbClientTable.value(16).toString();
                qryValForHairColour = qryForDbClientTable.value(17).toString();
                qryValForBuild = qryForDbClientTable.value(18).toString();
                holderForAttribute  = qryValForHairLength.toStdString();
                holderFor2ndAttribute = qryValForHairColour.toStdString();
                holderFor3rdAttribute = qryValForBuild.toStdString();
                newAnimal = new Mammal("cat","cat");

            }
           else if (i == 2){
                rank =  qryForDbClientTable.value(19).toInt();
                qryValForScaleType = qryForDbClientTable.value(20).toString();
                qryValForBodyLength = qryForDbClientTable.value(21).toString();
                qryValForBodyPattern = qryForDbClientTable.value(22).toString();
                holderFor3rdAttribute = qryValForBodyLength.toStdString();
                holderForAttribute = qryValForBodyPattern.toStdString();
                holderFor2ndAttribute = qryValForScaleType.toStdString();
                newAnimal = new Reptile("snake","snake");


            }
            else if (i == 3){
                rank =  qryForDbClientTable.value(23).toInt();
                qryValForScaleType = qryForDbClientTable.value(24).toString();
                qryValForBodyLength = qryForDbClientTable.value(25).toString();
                qryValForBodyPattern = qryForDbClientTable.value(26).toString();
                holderForAttribute = qryValForBodyPattern.toStdString();
                holderFor3rdAttribute = qryValForBodyLength.toStdString();
                holderFor2ndAttribute = qryValForScaleType.toStdString();
                newAnimal = new Reptile("lizard","lizard");

            }
            else if (i == 4){
                rank =  qryForDbClientTable.value(27).toInt();
                qryValForBuild = qryForDbClientTable.value(28).toString();
                qryValForBodyLength = qryForDbClientTable.value(29).toString();
                qryValForBodyPattern = qryForDbClientTable.value(30).toString();
                holderFor3rdAttribute = qryValForBodyPattern.toStdString();
                holderForAttribute  = qryValForBodyLength.toStdString();
                holderFor2ndAttribute = qryValForBuild.toStdString();
                newAnimal = new Amphibian("salamander","salamander");

            }
            else if (i == 5){
                rank =  qryForDbClientTable.value(31).toInt();
                qryValForBuild = qryForDbClientTable.value(32).toString();
                qryValForBodyLength = qryForDbClientTable.value(33).toString();
                qryValForBodyPattern = qryForDbClientTable.value(34).toString();
                holderFor3rdAttribute = qryValForBodyPattern.toStdString();
                holderForAttribute  = qryValForBodyLength.toStdString();
                holderFor2ndAttribute = qryValForBuild.toStdString();
                newAnimal = new Amphibian("frog","frog");

            }
            else if (i == 6){
                rank =  qryForDbClientTable.value(35).toInt();
                qryValForFinSize = qryForDbClientTable.value(36).toString();
                qryValForBodyPattern = qryForDbClientTable.value(37).toString();
                qryValForBodyLength = qryForDbClientTable.value(38).toString();
                holderFor3rdAttribute  = qryValForBodyPattern.toStdString();
                holderForAttribute = qryValForBodyLength.toStdString();
                holderFor2ndAttribute = qryValForFinSize.toStdString();
                newAnimal = new Fish("betta","betta");

            }
            else if (i == 7){
                rank =  qryForDbClientTable.value(39).toInt();
                qryValForFinSize = qryForDbClientTable.value(40).toString();
                qryValForBodyPattern = qryForDbClientTable.value(41).toString();
                qryValForBodyLength = qryForDbClientTable.value(42).toString();
                holderFor3rdAttribute  = qryValForBodyPattern.toStdString();
                holderForAttribute = qryValForBodyLength.toStdString();
                holderFor2ndAttribute = qryValForFinSize.toStdString();
                newAnimal = new Fish("goldfish","goldfish");

            }
            else if (i == 8){
                rank =  qryForDbClientTable.value(43).toInt();
                qryValForWingSpan = qryForDbClientTable.value(44).toString();
                qryValForBeakColour = qryForDbClientTable.value(45).toString();
                qryValForBeakLength = qryForDbClientTable.value(46).toString();
                holderForAttribute = qryValForBeakLength.toStdString();
                holderFor2ndAttribute = qryValForBeakColour.toStdString();
                holderFor3rdAttribute = qryValForWingSpan.toStdString();
                newAnimal = new Bird("parrot","parrot");

            }
            else if (i == 9){
                rank = qryForDbClientTable.value(47).toInt();
                qryValForWingSpan = qryForDbClientTable.value(48).toString();
                qryValForBeakColour = qryForDbClientTable.value(49).toString();
                qryValForBeakLength = qryForDbClientTable.value(50).toString();
                holderForAttribute = qryValForBeakLength.toStdString();
                holderFor2ndAttribute = qryValForBeakColour.toStdString();
                holderFor3rdAttribute = qryValForWingSpan.toStdString();
                newAnimal = new Bird("finch","finch");


            }

                newClient->ranks.add(&newAnimal);
                    //cout<<"Rank when retrieving: "<<rank<<endl;
                newClient->ranks.setRank(rank,newAnimal->getSpecies());
                newClient->ranks.get(i)->setPhysCharacteristics(holderFor3rdAttribute,holderForAttribute,holderFor2ndAttribute);

        }


        listForC.add(&newClient);
       // newClient->print();
    }
}

/*
 * Updates exisiting animals non-physical attributes and pyhsical attributes
 */
void Server::editAnimal(QSqlQuery &db,Animal *a){

    ID = a->getAnimalID();
    name1 = QString::fromStdString(a->getName());
    spec1 = QString::fromStdString(a->getSpecies());
    age1 = QString::fromStdString(a->getAge());
    gender1 = QString::fromStdString(a->getGender());

    colour1 = QString::fromStdString(a->getColour());
    height1 = QString::fromStdString(a->getHeight());
    weight1 = QString::fromStdString(a->getWeight());
    type1 = QString::fromStdString(a->getType());

    activeness = QString::fromStdString(a->getActiveness());
    playfulness = QString::fromStdString(a->getPlayfulness());
    individualism = QString::fromStdString(a->getIndividualism());
    affectionism = QString::fromStdString(a->getAffectionism());
    intelligence = QString::fromStdString(a->getIntelligence());
    discipline = QString::fromStdString(a->getDiscipline());
    assertiveness = QString::fromStdString(a->getAssertiveness());
    spaciousness = QString::fromStdString(a->getSpaciousness());
    energetic = QString::fromStdString(a->getEnergetic());
    diurnalNocturnal = QString::fromStdString(a->getDiurnalNocturnal());
    habitatPreference = QString::fromStdString(a->getHabitatPreference());
    appetite = QString::fromStdString(a->getAppetite());

    build = QString::fromStdString(a->getBuild());

    mammalHairColour = QString::fromStdString(a->getMammalHairColour());
    mammalHairLength = QString::fromStdString(a->getMammalHairLength());
    wingSpan = QString::fromStdString(a->getWingSpan());
    beakColour = QString::fromStdString(a->getBeakColour());
    beakLength = QString::fromStdString(a->getBeakLength());

    scaleType = QString::fromStdString(a->getScaleType());
    bodyLength = QString::fromStdString(a->getLength());
    bodyPattern = QString::fromStdString(a->getBodyPattern());

    finnsSize = QString::fromStdString(a->getFinnsSize());

    cout << "EDITED FROM SAME ID: " << ID << "\n";
    db.prepare("UPDATE animalDb SET Height=:h,Weight=:w,Activeness=:aT, Playfulness=:p, Individualism=:iD, Affectionism=:aF, Intelligence=:iT, Discipline=:dP,Assertiveness=:aS, Spaciousness=:sP,Energetic=:eG, Nocturnal=:nT, HabitatPreference=:hP,Appetite=:aP,FinSize=:fS,Build=:b, HairLength=:hL, HairColour=:hC,WingSpan=:wS,BeakLength=:bL,BeakColour=:bC,ScaleType=:sT,BodyPattern=:bP,BodyLength=:bLL WHERE ID=:i");

    db.bindValue(":i",ID);
    db.bindValue(":h",height1);
    db.bindValue(":w",weight1);
    db.bindValue(":aT",activeness);
    db.bindValue(":p",playfulness);
    db.bindValue(":iD",individualism);
    db.bindValue(":aF",affectionism);
    db.bindValue(":iT",intelligence);
    db.bindValue(":dP",discipline);
    db.bindValue(":aS",assertiveness);
    db.bindValue(":sP",spaciousness);
    db.bindValue(":eG",energetic);
    db.bindValue(":nT",diurnalNocturnal);
    db.bindValue(":hP",habitatPreference);
    db.bindValue(":aP",appetite);
    db.bindValue(":fS",finnsSize);
    db.bindValue(":b",build);
    db.bindValue(":hL",mammalHairLength);
    db.bindValue(":hC",mammalHairColour);
    db.bindValue(":wS",wingSpan);
    db.bindValue(":bL",beakLength);
    db.bindValue(":bC",beakColour);
    db.bindValue(":sT",scaleType);
    db.bindValue(":bP",bodyPattern);
    db.bindValue(":bLL",bodyLength);


    if (db.exec()){
        qDebug("Edited CORRECT");
    }
    else{
        qDebug("Edited NOT CORRECT");

    }
}

/*
 * Updates exisiting clients non-physical attributes and pyhsical attributes
 */

void Server::editClient(QSqlQuery &db,Client *c){

    ID = c->getClientId();
    firstName = QString::fromStdString(c->getFirstName());
    age1 = QString::fromStdString(c->getAge());
    lastName = QString::fromStdString(c->getLastName());
    gender1 = QString::fromStdString(c->getGender());

    email1 = QString::fromStdString(c->getEmail());
    phoneNumber1 = QString::fromStdString(c->getPhoneNumber());

    clientActiveness= QString::fromStdString(c->getClientActiveness());
    clientAffectionism = QString::fromStdString(c->getClientAffectionism());
    clientHabitatPreference = QString::fromStdString(c->getClientHabitaPreference());
    clientDiurnalNocturnal= QString::fromStdString(c->getClientDiurnalNocturnal());

    playfulness = QString::fromStdString(c->getClientPlayfulllnessPreference());
    individualism = QString::fromStdString(c->getClientIndividualismPreference());
    intelligence = QString::fromStdString(c->getClientIntelligencePreference());
    discipline = QString::fromStdString(c->getClientDisciplinePreference());
    assertiveness = QString::fromStdString(c->getClientAssertivenessPreference());
    spaciousness = QString::fromStdString(c->getClientSpaciousnessPreference());
    energetic = QString::fromStdString(c->getClientEnergeticPreference());
    appetite = QString::fromStdString(c->getClientAppetitePreference());

    if (c->getEdited()==true){

        cout<<"FOR CLIENT ID: "<< ID << endl;

        db.prepare("UPDATE clientDb SET FirstName=:fs,LastName=:ls,Age=:a,Gender=:g,Email=:e,PhoneNumber=:p, "
                         "Activeness=:aT,Affectionism=:aF,HabibtatPreference=:hP,Nocturnal=:nT,"
                         "DogRank=:dR,FurLength=:fL, FurColour=:fC,Build=:b,"
                         "CatRank=:cR,FurLength2=:fL2, FurColour2=:fC2, Build2=:b2,"
                         "SnakeRank=:sR,ScaleType=:sT, BodyLength=:bL, BodyPattern=:bP, "
                         "LizardRank=:lR, ScaleType2=:sT2, BodyLength2=:bL2, BodyPattern2=:bP2, "
                         "SalamanderRank=:sDR,Build3=:b3, BodyLength3=:bL3, BodyPattern3=:bP3, "
                         "FrogRank=:frR, Build4=:b4, BodyLength4=:bL4, BodyPattern4=:bP4, "
                         "BettaRank=:bR, FinSize=:fS, BodyPattern5=:bP5, BodyLength5=:bL5, "
                         "GoldFishRank=:gR,FinSize2=:fS2, BodyPattern6=:bP6, BodyLength6=:bL6,"
                         "ParakeetRank=:pR,WingSpan=:wS, BeakColour=:bC, BeakLength=:bL7, "
                         "FinchRank=:fR, WingSpan2=:wS2, BeakColour2=:bC2, BeakLength2=:bL8,Playfulness=:a1, Individualism=:a2, Intelligence=:a3, Discipline=:a4, Assertiveness=:a5, Spaciousness=:a6,"
                         "Energetic=:a7, Appetite=:a8 WHERE ID=:i");

        db.bindValue(":i",ID);
        db.bindValue(":fs",firstName);
        db.bindValue(":ls",lastName);
        db.bindValue(":e",email1);
        db.bindValue(":p",phoneNumber1);
        db.bindValue(":a",age1);
        db.bindValue(":g",gender1);

        db.bindValue(":aT",clientActiveness);
        db.bindValue(":aF",clientAffectionism);
        db.bindValue(":hP",clientHabitatPreference);
        db.bindValue(":nT",clientDiurnalNocturnal);

        db.bindValue(":a1",playfulness);
        db.bindValue(":a2",individualism);
        db.bindValue(":a3",intelligence);
        db.bindValue(":a4",discipline);
        db.bindValue(":a5",assertiveness);
        db.bindValue(":a6",spaciousness);
        db.bindValue(":a7",energetic);
        db.bindValue(":a8",appetite);

        if (db.exec()){
           qDebug("Yes EDITED CORRECTLY");
        }
        else{
            qDebug("NOPE NOT EDITED CORRECTLY");
        }


        //Iterates through the ranks and retreives correct info
        for (int j=0 ;j < MAX_ANIMAL_SIZE;j++){

            rank = c->getAnimalRank(c->ranks.get(j)->getSpecies());

            if (c->ranks.get(j)->getSpecies() == "dog" || c->ranks.get(j)->getSpecies() == "cat"){
                mammalHairLength = QString::fromStdString(c->ranks.get(j)->getMammalHairLength());
                mammalHairColour = QString::fromStdString(c->ranks.get(j)->getMammalHairColour());
                build = QString::fromStdString(c->ranks.get(j)->getBuild());


              if (c->ranks.get(j)->getSpecies() == "dog"){

                    cout << rank ;
                    db.bindValue(":dR",rank);
                    db.bindValue(":fL",mammalHairLength);
                    db.bindValue(":fC",mammalHairColour);
                    db.bindValue(":b",build);

                }
                else{

                    db.bindValue(":cR",rank);
                    db.bindValue(":fL2",mammalHairLength);
                    db.bindValue(":fC2",mammalHairColour);
                    db.bindValue(":b2",build);

                }

            }


            if (c->ranks.get(j)->getSpecies() == "snake" || c->ranks.get(j)->getSpecies() == "lizard"){
                scaleType = QString::fromStdString(c->ranks.get(j)->getScaleType());
                bodyLength = QString::fromStdString(c->ranks.get(j)->getLength());
                bodyPattern = QString::fromStdString(c->ranks.get(j)->getBodyPattern());
                if (c->ranks.get(j)->getSpecies() == "snake"){

                    db.bindValue(":sR",rank);
                    db.bindValue(":sT",scaleType);
                    db.bindValue(":bL",bodyLength);
                    db.bindValue(":bP",bodyPattern);
                }
                else{
                    db.bindValue(":lR",rank);
                    db.bindValue(":sT2",scaleType);
                    db.bindValue(":bL2",bodyLength);
                    db.bindValue(":bP2",bodyPattern);

                }




            }
            if (c->ranks.get(j)->getSpecies() == "frog" || c->ranks.get(j)->getSpecies() == "salamander"){
                bodyLength = QString::fromStdString(c->ranks.get(j)->getLength());
                bodyPattern = QString::fromStdString(c->ranks.get(j)->getBodyPattern());
                build = QString::fromStdString(c->ranks.get(j)->getBuild());
                if (c->ranks.get(j)->getSpecies() == "frog"){
                    db.bindValue(":frR",rank);
                    db.bindValue(":b4",build);
                    db.bindValue(":bL4",bodyLength);
                    db.bindValue(":bP4",bodyPattern);

                }
                else{
                    db.bindValue(":sDR",rank);
                    db.bindValue(":b3",build);
                    db.bindValue(":bL3",bodyLength);
                    db.bindValue(":bP3",bodyPattern);
                }


            }
            if (c->ranks.get(j)->getSpecies() == "parrot" || c->ranks.get(j)->getSpecies() == "finch"){
                wingSpan = QString::fromStdString(c->ranks.get(j)->getWingSpan());
                beakColour = QString::fromStdString(c->ranks.get(j)->getBeakColour());
                beakLength = QString::fromStdString(c->ranks.get(j)->getBeakLength());

                if (c->ranks.get(j)->getSpecies() == "parrot"){
                    db.bindValue(":pR",rank);
                    db.bindValue(":wS",wingSpan);
                    db.bindValue(":bC",beakColour);
                    db.bindValue(":bL7",beakLength);

                }
                else{
                    db.bindValue(":fR",rank);
                    db.bindValue(":wS2",wingSpan);
                    db.bindValue(":bC2",beakColour);
                    db.bindValue(":bL8",beakLength);
                }



            }
            if (c->ranks.get(j)->getSpecies() == "betta" || c->ranks.get(j)->getSpecies() == "goldfish"){
                finnsSize = QString::fromStdString(c->ranks.get(j)->getFinnsSize());
                bodyLength = QString::fromStdString(c->ranks.get(j)->getLength());
                bodyPattern = QString::fromStdString(c->ranks.get(j)->getBodyPattern());
                if (c->ranks.get(j)->getSpecies() == "betta"){
                    db.bindValue(":bR",rank);
                    db.bindValue(":fS",finnsSize);
                    db.bindValue(":bP5",bodyPattern);
                    db.bindValue(":bL5",bodyLength);

                }
                else{
                    db.bindValue(":gR",rank);
                    db.bindValue(":fS2",finnsSize);
                    db.bindValue(":bP6",bodyPattern);
                    db.bindValue(":bL6",bodyLength);

                }
            }

    }
        if (db.exec()){
           qDebug("Yes EDITED CORRECTLY");
        }
        else{
            qDebug("NOPE NOT EDITED CORRECTLY");
        }

   }
}

/*
 * Adds a new animal into the database
 */

void Server::addAnimal(QSqlQuery &db,Animal *a){

    //Must call :text or :integer as placeholder so that you can bind value to that placeholder and update it to the database
    db.prepare("INSERT INTO animalDb(ID,Name,Species,Age,Gender,Colour,Height,Weight,Type,Activeness, Playfulness, Individualism, Affectionism, Intelligence, Discipline,Assertiveness, Spaciousness,Energetic, Nocturnal, HabitatPreference,Appetite,FinSize,Build, HairLength, HairColour,WingSpan,BeakLength,BeakColour,ScaleType,BodyPattern,BodyLength)VALUES(:i,:n,:s,:a,:g,:c,:h,:w,:t,:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8,:a9,:a10,:a11,:a12,:fS,:b,:hL,:hC,:wS,:bL,:bC,:sT,:bP,:bLL)");

    ID = a->getAnimalID();
    name1 = QString::fromStdString(a->getName());
    spec1 = QString::fromStdString(a->getSpecies());
    age1 = QString::fromStdString(a->getAge());
    gender1 = QString::fromStdString(a->getGender());

    colour1 = QString::fromStdString(a->getColour());
    height1 = QString::fromStdString(a->getHeight());
    weight1 = QString::fromStdString(a->getWeight());
    type1 = QString::fromStdString(a->getType());

    activeness = QString::fromStdString(a->getActiveness());
    playfulness = QString::fromStdString(a->getPlayfulness());
    individualism = QString::fromStdString(a->getIndividualism());
    affectionism = QString::fromStdString(a->getAffectionism());
    intelligence = QString::fromStdString(a->getIntelligence());
    discipline = QString::fromStdString(a->getDiscipline());
    assertiveness = QString::fromStdString(a->getAssertiveness());
    spaciousness = QString::fromStdString(a->getSpaciousness());
    energetic = QString::fromStdString(a->getEnergetic());
    diurnalNocturnal = QString::fromStdString(a->getDiurnalNocturnal());
    habitatPreference = QString::fromStdString(a->getHabitatPreference());
    appetite = QString::fromStdString(a->getAppetite());

    build = QString::fromStdString(a->getBuild());

    mammalHairColour = QString::fromStdString(a->getMammalHairColour());
    mammalHairLength = QString::fromStdString(a->getMammalHairLength());
    wingSpan = QString::fromStdString(a->getWingSpan());
    beakColour = QString::fromStdString(a->getBeakColour());
    beakLength = QString::fromStdString(a->getBeakLength());

    scaleType = QString::fromStdString(a->getScaleType());
    bodyLength = QString::fromStdString(a->getLength());
    bodyPattern = QString::fromStdString(a->getBodyPattern());

    finnsSize = QString::fromStdString(a->getFinnsSize());

    cout << ID  << " IS THE ID" << endl;
    db.bindValue(":i",ID);
    db.bindValue(":n",name1);
    db.bindValue(":s",spec1);
    db.bindValue(":a",age1);
    db.bindValue(":g",gender1);

    db.bindValue(":c",colour1);
    db.bindValue(":h",height1);
    db.bindValue(":w",weight1);
    db.bindValue(":t",type1);

    db.bindValue(":a1",activeness);
    db.bindValue(":a2",playfulness);
    db.bindValue(":a3",individualism);
    db.bindValue(":a4",affectionism);
    db.bindValue(":a5",intelligence);
    db.bindValue(":a6",discipline);
    db.bindValue(":a7",assertiveness);
    db.bindValue(":a8",spaciousness);
    db.bindValue(":a9",energetic);
    db.bindValue(":a10",diurnalNocturnal);
    db.bindValue(":a11",habitatPreference);
    db.bindValue(":a12",appetite);


    db.bindValue(":fS",finnsSize);
    db.bindValue(":b",build);
    db.bindValue(":hL",mammalHairLength);
    db.bindValue(":hC",mammalHairColour);

    db.bindValue(":wS",wingSpan);
    db.bindValue(":bC",beakColour);
    db.bindValue(":bL",beakLength);

    db.bindValue(":sT",scaleType);
    db.bindValue(":bP",bodyPattern);
    db.bindValue(":bLL",bodyLength);



    if (db.exec()){
        qDebug("Added!");
    }
    else{
        qDebug("Not Added!");
    }

}

/*
 * Adds a new client into the database
 */
void Server::addClient(QSqlQuery &db,Client *c){

    ID = c->getClientId();
    firstName = QString::fromStdString(c->getFirstName());
    age1 = QString::fromStdString(c->getAge());
    lastName = QString::fromStdString(c->getLastName());
    gender1 = QString::fromStdString(c->getGender());

    email1 = QString::fromStdString(c->getEmail());
    phoneNumber1 = QString::fromStdString(c->getPhoneNumber());

    clientActiveness= QString::fromStdString(c->getClientActiveness());
    clientAffectionism = QString::fromStdString(c->getClientAffectionism());
    clientHabitatPreference = QString::fromStdString(c->getClientHabitaPreference());
    clientDiurnalNocturnal= QString::fromStdString(c->getClientDiurnalNocturnal());

    playfulness = QString::fromStdString(c->getClientPlayfulllnessPreference());
    individualism = QString::fromStdString(c->getClientIndividualismPreference());
    intelligence = QString::fromStdString(c->getClientIntelligencePreference());
    discipline = QString::fromStdString(c->getClientDisciplinePreference());
    assertiveness = QString::fromStdString(c->getClientAssertivenessPreference());
    spaciousness = QString::fromStdString(c->getClientSpaciousnessPreference());
    energetic = QString::fromStdString(c->getClientEnergeticPreference());
    appetite = QString::fromStdString(c->getClientAppetitePreference());



    cout<<"FOR NEW CLIENT: "<< ID <<endl;

    db.prepare("INSERT INTO clientDb(ID,FirstName,LastName,Age , Gender ,Email ,PhoneNumber , Activeness ,Affectionism ,HabibtatPreference ,Nocturnal,Playfulness , Individualism ,  Intelligence , Discipline,Assertiveness , Spaciousness,Energetic,Appetite)"
                     "VALUES(:i,:fn,:ln,:a,:g,:e,:p,:aC,:aF,:hP,:nT,:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8)");

    db.bindValue(":i",ID);
    db.bindValue(":fn",firstName);
    db.bindValue(":ln",lastName);
    db.bindValue(":a",age1);
    db.bindValue(":g",gender1);
    db.bindValue(":e",email1);
    db.bindValue(":p",phoneNumber1);


    db.bindValue(":aC",clientActiveness);
    db.bindValue(":aF",clientAffectionism);
    db.bindValue(":hP",clientHabitatPreference);
    db.bindValue(":nT",clientDiurnalNocturnal);

    db.bindValue(":a1",playfulness);
    db.bindValue(":a2",individualism);
    db.bindValue(":a3",intelligence);
    db.bindValue(":a4",discipline);
    db.bindValue(":a5",assertiveness);
    db.bindValue(":a6",spaciousness);
    db.bindValue(":a7",energetic);
    db.bindValue(":a8",appetite);
        if (db.exec()){
           qDebug("Yes EDITED CORRECTLY");
        }
        else{
            qDebug("NOPE NOT EDITED CORRECTLY");
        }
}
