#include "Management.h"
#include <iostream>
using namespace std;

    void Management::addCat(){
        if(catQueue.empty()==true){
            cout<<"Error: No cats are currently available"<<endl;
            return;
        }
        Pet * newCat = new Pet;
        cout<<"Please enter your cat's name: "<<endl;
        cin>>newCat->petName;
        newCat->petId = petIdCounter++;
        catQueue.push(newCat);
    }

    void Management::addDog(){
        if(dogQueue.empty()==true){
            cout<<"Error: No dogs are currently available"<<endl;
            return;
        }
            Pet * newDog = new Pet;
            cout<<"Please enter your dog's name: "<<endl;
            cin>>newDog->petName;
            newDog->petId = petIdCounter++;
            dogQueue.push(newDog);
            return;
    }
    void Management::adoptCat(){
        cout<<"Congratualtions you adopted "<<catQueue.front()->petName<<"!"<<endl;
        catQueue.pop();
        return;
    }

    void Management::adoptDog(){
        cout<<"Congratualtions you adopted "<<dogQueue.front()->petName<<"!"<<endl;
        dogQueue.pop();
        return;
    }

    void Management::adoptAny(){
        if((catQueue.empty()==false)&&(dogQueue.empty()==false)){
            if(catQueue.front()->petId >= dogQueue.front()->petId){
                adoptCat();
                return;
            }else{
                adoptDog();
                return;
            }
        }else if((catQueue.empty()==false)&&(dogQueue.empty()==true)){
            cout<<"There are no dogs avaliable at this time.";
            adoptCat();
            return;
        }else if((catQueue.empty()==true)&&(dogQueue.empty()==false)){
            cout<<"There are no cats avaliable at this time.";
            adoptDog();
            return;
        }else{
            cout<<"Error: No pets are currently available"<<endl;
            return;
        }

    }

    void Management::cleanMemCat(){
        while(!catQueue.empty()){
            delete catQueue.front();
            catQueue.pop();
        }
    }

    void Management::cleanMemDog(){
        while(!dogQueue.empty()){
            delete dogQueue.front();
            dogQueue.pop();
        }
    }