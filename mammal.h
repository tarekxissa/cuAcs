#ifndef MAMMAL_H
#define MAMMAL_H
#include <iostream>
using namespace std;
#include "animal.h"

class Mammal : public Animal{

public:
  Mammal(string,string);
  virtual ~Mammal();


  virtual void setPhysCharacteristics(string, string,string);

  /*setters for mammal physical characteristics*/
  virtual void setBuild(string);
  virtual void setMammalHairLength(string);
  virtual void setMammalHairColour(string);


  /*getters for the mammal physical characteristics*/
  virtual string getMammalHairLength();
  virtual string getMammalHairColour();
  virtual string getBuild();


protected:
  /* Attributes used for setPhysCharacteristics Fxn */
  string furLength;
  string furColour;

  /* Attributes used for setMammalBuild Fxn */
  string build;


  /*for testing purpose*/

virtual void print();
virtual void printPhys();

};


#endif
