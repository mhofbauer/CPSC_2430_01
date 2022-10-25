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
    };
    TreeNode* root;
// For this lab, you do not need to consider the situation when inserting the same values.
// Only insert different values when you test your program in the main function.
    TreeNode* insert(TreeNode * t, int x) {
        // add your code here
        // ...

        
}
    void inorder(TreeNode * t) {
        // add your code here
        // ...
        
}
void preorder(TreeNode * t) {
        // add your code here
        // ...
        if(t != NULL){
            cout<<t->val<<" ";
            preorder(t->left);
            preorder(t->right); //return???

        }
        cout<<endl;
        return;

        }
void postorder(TreeNode * t) {
        // add your code here
        // ...
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