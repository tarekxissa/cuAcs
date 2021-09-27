#ifndef BIRD_H
#define BIRD_H
#include <iostream>
using namespace std;
#include "animal.h"

class Bird : public Animal{

    public:
    Bird(string,string);
    virtual ~Bird();

    virtual void setPhysCharacteristics(string ,string, string);

    /*setters for the bird physical attributes*/
    virtual void setWingSpan(string);
    virtual void setBeakLength(string);
    virtual void setBeakColour(string);

    /*getters for the bird attributes*/
    virtual string getWingSpan();
    virtual string getBeakLength();
    virtual string getBeakColour();

  protected:
    string wingSpan;
    string beakLength;
    string beakColour;
    virtual void printPhys();

};


#endif
