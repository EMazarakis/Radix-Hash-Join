#include<stdio.h>
#include<iostream>

#include "mytuple.h"
#include "relation.h"
#include "segmentation.h"
#include "radix_hash_join.h"

using namespace std;


//This main is for testing purpose only,.
int main(void){

    int numberOfDigits = 2;
    int numCells = 10;

    myTuple *TuplesPtrA = new myTuple[numCells]; //todo try - catch

    relation *relPtrA = new relation(TuplesPtrA, numCells);

//Initialization
    int flag = 90;
    for(int i=0; i<numCells; i++){

        TuplesPtrA[i].setPayload(flag - (i*10));
    }

    TuplesPtrA[0].setKey(2);
    TuplesPtrA[1].setKey(0);
    TuplesPtrA[2].setKey(1);
    TuplesPtrA[3].setKey(1);
    TuplesPtrA[4].setKey(2);
    TuplesPtrA[5].setKey(2);
    TuplesPtrA[6].setKey(3);
    TuplesPtrA[7].setKey(3);
    TuplesPtrA[8].setKey(0);
    TuplesPtrA[9].setKey(3);
//------------------------------------------------------

    segmentation *segmPtrA = new segmentation(numberOfDigits, numCells, relPtrA);

    segmPtrA->createrrays();

    Radix_Hash_Join *rhjPtr = new Radix_Hash_Join(numberOfDigits);

    rhjPtr->RHJ_segmentationPhase(segmPtrA);


//Printings
    segmPtrA->printHistogram();
    segmPtrA->printPrefixSum();

    return 1;
}
