#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include "relation.h"
#include "mytuple.h"
#include<math.h>

//Keep all the necessary info of the segmentation phase
class segmentation
{
private:

    relation *R;
    relation *re_ordered_R;
    int *Histogram;
    int *Psum;
    int nDigits;
    int sizeOfRelation;

public:

    segmentation(int N, int szRelat, relation *r);

    void setRel(relation *r);
    void setReorderedRel(relation *re_r);
    void setHistogram(int *histPtr);
    void setPsum(int *PsumPtr);

    relation *getRel(void);
    relation *getReordRel(void);
    int *getHist(void);
    int *getPsum(void);
    int getNDigits(void);
    int createrrays(void);
    void printHistogram(void);
    void printPrefixSum(void);

};

#endif // SEGMENTATION_H
