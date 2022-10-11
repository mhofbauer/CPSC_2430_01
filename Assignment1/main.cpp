//Headers
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include "Management.h"

using namespace std;

void drawMainMenu();

int main(){
    cout << "hello world\n";
    drawMainMenu();
    Management shelter;
    int userIn = 0;
    cin>>userIn;
    switch (userIn){
                case 1:
                    shelter.addCat();
                    break;
 
                case 2:
                    shelter.addDog();
                    break;
             
                case 3:
                    shelter.adoptAny();
                    break;
 
                case 4:
                    shelter.adoptCat();
                    break;
     
                case 5:
                    shelter.adoptDog();
                    break;
                 
                default:
                    cout<<"INVALID INPUT";
                    break;
    }
}

void drawMainMenu(){
    cout<<"Welcome to the Animal Shelter"<<endl<<endl<<endl;

    cout<<"1: Add Cat "<<endl;
    cout<<"2: Add Dog "<<endl<<endl;
    cout<<"3: Adopt Oldest Animal "<<endl;
    cout<<"4: Adopt Cat"<<endl;
    cout<<"5: Adopt Dog"<<endl<<endl<<endl;


    cout<<"Use number keys to select an option";
}