#ifndef MATCHCOMBINATIONS_H
#define MATCHCOMBINATIONS_H

#include "match.h"
#include <vector>

using namespace std;


class MatchCombinations
{

public:

    vector<vector<Match> > makeMatchCombinations(vector<vector<string> >, vector<vector<Match> >);
    vector<vector<Match> > computeRank(vector<vector<Match> >, int);
    vector<Match> computeOptimalSet(vector<vector<Match> >);



private:

};

#endif // MATCHCOMBINATIONS_H
