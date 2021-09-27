#ifndef REPTILE_H
#define REPTILE_H
#include <iostream>
using namespace std;
#include "animal.h"

class Reptile : public Animal{

  public:
    Reptile(string,string);
    virtual ~Reptile();

    virtual void setPhysCharacteristics(string ,string, string);

    /*setter for reptile attributes*/
    virtual void setScaleType(string);
    virtual void setLength(string);
    virtual void setBodyPattern(string);

    /*getters for the reptile physical characteristics*/
    virtual string getLength();
    virtual string getBodyPattern();
    virtual string getScaleType();



  protected:
   /* Attributes used for setPhysCharacteristics Fxn */

    /*measured in centimeters or inches*/
    string bodyLength;

    /*different types of reptile body patterns: stripped, banded, solid, spotted, unique */
    string bodyPattern;

    /*different types of scales*:smooth, hard, horned */
    string scaleType;





    /*for testing purpose*/

    virtual void print();
    virtual void printPhys();
};


#endif
