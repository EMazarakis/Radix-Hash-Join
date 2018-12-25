#include "radix_hash_join.h"

Radix_Hash_Join::Radix_Hash_Join(int N){

    this->nDigits = N;
    //this->relR = NULL;
    //this->relS = NULL;
}

/*
Radix_Hash_Join::Radix_Hash_Join(int N, relation *R, relation *S){

    this->nDigits = N;
    this->relR = R;
    this->relS = S;
}
*/

void Radix_Hash_Join::RHJ_segmentationPhase(segmentation *relSegm){


    int SIZE = relSegm->getRel()->getNumTuples();

    //1.Fixing the histogram of the relation
    for(int i=0; i<SIZE; i++){

        relSegm->getHist()[ relSegm->getRel()->getTuplesArray()[i].getKey() ]++;
    }


//Hash Table ---- Re-Ordering the relation

    //2.Fixing the prefix sum of the histogram
    int numberOfBuckets = (int)pow(2, relSegm->getNDigits());

    relSegm->getPsum()[0] = 0;  //At the re-ordered relation, the contents of bucket 0 starts at zero index

    for(int i=1; i<numberOfBuckets; i++){

        relSegm->getPsum()[i] = relSegm->getPsum()[i-1] + relSegm->getHist()[i-1];
    }


    //3.Fixing the re-ordered relation
    int counter = 0;
    int indexReorderRel = 0;
    int32_t idBucket;

    for(int i=0; i<numberOfBuckets; i++){   //Searching all the elements of every bucket

        for(int j=0; j<SIZE; j++){          //For every tuple of the relation

            idBucket = ( relSegm->getRel()->getTuplesArray() )[j].getKey();
            if( idBucket == i ){    //which bucket elements we are searching for

                ( relSegm->getReordRel()->getTuplesArray() )[indexReorderRel] = ( relSegm->getRel()->getTuplesArray())[j];
                counter++;
                indexReorderRel++;
            }

            //No need to search more the relation. We find all the elements of a certain bucket
            if( counter == ( relSegm->getHist() )[i] ){ break; }
        }

        counter = 0;    //Next bucket
    }
}
