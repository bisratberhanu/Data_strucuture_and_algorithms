#include <iostream>
#include"insert_and_cyclecheck.cpp"
using namespace std;



int main(void)
{
    FloatList<int> list;
    list.insertNode(0, 2);
    list.insertNode(1, 7);
    list.insertNode(2, 12);
    list.insertNode(3, 10);
    list.insertNode(0, 5);
    list.displayList();
    cout << "Has cycle: " << list.hasCycle() << endl;


    // a test case where there is a cycle
    cout << "Test case where there is a cycle" << endl;

    FloatList<float> cycledlist;
    cycledlist.insertNode(0, 2.5);
    cycledlist.insertNode(1, 7.9);
    cycledlist.insertNode(2, 12.6);
    cycledlist.displayList(); // display the list with out a cycle 
    cycledlist.createCycle();
    cout << "Has cycle: " << cycledlist.hasCycle() << endl;
    



    
    
    return 0;
}
