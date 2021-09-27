#include <iostream>
//#include <iomanip>
using namespace std;
#include <string>
#include "reptile.h"

Reptile::Reptile(string name, string species):Animal(name,species){}

Reptile::~Reptile(){}

void Reptile::setPhysCharacteristics(string reptileLength,string reptilePattern, string reptileScaleType){
  bodyPattern = reptilePattern;
  bodyLength = reptileLength;
  scaleType = reptileScaleType;
}

void Reptile::setScaleType(string reptileScaleType){
  scaleType = reptileScaleType;
}

void Reptile::setBodyPattern(string reptileBodyPattern){
  bodyPattern = reptileBodyPattern;
}

void Reptile::setLength(string reptileLength){
  bodyLength = reptileLength;
}
string Reptile::getLength(){
  return this->bodyLength;
}
string Reptile::getBodyPattern(){
  return this->bodyPattern;
}

string Reptile::getScaleType(){
  return this->scaleType;
}

void Reptile::print(){


  cout<<"Name: "<<name<<endl;
  cout<<"Species: "<<species<<endl;
  cout<<"Age: "<<age<<endl;
  cout<<"Gender: "<<gender<<endl;
  cout<<"Length: "<<bodyLength<<endl;
  cout<<"Scale Pattern: "<<bodyPattern<<endl;

  cout<<"\n";
}



void Reptile::printPhys(){

  /*
    string bodyLength;
    string bodyPattern;
    string scaleType
  */

  cout<<"\t\tBody Lenght: "<<bodyLength<<endl;
  cout<<"\t\tBody Pattern: "<<bodyPattern<<endl;
  cout<<"\t\tScale Type: "<<scaleType<<endl;
}
