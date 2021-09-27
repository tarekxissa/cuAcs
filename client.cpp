#include <iostream>
#include "client.h"
#include <string>
using namespace std;

Client::Client(string clientFirstName, string clientLastName,string clientAge,string clientEmail, string clientPhoneNumber,string clientGender){
    firstName = clientFirstName;
    lastName = clientLastName;
    age = clientAge;
    email = clientEmail;
    phoneNumber = clientPhoneNumber;
    gender = clientGender;
    edited = false;
    isNewClient = false;
    ID =1;
}

void Client::setClientId(int id){
    ID = id;
}
//checks if the id of the client is the same as the this client id
bool Client::operator==(Client* client){

    if(this->ID == client->getClientId()){return true;}
    return false;
}

Client::~Client(){}

void Client::setClientBasicInfo(string clientGender){

    gender = clientGender;
}
void Client::setContactInfo(string clientEmail,string clientPhoneNumber){

    email = clientEmail;
    phoneNumber = clientPhoneNumber;

}


//checks if the id of the client is the same as the this client id


/*setters for client personal info*/
void Client::setFirstName(string clientFirstName){firstName = clientFirstName;}
void Client::setLastName(string clientLastName){lastName = clientLastName;}
void Client::setGender(string clientGender){gender = clientGender;}
void Client::setAge(string clientAge){age = clientAge;}

/*setters for contact info*/
void Client::setEmail(string clientEmail){email = clientEmail;}
void Client::setPhoneNumber(string clientPhoneNumber){phoneNumber = clientPhoneNumber;}

/*setters for the non physiscal attributes that apply to clients*/

void Client::setClientDiurnalNocturnal(string clientDiurnalNocturnal){
    diurnalNocturnal = clientDiurnalNocturnal;
}
void Client::setClientHabitaPreference(string clientHabitatPreference){
    habitatPreference = clientHabitatPreference;
}
void Client::setClientAffectionism(string clientAffectionism){
    affectionism = clientAffectionism;
}
void Client::setClientActiveness(string clientActiveness){
    activeness = clientActiveness;
}

/*setters for the non physiscal attributes that apply to animals only*/
void Client::setClientIndividualismPreference(string clientIndividualismPreference){
    individualism = clientIndividualismPreference;
}
void Client::setClientIntelligencePreference(string clientIntelligencePreference){
    intelligence = clientIntelligencePreference;
}
void Client::setClientDisciplinePreference(string clientDisciplinePreference){
    discipline = clientDisciplinePreference;
}
void Client::setClientAssertivenessPreference(string clientAssertivenessPreference){
    assertiveness = clientAssertivenessPreference;
}
void Client::setClientPlayfulllnessPreference(string clientPlayfullnessPreference){
    playfulness = clientPlayfullnessPreference;
}
void Client::setClientEnergeticPreference(string clientEnergeticPreference){
    energetic = clientEnergeticPreference;
}
void Client::setClientSpaciousnessPreference(string clientSpaciounessPreference){
    spaciousness = clientSpaciounessPreference;
}
void Client::setClientAppetitePreference(string clientAppetitePreference){
    appetite = clientAppetitePreference;
}


/*monster setter for non-physicall attributes*/
void Client::setCharacterTraits(string clientActiveness,string clientAffectionism,string clientDiurnal,string clientHabitatPreference){
    /*non-Physical attributes that apply also to client*/
    activeness = clientActiveness;
    affectionism = clientAffectionism;
    diurnalNocturnal = clientDiurnal;
    habitatPreference = clientHabitatPreference;
}


void Client::setNonPhysPreferences(string clientIndividualismPreference,string clientIntelligencePreference,string clientDisciplinePreference,string clientAssertivenessPreference,string clientPlayfullnessPreference,string clientEnergeticPreference,string clientSpaciousnessPreference,string clientAppetitePreference){
        /*non-Physicall attributes that apply to only animals*/
        individualism = clientIndividualismPreference;
        intelligence = clientIntelligencePreference;
        discipline = clientDisciplinePreference;
        assertiveness = clientAssertivenessPreference;
        playfulness = clientPlayfullnessPreference;
        energetic = clientEnergeticPreference;
        spaciousness = clientSpaciousnessPreference;
        appetite = clientAppetitePreference;
}


/*getter for client contatc info*/
string Client::getFirstName(){return firstName;}
string Client::getLastName(){return lastName;}
string Client::getGender(){return gender;}
string Client::getAge(){return age;}

/*getters for contact info*/
string Client::getEmail(){return email;}
string Client::getPhoneNumber(){return phoneNumber;}


int Client::getClientId(){return ID;}

int Client::getAnimalRank(string animal){

    return ranks.getRank(animal);
}

/*getters for the non physiscal attributes that apply to clients*/

string Client::getClientDiurnalNocturnal(){return diurnalNocturnal;}
string Client::getClientHabitaPreference(){return habitatPreference;}
string Client::getClientAffectionism(){return affectionism;}
string Client::getClientActiveness(){return activeness;}

/*getters for the non physiscal attributes that apply to animals only*/
string Client::getClientIndividualismPreference(){return individualism;}
string Client::getClientIntelligencePreference(){return intelligence;}
string Client::getClientDisciplinePreference(){return discipline;}
string Client::getClientAssertivenessPreference(){return assertiveness;}
string Client::getClientPlayfulllnessPreference(){return playfulness;}
string Client::getClientEnergeticPreference(){return energetic;}
string Client::getClientSpaciousnessPreference(){return spaciousness;}
string Client::getClientAppetitePreference(){return appetite;}



/*Helper Setter functions*/
void Client::setNewClient(bool aNewClient){isNewClient = aNewClient;}


/*Helper Getter functions*/
bool Client::getNewClient(){return isNewClient;}


void Client::print(){

    cout<< "CLient with ID: "<<ID<<endl;
    cout<<"\tPERSONAL INFO"<<endl;
    cout<<"\t============"<<endl;
    cout<<"\tFull Name: "<<firstName<<" "<<lastName<<"\tGender: "<<gender<<"\tNew client: "<<this->isNewClient<<"\tEdited: "<<edited<<endl;
    cout<< "\t\nCONTACT INFO"<<endl;
    cout<<"\t============"<<endl;
    cout<<"\tEmail: "<<email<<"\tPhoneNumber: "<<phoneNumber<<endl;

    cout<<"\n\tCHARACTER TRAITS"<<endl;
    cout<<"\t============================================================================"<<endl;
    cout<<"\tDiurnal-Nocturnal: "<<diurnalNocturnal<<"\tHabitat Preference: "<<habitatPreference<<endl;
    cout<<"\tAffectionism: "<<affectionism<<"\tActiveness: "<<activeness<<endl;

    cout<<"\n\tNON-PHYSICAL ATTRIBUTES PREFERENCES"<<endl;
    cout<<"\t==========================================================================="<<endl;
    cout<<"\tIndividualism: "<<individualism<<"\tIntelligence: "<<intelligence<<endl;
    cout<<"\tDiscipline: "<<discipline<<"\tAssertiveness: "<<assertiveness<<endl;
    cout<<"\tPlayfullness: "<<playfulness<<"\tEnergetic: "<<energetic<<endl;
    cout<<"\tSpaciousness: "<<spaciousness<<"\tAppetite: "<<appetite<<"\n"<<endl;

}



bool Client::getEdited(){return edited;}
void Client::setEdited(bool state){edited = state;}


void Client::incramentID(int oldID){

    ID+=oldID;
}

void Client::populateRanks(){

    if(ranks.size()>0){ranks.clear();}

    //cout<<"\tbeginnig populate ranks "<<endl;

    vector<string> animals;
    animals.push_back("Dog");
    animals.push_back("Cat");
    animals.push_back("Parrot");
    animals.push_back("Finch");
    animals.push_back("Salamander");
    animals.push_back("Frog");
    animals.push_back("Snake");
    animals.push_back("Lizard");
    animals.push_back("Betta");
    animals.push_back("Goldfish");



    //physical attribute vectors


    vector<string> furLength;//same as for beakLenght, bodyLength, finnSize, wingSpan
    furLength.push_back("Short");
    furLength.push_back("Medium");
    furLength.push_back("Long");



    vector<string> furColour;
    furColour.push_back("Dark Brown");
    furColour.push_back("Light Brown");
    furColour.push_back("Blonde");
    furColour.push_back("White");
    furColour.push_back("Polka Dot");

    vector<string> bodyPattern;
    bodyPattern.push_back("Dotted");
    bodyPattern.push_back("Stripped");

    vector<string> build;
    build.push_back("Thin");
    build.push_back("Average");
    build.push_back("Bulky");

    vector<string> beakColour;
    beakColour.push_back("Red");
    beakColour.push_back("Orange");
    beakColour.push_back("Yellow");
    beakColour.push_back("Black");
    beakColour.push_back("Blue");
    beakColour.push_back("Mixed");

    vector<string> scaleType;
    scaleType.push_back("Smooth");
    scaleType.push_back("Jagged");

    //ranks
    vector<int> rank;
    rank.push_back(1);
    rank.push_back(2);
    rank.push_back(3);
    rank.push_back(4);
    rank.push_back(5);
    rank.push_back(6);
    rank.push_back(7);
    rank.push_back(8);
    rank.push_back(9);
    rank.push_back(10);

    //make the animals and add them ot the ranks linkedlist

    //cout<<"start populationg ranks"<<endl;

    //cout<<"\tin ranks at current animal"<<endl;
    Animal *currentAnimal;
  //  cout<<"\tdone declaring the animal"<<endl;
    for(int i=0;i<10;i++){

        /*string nonPhys1 = to_string(rand()%5+1);
        string nonPhys2 = to_string(rand()%5+1);
        string nonPhys3 = to_string(rand()%5+1);
        string nonPhys4 = to_string(rand()%5+1);
        string nonPhys5 = to_string(rand()%5+1);
        string nonPhys6 = to_string(rand()%5+1);
        string nonPhys7 = to_string(rand()%5+1);
        string nonPhys8 = to_string(rand()%5+1);
        string nonPhys9 = to_string(rand()%5+1);
        string nonPhys10 = to_string(rand()%5+1);
        string nonPhys11 = to_string(rand()%5+1);
        string nonPhys12 = to_string(rand()%5+1);*/

        string physOne, physTwo, physThree;

        if(animals[i] == "Dog" || animals[i] == "Cat"){

            //cout<<"\tmaking cat or dog"<<endl;

            if(animals[i] == "Dog"){currentAnimal = new Mammal("Dog","Dog");}
            if(animals[i] == "Cat"){currentAnimal = new Mammal("Cat","Cat");}

            //cout<<"\tmaking physical attribute 1"<<endl;

            physOne = furLength[rand()%2];

            //cout<<"making physical attribute 2"<<endl;
            physTwo = furColour[rand()%2];
            //cout<<"making physical attribute 3"<<endl;
            physThree = build[rand()%2];

            cout<<"\tsetting physical attributes"<<endl;
            currentAnimal->setPhysCharacteristics(physThree,physOne,physTwo);//build HL HC
             // cout<<"\tPrinting physical characteristic"<<endl;
             // cout<<"\t--------------------------------"<<endl;
             // currentAnimal->printPhys();
             // cout<<endl;



        }
        else if(animals[i] == "Parrot" || animals[i] == "Finch"){

            if(animals[i] == "Parrot"){currentAnimal = new Bird("Parrot","Parrot");}
            if(animals[i] == "Finch"){currentAnimal = new Bird("Finch","Finch");}

            physOne = furLength[rand()%3];
            physTwo = furLength[rand()%3];
            physThree = beakColour[rand()%6];
            //cout<<"\tsetting physical attributes"<<endl;
            currentAnimal->setPhysCharacteristics(physOne,physTwo,physThree);//birdWingSpan, string birdBeakLength, string birdBeakColour


             // cout<<"\tPrinting physical characteristic"<<endl;
             // cout<<"\t--------------------------------"<<endl;
             // currentAnimal->printPhys();
             // cout<<endl;

        }
        else if(animals[i] == "Salamander" || animals[i] == "Frog"){

            if(animals[i] == "Salamander"){currentAnimal = new Amphibian("Salamander","Salamander");}
            if(animals[i] == "Frog"){currentAnimal = new Amphibian("Frog","Frog");}

            physOne = bodyPattern[rand()%2];
            physTwo = furLength[rand()%3];
            physThree = build[rand()%3];
            //cout<<"\tsetting physical attributes"<<endl;
            currentAnimal->setPhysCharacteristics(physOne,physTwo,physThree);//string amphibianBodyPattern,string amphibianBodyLength, string amphibianBuild

            // cout<<"\tPrinting physical characteristic"<<endl;
            // cout<<"\t--------------------------------"<<endl;
            // currentAnimal->printPhys();
            // cout<<endl;
        }
        else if(animals[i] == "Snake" || animals[i] == "Lizard"){

            if(animals[i] == "Snake"){currentAnimal = new Reptile("Snake","Snake");}
            if(animals[i] == "Lizard"){currentAnimal = new Reptile("Lizard","Lizard");}

            physOne = furLength[rand()%3];
            physTwo = bodyPattern[rand()%2];
            physThree = scaleType[rand()%2];
            //cout<<"\tsetting physical attributes"<<endl;
            currentAnimal->setPhysCharacteristics(physOne,physTwo,physThree);//string reptileLength,string reptilePattern, string reptileScaleType

            // cout<<"\tPrinting physical characteristic"<<endl;
            // cout<<"\t--------------------------------"<<endl;
            // currentAnimal->printPhys();
            //cout<<endl;
        }
        else{//it's betta or goldfish

            if(animals[i] == "Betta"){currentAnimal = new Fish("Betta","Betta");}
            if(animals[i] == "Goldfish"){currentAnimal = new Fish("Goldfish","Goldfish");}

            physOne = bodyPattern[rand()%2];
            physTwo = furLength[rand()%1];
            physThree = furLength[rand()%3];
            //cout<<"\tsetting physical attributes"<<endl;
            currentAnimal->setPhysCharacteristics(physOne,physTwo,physThree);//string fishBodyPattern,string fishBodyLength, string fishFinnsSize

            // cout<<"\tPrinting physical characteristic"<<endl;
            // cout<<"\t--------------------------------"<<endl;
            // currentAnimal->printPhys();
            //cout<<endl;
        }
        //currentAnimal->setNonPhysicalAttributes(nonPhys1,nonPhys2,nonPhys3,nonPhys4,nonPhys5,nonPhys6,nonPhys7,nonPhys8,nonPhys9,nonPhys10,nonPhys11,nonPhys12);

        //cout<<"Seg fault here"<<endl;
        int rankIndex = rand()%rank.size();

        // cout<<"\tRandIndex is : "<<rank[rankIndex]<<endl;
        // cout<<"\tadding the animal and randindex to the linkled list"<<endl;
        ranks.addRank(rank[rankIndex],&currentAnimal);

        //cout<<"\tthere should be no "<<rank[rankIndex]<<" in the vector of rank"<<endl;



        if(rank.size()>0){
            rank.erase(rank.begin() + (rankIndex));

        }





    }




}
