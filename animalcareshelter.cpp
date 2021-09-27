#include <iostream>
#include "animalcareshelter.h"
#include "QDebug"
using namespace std;

AnimalCareShelter::AnimalCareShelter(){

    this->name = "Carleton Univesity Animal Care Shelter";
}

AnimalCareShelter::~AnimalCareShelter(){}




void AnimalCareShelter::makeNewAnimal(vector<string> newAnimal){

     //constructor variables: the name and the species
    string animalName = newAnimal[1];
    string animalSpecies = newAnimal[2];

    //for setPhysCharacteristics function. There are 3 of them
    string physAttribute1 = newAnimal[3];
    string physAttribute2 = newAnimal[4];
    string physAttribute3 = newAnimal[5];

    //for setBasicInfo functio. there are 6 of them
    string animalAge = newAnimal[6];
    string animalGender = newAnimal[7];
    string animalColour = newAnimal[8];
    string animalHeight = newAnimal[9];
    string animalWeight = newAnimal[10];
    string animalType = newAnimal[11];

    //for setNonPhysCharacteristics function: there are 12 of them
    string activeness = newAnimal[12];
    string playfulness = newAnimal[13];
    string individualism = newAnimal[14];
    string affectionism = newAnimal[15];
    string intelligence = newAnimal[16];
    string displicine = newAnimal[17];
    string assertiveness = newAnimal[18];
    string spaciousness = newAnimal[19];
    string energy = newAnimal[20];
    string dirunal = newAnimal[21];
    string habitat = newAnimal[22];
    string appetite = newAnimal[23];

    Animal* currentAnimalBeingAdded;
    //animalType is specifying to indicate for animal constructor which type of animal to add.
    if(newAnimal[0] == "dog" || newAnimal[0] == "cat"){
       currentAnimalBeingAdded = new Mammal(animalName,animalSpecies);
       //currentAnimalBeingAdded->setPhysCharacteristics(build.toUtf8().constData(),furLength.toUtf8().constData(),furColour.toUtf8().constData());
       currentAnimalBeingAdded->setPhysCharacteristics(physAttribute1,physAttribute2,physAttribute3);

    }
    else if(newAnimal[0] == "snake" || newAnimal[0] == "lizard"){
       currentAnimalBeingAdded = new Reptile(animalName,animalSpecies);
       //currentAnimalBeingAdded->setPhysCharacteristics(bodyLength.toUtf8().constData(),bodyPattern.toUtf8().constData(),scaleType.toUtf8().constData());
       currentAnimalBeingAdded->setPhysCharacteristics(physAttribute1,physAttribute2,physAttribute3);
    }
    else if(newAnimal[0] == "finch" || newAnimal[0] == "parrot"){
       currentAnimalBeingAdded = new Bird(animalName,animalSpecies);
       //currentAnimalBeingAdded->setPhysCharacteristics(wingSpan.toUtf8().constData(),beakLength.toUtf8().constData(),beakColour.toUtf8().constData());
       currentAnimalBeingAdded->setPhysCharacteristics(physAttribute1,physAttribute2,physAttribute3);
    }
    else if(newAnimal[0] == "betta" || newAnimal[0] == "goldfish"){
       currentAnimalBeingAdded= new Fish(animalName,animalSpecies);
       //currentAnimalBeingAdded->setPhysCharacteristics(bodyPattern.toUtf8().constData(),bodyLength.toUtf8().constData(),finnSize.toUtf8().constData());
       currentAnimalBeingAdded->setPhysCharacteristics(physAttribute1,physAttribute2,physAttribute3);

    }
    else if(newAnimal[0] == "frog" || newAnimal[0] == "salamander"){
       currentAnimalBeingAdded = new Amphibian(animalName,animalSpecies);
       //currentAnimalBeingAdded->setPhysCharacteristics(bodyPattern.toUtf8().constData(),bodyLength.toUtf8().constData(),build.toUtf8().constData());
       currentAnimalBeingAdded->setPhysCharacteristics(physAttribute1,physAttribute2,physAttribute3);
    }

    //Age,gender,colour,height,weight,typeOfAnimal
     currentAnimalBeingAdded->setBasicInfo(animalAge,animalGender,animalColour,animalHeight,animalWeight,animalType);

     currentAnimalBeingAdded->setNonPhysicalAttributes(activeness,playfulness,individualism,affectionism,intelligence,displicine,
                                                       assertiveness,spaciousness,energy,dirunal,habitat,appetite);

     currentAnimalBeingAdded->incramentID(this->getPreviousIDForAnimal());
     cout << "ID FOR ANIMAL IS: " << currentAnimalBeingAdded->getAnimalID() << endl;


    // currentAnimalBeingAdded->setNewAnimal(true);

     if (currentAnimalBeingAdded->getNewAnimal() == false){
         currentAnimalBeingAdded->setNewAnimal(true);
     }

     animals.add(&currentAnimalBeingAdded);
}

int  AnimalCareShelter::previousIDForAnimal=0;
int  AnimalCareShelter::previousIDForClient=0;

int AnimalCareShelter::getPreviousIDForAnimal(){
    return previousIDForAnimal;

}

int AnimalCareShelter::getPreviousIDClient(){
    return previousIDForClient;
}

void AnimalCareShelter::setPreviousIDForAnimal(int newID){
    previousIDForAnimal = newID;

}

void AnimalCareShelter::setPreviousIDClient(int newID){
    previousIDForClient = newID;

}

void AnimalCareShelter::runACM(){

  if(optimalSetMatches.size() > 0){
      cout<<'CLEARING THE LINKE LIST'<<endl;
      optimalSetMatches.clear();
  }

  int numAnimals = animals.size();
  int numClients = clients.size();
  //vector<Match> optimalSet = acm.launchACM(animals,clients,numAnimals,numClients);

  optimalSetMatches = acm.launchACM(animals,clients,numAnimals,numClients);





   //cout<<"SIZE OF OPTIMAL SET = "<<optimalSet.size()<<endl;


//   cout<<"PRINTING FORM ANIMAL CARE SHELTER"<<endl;
//    for(int i = 0;i<optimalSet.size();i++){
//      optimalSet[i].print();

//    }


//    cout<<"ADDING MATCHES OT THE LINKED LIST"<<endl;
//  for(int i=0;i<optimalSet.size();i++){
//    Match* matchPtr = &optimalSet[i];
//    cout<<"MATCH BBEFORE ADDING TO THE LINKED LIST"<<endl;
//   // matchPtr->print();
//    animalClientMatches.add(&matchPtr);
//  }
}
