#ifndef STORAGECENTER_H
#define STORAGECENTER_H
using namespace std;
#include "linkedlist.h"
#include "animal.h"
#include "client.h"
#include "match.h"

class StorageCenter{

    public:
        StorageCenter();
        ~StorageCenter();
        string getName();




    protected:
        string name;



};
#endif // STORAGECENTER_H
