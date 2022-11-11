/* 
** Min-Heap construction and basic operations 
** Lab 4, CPSC 2430, Xin Zhao
*/
// define the max size for the heap array 
#include <iostream>
#include <vector>
using namespace std;

const int HEAP_MAX_SIZE = 1000;
class MinHeap {
private:
    //int heapArr[HEAP_MAX_SIZE];
    vector<int> heapVec;
    
    int size;

    int left(int i){ //function that calculates the left child 
        return(2*i+1);
    }
    int right(int i){ //function that calculates the right child 
        return(2*i+2);
    }
    int parent(int i){ //function that calculates the parent
        return(i-1)/2;
    }
    void swapHeap(int x, int y) {       //calls vector swapping function. Not necessary but you don't have to index the vector
        // add your code here
        swap(heapVec[x],heapVec[y]);
        return;
    }
    void percolateUp(int index) {
         // add your code here
        int indexParent = parent(index); //calls the parent function
        if((index != 0)&&(heapVec[index]< heapVec[indexParent])){ //checks if the index is 0 or if the values are not in the right order to meet the heap property
            swapHeap(index,indexParent); //if it's not 
            percolateUp(indexParent); //checks the parent of the node recursively working up the tree
         }
        return; //if this is hit than function 
    }
    void percolateDown(int index) {
         // add your code here
         //grabbing some values and putting them into variables
         int rightChild = right(index);
         int leftChild = left(index);
         int minVal = index;

         if((heapVec[rightChild]< heapVec[minVal])&&(rightChild < heapVec.size())){ //checks if the right child is smaller than the root values and if the heap properties are met
            minVal = rightChild;
         }
        if((heapVec[leftChild]< heapVec[minVal])&&(leftChild < heapVec.size())){ //checks if the left child is smaller than the root values and if the heap properties are met
            minVal = leftChild;
         }       
        if(minVal != index){ // breaks out of function if the minVal is the current val 
            swapHeap(index,minVal); //otherwise the two values are swapped and the function is called recursively to countinue down the tree.
            percolateDown(minVal);
        }
        
    }
    public:
    MinHeap() { size = -1; }
    void insert(int element) {
        // add your code here
        heapVec.push_back(element);
        int i = heapVec.size() - 1;
        percolateUp(i);
    }
    void deleteMin() {
         // add your code here
         if(heapVec.size() != 0){ //checks if there is a heap to delete
            heapVec[0] = heapVec.back(); //sets the index to the back of the heap
            heapVec.pop_back(); //vector pops the  heapVec
            percolateDown(0); //calls the percolate down to ensure the heap still meets the criteria 
         }
         cout<<"Heap is empty!"<<endl; // if the the heap is empty outputs the value
         return;
    }
    int extractMin() {
         // add your code here
        if(heapVec.size() != 0){ //if the heap is not empty
            cout<<"Minimum value of vector: "<<heapVec.front()<<endl; //couts the front value
            return heapVec.front(); //returns it as well
        }
        cout<<"Heap is empty!"<<endl;
        return -1;
}
    int heapSize() {
         // add your code here
         cout<<"Heap size: "<<heapVec.size()<<endl;
         return heapVec.size();
}
    void heapDisplay() {
         // add your code here
         cout<<"Heap display: "<<endl;
         for (auto elem : heapVec){ //for loop to output the heap
            cout<<elem<<" ";
         }
         cout<<endl;
         return;
}
};
// in your main function, test your implementations. For example,  
int main() {
    MinHeap mh;
    mh.insert(4);
    mh.insert(8);
    mh.insert(1);
    mh.insert(7);
    mh.insert(3);
    // display heap
mh.heapDisplay();  // the output should be: 1, 3, 4, 8, 7
    // deleteMin
    mh.deleteMin();
mh.heapDisplay();  // the output should be: 3, 7, 4, 8
    // extractMin
mh.extractMin();   // the output should be: 3
    // heapSize
mh.heapSize();   // the output should be: 4
    return 0;
}