using namespace std;

#include <iostream>
#include "LinkedList.cpp"
int main(void){
    // Your code here!
    FloatList<float> list;
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);
    list.insertNode(10.5);
    cout << "Here are the initial values:\n";
    list.displayList();
    cout << endl;
    cout << "Now after deleting the node in the middle.\n";
    list.deleteNode(7.9);
    list.displayList();
    cout << endl;
    cout << "Now deleting the last node.\n";	
    cout << "Here are the nodes left.\n";	
    list.deleteNode(12.6);
    list.displayList();
    cout << endl;
    cout << "Now deleting the only remaining node.\n";
    cout << "Here are the nodes left.\n";
    list.deleteNode(2.5);
    list.displayList();
}