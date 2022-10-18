#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

//function defs

int sumDigits(int userNum);
double root5(int n,double y);
int doubleInt(int input);
int halveInt(int input);
int egyptDivision(int divisor, int dividend);
double ramanujan(int depthCounter,double recursiveOutput);


int main()
{
    //task 1
    /*
    
    For T(n)=11n^3+logn+12sqrt(n) the big O is n^3. For this we choose C = 12 and n =1.035. 
    From there we can find 12(1.035)^3 =13.304 and 12sqrt(1.035)=12.21. Showing that moving
    forward n^3 will always grow faster. Even if 12sqrt(n) grows faster than 11n^3 up to n=1.035.
    And thus proving if there exist constant C > 0 and N ≥ 0 such that for all n ≥ N, T(n) ≤ C*n^3,
    T(n) is O(n^3).

    */

    //task2
    cout<<sumDigits(123)<<endl; //expected 6
    cout<<sumDigits(111)<<endl; //expected 3
    //task3
    cout<<"Root5 of 3125: "<<root5(3125,1)<<endl; //expected 5
    //task 4
    cout<<"Using Eyptian division 1960/56 = "<<egyptDivision(56,1960)<<endl; //expected 35
    //task5
    cout<<"At a depth of 2, Ramanujan returns "<<ramanujan(2,0)<<endl;
    cout<<"At a depth of 10, Ramanujan returns "<<ramanujan(10,0)<<endl;
    cout<<"At a depth of 100, Ramanujan returns "<<ramanujan(100,0)<<endl;
    //ramanujan at infinity answer on line 111
    return 0;
}

//task 2
int sumDigits(int userNum){
    if(userNum<1){ //the base case of or function. Ints can't be less than 1
        return 0;
    }else{
        int output = userNum%10 + sumDigits(userNum/10);  //If the number is larger than one then the remainder of num/10 is added to the recurive function of num/10
                                                          //This brings the number down one place and begins the loop again till the input is only the base case.
        return output; //outputs answer
    }
}

//task 3
double root5(int n,double y){
    if(abs(pow(y,5)-n)<0.00001){ //if our is 0 to a precision greater than 0.00001 we can conclude our guess is accurate
        return y; //returns accurate guess for root
    }else{
        double newGuess = ((4*y)+(n/pow(y,4)))/5; //extrapolated formula for finding the fifth root
        root5(n,newGuess); //repeats the guess process and calls the recursive funciotn
        //return y; //error case to avoid non-void function //note unsure what to do here as if I add this it breaks the function but otherwise I get a wreturn type error
    }
}

//task 4
int doubleInt(int input){ //component of egyptDiv
    input = input +input; //adds the element to itself to double it 
    return input; //returns updated element
}

int halveInt(int input){
    if(input<2){
        return 0; //if the element is less than 2 then the answer will be zero because there is no decimals for int
    }else{
        int output = 1+halveInt(input-2); //takes 1 plus the input -2. This acts as a counter for how many times 2 fits into the base input.
        return output; //returns the number of times 2 fits into the number ie the results of input/2
    }
}


int egyptDivision(int divisor, int dividend){
    int a,b,c,d; //creates four columns
    a = 1; b = divisor; c = dividend; d=0; //populates four colums with base cases as per documentation.
    while(b<c){ //while column b is less than column c the a and b column values are doubled
        //cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<" d: "<<d<<endl; //option to produce table from documentation
        a = doubleInt(a);
        b = doubleInt(b);
    }
    
    while(c>1){ //while c is above 1 there is a remainder and division needs to countinue
        if(b<=c){ //if column b is smaller or equal than c a is added to d and b is subtracted from c
            d=d+a;
            c=c-b;
        }
        //in each iteration the a and b columns are always halved 
        a = halveInt(a); 
        b = halveInt(b);
    }
    return d; //once c is 0 column d will hold the answer and can be returned to the user.
}


//task 5
double ramanujan(int depthCounter,double recursiveOutput){ //note will not take recursiveOutput = 0 for default. Annoying!
    int startingPoint = 6; //ramanujan starts at 6 always
    double nestedResult = (sqrt(startingPoint+depthCounter+recursiveOutput)*(depthCounter+1)); //formula for each section of nested ramanujan expression. Recursive output is put inside as the function is nested deeper each iteration

    if (depthCounter == 0){ //if our depth couter is at zero then we have completed all the nessacry nested expression. Our function evaluates from the outside in, so when zero is reached the intended starting point in traditional order of operations
        return nestedResult; //outputs final result
    }else{
        ramanujan(depthCounter-1,nestedResult);//if the desired depth is not reached the nestedOutput is put back into the function to be repeated.
    }
}

//Task 5 final part
//As the ramanujan function is carried out to infinity it will approach the value of 4