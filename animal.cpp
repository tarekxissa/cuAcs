#include <iostream>
//#include <iomanip>
using namespace std;
#include <string>
#include "animal.h"

Animal::Animal(string animalName,string animalSpecies){

    name = animalName;
    species = animalSpecies;
    edited = false;
    isNewAnimal = false;
    ID =1;
}

Animal::~Animal(){}

void Animal::setBasicInfo(string animalAge,string animalGender,string animalColour,string animalWeight, string animalHeight, string animalType){

  /*using setters*/
  setAge(animalAge);
  setGender(animalGender);
  setColour(animalColour);
  setWeight(animalWeight);
  setHeight(animalHeight);
  setType(animalType);

}

/*setter for all the non-physical attributes*/
void Animal::setNonPhysicalAttributes(string animalActiveness,string animalPlayfulness,string animalIndividulaism,string animalAffectionism,string animalIntelligence,string animalDiscipline,string animalAssert,string animalSpacious,string animalEnergy,string animalNocturnal,string animalHabitat, string animalAppetite){
  setActiveness(animalActiveness);
  setPlayfulness(animalPlayfulness);
  setIndividualism(animalIndividulaism);
  setAffectionism(animalAffectionism);
  setIntelligence(animalIntelligence);
  setDiscipline(animalDiscipline);
  setAssertiveness(animalAssert);
  setHabitatPreference(animalHabitat);
  setDiurnalNocturnal(animalNocturnal);
  setAppetite(animalAppetite);
  setEnergy(animalEnergy);
  setSpaciousness(animalSpacious);

}

/*getters for all attributes*/
string Animal::getName(){return name;}
string Animal::getSpecies(){return species;}
string Animal::getAge(){return age;}
string Animal::getGender(){return gender;}
string Animal::getColour(){return colour;}
string Animal::getHeight(){return height;}
string Animal::getWeight(){return weight;}
string Animal::getType(){return typeOfAnimal;}

/*getters for all non-Physical attributes*/
string Animal::getActiveness(){return activeness;}
string Animal::getPlayfulness(){return playfulness;}
string Animal::getIndividualism(){return individualism;}
string Animal::getAffectionism(){return affectionism;}
string Animal::getIntelligence(){return intelligence;}
string Animal::getDiscipline(){return discipline;}
string Animal::getAssertiveness(){return assertiveness;}
string Animal::getEnergetic(){return energetic;}
string Animal::getDiurnalNocturnal(){return diurnalNocturnal;}
string Animal::getAppetite(){return appetite;}
string Animal::getSpaciousness(){return spaciousness;}
string Animal::getHabitatPreference(){return habitatPref;}


int Animal::getAnimalID(){return ID;}

void Animal::setAnimalId(int id){
  ID = id;
}

bool Animal::operator==(Animal* animal){
  if(this->ID == animal->getAnimalID()){
    return true;
  }
  return false;
}
bool Animal::getEdited(){return edited;}
bool Animal::getNewAnimal(){return isNewAnimal;}
void Animal::incramentID(int oldId){ID += oldId;}
void Animal::setEdited(bool edit){edited = edit;}
void Animal::setID(int id){
    ID = id;
}



/*Helper getter functions*/

/*Helper setter functions*/
void Animal::setNewAnimal(bool animalToTrue){isNewAnimal = animalToTrue;}


/*setters for all individual attributes*/
void Animal::setName(string animalName){ name = animalName;}
void Animal::setSpecies(string animalSpecies){species = animalSpecies;}
void Animal::setAge(string animalAge){age = animalAge;}
void Animal::setGender(string animalGender){gender = animalGender;}
void Animal::setColour(string animalColour){colour = animalColour;}
void Animal::setHeight(string animalHeight){height = animalHeight;}
void Animal::setWeight(string animalWeight){weight = animalWeight;}
void Animal::setType(string animalType){typeOfAnimal = animalType;}

/*setters for allindividual non-Physical attributes*/
void Animal::setActiveness(string animalActiveness){activeness = animalActiveness;}
void Animal::setPlayfulness(string animalPlayfulness){playfulness = animalPlayfulness;}
void Animal::setIndividualism(string animalIndividualism){individualism = animalIndividualism;}
void Animal::setAffectionism(string animalAffectionism){affectionism = animalAffectionism;}
void Animal::setIntelligence(string animalIntelligence){intelligence = animalIntelligence;}
void Animal::setDiscipline(string animalDiscipline){discipline = animalDiscipline;}
void Animal::setAssertiveness(string animalAssertiveness){assertiveness = animalAssertiveness;}
void Animal::setHabitatPreference(string habitatPre){habitatPref = habitatPre;}
void Animal::setDiurnalNocturnal(string animalDiurnal){diurnalNocturnal = animalDiurnal;}
void Animal::setSpaciousness(string animalSpaciousness){spaciousness = animalSpaciousness;}
void Animal::setAppetite(string animalAppetite){appetite = animalAppetite;}
void Animal::setEnergy(string animalEnergy){ energetic = animalEnergy;}


/*the following functions have to be implemented in the base class becuase they are virtual and not pure virtual. not
implementeing them will result in an "undefiend reference to fucntion "error when linking
*/
/*virtual functions which will be implemented in each or some of the middle subclasses */
/*
void Animal::setPhysCharacteristics(string height,string weight){}
//void Animal::setMammalPhysBuild(string build){}
//void Animal::setBirdWingSpan(string wingSpan){}

 getters overwritten for inheritance purposes

*/

string Animal::getMammalHairLength(){return "N/A";}
string Animal::getMammalHairColour(){return "N/A";}
string Animal::getBuild(){return "N/A";}
string Animal::getBodyPattern(){return "N/A";}
string Animal::getLength(){return "N/A";}
string Animal::getWingSpan(){return "N/A";}
string Animal::getFinnsSize(){return "N/A";}
string Animal::getBeakColour(){return "N/A";}
string Animal::getBeakLength(){return "N/A";}
string Animal::getScaleType(){return "N/A";}



void Animal::setMammalHairLength(string){};
void Animal::setMammalHairColour(string){};
/*Mammal and Amphibian class*/
void Animal::setBuild(string){};
/*Amphibian, reptile, fish class*/
void Animal::setLength(string ){};
void Animal::setBodyPattern(string){};
/*Fish class*/
void Animal::setFinnsSize(string){};
/*Bird class*/
void Animal::setWingSpan(string){};
void Animal::setBeakLength(string){};
void Animal::setBeakColour(string){};
/*Reptile class*/
void Animal::setScaleType(string){};

void Animal::setPhysCharacteristics(string, string,string){}

void Animal::print(){

  cout<<"Name: "<<name<<endl;
  cout<<"Species: "<<species<<endl;
  cout<<"Age: "<<age<<endl;
  cout<<"Gender: "<<gender<<endl;
  cout<<"Animal Type: "<<typeOfAnimal<<endl;
  cout<<"Weight: "<<weight<<endl;
  cout<<"Height: "<<height<<endl;
  cout<<"Colour: "<<colour<<endl;

  cout<<"\n";

}

void Animal::printPhys(){}
