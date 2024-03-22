
#include <iostream>
using namespace std;
#ifndef FloatList_H
#define FloatList_H
#endif
template <class T>
class LinkedList
{
    private:	// Declare a structure for the list
    struct ListNode	
    {
        T value;		
        struct ListNode *next;	
        
    }; 	
    ListNode *head;	// List head pointer
    friend class Stack;
    friend class Queue;
    public:	
    LinkedList(void)	// Constructor
    { 
        head = NULL; 
        
    }	
    ~LinkedList(void); // Destructor
    void appendNode(T);	
    void insertNode(T);	
    void deleteNode(T);	
    void addNodeFront(T);
    void displayList(void);
    bool IsEmpty() 
    { 
        return head == NULL; 
        
    }
    
};
template <class T>
void LinkedList<T>::appendNode(T num)
{	
    ListNode *newNode, *nodePtr; // Allocate a new node & store num
    newNode = new ListNode;	
    newNode->value = num;	
    newNode->next = NULL; // If there are no nodes in the list
    // make newNode the first node
    if (!head)		
    head = newNode;	
    else	// Otherwise, insert newNode at end
    {		// Initialize nodePtr to head of list
    nodePtr = head;		// Find the last node in the list
    while (nodePtr->next)			
       nodePtr = nodePtr->next;		
    // Insert newNode as the last node
    nodePtr->next = newNode;
    }
}
template <class T>
LinkedList<T>::~LinkedList(void)
{
    ListNode *nodePtr, *nextNode;
    nodePtr = head;
    while (nodePtr != NULL)
    {
        nextNode = nodePtr->next;
        delete nodePtr;		
        nodePtr = nextNode;	
        
    }
}
template <class T>
void LinkedList<T>::displayList(void)
{
    ListNode *nodePtr;
    nodePtr = head;	
    while (nodePtr)
    {
        cout<<nodePtr->value<<endl;		
        nodePtr = nodePtr->next;
    }
}
template <class T>
void LinkedList<T>::insertNode(T num)
{
    ListNode *newNode, *nodePtr, *previousNode;
    // Allocate a new node & store Num
    newNode = new ListNode;
    newNode->value = num;
    // If there are no nodes in the list
    // make newNode the first node
    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else	// Otherwise, insert newNode.
    {
	  // Initialize nodePtr to head of list
      nodePtr = head;
      // Skip all nodes whose value member is less
	  // than num.
    while (nodePtr != NULL && nodePtr->value < num)
    {	
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }
     // If the new mode is to be the 1st in the list,
     // insert it before all other nodes.
    if (previousNode == NULL)
	{
	    head = newNode;
	    newNode->next = nodePtr;
	}
	else
	{
	    previousNode->next = newNode;
	    newNode->next = nodePtr;
	}
	}
}
template <class T>
void LinkedList<T>::deleteNode(T num)
{
    ListNode *nodePtr, *previousNode;
    // If the list is empty, do nothing.
    if (!head)
       return;
       // Determine if the first node is the one.
    if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to head of list	
        nodePtr = head;
        // Skip all nodes whose value member is
		// not equal to num	
        while (nodePtr != NULL && nodePtr->value != num)
        {	
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        // Link the previous node to the node after
		// nodePtr, then delete nodePtr.
        previousNode->next = nodePtr->next;
        delete nodePtr;
        }
} 

template <class T>
void LinkedList<T>::addNodeFront(T num)
{	
    ListNode *newNode, *nodePtr; // Allocate a new node & store num
    newNode = new ListNode;	
    newNode->value = num;	
    newNode->next = NULL; // If there are no nodes in the list
    // make newNode the first node
    if (!head)		
    head = newNode;	
    else	// Otherwise, insert newNode at end
    {		// Initialize nodePtr to head of list
    nodePtr = head;		
    head=newNode;
    newNode->next = nodePtr;
    }
}
class Queue: LinkedList<double>{
public:
	Queue() {		// constructor
		front = rear = NULL;
	}		
	~Queue() {		// destructor
		//double value;
		while (!IsEmpty()) Dequeue();
	}
	bool IsEmpty() {
		if (front) 	return false;
		else	    	return true;
	}
	void Enqueue(double x);
	double Dequeue(void);
	void DisplayQueue(void);
private:
	ListNode *front;	// pointer to front node
	ListNode *rear;	// pointer to last node
};


void Queue::Enqueue(double x) {
	ListNode *newNode	=	new ListNode;
	newNode->value	=	x;
	newNode->next	=	NULL;
	if (IsEmpty()) {
		front		=	newNode;
		rear		=	newNode;
	}
	else {
		rear->next	=	newNode;
		rear		=	newNode;
	}
}


double Queue::Dequeue() {
    double x=0.0;
    if (IsEmpty()) {
		cout << "Error: the queue is empty." << endl;
		return -1.0;
	}
	else {
		x			=	front->value;
		ListNode *nextNode	=	front->next;
		delete front;
		front			=	nextNode;
	}
	return x;
}


void Queue::DisplayQueue() {
	cout << "front -->";
	ListNode *currNode, *nodePtr =	front;
	
    while (nodePtr)
    {
        if(nodePtr==front)
           cout << "\t";
        else
            cout << "\t\t"; 
        cout<<nodePtr->value<<endl;		
        nodePtr = nodePtr->next;
    }
	cout << "\t<-- rear" << endl;		
}







