#include "stack_class.h"

MyStack::MyStack()
{

}

void MyStack::push(int num)
{
	insertHead(num);
}

MyList::ListNode* MyStack::pop()
{
	return deleteHead();
}
