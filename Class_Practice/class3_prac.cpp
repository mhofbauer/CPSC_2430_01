//#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Student{
	public:    
        string name;
	    int age;
};

void display(stud){
    cout<<stud.name<<endl;
    cout<<stud.age<<endl;
}

int main(){
    // cout<<"Hello World"<<endl;
    /*
    string s = "Hi, do you want to play Dota?";
    cout << s<< endl;
    return 0;
    */
   Student stud0("Elijah", 24);

   Student stud1("John", 30);
   display(stud0);
   display(stud1);

}