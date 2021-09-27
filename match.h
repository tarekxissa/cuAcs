#ifndef MATCH_H
#define MATCH_H
#include <iostream>
#include <string>
#include "animalheaders.h"
#include "client.h"

using namespace std;

class Match{

    public:
        Match(Client*,Animal*,int);
        ~Match();

        /*gets the rank of the this match's Animal on this match's Client profile*/
        int getMatchAnimalRank(Animal**);

        /*getters for the match class attributes*/
         unsigned int getMatchId();
         float getNonPhysicalTotal();
         float getNonPhysicalAverage();
         float getPhysicalTotal();
         float getPhysicalAverage();
         float getMatchTotal();
         float getMatchAverage();

        Client* getClient();    //returns a pointer to this match's Client
        Animal* getAnimal();    //returns a pointer to this match's Animal

        /*setters for the match class attributes*/
        void setNonPhysicalTotalAndAverage(float);
        void setNonPhysicalAverage(float);
        void setPhysicalTotalAndAverage(float);
        void setPhysicalAverage(float);
        void setMatchTotalAndAverage();
        void setMatchAverage(float);


        void print();


    private:
        Client* client;
        Animal* animal;

        /* a match id is going to be a concatenation of the cleint's and animal's ids*/
        unsigned int matchId;


        /* if errors, check to initialize attributes to 0 */

        /*the total of the non-physiscal attributes calculated by 5-|clientPreff-animalAttribute|*/
         float matchNonPhysicalTotal;      //the largest value it can hold is 60

        /*the average of the non-physiscal attributes calculated by macthPhsysicalTotal/12 */
         float matchNonPhysicalAverage;    //the largest value it can hold is 5

        /*the total of the physiscal attributes calculated by 3-|clientPreff-animalAttribute|*/
         float matchPhysicalTotal;    //the larget value it can hold it 3

        /*the average of the physiscal attributes calculated by macthPhsysicalTotal/3 */
         float matchPhysicalAverage;   //the largest value it can hold is 3

        /*the match total of the physiscal and non-physical attributes calculated by matchNonPhysicalTotal + matchPhsysicalTotal  */
         float matchTotal;    //the largest value it can hold is 63

        /*the match average of the physiscal and non-physical attributes calculated by (matchNonPhysicalTotal + matchPhsysicalTotal)/15*/
         float matchAverage;   //the largest value it can hold is 4.6


};

#endif
