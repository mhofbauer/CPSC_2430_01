//Headers
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

unsigned int petIdCounter = 0;

#ifndef Management_H
#define Management_H

struct Pet{
    string petName;
	int petId;
};

class Management{
	public:    
        queue<Pet*> catQueue;
        queue<Pet*> dogQueue;
        void addCat();
        void addDog();
        void adoptDog();
        void adoptCat();
        void adoptAny();
        void cleanMemCat();
        void cleanMemDog();
};
#endif