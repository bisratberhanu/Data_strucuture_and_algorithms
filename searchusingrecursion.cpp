#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

bool searchInTree(TreeNode* root, int value) {
    
    if (root == nullptr) {
        return false;
    }

   
    if (root->val == value) {
        return true;
    }

    
    if( value < root->val ){searchInTree(root->left, value);}
    else{searchInTree(root->right, value);}
    

    
    return false;
}

