#include "relation.h"

relation::relation(){

    this->tuplesArray = NULL;
    this->numTuples = 0;
}

relation::relation(myTuple *t,  int sz){

    this->tuplesArray = t;
    this->numTuples = sz;
}

void relation::setTuplesArray(myTuple *tuplesArray){

    this->tuplesArray = tuplesArray;
}

void relation::setNumTuples(int sizeOfArray){

    this->numTuples = sizeOfArray;
}

myTuple *relation::getTuplesArray(void){

    return tuplesArray;
}

int relation::getNumTuples(void){

    return numTuples;
}
