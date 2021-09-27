#include <iostream>
//#include <iomanip>
using namespace std;
#include <string>
#include "bird.h"


Bird::Bird(string name, string species):Animal(name,species){}

Bird::~Bird(){}

void Bird::setPhysCharacteristics(string birdWingSpan, string birdBeakLength, string birdBeakColour){
  beakLength = birdBeakLength;
  beakColour = birdBeakColour;
  wingSpan = birdWingSpan;
}

void Bird::setWingSpan(string birdWingSpan){
  this->wingSpan = birdWingSpan;
}

void Bird::setBeakLength(string birdBeakLength){
  beakLength = birdBeakLength;
}

void Bird::setBeakColour(string birdBeakColour){
  beakColour = birdBeakColour;
}

string Bird::getWingSpan(){
  return wingSpan;
}
string Bird::getBeakColour(){
  return beakColour;
}
string Bird::getBeakLength(){
  return beakLength;
}


void Bird::printPhys(){

  /*

  string wingSpan;
    string beakLength;
    string beakColour;
  */

  cout<<"\t\tWing Span: "<<wingSpan<<endl;
  cout<<"\t\tBeak Length: "<<beakLength<<endl;
  cout<<"\t\tBeak Colour: "<<beakColour<<endl;
}
