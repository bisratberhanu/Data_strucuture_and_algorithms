#include "queue.cpp"
#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    Queue queue;
    queue.Enqueue(2.5);
    queue.Enqueue(7.9);
    queue.Enqueue(12.6);
    cout << "Here are the initial values of queue:\n";
    queue.DisplayQueue();
    queue.Dequeue();
    cout << "Here are the values of queue after one dequeue:\n";
    queue.DisplayQueue();
    
    queue.Dequeue();
    cout << "Here are the values of queue after two dequeues:\n";
    queue.DisplayQueue();
}