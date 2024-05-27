#include <iostream>
using namespace std;
class BalancedSearchTree
{
    public:
    struct TreeNode
    {
        int value;
		int bFactor;
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
    void rotateToLeft(TreeNode *&);
    void rotateToRight(TreeNode *&);
    void balanceFromLeft(TreeNode *&);
    void balanceFromRight(TreeNode *&);
    void insertIntoAVL(TreeNode *&, TreeNode *, bool &);
    void deleteFromAVL(TreeNode *&, int, bool &);
    
    BalancedSearchTree()		// Constructor		
    { root = NULL; }
    // ~BalancedSearchTree()	// Destructor	
    // { destroySubTree(root); }
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

void BalancedSearchTree::insertNode(int num)
{
    bool isTaller=false;
	TreeNode *newNode;	// Pointer to a new node    
    // Create a new node
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = NULL;
    insertIntoAVL(root, newNode, isTaller);
}

void BalancedSearchTree::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        destroySubTree(nodePtr->left);
        destroySubTree(nodePtr->right);
        remove(nodePtr->value);
    }
}

void BalancedSearchTree::displayInOrder(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

void BalancedSearchTree::displayPreOrder(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);		
        displayPreOrder(nodePtr->right);
    }
}

void BalancedSearchTree::displayPostOrder(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);		
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}

bool BalancedSearchTree::searchNode(int num)
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

void BalancedSearchTree::remove(int num)
{
    bool isShorter=false;
    deleteFromAVL(root, num, isShorter);
}

void BalancedSearchTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if (num < nodePtr->value)
    deleteNode(num, nodePtr->left);
    else if (num > nodePtr->value)
    deleteNode(num, nodePtr->right);
    else
	makeDeletion(nodePtr);
}

void BalancedSearchTree::makeDeletion(TreeNode *&nodePtr)
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

void BalancedSearchTree::rotateToLeft(TreeNode *&nodePtr)
{
    TreeNode *p;	// Temporary pointer, used in	                      
    // reattaching the right subtree	
    if (nodePtr == NULL)
    cout << "Cannot rotate an empty tree.\n";
    else if (nodePtr->right == NULL)
    cout << "Error in the Tree: No right subtree to rotate. \n";
    else
    {
        // Put the right subtree to the temporary pointer 
        p = nodePtr->right;
        // Make the left subtree of p become the right subtree of root		
        nodePtr->right = p->left; 
		p->left = nodePtr; // Make the root the left child of p
		nodePtr=p; //Make p the new root of the subtree
    }
}

void BalancedSearchTree::rotateToRight(TreeNode *&nodePtr)
{
    TreeNode *p;	// Temporary pointer, used in	                      
    // reattaching the right subtree	
    if (nodePtr == NULL)
    cout << "Cannot rotate an empty tree.\n";
    else if (nodePtr->left == NULL)
    cout << "Error in the Tree: No left subtree to rotate. \n";
    else
    {
        // Put the left subtree to the temporary pointer 
        p = nodePtr->left;
        // Make the right subtree of p become the left subtree of root		
        nodePtr->left = p->right; 
		p->right = nodePtr; // Make the root the right child of p
		nodePtr=p; //Make p the new root of the subtree
    }
}

void BalancedSearchTree::balanceFromLeft(TreeNode *&nodePtr)
{
    TreeNode *p, *w;	// Temporary pointers declared
	p=nodePtr->left;
	switch(p->bFactor)
	{
	case -1:
	    nodePtr->bFactor=0;
       	p->bFactor=0;
        rotateToRight(nodePtr);
        break;
    case 0:
        cout << "Error: Can't balance from left .\n";
        break;
    case 1:
        w=p->right;
        switch(w->bFactor)
        {
        case -1:
            nodePtr->bFactor=1;
            p->bFactor=0;
            break;
        case 0:
            nodePtr->bFactor=0;
            p->bFactor=0;
            break;	
        case 1:
            nodePtr->bFactor=0;
            p->bFactor=-1;
		}//end inner switch
    w->bFactor=0;
    rotateToLeft(p);
    nodePtr->left=p;
    rotateToRight(nodePtr);	
	}//end outer switch 	   
}//end balanceFromLeft

void BalancedSearchTree::balanceFromRight(TreeNode *&nodePtr)
{
    TreeNode *p, *w;	// Temporary pointers declared
	p=nodePtr->right;
	switch(p->bFactor)
	{
	case 1:
	    nodePtr->bFactor=0;
       	p->bFactor=0;
        rotateToLeft(nodePtr);
        break;
    case 0:
        cout << "Error: Can't balance from left .\n";
        break;
    case -1:
        w=p->left;
        switch(w->bFactor)
        {
        case -1:
            nodePtr->bFactor=0;
            p->bFactor=1;
            break;
        case 0:
            nodePtr->bFactor=0;
            p->bFactor=0;
            break;	
        case 1:
            nodePtr->bFactor=-1;
            p->bFactor=0;
		}//end inner switch
    w->bFactor=0;
    rotateToRight(p);
    nodePtr->right=p;
    rotateToLeft(nodePtr);	
	}//end outer switch 	   
}//end balanceFromRight

void BalancedSearchTree::insertIntoAVL(TreeNode *&nodePtr, TreeNode *newNode, bool &isTaller)
{
    if(nodePtr==NULL)
	{
	    nodePtr=newNode;
		isTaller=true;
	}
	else if(nodePtr->value==newNode->value)
	    cout << "No duplicates are allowed. \n";
    else if(nodePtr->value>newNode->value) //newItem goes to the left subtree
	{
	    insertIntoAVL(nodePtr->left, newNode, isTaller);
		if(isTaller)//If the subtree grew in height after insertion
		    switch(nodePtr->bFactor)
			{
			    case -1:
				    balanceFromLeft(nodePtr);
					isTaller=false;
					break;
			    case 0:
				    nodePtr->bFactor=-1;
					isTaller=true;
					break;
				case 1:
				    nodePtr->bFactor=0;
					isTaller=false;				
			}//end of switch
	}//end if
	else //newItem goes to the right subtree
	{
	    insertIntoAVL(nodePtr->right, newNode, isTaller);
        if(isTaller)//If the subtree grew in height after insertion
		    switch(nodePtr->bFactor)
			{
			    case -1:
				    nodePtr->bFactor=0;
					isTaller=false;
					break;
			    case 0:
				    nodePtr->bFactor=1;
					isTaller=true;
					break;
				case 1:
				    balanceFromRight(nodePtr);
					isTaller=false;				
			}//end of switch		    
	}//end else     	   
}//end insertIntoAVL



// assignment 2 

void BalancedSearchTree::deleteFromAVL(TreeNode *&nodePtr, int num, bool &isShorter)
{
    if(nodePtr==NULL)
    {
        cout << "Error: The node to be deleted is not in the tree. \n";
        isShorter=false;
    }
    else if(nodePtr->value==num)
        deleteNode(num, nodePtr);
    else if(nodePtr->value>num) //deleteItem is in the left subtree
    {
        deleteFromAVL(nodePtr->left, num, isShorter);
        if(isShorter)
            switch(nodePtr->bFactor)
            {
                case -1:
                    nodePtr->bFactor=0;
                    isShorter=true;
                    break;
                case 0:
                    nodePtr->bFactor=1;
                    isShorter=false;
                    break;
                case 1:
                    balanceFromRight(nodePtr);
                    if(nodePtr->bFactor==0)
                        isShorter=false;
                    else
                        isShorter=true;				
            }//end of switch
    }//end if
    else //deleteItem is in the right subtree
    {
        deleteFromAVL(nodePtr->right, num, isShorter);
        if(isShorter)
            switch(nodePtr->bFactor)
            {
                case -1:
                    balanceFromLeft(nodePtr);
                    if(nodePtr->bFactor==0)
                        isShorter=false;
                    else
                        isShorter=true;
                    break;
                case 0:
                    nodePtr->bFactor=-1;
                    isShorter=false;
                    break;
                case 1:
                    nodePtr->bFactor=0;
                    isShorter=true;				
            }//end of switch		    
    }//end else     	   
}//end deleteFromAVL





