#ifndef CLIENT_H
#define CLIENT_H
#include <string>

#include "animalheaders.h"
#include "linkedlist.h"

using namespace std;



class Client{

    public:
        Client(string,string,string,string,string,string);
        ~Client();

        bool operator==(Client*);

        LinkedList<Animal> ranks;

        /*setters for personal info*/
        void setClientBasicInfo(string);

        void setFirstName(string);
        void setLastName(string);
        void setGender(string);
        void setAge(string);

        void setEmail(string);
        void setPhoneNumber(string);

        /*setters for contact information*/
        void setContactInfo(string,string);

        void setClientId(int);

        /*setters for the non physiscal attributes that apply to clients*/

        void setClientDiurnalNocturnal(string);
        void setClientHabitaPreference(string);
        void setClientAffectionism(string);
        void setClientActiveness(string);

         /*setters for the non physiscal attributes that apply to animals only*/
        void setClientIndividualismPreference(string);
        void setClientIntelligencePreference(string);
        void setClientDisciplinePreference(string);
        void setClientAssertivenessPreference(string);
        void setClientPlayfulllnessPreference(string);
        void setClientEnergeticPreference(string);
        void setClientSpaciousnessPreference(string);
        void setClientAppetitePreference(string);

        /*monster setter for non-physiscal attributes*/
        void setCharacterTraits(string,string,string,string);
        void setNonPhysPreferences(string,string,string,string,string,string,string,string);



        /*getters for client personal info*/
        string getFirstName();
        string getLastName();
        string getGender();
        string getAge();

        bool getEdited();

        void setEdited(bool);

        void incramentID(int oldID);

        /*getter for client contatc info*/
        string getEmail();
        string getPhoneNumber();

        int getClientId();
        int getAnimalRank(string);

        /*getters for the non physiscal attributes that apply to clients*/

        string getClientDiurnalNocturnal();
        string getClientHabitaPreference();
        string getClientAffectionism();
        string getClientActiveness();

         /*getters for the non physiscal attributes that apply to animals only*/
        string getClientIndividualismPreference();
        string getClientIntelligencePreference();
        string getClientDisciplinePreference();
        string getClientAssertivenessPreference();
        string getClientPlayfulllnessPreference();
        string getClientEnergeticPreference();
        string getClientSpaciousnessPreference();
        string getClientAppetitePreference();

        /*for testing purpuses*/
        void print();


        //Helper Setter functions
        void setNewClient(bool);



        //Helper Getter functions
        bool getNewClient();

        //for testing
        void populateRanks();

    private:
        string firstName;
        string lastName;
        string age;


        string gender;
        string email;
        string phoneNumber;

        /*non-physical atributes that apply to clients*/
        string diurnalNocturnal;
        string habitatPreference;
        string affectionism;
        string activeness;

        /*non-physical atributes that apply to animals only*/
        string individualism;
        string intelligence;
        string discipline;
        string assertiveness;
        string playfulness;
        string energetic;
        string spaciousness;
        string appetite;




        //this can be either: new, edited, old

        bool isNewClient;

        //intergers from 0 to n

        bool edited;
        int ID;
};

#endif
