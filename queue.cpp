#include "queue.h"

MyQueue::MyQueue()
{}

void MyQueue::enqueue(int num)
{
	insertHead(num);
}

void MyQueue::dequeue()
{
	deleteTail();
}
