#include <stdio.h>
#include <iostream>
using namespace std;


int main(){
    for(int i = 0; i< 11; ++i)
    {
        cout << "* \n";
    }
	
	cout << "\n";
	
	int n = 0;
	
	for(int i = 0; i< 11; ++i)
    {
        for(int j = 0; j < n; ++j) 
		{
			cout << "*";
			 n++;
		}
		cout << "\n";
    }
	
	
	int k,l;
	
	for(k = 5 ; k>0; k--){
		for(l = k; l <= 5; l++){
			cout << l << " ";
		}
		cout <<"\n";
	}
	
    return 0;
}