//Headers
#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include<bits/stdc++.h>
using namespace std;

//Function def
char gradeConverter(int grade);
int palindromeCheck(string input);

//Class def
class Box{
    public:

    //Overloading Class constructor 
    int length, width, height; 
    Box(int l, int w, int h){
        this->length= l;
        this->width= w;
        this->height= h;
    }
    //Second constructor for a default case of all zero values
    Box(){
        this->length= 0;
        this->width= 0;
        this->height= 0;
    }
    //function for convient printing of objects
    void printBox(Box box){
        cout<<"Box Dimensions - "<<endl<<"Length: "<<box.length<<endl<<"Width: "<<box.width<<endl<<"Height: "<<box.height<<endl<<endl;
        return;
    }
    //function to add boxes
    Box addBox(Box box1,Box box2){
        Box addedBox;
        //checks to see which length and width is larger of the two boxes. Because we are stacking them the largest dimension will become the new LxW
        if(box1.length >= box2.length){
            addedBox.length = box1.length;
        }else{
            addedBox.length = box2.length;
        }

        if(box1.width >= box2.width){
            addedBox.width = box1.width;
        }else{
            addedBox.width = box2.width;
        }

        //Only the l and w are replaced. The "stacked" box will add the boxes height 
        addedBox.height = box1.height + box2.height;

        //calls print function to display new object and returns it values
        printBox(addedBox);
        return addedBox; 
    }

};

//functs
char gradeConverter(int grade){

    //Instead of if/else I used a switch to determine which range the percentage falls into
    switch(grade){
    case 90 ... 100 : // range of percents correlating to each letter grade
        cout<<"A grade of "<<grade<<" is a "<<'A'<<endl; //message for user
        return 'A'; //Char of letter grade is returned
        break;  //breaks out of switch shouldn't be reached but following convention.
    case 80 ... 89: 
        cout<<"A grade of "<<grade<<" is a "<<'B'<<endl;
        return 'B';
        break;
    case 70 ... 79: 
        cout<<"A grade of "<<grade<<" is a "<<'C'<<endl;
        return 'C';
        break;
    case 60 ... 69:
        cout<<"A grade of "<<grade<<" is a "<<'D'<<endl;
        return 'D';
        break;
    case 0 ... 59: 
        cout<<"A grade of "<<grade<<" is a "<<'F'<<endl;
        return 'F';
        break;

    default: //default case will cover invalid inputs from the user and display an error message
        cout<<"Please enter a valid grade percentage"<<endl<<endl;
        return 'N'; //returns an error value of N for the char
        break; 
    }

}

int palindromeCheck(){
    //variable declarations 
    string input; 
    string reversedString;

    //user input
    cout<<endl<<"Please enter a word for the Palindrome Checker:"<<endl;
    cin>>input; 
    //making a copy of the variable for manipulation
    string stringHolder = input;
    transform(stringHolder.begin(), stringHolder.end(), stringHolder.begin(), ::tolower); //Makes are test string all lowercase. To avoid case sensitivity for user input.

    //creates a stack that will be used to to reverse
    stack<char> reverser;
    
    //first loop pushes the chars to the stack till it has itterated through entire string
    for(int i = 0; i < stringHolder.size(); i++){
        reverser.push(stringHolder[i]);
    }
    //Now we can use FIFO rules of stack to pull the chars out in reverse order for the length of the string
    for(int i = 0; i < stringHolder.size(); i++){
        char top = reverser.top(); //assigns a char to represent the top of the stack
        reversedString.push_back(top); //pushes the top char into the reversedString string
        reverser.pop(); //pops that string off the stack so that we can itterate down the stack
    }

    //runs a check comparing the input in all lower versus the reversed value and returns the associated value and a message to user.
    if(stringHolder == reversedString){
        cout<<input<<" is a Palindrome."<<endl;
        return 1;
    }else{
        cout<<input<<" is not a Palindrome."<<endl;
        return 0;
    }
    


}

int main(){
    //Testing grade inputs. I belive this is the table specified in the lab manual
    gradeConverter(91);
    gradeConverter(81);
    gradeConverter(71);
    gradeConverter(61);
    gradeConverter(51);
    gradeConverter(-20);

    //Box test 1
    Box box1(20,15,7);
    Box box2(25,10,14);

    Box addedBox1;
    addedBox1.addBox(box1,box2);

    //Box test 2
    Box box3(6,3,1);
    Box box4(4,4,14);

    Box addedBox2;
    addedBox2.addBox(box3,box4);

    //Calls palindrome function
    palindromeCheck();

    //returns int for main funct convention
    return 0;
}