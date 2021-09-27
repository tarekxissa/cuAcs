#include <iostream>
#include <string>
#include "amphibian.h"
using namespace std;

Amphibian::Amphibian(string name, string species):Animal(name,species){}

Amphibian::~Amphibian(){}


void Amphibian::setPhysCharacteristics(string amphibianBodyPattern,string amphibianBodyLength, string amphibianBuild){
  bodyLength = amphibianBodyLength;
  bodyPattern = amphibianBodyPattern;
  build = amphibianBuild;
}

void Amphibian::setBuild(string amphibianBuild){
  build = amphibianBuild;
}

void Amphibian::setLength(string amphibianLength){
  bodyLength = amphibianLength;
}

void Amphibian::setBodyPattern(string amphibianPattern){
  bodyPattern = amphibianPattern;
}

string Amphibian::getLength(){
  return bodyLength;
}
string Amphibian::getBodyPattern(){
  return bodyPattern;
}
string Amphibian::getBuild(){
  return build;
}

void Amphibian::print(){


  cout<<"Name: "<<name<<endl;
  cout<<"Species: "<<species<<endl;
  cout<<"Age: "<<age<<endl;
  cout<<"Gender: "<<gender<<endl;
  cout<<"Length: "<<bodyLength<<endl;
  cout<<"Scale Pattern: "<<bodyPattern<<endl;

  cout<<"\n";
}

void Amphibian::printPhys(){

  cout<<"\t\tBody Length: "<<bodyLength<<endl;
  cout<<"\t\tScale Pattern: "<<bodyPattern<<endl;
  cout<<"\t\tBuild: "<<build<<endl;
}
