#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "acm.h"


using namespace std;


vector<Match> ACM::launchACM(LinkedList<Animal> animals,LinkedList<Client> clients,int numAnimals,int numClients){



  vector<string> animalIds;
  vector<string> clientIds;

  for (int i= 0;i<animals.size();i++){
    animalIds.push_back(to_string(i));
  }

//  cout<< ("SIZE OF ANIMALIDS");

//    cout<<("%d",animalIds.size());



  for (int i= 0;i<clients.size();i++){
    clientIds.push_back(to_string(i));
  }

//  cout<< ("SIZE OF CLIENTIDS");

//  cout<<("%d",clientIds.size());



  cout<<"ID COMBINATIONS"<<endl;


  vector<vector<string> > idCombinations = makeIdCombs.getAllIdCombinations(animalIds,clientIds,numAnimals,numClients);

  //cout<<"SIZE OF idcombinations = "<<idCombinations.size()<<endl;

//  for(int i=0;i<idCombinations.size();i++){
//      cout<<"SIZE OF COMBINATION "<<i<<" = "<<idCombinations[i].size()<<endl;

//      for(int j = 0; j<idCombinations[i].size();j++){
//          cout <<idCombinations[i][j]<<" ";
//      }
//      cout<<endl;
//  }

  cout<<"ONE TO ONE MATCHES"<<endl;

  vector<vector<Match> > oneToOne = animalClientCompatibility.computeAllMatchCompatibility(animals,clients);

  //cout<<"SIZE OF oneToOne = "<<oneToOne.size()<<endl;

  cout<<"MATCH COMBINATIONS"<<endl;


  vector<vector<Match> > macthCombinations = animalClientCombinations.makeMatchCombinations(idCombinations,oneToOne);

  //idCombinations.clear();

  //cout<<"SIZE OF macthCombinations = "<<macthCombinations.size()<<endl;
  //oneToOne.clear();

  cout<<"RANK SETS"<<endl;

  vector<vector<Match> > rankSets = animalClientCombinations.computeRank(macthCombinations,0);

  //cout<<"SIZE OF rankSets = "<<rankSets.size()<<endl;

  macthCombinations.clear();

  cout<<"OPTIMAL SET"<<endl;
  vector<Match> optimalSet = animalClientCombinations.computeOptimalSet(rankSets);

  rankSets.clear();

  return optimalSet;



}
