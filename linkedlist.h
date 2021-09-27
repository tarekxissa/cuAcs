#ifndef LinkedList_H
#define LinkedList_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include "animal.h"

/**
 * LinkedList implementation as a template that takes any object type
 *Author: Yvan Niyonzima
*/

using namespace std;

template <class T>
class LinkedList{

    template<class D>
    class Node{
        friend class LinkedList<T>;

        private:
            int index;
            unsigned int rank : 4;               //animal rank
            D* data;                 //index of the element in this LinkedList
            Node *next;             //points to the next element of the LinkedList
            Node *prev;             //points to the previous element of the LinkedList            D *data;                 //the data of the lis
            /*Node* operator=(Node* newNode){
                cout<<"deleting previous data"<<endl;
                delete this->data;              //free data previously there
                cout<<"Printing deleted data(should be null)"<<endl;
                this->data->print();
                cout<<endl;
                this->data = newNode->data;     //assig new data
                cout<<"printing new data(should be reptile with name Lola"<<endl;
                cout<<endl;
                this->data->print();
                delete newNode;
                return this;               //delete the node that had the data
            }*/
    };

    public:
        LinkedList();                      //default constructor
        ~LinkedList();                    //destructor
    /*protected:*/
        Node<T> *head;


        int numElements;            //number of elements in the LinkedList

        void add(T**);                //appends the specified element to the end of the LinkedList

        void addRank(int,T**);          //adds the specified element at the specified position

        void addClient(T**);

        void addAnimal(T**);

        void clear();               //removes all the elements from this LinkedList


        T* get(int=0);               //returns the element at the specified index in this LinkedList

        int getRank(string);      //takes an and returns it's rank based on its species

        void set(T**,int);          //sets the element pointed to by T at index i

        void setRank(int,string);   //sets the rank of animal when edited

        bool isEmpty();             //returns true if this LinkedList has no element

        int size();                  //returns the number of elements in this LinkedList

        void boundsCheck(int);



        void shiftRight(int);       //shifts all the elements one index to the right

        void shiftLeft(int);        //shift all the elements one index to the left

        void shiftRight(Node<T>*);
        void shiftLeft(Node<T>*);

        //overloaded operator that takes a linked list a copies it to another
        LinkedList<T>& operator=(vector<T*>);



        string name;

        void print();
        void printRanksTest();
        void printClient();

        T* getByRank(int);

        T* getByType(string);


        bool dealocate;





};



/**
 * DEFAULT CONSTRUCTOR
 *  creates a new LinkedList with zero elements
*/

template<class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    this->numElements = 0;

    dealocate = false;
}


/*linked list destructore
* deallocates the dynamically allocated objects of clients and animals*/

template<class T>
LinkedList<T>::~LinkedList(){
    //cout<<"Linked list called "<<this->name<<endl;

    if(dealocate){
        Node<T>* curr = head;
        Node<T>* prev = NULL;

        while(curr != NULL){

        //cout<<"deleting this current animal"<<endl;
        //cout<<"============================"<<endl;

        //curr->data->print();

            prev = curr->next;
            delete curr->data;
            delete curr;
            curr = prev;
        }
    }

}


/* For clearing the list.*/
template<class T>
void LinkedList<T>::clear(){
  Node<T>* curr = head;
  Node<T>* prev = NULL;

  while(curr != NULL){

      prev = curr->next;
      delete curr->data;
      //delete curr;
      curr = prev;
  }
}


/*returns the amout of elements in this current linked list*/
template<class T>
int LinkedList<T>::size(){
    return numElements;
}



/*array operation that checks for an index out of bounds error*/
template<class T>
void LinkedList<T>::boundsCheck(int index){

    if(index < 0 || index > numElements-1){
        cerr<<"Invalid Index"<<endl;
        exit(1);
    }

}

/*function that shifts all the elements on index to the right for the index in the parameter*/

template<class T>

void LinkedList<T>::shiftRight(int startingIndex){

    Node<T>* currNode = head;
    while(currNode->next != NULL){
        if(currNode->index == startingIndex){
            break;
        }
        currNode = currNode->next;
    }
    shiftRight(currNode);   //using the shiftRight that takes a node as a parameter


}

/*functions that shifts all the elements one index to the left starting form index in parameter*/
template<class T>
void LinkedList<T>::shiftLeft(int startingIndex){

    Node<T*> currNode = head;

    while(currNode->next!= NULL){
        if (currNode->index == startingIndex){
            break;
        }
        currNode = currNode->next;
    }
    shiftLeft(currNode);        //using the shiftLeft that takes in a node as a Parameter
}


/*shift right function that takes a Node as a parameter*/
template<class T>
void LinkedList<T>::shiftRight(Node<T>* node){

    Node<T>* currNode = node;

    while(currNode != NULL){
        currNode->index++;

        currNode = currNode->next;
    }

}

/*shift left function that takes a Node as a parameter*/
template<class T>
void LinkedList<T>::shiftLeft(Node<T>* node){

    Node<T>* curr = node;

    while(curr != NULL){
        curr->index--;
        curr = curr->next;
    }

}

/*adds the elements pointed to by newData at the end of this linkedlist*/

template<class T>
void LinkedList<T>::add(T** newData){

    //cout<<"Beginning to add animal"<<endl;


    Node<T>* newNode = new Node<T>;
    newNode->data = *newData;
    newNode->index = numElements++;

    if(head == NULL){
        //cout<<"inside add if statement"<<endl;
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;


    }else{
        //cout<<"inside add else statement"<<endl;
        Node<T>* currNode = head;
        while (currNode->next != NULL){
            currNode = currNode->next;
        }
        newNode->prev = currNode;
        currNode->next = newNode;
        newNode->next = NULL;


    }
     //cout<<"Done to add animal"<<endl;

}

//mostly going to be used for ranking
template<class T>
void LinkedList<T>::addRank(int rank,T** newData){



    Node<T>* newNode = new Node<T>;
    newNode->data = *newData;
    newNode->index = numElements++;

    newNode->rank = rank;   //set the animals rank


    if(head == NULL){
        //cout<<"inside add if statement"<<endl;
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;


    }else{
        //cout<<"inside add else statement"<<endl;
        Node<T>* currNode = head;
        while (currNode->next != NULL){
            currNode = currNode->next;
        }
        newNode->prev = currNode;
        currNode->next = newNode;
        newNode->next = NULL;


    }


}


template<class T>
void LinkedList<T>::setRank(int rank,string speciesType){

    if(rank < 1 || rank > 10){
        //cerr<<"Rank SET TO NULL"<<endl;
    }

    Node<T>* currNode = head;

    while(currNode != NULL){
        if(currNode->data->getSpecies() == speciesType){
            currNode->rank = rank;
            break;
        }
        currNode = currNode->next;
    }
}

template<class T>
void LinkedList<T>::set(T** newData, int atIndex){

    boundsCheck(atIndex);

    Node<T>* currNode = head;

    while(currNode != NULL){
        if(currNode->index == atIndex){
            break;
        }


        currNode = currNode->next;
    }
    delete currNode->data;


    currNode->data = *newData;

}


/*returns the elements at the index specifeid by index*/
template<class T>
T* LinkedList<T>::get(int index){

    boundsCheck(index);
    T* data = NULL;
    Node<T>* curr = head;

    while(curr != NULL){
        if(curr->index == index){
            data = curr->data;
            break;
        }
        curr = curr->next;
    }
    return data;

}

//gets by the ranks

template<class T>
T* LinkedList<T>::getByRank(int animalRank){

    //boundsCheck(index);
    T* data = NULL;
    Node<T>* curr = head;

    while(curr != NULL){
        if(curr->rank == animalRank){
            data = curr->data;
            break;
        }
        curr = curr->next;
    }
    return data;
}


template<class T>
T* LinkedList<T>::getByType(string animalType){

    Node<T>* currNode = head;

    Animal *toReturn;

    while(currNode != NULL){
//        cout<<"in while loop"<<endl;
//        cout<<"Aniaml in parameter = "<<animalType<< " and animal in ranks = "<<currNode->data->getSpecies()<<endl;

        if(animalType == currNode->data->getSpecies()){
//            cout<<"in if statement"<<endl;
            toReturn = currNode->data;
            break;

        }

        currNode = currNode->next;
    }

    return toReturn;
}



/*takes an animal and returns it's rank based on the animals species*/

template<class T>
int LinkedList<T>::getRank(string animalType){

    Node<T>* currNode = head;
    int animalRank=0;
    while(currNode != NULL){
//        cout<<"in while loop"<<endl;
//        cout<<"Aniaml in parameter = "<<animalType<< " and animal in ranks = "<<currNode->data->getSpecies()<<endl;

        if(animalType == currNode->data->getSpecies()){
           // cout<<"in if statement"<<endl;
            animalRank = currNode->rank;
            break;
        }

        currNode = currNode->next;
    }

    return animalRank;
}
template<class T>
LinkedList<T>& LinkedList<T>::operator=(vector<T*> copyFrom){

    for(int i=0;i<copyFrom.size();i++){

        this->add(&copyFrom[i]);
    }

    return *this;

}

//////////////////////////////////////////////////////////FOR TESTING//////////////////////////////////////////////////////////////
/*for testing purposes*/
/*prnts out the data in this list*/
template<class T>
void LinkedList<T>::print(){


    if(head == NULL){
        cerr<<"This LinkedList is empty"<<endl;
        //exit(1);
    }

    Node<T>* curr = head;

    while(curr != NULL){
        //cout<<"Data at index "<<curr->index<<endl;
        cout<<"Rank = "<<curr->rank<<endl;
        curr->data->print();

        curr = curr->next;
    }
}

template<class T>
void LinkedList<T>::printClient(){
    if(head == NULL){
        cerr<<"This LinkedList is empty"<<endl;
        //exit(1);
    }

    Node<T>* curr = head;

    while(curr != NULL){

        curr->data->print();

        curr = curr->next;
    }
}



template<class T>
void LinkedList<T>::printRanksTest(){

    Node<T>* currNode = head;

    while(currNode != NULL){

        cout<<"Rank: "<<currNode->index+1<<"\t Data: "<<currNode->data<<endl;
        currNode = currNode->next;
    }
}


template<class T>
void LinkedList<T>::addAnimal(T** newData){

    //cout<<"Beginning to add animal"<<endl;


    Node<T>* newNode = new Node<T>;
    newNode->data = *newData;
    newNode->index = numElements++;

    if(head == NULL){
        //cout<<"inside add if statement"<<endl;
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;


    }else{
        //cout<<"inside add else statement"<<endl;
        Node<T>* currNode = head;
        while (currNode->next != NULL){
            currNode = currNode->next;
        }
        newNode->prev = currNode;
        currNode->next = newNode;
        newNode->next = NULL;


    }
     //cout<<"Done to add animal"<<endl;

}

//called to add a client
template<class T>
void LinkedList<T>::addClient(T** newData){

    //cout<<"Beginning to add client"<<endl;


    Node<T>* newNode = new Node<T>;
    newNode->data = *newData;
    newNode->index = numElements++;

    if(head == NULL){
        //cout<<"inside add if statement"<<endl;
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;


    }else{
        //cout<<"inside add else statement"<<endl;
        Node<T>* currNode = head;
        while (currNode->next != NULL){
            currNode = currNode->next;
        }
        newNode->prev = currNode;
        currNode->next = newNode;
        newNode->next = NULL;


    }
     //cout<<"Done to add client"<<endl;

}


#endif
