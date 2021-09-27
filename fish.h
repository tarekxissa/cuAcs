#ifndef FISH_H
#define FISH_H
#include "animal.h"
using namespace std;

class Fish : public Animal{

    public:
        Fish(string,string);
        virtual ~Fish();

        virtual void setPhysCharacteristics(string,string,string);

        /*setters for fish attributes*/
        virtual void setFinnsSize(string);
        virtual void setLength(string);
        virtual void setBodyPattern(string);


        /*getters for fish attributes*/
        virtual string getFinnsSize();
        virtual string getLength();
        virtual string getBodyPattern();

    protected:
        /* Attributes used for setPhysCharacteristics Fxn */
        string finnsSize;
        string bodyLength;
        string bodyPattern;


        /*for testing purpose*/
        virtual void print();
        virtual void printPhys();
};
#endif
