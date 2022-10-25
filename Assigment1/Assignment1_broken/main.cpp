//Headers
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include "management.h"

using namespace std;


void drawMainMenu(){
    cout<<"Welcome to the Animal Shelter"<<endl<<endl<<endl;

    cout<<"1: Add Cat "<<endl;
    cout<<"2: Add Dog "<<endl<<endl;
    cout<<"3: Adopt Oldest Animal "<<endl;
    cout<<"4: Adopt Cat"<<endl;
    cout<<"5: Adopt Dog"<<endl<<endl<<endl;


    cout<<"Use number keys to select an option";
    return;
}


void AnimalFarm::managmentSystem(){

    drawMainMenu();
    int userIn;
    cin>>userIn;
    switch (userIn){
                case 1:
                    addCat();
                    break;
 
                case 2:
                    addDog();
                    break;
             
                case 3:
                    adoptAny();
                    break;
 
                case 4:
                    adoptCat();
                    break;
     
                case 5:
                    adoptDog();
                    break;
                 
                default:
                    cout<<"INVALID INPUT";
                    break;
            }
}