#ifndef RADIX_HASH_JOIN_H
#define RADIX_HASH_JOIN_H


#include "relation.h"
#include "segmentation.h"
#include<math.h>

class Radix_Hash_Join
{
private:

    int nDigits;        //number Of less important Digits
    //relation *relR;     //relation R
    //relation *relS;     //relation S

public:

    //Radix_Hash_Join(int N, relation *R, relation *S);
    Radix_Hash_Join(int N);

    //First
    void RHJ_segmentationPhase(segmentation *relSegm);

    //Second
    void RHJ_buildingIndexingPhase();

    //Third
    void RHJ_comparingPhase();

    void H1_function();
    void H2_function();
};

#endif // RADIX_HASH_JOIN_H
