 #include <iostream>
 #include "binarysearch.cpp"
 using namespace std;
// int main(void)
// {
//     IntBinaryTree tree;
//     cout << "Inserting nodes.\n";
//     tree.insertNode(5);
//     tree.insertNode(8);
//     tree.insertNode(3);
//     tree.insertNode(12);
//     tree.insertNode(9);
//     cout << "Inorder traversal:\n";
//     tree.showNodesInOrder();
//     cout << "\nPreorder traversal:\n";
//     tree.showNodesPreOrder();
//     cout << "\nPostorder traversal:\n";
//     tree.showNodesPostOrder();
// } 


// int main(void)
// {
//    IntBinaryTree tree;
//    cout << "Inserting nodes.\n";
//    tree.insertNode(5);
//    tree.insertNode(8);
//    tree.insertNode(3);
//    tree.insertNode(12);
//    tree.insertNode(9);
//    if (tree.searchNode(10))
//    cout << "3 is found in the tree.\n";
//    else
//    cout << "3 was not found in the tree.\n";

//    return 0;
// }


int main(void)
{
   IntBinaryTree tree;
   cout << "Inserting nodes.\n";
   tree.insertNode(5);
   tree.insertNode(8);
   tree.insertNode(3);
   tree.insertNode(12);
   tree.insertNode(9);
   cout << "Here are the values in the tree:\n";
   tree.showNodesInOrder();
   cout << "Deleting 8...\n";
   tree.remove(8);
   cout << "Deleting 12...\n";
   tree.remove(12);
   cout << "Now, here are the nodes:\n";
   tree.showNodesInOrder();

   return 0;
}

