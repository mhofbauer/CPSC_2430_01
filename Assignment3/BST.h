#include <iostream>
#include <vector>
using namespace std;

class BST{
    private:    
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int t){ //added a consructor to accept our input value of the stem without extra assignments
            this->val = t;
        };
    };
     TreeNode* root = nullptr;

    TreeNode* insert(TreeNode* t, int x);
    void inorder(TreeNode* t);
    void preorder(TreeNode* t);
    void postorder(TreeNode* t);
    int nodeCounter(TreeNode* t);
    int heightOfTree(TreeNode* t);
    int balanceCheck(TreeNode* t);
    TreeNode* deleteTree(TreeNode* t);
    int findPredecessor(TreeNode* t,int val); //returns the value of a nodes predecessor based of an entered value
    int findSuccessorValue(TreeNode* t,int val); //returns the value of a nodes predecessor based of an entered value
    TreeNode* leafFinder(TreeNode*);
    int treeSearch(TreeNode* t, int value);
    TreeNode* deleteNode(TreeNode* t, int target);

    public:
    
    

    //helper
    BST();
    

    //print  functions
    void insertNode(int x);
    void inorderDisplay();
    void preorderDisplay();
    void postorderDisplay();
    void nodeCounterDisplay();
    void heightDisplay();
    void balanceCheckDisplay();
    void destroyTree();
    void predecessorDisplay();
    void successorDisplay();
    void treeSearchDisplay();
    void deleteNodeDisplay();
};
