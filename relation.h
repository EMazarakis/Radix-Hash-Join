#ifndef RELATION_H
#define RELATION_H

#include "mytuple.h"

class relation
{
private:

    myTuple *tuplesArray;     //One dimensional array of tuples
    int numTuples;     //Actually this is the size of the array

public:

    relation();
    relation(myTuple *t,  int sz);
    void setTuplesArray(myTuple *tuplesArray);
    void setNumTuples(int sizeOfArray);
    myTuple *getTuplesArray(void);
    int getNumTuples(void);
};

#endif // RELATION_H
