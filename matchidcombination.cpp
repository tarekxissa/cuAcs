#include <iostream>
#include "matchidcombination.h"
#include <string>
#include <sstream>
#include <QDebug>

using namespace std;

MatchIdCombination::MatchIdCombination(){
    counter = 1;
}
MatchIdCombination::~MatchIdCombination(){}



//comment on this function not yet made
template<typename T>
void MatchIdCombination::addToTempVector(const T& c, int combo)
{
    //qDebug ("addToTempVector");

    //cout<<"Inside addToTempVector"<<endl;
    int n = c.size();
    vector<string> tempVec;
    //cout<<"comb "<<counter<<": ";
    for (int i = 0; i < n; ++i) {
        if ((combo >> i) & 1)
            //cout << c[i] << ' ';
            tempVec.push_back(c[i]);

    }
    tempCombo.push_back(tempVec);

    //cout << endl;
}



//FUNCTIONS NOT TO CHANGE
template<typename T>
void MatchIdCombination::combo(const T& c, int k)
{
    //cout<<"Inside combo"<<endl;
    int n = c.size();
    int combo = (1 << k) - 1;       // k bit setsv
    while (combo < 1<<n) {

        addToTempVector(c, combo);



        int x = combo & -combo;
        int y = combo + x;
        int z = (combo & ~y);

        //qDebug("x in division = %d",x);

        combo = z / (x);
        combo >>= 1;
        combo |= y;
    }
}



//this function makes the different combinations of numbers depending on the percentage we give it

//previous:
    //vector<vector<string> > MatchIdCombination::makeNumberCombination(int numberOfClientAnimal,int percentage)

//new
vector<vector<string> > MatchIdCombination::makeNumberCombination(vector<string>& passedAnimalClientVectorIDs, int percentage){

    // qDebug ("makeNumberCombination");

    //cout<<"Inside makeNumberCombination"<<endl;
    //declare the vector to return
    vector<vector<string> > numCombo;


    int i = percentage;
    do
    {
        combo(passedAnimalClientVectorIDs, i);
        i++;
    } while (i<= passedAnimalClientVectorIDs.size());


    //assing the numCombo vector to the tempCombo
    numCombo = tempCombo;

    //clear tempCombo for next usage
    tempCombo.clear();

    //return the vector of number combinations
    return numCombo;

}

//this function makes combination of IDs
vector<string> MatchIdCombination::singleIDCombLeftToRight(vector<string>& animalComb, vector<string>& clientComb){

    //cout<<"Inside singleIDCombLeftToRight"<<endl;
    vector<string> idComb;

    if(animalComb.size() == clientComb.size()){

        int i = 0;

        int terminate = clientComb.size();

        do
        {
            string combo = animalComb[i] + clientComb[i];
            idComb.push_back(combo);
            i++;
        } while (i < terminate);


    }

    return idComb;

}


vector<string> MatchIdCombination::singleIDCombRightToLeft(vector<string>& animalComb, vector<string>& clientComb){

    //cout<<"Inside singleIDCombRightToLeft"<<endl;
    vector<string> idComb;


    /*doing it from numbers left to right*/
    if(animalComb.size() == clientComb.size()){


        int i = clientComb.size()-1;
        int size = clientComb.size();
        do
        {
            string combo = animalComb[size-i-1] + clientComb[i];
            idComb.push_back(combo);
            i--;
        } while (i>=0);

    }

    return idComb;

}


vector<vector<string> > MatchIdCombination::makeAllIdCombinations(vector<vector<string> >& animalCombos,vector<vector<string> >& clientCombos){



    vector<vector<string> > allIdCombos;

    vector<string> singleCombosLeftToRight;
    vector<string> singleCombosRightToLeft;


    int i=0;
    do
    {
        /* code */
        int j=0;
        do
        {
            /* code */
            singleCombosLeftToRight = singleIDCombLeftToRight(animalCombos[i], clientCombos[j]);

            singleCombosRightToLeft = singleIDCombRightToLeft(animalCombos[i], clientCombos[j]);

            /*only add the singleCombo is its size in not 0*/
            if(singleCombosLeftToRight.size() > 0){

                allIdCombinationString.push_back(singleCombosLeftToRight);
                allIdCombinationString.push_back(singleCombosRightToLeft);


                allIdCombos.push_back(singleCombosLeftToRight);
                allIdCombos.push_back(singleCombosRightToLeft);

                if(allIdCombos.size() > 260 || allIdCombinationString.size() > 260){
                    return allIdCombos;
                }

            }


            singleCombosRightToLeft.clear();
            singleCombosLeftToRight.clear();
            j++;
        } while (j < clientCombos.size());




        i++;

    } while (i < animalCombos.size());



    return allIdCombos;
}


void MatchIdCombination::convertIdsToInt(){



    vector<unsigned int> tempIdToInt;
    for(int i=0;i<allIdCombinationString.size();i++ ){
        for(int j=0;j<allIdCombinationString[i].size();j++){
            string id = allIdCombinationString[i][j];
            istringstream iss (id);
            unsigned int currIdToInt;
            iss >> currIdToInt;

            tempIdToInt.push_back(currIdToInt);

        }
        idCombinations.push_back(tempIdToInt);
        tempIdToInt.clear();
    }

}

//ACTUAL FUNTION CALLED TO GET ALL THE IDS OF UNSIGNED INTS
vector<vector<string> > MatchIdCombination::getAllIdCombinations(vector<string>& passedAniamlIDs, vector<string>& passedClientIDs,int& totalAnimals,int& totalClients){

    //cout<<"Inside getAllIdCombinations"<<endl;

    //cout<<"number of animals: "<<totalAnimals<<endl;
    //cout<<"number of clients: "<<totalClients<<endl;

    vector<vector<string> > idCombinations;
    if(totalAnimals <=0 || totalClients <= 0){
        cerr << "Number of clients or animals = 0"<<endl;
        exit(1);
    }

    vector<vector<string> > animalIds;
    vector<vector<string> > clientIds;

    if(totalAnimals == totalClients){



        animalIds = makeNumberCombination(passedAniamlIDs,0.9*totalAnimals);

        clientIds = makeNumberCombination(passedClientIDs,0.9*totalClients);


    }else if(totalAnimals > totalClients){

        animalIds = makeNumberCombination(passedAniamlIDs,0.9*totalClients);



        clientIds = makeNumberCombination(passedClientIDs,0.9*totalClients);



    }else{
         animalIds = makeNumberCombination(passedAniamlIDs,0.9*totalAnimals);



        clientIds = makeNumberCombination(passedClientIDs,0.9*totalAnimals);

    }



    /*make all the id combinations and add them to allCombinationStrings */

    //qDebug ("MAKE ALL ID COMBINATIONS IN matchidcombination.cpp");
    idCombinations = makeAllIdCombinations(animalIds,clientIds);

    /*convert the string vector of ids from allCombinationStrings to integers*/
    //convertIdsToInt();

    return idCombinations;
}


//these functions are for testing purposes

void MatchIdCombination::printComboVector(vector<vector<string> > comboVector){

    for(int i=0;i<comboVector.size();i++){

        for(int j=0;j<comboVector[i].size();j++){

            cout<<comboVector[i][j]<<" ";
        }
        cout<<endl;
    }
}

void MatchIdCombination::printSingleAlpahNumCombo(vector<string> comb){

    for(int i=0; i < comb.size();i++){
        cout<< comb[i]<<" ";

    }
    cout<<endl;
}

void MatchIdCombination::printUnsignedIds(vector<vector<unsigned int> > ids){

    for(int i=0; i < ids.size();i++){
        for(int j=0; j< ids[i].size();j++){
            cout<< ids[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}
