 #include <iostream>
using namespace std;
#ifndef FloatList_H
#define FloatList_H
#endif
template <class T>
class FloatList
{
    private:	// Declare a structure for the list
    struct ListNode	
    {
        T value;		
        struct ListNode *next;	
        
    };
    ListNode *head;	// List head pointer 	
   
    public:	
    FloatList(void)	// Constructor
    { 
         
        head = NULL; 
        
    }	
    ~FloatList(void); // Destructor
    
    void insertNode(int index, T);	
    bool hasCycle(void);
    void createCycle(void);
    void displayList(void);
    
};


template <class T>
FloatList<T>::~FloatList(void)   // destructor
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
void FloatList<T>::displayList(void)  // displayList function
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
void FloatList<T>::insertNode(int index, T num) // insertNode function
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
      if (index == 0) // if index is 0, insert at the beginning
      {
        newNode->next = head;
        head = newNode;
      }
	  else{
      int i = 0;
    while (nodePtr != NULL && i < index)
    {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
        i++;
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
}

template <class T>
void FloatList<T>::createCycle() // createCycle function
{
    ListNode *nodePtr;
    nodePtr = head;
    while (nodePtr->next != NULL)
    {
        nodePtr = nodePtr->next;
    }
    nodePtr->next = head;
}

template <class T>
bool FloatList<T>::hasCycle() // hasCycle function
{
    ListNode *slow = head;
    ListNode *fast = head;
    while ( fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}


// main function and test cases




 









