//Headers
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;


#ifndef Management_H
#define Management_H

struct Pet{ //struct holds the existance of our pet objects we create and pass into our queue of pets
    string petName;
	int petId;
};

class Management{
	public:    
        queue<Pet*> catQueue; //LIFO queues allow us to keep track of who came in first for each group
        queue<Pet*> dogQueue; 
        void addCat(); // protype declarations of our functions.
        void addDog();
        void adoptDog();
        void adoptCat();
        void adoptAny();
        void cleanMemCat();
        void cleanMemDog();
};
#endif