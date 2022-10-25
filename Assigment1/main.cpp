//Headers
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include "Management.h"

using namespace std;

void drawMainMenu();

int main(){
    //drawMainMenu(); //calls a function to print menu
    Management shelter; //creates an instance of Management
    int userIn = 0; 
    do{
    drawMainMenu(); //calls a function to print menu
    cin>>userIn; //takes a user input to be passed into out switch
    switch (userIn){
                case 1:
                    shelter.addCat(); // our switch gives us access to the functions declared in Management
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
                    
                case 6:
                    break;
                 
                default:
                    cout<<"INVALID INPUT";
                    break;
    }
    }while(userIn != 6);
    cout<<"exiting system"<<endl;
}

void drawMainMenu(){ //draws menu
    cout<<"Welcome to the Animal Shelter"<<endl<<endl<<endl;

    cout<<"1: Add Cat "<<endl;
    cout<<"2: Add Dog "<<endl<<endl;
    cout<<"3: Adopt Oldest Animal "<<endl;
    cout<<"4: Adopt Cat"<<endl;
    cout<<"5: Adopt Dog"<<endl<<endl<<endl;
    cout<<"6: EXIT"<<endl<<endl<<endl;


    cout<<"Use number keys to select an option"<<endl;
}