//Notes:
//use nested loops & check inputs

#include <stdio.h>
#include <iostream>
using namespace std;
//Declarations:

int bico(){ 
    int degree, indexCoefficient;

//Gathers user input and checks for valid inputs.
	cout <<"Please input the degree of the binomial: "<< endl; 
    cin >> degree;
    if(degree >= 0){
        cout <<"Please input the index of the coefficient: "<< endl;
        cin >> indexCoefficient;
        cout<<endl;
        if(indexCoefficient < 0){ //index cannot be a negative value. No values are present within this space.
            cout << "error"<<endl<<"Please input a non-negative input"<<endl; 
            return 0; //exits program
        }else if(indexCoefficient>(degree-1)){ //index cannot be greater than the values generated. 
            cout << "error"<<endl<<"Index out of range"<<endl;
            return 0; //exits program
        }
    }else{ //negative degrees are possible but outside the scope of the program
        cout << "error"<<endl<<"Please input a non-negative input"<<endl; 
        return 0; //exits program
    }
    

    int coffiencientsList[degree][degree]; //A two dimesional array holds calculated values of coffiencients. The dimesions are defined by our degree inputted.
    
    
    //The array is populated by two for loops that generate the pascals triange of coefficents until the lines generated equal the user inputted coefficient

    for(int lineCounter = 0; lineCounter <= degree; lineCounter++){ //The degree inputed determines the number of lines we generate. Line 2 being X^2+2xy+y^2 for explample
        for(int coefCount = 0; coefCount <= lineCounter; coefCount++){ //To populate each row a number is created from the for loop till the length of the row is equal in size to the value of the column 
           if(coefCount == 0 || coefCount == lineCounter){ //Checks if coefficient values is the beginning or end of the line as the coefficients of the highest degree X and Y values are 0
                coffiencientsList[lineCounter][coefCount] = 1;
                //cout<<"1 "; Output for testing 
           }else{ // For values not
                int newCoefficent= coffiencientsList[lineCounter-1][coefCount]+coffiencientsList[lineCounter-1][coefCount-1];
                coffiencientsList[lineCounter][coefCount] = newCoefficent;
                //cout<<newCoefficent<<" "; //Output for testing
           }
        }
        //cout<<endl;//Output for testing
    }
    int output = coffiencientsList[degree][indexCoefficient]; //We access the array at the degree and index inputted by user to select the desired output now that it is populated 
    cout<<"The results is: "<<output<<endl; 
    return output; //Returns value of the coefficent
}



int main(){
    bico(); //Call bico funtion in main
    return 0; //main is declared with int so it must return a number
}