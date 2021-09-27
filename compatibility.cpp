#include "compatibility.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <sstream>
using namespace std;

Compatibility::Compatibility(){


}
float Compatibility:: computePhysicalCompatibility(Animal* animalCalc ,Client* clientCalc){
    float physMatchLevel = 0;
    int animalRank = clientCalc->getAnimalRank(animalCalc->getSpecies());


    // cout<<"\tAnimal "<<animalCalc->getSpecies()<<" Physical Characteristics (with ranks "<<clientCalc->getAnimalRank(animalCalc->getSpecies())<<")"<<endl;
    // cout<<"\t-------------------------------"<<endl;
    // animalCalc->printPhys();
    // cout<<endl;
    //
    // cout<<"\tClient "<<clientCalc->getFirstName()<<" Physical Preferences for "<<clientCalc->ranks.getByRank(animalRank)->getSpecies()<<endl;
    // cout<<"\t------------------------------------------------------------"<<endl;
    // clientCalc->ranks.getByRank(animalRank)->printPhys();

    //cout<<"Ranks size "<<clientCalc->ranks.size()<<endl;

    Animal *dummyAnimal;
    if(animalRank < 6){

        //cout<<"ClientCalc"<<endl;
        if(animalCalc->getType() == "cat" || animalCalc->getType() == "dog"){

            //cout<<"get type in compatibility "<<animalCalc->getType()<<endl;


            dummyAnimal = clientCalc->ranks.getByRank(animalRank);

//            cout<<"aniaml hair colour = "<<animalCalc->getMammalHairColour()<<endl;
//            cout<<"client animal hair colour = "<<clientCalc->ranks.getByType(animalCalc->getType())->getMammalHairColour()<<endl;


            if(animalCalc->getMammalHairColour() == clientCalc->ranks.getByType(animalCalc->getType())->getMammalHairColour()){
                physMatchLevel++;
            }
            if(animalCalc->getMammalHairLength() == clientCalc->ranks.getByType(animalCalc->getType())->getMammalHairLength()){
                physMatchLevel++;
            }
            if(animalCalc->getBuild() == clientCalc->ranks.getByType(animalCalc->getType())->getBuild()){
                physMatchLevel++;
            }
        }
        else if(animalCalc->getType() == "snake" || animalCalc->getType() == "lizard"){
            if(animalCalc->getBodyPattern() == clientCalc->ranks.getByType(animalCalc->getType())->getBodyPattern()){
                physMatchLevel++;
            }
            if(animalCalc->getLength() == clientCalc->ranks.getByType(animalCalc->getType())->getLength()){
                physMatchLevel++;
            }
            if(animalCalc->getScaleType() == clientCalc->ranks.getByType(animalCalc->getType())->getScaleType()){
                physMatchLevel++;
            }
        }

        else if(animalCalc->getType() == "frog" || animalCalc->getType() == "salamander"){
            if(animalCalc->getBodyPattern() == clientCalc->ranks.getByType(animalCalc->getType())->getBodyPattern()){
                physMatchLevel++;
            }
            if(animalCalc->getLength() == clientCalc->ranks.getByType(animalCalc->getType())->getLength()){
                physMatchLevel++;
            }
            if(animalCalc->getBuild() == clientCalc->ranks.getByType(animalCalc->getType())->getBuild()){
                physMatchLevel++;
            }
        }
        else if(animalCalc->getType() == "parrot" || animalCalc->getType() == "finch"){
            if(animalCalc->getWingSpan() == clientCalc->ranks.getByType(animalCalc->getType())->getWingSpan()){
                physMatchLevel++;
            }
            if(animalCalc->getBeakColour() == clientCalc->ranks.getByType(animalCalc->getType())->getBeakColour()){
                physMatchLevel++;
            }
            if(animalCalc->getBeakLength()  == clientCalc->ranks.getByType(animalCalc->getType())->getBeakLength()){
                physMatchLevel++;
            }
        }
        else if(animalCalc->getType() == "betta" || animalCalc->getType() == "goldfish"){
            if(animalCalc->getFinnsSize() == clientCalc->ranks.getByType(animalCalc->getType())->getFinnsSize()){
                physMatchLevel++;
            }
            if(animalCalc->getBodyPattern() == clientCalc->ranks.getByType(animalCalc->getType())->getBodyPattern()){
                physMatchLevel++;
            }
            if(animalCalc->getLength() == clientCalc->ranks.getByType(animalCalc->getType())->getLength()){
                physMatchLevel++;
            }
        }
        //cout<<"physical comp for animal "<<physMatchLevel<<endl;

     }
    else{
        printf("This animal is not in the top 5 ranking of the client\n");
        return 0;
    }

    return physMatchLevel;
}
float Compatibility:: computeNonPhysicalCompatibility(Animal* animalCalc, Client* clientCalc){







   float traitCompatibility = 5 - abs(stof(animalCalc->getIndividualism().substr(0,1)) - stof(clientCalc->getClientIndividualismPreference().substr(0,1)))
                            + 5 - abs(stof(animalCalc->getAffectionism().substr(0,1)) - stof(clientCalc->getClientAffectionism().substr(0,1)))
                            + 5 - abs(stof(animalCalc->getIntelligence().substr(0,1)) - stof(clientCalc->getClientIntelligencePreference().substr(0,1)))
                            + 5 - abs(stof(animalCalc->getDiscipline().substr(0,1)) - stof(clientCalc->getClientDisciplinePreference().substr(0,1)))
                            + 5 - abs(stof(animalCalc->getAssertiveness().substr(0,1)) - stof(clientCalc->getClientAssertivenessPreference().substr(0,1)))
                            + 5 - abs(stof(animalCalc->getPlayfulness().substr(0,1)) - stof(clientCalc->getClientPlayfulllnessPreference().substr(0,1)))
                            + 5 - abs(stof(animalCalc->getActiveness().substr(0,1)) - stof(clientCalc->getClientActiveness().substr(0,1)))
                            + 5 - abs(stof(animalCalc->getEnergetic().substr(0,1)) - stof(clientCalc->getClientEnergeticPreference().substr(0,1)));

   float otherCompatibility = 5 - abs(stof(animalCalc->getSpaciousness().substr(0,1)) - stof(clientCalc->getClientSpaciousnessPreference().substr(0,1)))
                            + 5 - abs(stof(animalCalc->getDiurnalNocturnal().substr(0,1)) - stof(clientCalc->getClientDiurnalNocturnal().substr(0,1)))
                            + 5 - abs(stof(animalCalc->getAppetite().substr(0,1)) - stof(clientCalc->getClientAppetitePreference().substr(0,1)))
                            + 5 - abs(stof(animalCalc->getHabitatPreference().substr(0,1)) - stof(clientCalc->getClientHabitaPreference().substr(0,1)));


   float nonPhysCompatibility = (0.9*traitCompatibility) + (1.2 * otherCompatibility);

    //float indiv = stof(animalCalc.getIndividualism().substr(0,1)) - stof(clientCalc.getClientIndividualismPreference().substr(0,1));
  //physicalCompatibility = indiv + affect + intelllingence + discipline + assertive + playfull + energetic + space + diurnal + appetite + habitat + active;

    return nonPhysCompatibility;

}

vector<vector<Match> > Compatibility:: computeAllMatchCompatibility(LinkedList<Animal> allAnimals,LinkedList<Client> allClients){
    float nonPhysMatchlvl;
    float nonPhysMatchAvg;

    //cout<<"starting to compute all match compatibility"<<endl;

    for(int i = 0; i < allAnimals.size(); i++){
        //cout<<"for animal: "<<i<<endl;
        vector<Match> forEachAnimal;
        for(int y = 0; y < allClients.size(); y++){
          //  cout<<"computing the non physical compatibility"<<endl;
            nonPhysMatchlvl = computeNonPhysicalCompatibility(allAnimals.get(i), allClients.get(y));
            //cout<<"done computing the non physical compatibility"<<endl;
            nonPhysMatchAvg = nonPhysMatchlvl / 12;
            if(nonPhysMatchAvg >= 3){
                //convert i and y to strings
                //concatenate the strings
                //convert the concatenated string to an int
                string animalID = to_string(i);
                string clientID = to_string(y);
                string matchID = animalID + clientID;
                //cout<<"the match id is: "<<stoi(matchID)<<endl;

                Match newMatch(allClients.get(y), allAnimals.get(i), stoi(matchID));
                newMatch.setNonPhysicalTotalAndAverage(nonPhysMatchlvl);
                //ask yvan about how to set physical total
                newMatch.setPhysicalTotalAndAverage(computePhysicalCompatibility(allAnimals.get(i), allClients.get(y)));
                newMatch.setMatchTotalAndAverage(); //Ask YVAN ABOUT THIS PROBLEM

                forEachAnimal.push_back(newMatch);
            }
            else{
                Match dummyMatch(NULL, NULL, 0);

                forEachAnimal.push_back(dummyMatch);
            }

        }
        compatibleMatches.push_back(forEachAnimal);

    }
    return compatibleMatches;


}

