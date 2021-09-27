#ifndef ACM_H
#define ACM_H
#include "linkedlist.h"
#include <vector>
#include "acmlibrary.h"
using namespace std;

class ACM {

  public:
    vector<Match> launchACM(LinkedList<Animal>,LinkedList<Client>,int,int);


  private:

    Compatibility animalClientCompatibility;
    MatchCombinations animalClientCombinations;
    MatchIdCombination makeIdCombs;


    //vector<vector<Match> > oneToOne;
//    vector<vector<string> > idCombinations;
//    vector<vector<Match> > macthCombinations;
//    vector<vector<Match> > rankSets;
//    vector<Match> optimalSet;




};

#endif
