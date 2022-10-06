#include <iostream>
#include <string>

#include <vector>

using namespace std;

 int main(){
     //creating and populating vectors
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5); 

    //size of vector
    cout << v.size() << endl << endl;

    //Printing vectors
    for(int i = 0; i<v.size(); i++){
        cout<< v[i] << endl;
    }
    cout <<endl;
    
    //inserting values into vectors
    v.insert(v.begin()+3, 10); //works but not preferred

    for(int i = 0; i<v.size(); i++){ //checking vector
        cout<< v[i] << endl;
    }



    return 0;
 }