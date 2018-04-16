#include "queue_derived.h"
  
MyQueue::MyQueue()
{
    cout << "MyQueue constructor" << endl;
}

void MyQueue::enqueue(int num)
{
        cout << "enqueue " << num << endl;
        insertHead(num);
}

void MyQueue::dequeue()
{
        cout << "dequeue " << endl;
        deleteTail();
}
~     
