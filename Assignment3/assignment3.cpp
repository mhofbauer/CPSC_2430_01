#include "BST.h"
#include <iostream>
#include <vector>
using namespace std;

void drawMainMenu();

int main(){
    //drawMainMenu(); //calls a function to print menu
    BST tree; //creates an instance of BST
    int userIn = 0; 
    do{
    drawMainMenu(); //calls a function to print menu
    cin>>userIn; //takes a user input to be passed into out switch
    switch (userIn){
                case 1: //insert
                    {
                    cout<<"Please enter a value to insert:"<<endl;
                    int valueIn=0;
                    cin>>valueIn;
                    tree.insertNode(valueIn); // our switch gives us access to the functions declared in BST
                    cout<<endl;
                    break;
                    }
                case 2:     //search
                    {
                    tree.treeSearchDisplay();
                    cout<<endl;
                    break;
                    }
                case 3://predecessor
                    {
                    tree.predecessorDisplay();
                    cout<<endl;
                    break;
                    }
                case 4: //successor
                {
                    tree.successorDisplay();
                    cout<<endl;
                    break;
                }
                case 5://height
                {
                    tree.heightDisplay();
                    cout<<endl;
                    break;
                }  
                case 6://number of nodes
                {
                    tree.nodeCounterDisplay();
                    cout<<endl;
                    break;
                }
                case 7://Delete
                {   
                    tree.deleteNodeDisplay();
                    cout<<endl;
                    break;
                }
                case 8: //Traverse inorder
                {
                    tree.inorderDisplay();
                    cout<<endl;
                    break;
                }   
                case 9: //Traverse preorder
                {
                    tree.preorderDisplay();
                    cout<<endl;
                    break;
                }
                case 10: //Traverse postorder
                { 
                    tree.postorderDisplay();
                    cout<<endl;   
                    break;
                }
                case 11: //check balance
                {
                    tree.balanceCheckDisplay();
                    cout<<endl;
                    break;
                }   
                case 12: //destroy tree
                {
                    tree.destroyTree();
                    cout<<endl;
                    break;
                }
                default:
                {
                    cout<<"INVALID INPUT";
                    cout<<endl;
                    break;
                }
    }
    }while(userIn != 0);
    cout<<"exiting system"<<endl;
}

void drawMainMenu(){
    cout << "Please select an operation to test:\n" << endl;
    cout << "1. Insert a node" << endl
    << "2. Search for a value" << endl
    << "3. Find the predecessor for an existing value" << endl
    << "4. Find the successor for an existing value" << endl
    << "5. Find the height of tree" << endl
    << "6. Find the total number of nodes in tree" << endl
    << "7. Delete a node" << endl
    << "8. Traverse inorder and display" << endl
    << "9. Traverse preorder and display" << endl
    << "10. Traverse postorder and display" << endl
    << "11. Check if a tree is balanced" << endl
    << "12. Destroy tree" << endl
    << "0. Quit" << endl<<endl;
}