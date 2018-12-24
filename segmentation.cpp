#include "segmentation.h"

segmentation::segmentation(int N, int szRelat, relation *r)
{
    this->nDigits = N;
    this->sizeOfRelation = szRelat;
    this->R = r;
    this->Histogram = NULL;
    this->Psum = NULL;
    this->re_ordered_R = NULL;
}


void segmentation::setRel(relation *r){
    this->R = r;
}

void segmentation::setReorderedRel(relation *re_r){
    this->re_ordered_R = re_r;
}

void segmentation::setHistogram(int *histPtr){
    this->Histogram = histPtr;
}

void segmentation::setPsum(int *PsumPtr){
    this->Psum = PsumPtr;
}


relation *segmentation::getRel(void){
    return R;
}

relation *segmentation::getReordRel(void){
    return re_ordered_R;
}

int *segmentation::getHist(void){
    return Histogram;
}

int *segmentation::getPsum(void){
    return Psum;
}

int segmentation::getNDigits(void){
    return nDigits;
}

void segmentation::printHistogram(void){

    int counter = (int)pow(2, nDigits);

    for(int i=0; i<counter; i++){

        printf("(Bucket,#Elements)=(%d,%d) \n",i, Histogram[i]);
    }
}

void segmentation::printPrefixSum(void){

    int counter = (int)pow(2, nDigits);

    for(int i=0; i<counter; i++){

         printf("(Bucket,startIndex)=(%d,%d) \n",i, Psum[i]);
    }
}


int segmentation::createrrays(void){

    int sizeOfArrays = (int)pow(2.0, (double)this->nDigits);

    this->Histogram = new int[sizeOfArrays];      //Try-catch std::nothrow

    this->Psum = new int[sizeOfArrays];           //Try-catch std::nothrow

    //Initialization of arrays
    for(int i=0; i<sizeOfArrays; i++){

        this->Histogram[i] = 0;
        this->Psum[i] = 0;
    }


    myTuple *TuplesPtr = new myTuple[this->sizeOfRelation];             //todo try - catch

    this->re_ordered_R = new relation(TuplesPtr, this->sizeOfRelation);  //todo try - catch

    cout<< "All the arrays have been created." << endl;

    return EXIT_SUCCESS;
}

