#include <iostream>

using namespace std;

/* 
** Binary Search Tree Insertion and Traverse
** Lab 3, CPSC 2430
** Xin Zhao
*/
class BST {
private:    
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int t){ //added a consructor to accept our input value of the stem without extra assignments
            this->val = t;
        };
    };
    TreeNode* root;
// For this lab, you do not need to consider the situation when inserting the same values.
// Only insert different values when you test your program in the main function.
    TreeNode* insert(TreeNode * t, int x) {
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
    void inorder(TreeNode * t) {
        if(t != NULL){ //If there is nodes at a point we enter the fuction
            inorder(t->left); //we want to traverse to the left most node 
            cout<<t->val<<" "; //once we are at that point we can ouput our value
            inorder(t->right); //then move right
        }
        return;
}
void preorder(TreeNode * t) {
        if(t != NULL){ //If there is nodes at a point we enter the fuction
            cout<<t->val<<" "; //in preorder we output the root first 
            preorder(t->left); // then the left side 
            preorder(t->right); //and lastly the right
        }
        return;
        }
void postorder(TreeNode * t) {
        if(t != NULL){ //If there is nodes at a point we enter the fuction
            postorder(t->left); //in post order we do the left tree
            postorder(t->right); // then the right tree
            cout<<t->val<<" "; //and the root is called last
        }
        return;
}
public:
    BST() {
        root = nullptr;
    }
    void insertNode(int x){
        root = insert(root, x);
    }
    void inorderDisplay(){
        inorder(root);
    }
    void preorderDisplay(){
        preorder(root);
    }
    void postorderDisplay(){
        postorder(root);
    }
};
// in your main function, test your implementations. For example,  
int main() {
        BST t;
        t.insertNode (10);
        t.insertNode (7);
        t.insertNode (29);
        t.insertNode (30);
        t.insertNode (9);
        // inorder display
        t.inorderDisplay();  // the output should be: 7, 9, 10, 29, 30
        // preorder display
        t.preorderDisplay();  // the output should be: 10, 7, 9, 29, 30
        // postorder display
        t.postorderDisplay();  // the output should be: 9, 7, 30, 29, 10
        return 0; 
        }