#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

using namespace std;

class Animal{

  //friend class Array<Animal>;


  public:
    Animal(string,string);
    virtual ~Animal();

    /*this fucntion setsn the basic information about the animals such as name apsecies and gender*/
    void setBasicInfo(string,string, string,string,string,string);

    bool operator==(Animal*);


    /*getters overwritten for inheritance purposes*/

    /*Mammal class*/

    virtual string getMammalHairLength();
    virtual string getMammalHairColour();

    /*Mammal and Amphibian class */

    virtual string getBuild();
    /*Amphibian, reptile, fish class*/
    virtual string getLength();
    virtual string getBodyPattern();
    /*Fish class*/
    virtual string getFinnsSize();
    /*Bird class*/
    virtual string getWingSpan();
    virtual string getBeakLength();
    virtual string getBeakColour();
    virtual string getScaleType();
    /*Reptile class*/


   /*setters overwritten for inheritance purposes*/

    /*this function will be overwrittem in all of the classes*/


    virtual void setPhysCharacteristics(string,string,string);

    /*Mammal class*/
    virtual void setMammalHairLength(string);
    virtual void setMammalHairColour(string);
    /*Mammal and Amphibian class*/
    virtual void setBuild(string);
    /*Amphibian, reptile, fish class*/
    virtual void setLength(string);
    virtual void setBodyPattern(string);
    /*Fish class*/
    virtual void setFinnsSize(string);
    /*Bird class*/
    virtual void setWingSpan(string);
    virtual void setBeakLength(string);
    virtual void setBeakColour(string);
    /*Reptile class*/
    virtual void setScaleType(string);

    virtual void setNonPhysicalAttributes(string,string,string,string,string,string,string,string,string,string,string,string);


   /*getters for all attributes physiscal attributes*/
    string getName();
    string getSpecies();
    string getAge();
    string getGender();
    string getColour();
    string getHeight();
    string getWeight();
    string getType();

    /*getters for all attributes non-physiscal attributes*/
    string getActiveness();
    string getPlayfulness();
    string getIndividualism();
    string getAffectionism();
    string getIntelligence();
    string getDiscipline();
    string getAssertiveness();
    string getSpaciousness();
    string getEnergetic();
    string getDiurnalNocturnal();
    string getHabitatPreference();
    string getAppetite();

    /*setters for all attributes physiscal attributes*/
    void setName(string);
    void setSpecies(string);
    void setAge(string);
    void setGender(string);
    void setColour(string);
    void setHeight(string);
    void setWeight(string);
    void setType(string);

    /*setters for all attributes non-physiscal attributes*/
    void setActiveness(string);
    void setPlayfulness(string);
    void setIndividualism(string);
    void setAffectionism(string);
    void setIntelligence(string);
    void setDiscipline(string);
    void setAssertiveness(string);
    void setHabitatPreference(string);
    void setDiurnalNocturnal(string);
    void setEnergetic(string);
    void setAppetite(string);
    void setSpaciousness(string);
    void setEnergy(string);

    void setEdited(bool);
    void setAnimalId(int);
    void incramentID(int);

    int getAnimalID();


    //Helper setter functions
    void setNewAnimal(bool);

    void setID(int);

    bool getEdited();

    //Helper getter functions
    bool getNewAnimal();



    /*for testing purposes*/
    virtual void print();

    virtual void printPhys();


  protected:
    /*Attributes set in constructor*/
    string name;
    string species;



    /*Attributes set in setBasicInfo*/
    string age;
    string gender;
    string colour;

    /* Attributes set in setPhysCharacteristics */
    string height;
    string weight;
    string typeOfAnimal;

    /*non -physical attributes inherited by all classes*/
    string activeness;
    string playfulness;
    string individualism;
    string affectionism;
    string intelligence;
    string discipline;
    string assertiveness;
    string energetic;
    string diurnalNocturnal;
    string spaciousness;
    string appetite;
    string habitatPref;

    int ID;
    bool edited;
    bool isNewAnimal;




};


#endif
