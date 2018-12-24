#ifndef MYTUPLE_H
#define MYTUPLE_H


#include <iostream>
using namespace std;

class myTuple
{
private:

    int key;        //It means the id of the bucket
    int payload;    //It means the actual value

public:

    myTuple();                        //constructor
    myTuple(int k, int p);    //constructor
    void setKey(int myKey);
    void setPayload(int myPayload);
    int getKey(void);
    int getPayload(void);
    void printData();
};

#endif // MYTUPLE_H
