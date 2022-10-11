//Headers
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

unsigned int petIdCounter;

struct Pet{
    string petName;
	int petId;
};

class AnimalFarm{
	public:    
        queue<Pet*> catQueue;
        queue<Pet*> dogQueue;
        void addCat();
        void helloWorld();
};