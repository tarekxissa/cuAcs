#include "matchcombinations.h"
#include <iostream>
#include <string>
#include <QDebug>

using namespace std;

vector<vector<Match> > MatchCombinations::computeRank(vector<vector<Match> > matchRanks, int reduction){

    //cout<<"SIZE OF matchranks IN  computeRak = %d"<<matchRanks.size()<<endl;
    int red = reduction;
    vector<vector<Match> > finalVect;
    int passLevel; //declared passlevel
    int currentSetLevel; //level for each vector of matches
    for(unsigned int i = 0; i < matchRanks.size(); i++){
        passLevel = (matchRanks[i].size()/ 2 + 1 )- red;
        //cout<<"PASS LEVEL "<<passLevel<<endl;
        currentSetLevel = 0;
        for(unsigned int y = 0; y < matchRanks[i].size(); y++){
            Match temp = matchRanks[i][y];
            for(int x = 0; x < 5; x++){

                if(temp.getClient()->ranks.get(x)->getType() == temp.getAnimal()->getType()){
                    currentSetLevel++;
                    break;
            }
        }
      }
        if(currentSetLevel >= passLevel){
           // cout<<"PASSED RANK TEST"<<endl;
            finalVect.push_back(matchRanks[i]);
        }

        if(i == matchRanks.size() - 1 && finalVect.size() <=5) {
            i = 0;
            red += 1;
        }

   }
//    if(finalVect.size() <= 5){
//        qDebug("PASS LEVEL ");
//        computeRank(matchRanks, reduction + 1);
//    }

    //cout<<"SIZE OF finalVect BEFORE RETURNING = "<<finalVect.size()<<endl;

    return finalVect;
}


vector<Match> MatchCombinations:: computeOptimalSet(vector<vector<Match> > finalVect){
    float setLevel = 0;
    float setAvgLevel;
    vector<Match> optimalSet;
    float optimalSetLevel = 0;
    float optimalSetAvgLevel = 0;
    for(unsigned int i = 0; i < finalVect.size(); i++){
        setLevel = 0;
        for(unsigned int y = 0; y < finalVect[i].size(); y++){
            setLevel += finalVect[i][y].getMatchTotal();
        }
        setAvgLevel = setLevel / finalVect[i].size();
        if((setAvgLevel > optimalSetAvgLevel) || ((setAvgLevel == optimalSetAvgLevel) && (finalVect[i].size() > optimalSet.size()))){
            optimalSet = finalVect[i];
            optimalSetLevel = 0;
            for(unsigned int z = 0; z < optimalSet.size(); z++){
               optimalSetLevel += optimalSet[z].getMatchTotal();

            }
            optimalSetAvgLevel = optimalSetLevel / optimalSet.size();
        }


    }

    return optimalSet;

}

vector<vector<Match> > MatchCombinations:: makeMatchCombinations(vector<vector<string> > MatchIDcombinations, vector<vector<Match> > oneToOneMatches){
    vector<vector<Match> > allMatchesComb;
    vector<Match> dummyVec;
    //int vecPass = 0;
    for(unsigned int i = 0; i < MatchIDcombinations.size(); i++){

        for(unsigned int y = 0; y < MatchIDcombinations[i].size(); y++){
            int id1;
            int id2;
            if((MatchIDcombinations[i][y].length()) % 2 == 0){
                id1 = stoi(MatchIDcombinations[i][y].substr(0,MatchIDcombinations[i][y].length() / 2));
                id2 = stoi(MatchIDcombinations[i][y].substr(MatchIDcombinations[i][y].length() / 2,MatchIDcombinations[i][y].length() / 2));
            }
            else{//if the size of id is odd
                id1 = stoi(MatchIDcombinations[i][y].substr(0,MatchIDcombinations[i][y].length() / 2));
                id2 = stoi(MatchIDcombinations[i][y].substr(MatchIDcombinations[i][y].length() / 2,(MatchIDcombinations[i][y].length() / 2)+1));

            }


            if(oneToOneMatches[id1][id2].getAnimal() != NULL){
                    //add it to the currentVec
                    dummyVec.push_back(oneToOneMatches[id1][id2]);
             }


           }
           if(dummyVec.size() == MatchIDcombinations[i].size()){
              //cout<<"vector passed : "<<vecPass<<endl;
              //vecPass++;
              allMatchesComb.push_back(dummyVec);

            }
          dummyVec.clear();

        }
    return allMatchesComb;
}
