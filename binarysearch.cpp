#include <iostream>
using namespace std;
class IntBinaryTree
{
    public:
    struct TreeNode
    {
        int value;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *root;
    void destroySubTree(TreeNode *);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *);
    void displayPreOrder(TreeNode *);
    void displayPostOrder(TreeNode *);
    public:
    IntBinaryTree()		// Constructor		
    { root = NULL; }
    ~IntBinaryTree()	// Destructor	
    { destroySubTree(root); }
    void insertNode(int);
    bool searchNode(int);
    void remove(int);
    void showNodesInOrder(void)
    {	displayInOrder(root); }
    void showNodesPreOrder()
    {	displayPreOrder(root); }
    void showNodesPostOrder()
    {	displayPostOrder(root); }
    
};

void IntBinaryTree::insertNode(int num)
{
    TreeNode *newNode,	// Pointer to a new node         
    *nodePtr;	// Pointer to traverse the tree
    // Create a new node
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = NULL;
    if (!root)	// Is the tree empty?
    root = newNode;
    else
    {
        nodePtr = root; 
        while (nodePtr != NULL)
        {
            if (num < nodePtr->value)
            {
                if (nodePtr->left)
                nodePtr = nodePtr->left;
                else
                {
                    nodePtr->left = newNode;
                    break;
                }
            }
            else if (num > nodePtr->value)
            {
                if (nodePtr->right)
                nodePtr = nodePtr->right;
                else
                {
                    nodePtr->right = newNode;
                    break;
                    }
                }
            else
            {
                cout << "Duplicate value found in tree.\n";				
                break;
            }
        }		
    }
}

void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        destroySubTree(nodePtr->left);
        destroySubTree(nodePtr->right);
        remove(nodePtr->value);
    }
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);		
        displayPreOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);		
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}

bool IntBinaryTree::searchNode(int num)
{
    TreeNode *nodePtr = root;
    while (nodePtr)
    {
        if (nodePtr->value == num)
        return true;
        else if (num < nodePtr->value)
        nodePtr = nodePtr->left;
        else
        nodePtr = nodePtr->right;
    }
    return false;
}

void IntBinaryTree::remove(int num)
{
    deleteNode(num, root);
}

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if (num < nodePtr->value)
    deleteNode(num, nodePtr->left);
    else if (num > nodePtr->value)
    deleteNode(num, nodePtr->right);
    else
	makeDeletion(nodePtr);
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
    TreeNode *tempNodePtr;	// Temporary pointer, used in	                      
    // reattaching the left subtree	
    if (nodePtr == NULL)
    cout << "Cannot delete empty node.\n";
    else if (nodePtr->right == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left; // Reattach the left child		
        delete tempNodePtr;
    }
    else if (nodePtr->left == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right; // Reattach the right child	
        delete tempNodePtr;
    }
    // If the node has two children
    else
    {
        // Move one node the right.
        tempNodePtr = nodePtr->right;
        // Go to the end left node		
        while (tempNodePtr->left)
        tempNodePtr = tempNodePtr->left;
        // Reattach the left subtree
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}









