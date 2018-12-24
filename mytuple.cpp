#include "mytuple.h"

myTuple::myTuple()
{
//An empty constructor
}

myTuple::myTuple(int k, int p){

    key = k;
    payload = p;
}


void myTuple::setKey(int myKey){

    key = myKey;
}

void myTuple::setPayload(int myPayload){

    payload = myPayload;
}

int myTuple::getKey(void){

    return key;
}

int myTuple::getPayload(void){

    return payload;
}


void myTuple::printData(){

    printf("(Key, Payload)=(%d, %d)\n", key, payload);
}
