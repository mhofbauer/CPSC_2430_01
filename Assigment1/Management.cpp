#include "Management.h"
#include <iostream>
using namespace std;

    unsigned int petIdCounter = 0; //global variable for counting the pets in the system

    void Management::addCat(){ //takes in user input and creates pet object
        Pet * newCat = new Pet; //creates pet object pointer
        cout<<"Please enter your cat's name: "<<endl; 
        cin>>newCat->petName; //message to user and assigns user in to the oject pointer's name
        newCat->petId = petIdCounter+1; // assigns and increaes the global variable for idCounter to keep track of overall arrival time
        petIdCounter++;
        catQueue.push(newCat);
    }

    void Management::addDog(){ //uses same methods as addCat()
            Pet * newDog = new Pet;
            cout<< "Please enter your dog's name: "<<endl;
            cin>>newDog->petName;
                newDog->petId = petIdCounter+ 1;
                petIdCounter++;
            dogQueue.push(newDog);
            return;
    }
    void Management::adoptCat(){
        if(catQueue.empty()==true){ //checks if there is a cat available
            cout<<"Error: No cats are currently available"<<endl;
            return;
        }
        cout<<"Congratualtions you adopted a cat named "<<catQueue.front()->petName<<"!"<<endl;
        catQueue.pop(); //removes that pet object from the queue. 
        return;
    }

    void Management::adoptDog(){
        if(dogQueue.empty()==true){ //checks if a dog is available in the queue
            cout<<"Error: No dogs are currently available"<<endl;
            return;
        }
        cout<<"Congratualtions you adopted a dog named "<<dogQueue.front()->petName<<"!"<<endl;
        dogQueue.pop(); //Congratualts the user and removes the pet object from the queue
        return;
    }

    void Management::adoptAny(){ 
        if((catQueue.empty()==false)&&(dogQueue.empty()==false)){ //checks if both queues are full
            if(catQueue.front()->petId < dogQueue.front()->petId){//if both queues are populated takes the pet that has the highest id(the first pet in the system)
                cout<<"id num "<<catQueue.front()->petId<<endl;
                adoptCat();
                return;
            }else{
                cout<<"id num "<<dogQueue.front()->petId<<endl;
                adoptDog();
                return;
            }
        }else if((catQueue.empty()==false)&&(dogQueue.empty()==true)){ //if there is cats in a queue but not dogs informs the user and jumps and links to adopt cat
            cout<<"There are no dogs avaliable to adopt at this time. You will be adopting a cat"<<endl;
            adoptCat();
            return;
        }else if((catQueue.empty()==true)&&(dogQueue.empty()==false)){ //if there is dogs in a queue but not cats informs the user and jumps and links to adopt dog
            cout<<"There are no cats avaliable to adopt at this time. You will be adopting a dog"<<endl;
            adoptDog();
            return;
        }else{
            cout<<"Error: No pets are currently available"<<endl; //if none of the cases are met then there are no pets in the shelter
            return;
        }

    }
    
    //clean memory functions that empty queues and destroys all objects

    void Management::cleanMemCat(){ 
        while(!catQueue.empty()){ //while queue is populated it deletes the object and pops it off the queue
            delete catQueue.front();
            catQueue.pop();
        }
    }

    void Management::cleanMemDog(){ //same methods as cleanMemCat
        while(!dogQueue.empty()){
            delete dogQueue.front();
            dogQueue.pop();
        }
    }