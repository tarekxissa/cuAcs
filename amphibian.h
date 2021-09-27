#ifndef AMPHIBIAN_H
#define AMPHIBIAN_H
#include "animal.h"
using namespace std;
class Amphibian : public Animal{

    public:
        Amphibian(string,string);
        virtual ~Amphibian();

        virtual void setPhysCharacteristics(string,string,string);



        /*setter for the amphibian physical characteristics*/
        virtual void setLength(string);
        virtual void setBodyPattern(string);
        virtual void setBuild(string);


        /*getters for the amphibian physical characteristics*/
        virtual string getLength();
        virtual string getBodyPattern();
        virtual string getBuild();


    protected:
    /* Attributes used for setPhysCharacteristics Fxn */
        string bodyPattern;
        string bodyLength;
        string build;
        virtual void print();
        virtual void printPhys();


};

#endif
