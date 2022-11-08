#include "BST.h"
#include <iostream>
#include <vector>
using namespace std;

unsigned int nodeCount = 0; //an empty tree has 

BST::TreeNode* BST::insert(TreeNode* t, int x){
        if(t==nullptr){ //we want to find where there is not a vlaue in our tree and insert our value. There will be a nullpointer were there is no data.
            return new TreeNode(x); //At this point we insert the node with value x by returning the constructor
        }
        if (x<t->val){ //if there is a node to refrences the data values will be compared. If it larger than our intended node value we move left to the next node postion and recall the insert function
            t->left = insert(t->left,x); 
        }else{ //If it is larger we move to the right node position and call the recursive function
            t-> right =insert(t->right,x);
        }
        return t;    
}

void BST::inorder(TreeNode* t) {
        if(t != NULL){ //If there is nodes at a point we enter the fuction
            inorder(t->left); //we want to traverse to the left most node 
            cout<<t->val<<" "; //once we are at that point we can ouput our value
            inorder(t->right); //then move right
        }
        return;
}

void BST::preorder(TreeNode* t) {
        if(t != NULL){ //If there is nodes at a point we enter the fuction
            cout<<t->val<<" "; //in preorder we output the root first 
            preorder(t->left); // then the left side 
            preorder(t->right); //and lastly the right
        }
        return;
}

void BST::postorder(TreeNode* t) {
        if(t != NULL){ //If there is nodes at a point we enter the fuction
            postorder(t->left); //in post order we do the left tree
            postorder(t->right); // then the right tree
            cout<<t->val<<" "; //and the root is called last
        }
        return;
}

int BST::nodeCounter(TreeNode* t){
    if(t != NULL){ //If there is nodes at a point we enter the fuction
            inorder(t->left); //we want to traverse to the left most node 
            nodeCount = nodeCount+1; //instead of printing this in order traversal at each node we are adding one to the counter
            inorder(t->right); //then move right
        }
        return nodeCount;
}
int BST::heightOfTree(TreeNode* t){
    int leftHeight, rightHeight;
    if(t != NULL){
        leftHeight = heightOfTree(t->left); 
        rightHeight = heightOfTree(t->right);
    }else{
        return 0;
    }
    if(t != root){ //if it's not the root or our BST then we iterate sense the root has a height of 0
        if(rightHeight > leftHeight){ //takes the larger value as we want the path with the largest height
            return rightHeight+1; //adds one to our height for each travel
        }else{
            return leftHeight+1;
        }
    }else{ //case of at route just pass values to next iteration
        if(rightHeight > leftHeight){
            return rightHeight;
        }else{
            return leftHeight;
        }
    }

}

int BST::balanceCheck(TreeNode* t){
    int leftHeight; 
    int rightHeight;

    if(t == NULL){
        return 1;
    }
    leftHeight = heightOfTree(t->left); //finds the height of out tree for comparison
    rightHeight = heightOfTree(t->right);

    if((abs(rightHeight-leftHeight)<=1)&&(balanceCheck(t->left))&&(balanceCheck(t->right))){ //checks height of left and right then calls the fucntion for the node left and right beacuse all nodes must be balances
        return 1;
    }else{
        return -1;
    }

}

BST::TreeNode* BST::deleteTree(TreeNode* t){
    if(t != NULL){ //If there is nodes at a point we enter the fuction
            deleteTree(t->left); //we follow post order to the left tree
            deleteTree(t->right); // then the right tree
            cout<<"deleting "<<t->val<<endl;
            delete t; //and then the root is deleted
            t = nullptr;
            return t;

        }
        return t;
}
int BST::findPredecessor(TreeNode* t, int value){
    int predecessorValue = -1; //default is -1 for NULL
    if (!t){
        return -1; //default is -1 for NULL
    }else{
        while (t){
            if(t->val < value){ // if t is real and t is less than our value it is our predecessor 
                predecessorValue = t->val;
                t = t->right;
            }else if(t->val > value){ 
                t = t->left; 
            }else{
                if(t->left){
                    t = t->left;
                    while(t->right){ 
                        t = t->right;
                    }
                    predecessorValue = t->val;
                }
                break;
            }
        }
        return predecessorValue; 
    }
}

BST::TreeNode* BST::leafFinder(TreeNode* t){
    if(t != NULL){              //as long as there is a root it runs otherwise returns null
        while(t->left != NULL){ //while there is a root left it travels down the path till there is no left value
            t = t->left;
        }
        return t; //root is returned
    }else{
        return NULL;
    }

}

int BST::findSuccessorValue(TreeNode* t, int value){
    int successorValue = -1;
    if (!t){
        return -1;
    }else{
        if(t->right != NULL){ //there is a right value and thus can call our helper function to find the right most value
            t = leafFinder(t->right);
            successorValue = t->val;
            return successorValue;
        }else{
            TreeNode* next = NULL; //no right node
            TreeNode* prev = t; //left most known root
            while(next != t){
                if(t->val < prev-> val){ //walking forwards till we get a value 
                    next = prev;
                    prev = prev->left;
                }else{
                    prev=prev->right; 
                }
                t = next; //once the while statement is run we have reached the value right of our root that is not our value
                successorValue = t->val; // this value is passed to t and returned
                return successorValue; //I did it this way so that I could potienally use this function to return any data about t desired.
            }
        }
        
    }
    return -1; //shouldn't be touched but avoids poteintal wreturn error 
}

int BST::treeSearch(TreeNode* t, int value){
    if(t != NULL){              //as long as there is a root it runs otherwise returns null
        if(t->val == value){ //if it's there we return 1
            return 1;
        }else if(t->val > value){ //if the value of the root is greater then the value we step right then iterate
            return treeSearch(t->left,value); 
        }else{ // otherwise we step left and repeat the function
            return treeSearch(t->right, value);
        }
    }else{
        return -1;
    }
}

BST::TreeNode* BST::deleteNode(TreeNode* t, int target){ //kinda working still confused on this one 
    if(t != NULL){
        if(t->val > target){ //searching for the root 
            t->left = deleteNode(t->left,target); //steps left and iterates
        }else if(t->val < target){
            t->left = deleteNode(t->right,target);//steps right and iterates
        }else{//if the node is there we need to check for children
            if(!t->left && !t->right){//best case - no children
                delete t;
                return nullptr;
            }else if(!t->right){ // has a left child but no right child
                TreeNode* leftChild = t->left;
                delete t;
                return leftChild;
            }else if(!t->left){ //has a right child but no left child
                TreeNode* rightChild = t->right;
                delete t;
                return rightChild;
            }else{
                int replacement = findPredecessor(root,t->val); //if it gets here it means that the succcessor or predecessor must be used.
                t-> val = replacement; //successor node is set as the new value.
                root->left = deleteNode(t->left,replacement);//searches and removes duplicates. Essientally reshaping the BST as no value is deleted for this outcome just replaced
            }

        }
    }
    return nullptr;
}

//public

BST::BST() {
        root = nullptr;
}

//print functions serve to give access to our private classes in the switch in main

void BST::insertNode(int x){
     root = insert(root, x);
}

void BST::inorderDisplay(){
    inorder(root);
}

void BST::preorderDisplay(){
    preorder(root);
}

void BST::postorderDisplay(){
    postorder(root);
}

void BST::nodeCounterDisplay(){
    cout<<"Number of nodes: ";
    cout<<nodeCounter(root);
}

void BST::heightDisplay(){
    cout<<"Height of tree: ";
    cout<<heightOfTree(root);
}

void BST::balanceCheckDisplay(){ 
    int flag = balanceCheck(root); //flag for our boolean like logic
    if(flag == 1){  //intreprets our output
        cout<<"The tree is balanced"<<endl; 
        return;
    }else{
        cout<<"The tree is not balanced"<<endl;
        return;
    }
}

void BST::destroyTree(){
    cout<<"Deleting the tree"<<endl;
    deleteTree(root);
}

void  BST::predecessorDisplay(){
    cout<<"Insert a value to find predecessor of: "<<endl;
    int input;
    cin>>input;
    cout<<"The predecessor of "<<input<<" is: "<<findPredecessor(root,input)<<endl;
}

void  BST::successorDisplay(){
    cout<<"Insert a value to find successor of: "<<endl;
    int input;
    cin>>input;
    cout<<"The successor of "<<input<<" is: "<<findSuccessorValue(root,input)<<endl;
}

void BST::treeSearchDisplay(){
    cout<<"Insert a value to search the BST: "<<endl;
    int input;
    cin>>input;

    int flag = treeSearch(root,input); //flag for our boolean like logic
    if(flag == 1){  //intreprets our output
        cout<<input<<" is in the tree"<<endl; 
        return;
    }else{
        cout<<input<<" is in the tree"<<endl;
        return;
    }
}

void BST::deleteNodeDisplay(){
    cout<<"Insert a value to delete it from the BST: "<<endl;
    int input;
    cin>>input;
    cout<<"Deleting "<<input<<" from the BST."<<
    deleteNode(root,input);
}