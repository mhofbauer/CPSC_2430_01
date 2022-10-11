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


        void addCat(){
            Pet * newCat = new Pet;
            cout<<"Please enter your Cat's name: "<<endl;
            cin>>newCat->petName;
            newCat->petId = petIdCounter++;
            catQueue.push(newCat);
            return;
        }

        void addDog(){
            Pet * newDog = new Pet;
            cout<<"Please enter your Dog's name: "<<endl;
            cin>>newDog->petName;
            newDog->petId = petIdCounter++;
            dogQueue.push(newDog);
            return;
        }
        void adoptCat(){
            catQueue.pop();
            return;
        }

        void adoptDog(){
            dogQueue.pop();
            return;
        }

        void adoptAny(){
            Pet * newCat = new Pet;
            Pet * newDog = new Pet;
            
            newCat = catQueue.front();
            newDog = dogQueue.front();

            if(newCat->petId >= newDog->petId){
                adoptCat();
            }else{
                adoptCat();
            }
            return;
        }

        void cleanMemCat(){
            while( !catQueue.empty() ) {
            delete catQueue.front();
            catQueue.pop();
            }
        }

        void cleanMemDog(){
            while( !dogQueue.empty() ) {
            delete dogQueue.front();
            dogQueue.pop();
            }
        }
};


