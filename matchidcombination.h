#ifndef MATCHIDCOMBINATION_H
#define MATCHIDCOMBINATION_H



#include <vector>
#include <unistd.h>
#include <algorithm>
#include <typeinfo>
#include <string>

using namespace std;
class MatchIdCombination{

    public:
        MatchIdCombination();
        ~MatchIdCombination();






        vector<vector<unsigned int> > idCombinations;

        int counter;

        vector<vector<string> > allIdCombinationString;

        vector<vector<string> > tempCombo;

        ////////////////////////////////////////FUNCTIONS///////////////////////////////////////////////////

        template<typename T>
        void addToTempVector(const T&, int);

        template<typename T>
        void combo(const T&,int);

        vector<vector<string> > makeNumberCombination(vector<string>&,int);

        vector<string> singleIDCombLeftToRight(vector<string>&, vector<string>&);

        vector<string> singleIDCombRightToLeft(vector<string>&,vector<string>&);

        vector<vector<string> > makeAllIdCombinations(vector<vector<string> >&,vector<vector<string> >&);

        void convertIdsToInt();

        vector<vector<string> > getAllIdCombinations(vector<string>&,vector<string>&,int&,int&);


         //////////////////////////////////////*for testing purpuses*//////////////////////////////////////

        void printComboVector(vector<vector<string> >);

        void printSingleAlpahNumCombo(vector<string>);

        void printUnsignedIds(vector<vector<unsigned int> >);










};

#endif // MATCHIDCOMBINATION_H
