#include <iostream>
#include <string>
#include "fish.h"
using namespace std;

Fish::Fish(string name, string species):Animal(name,species){}

Fish::~Fish(){}


void Fish::setPhysCharacteristics(string fishBodyPattern,string fishBodyLength, string fishFinnsSize){
    bodyPattern = fishBodyPattern;
    bodyLength = fishBodyLength;
    finnsSize = fishFinnsSize;
}

void Fish::setFinnsSize(string fishFinnsSize){
    finnsSize = fishFinnsSize;
}

void Fish::setLength(string fishLength){
    bodyLength = fishLength;
}

void Fish::setBodyPattern(string fishBodyPattern){
    bodyPattern = fishBodyPattern;
}

string Fish::getLength(){
    return this->bodyLength;
}

string Fish::getBodyPattern(){
    return this->bodyPattern;
}

string Fish::getFinnsSize(){
    return this->finnsSize;
}
void Fish::print(){


  cout<<"Name: "<<name<<endl;
  cout<<"Species: "<<species<<endl;
  cout<<"Age: "<<age<<endl;
  cout<<"Gender: "<<gender<<endl;
  cout<<"Finn Size: "<<finnsSize<<endl;

  cout<<"\n";
}

void Fish::printPhys(){

  /*

  string finnsSize;
        string bodyLength;
        string bodyPattern;
  */

  cout<<"\t\tFinnSize: "<<finnsSize<<endl;
  cout<<"\t\tBody Length: "<<bodyLength<<endl;
  cout<<"\t\tBody Pattern: "<<bodyPattern<<endl;
}
