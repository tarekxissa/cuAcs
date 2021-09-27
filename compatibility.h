#ifndef COMPATIBILITY_H
#define COMPATIBILITY_H
#include "match.h"
#include "linkedlist.h"
#include <vector>
using namespace std;

class Compatibility
{
public:
   Compatibility();
   float computePhysicalCompatibility(Animal*,Client*);
   float computeNonPhysicalCompatibility(Animal*,Client*);
   vector<vector<Match> > computeAllMatchCompatibility(LinkedList<Animal>,LinkedList<Client>);



private:
    vector<vector<Match> > compatibleMatches;

};

#endif // COMPATIBILITY_H
