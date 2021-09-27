#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include "mammal.h"


Mammal::Mammal(string name, string species):Animal(name,species){}

Mammal::~Mammal(){}

void Mammal::setPhysCharacteristics(string animalBuild,string animlHLength, string animalHColour){
  build = animalBuild;
  furLength = animlHLength;
  furColour = animalHColour;
}

void Mammal::setBuild(string mammalBuild){
  build = mammalBuild;
}

void Mammal::setMammalHairLength(string mammalHairLength){
  furLength = mammalHairLength;
}

void Mammal::setMammalHairColour(string mammalHairColour){
  furColour = mammalHairColour;
}

string Mammal::getMammalHairLength(){return furLength;}
string Mammal::getMammalHairColour(){return furColour;}
string Mammal::getBuild(){return build;}

void Mammal::print(){


  cout<<"Name: "<<name<<endl;
  cout<<"Species: "<<species<<endl;
  cout<<"Age: "<<age<<endl;
  cout<<"Gender: "<<gender<<endl;
  cout<<"HairLength: "<<furLength<<endl;

  cout<<"\n";
}

void Mammal::printPhys(){

  /*

  string furLength;
  string furColour;
  string build;
  */

  cout<<"\t\tFur Lenght: "<<furLength<<endl;
  cout<<"\t\tFur Colour: "<<furColour<<endl;
  cout<<"\t\tBuild: "<<build<<endl;
}
