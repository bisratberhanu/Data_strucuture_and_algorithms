#include <iostream>
#include "AVLtrees.cpp"
using namespace std;
int main(void)
{
    BalancedSearchTree tree;
    cout << "Inserting nodes.\n";
    tree.insertNode(5);
    tree.insertNode(6);
    tree.insertNode(7);
    tree.insertNode(8);
    tree.insertNode(9);
    cout << "Inorder traversal:\n";
    tree.showNodesInOrder();
    cout << "\nPreorder traversal:\n";
    tree.showNodesPreOrder();
    cout << "\nPostorder traversal:\n";
    tree.showNodesPostOrder();
    
    cout << "Deleting 8...\n";
    tree.remove(8);
    
    cout << "Inorder traversal:\n";
    tree.showNodesInOrder();
    cout << "\nPreorder traversal:\n";
    tree.showNodesPreOrder();
    cout << "\nPostorder traversal:\n";
    tree.showNodesPostOrder();
} 
