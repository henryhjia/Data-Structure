#include "stack.h"

MyStack::MyStack()
{

}

void MyStack::push(int num)
{
	insertHead(num);
}

void MyStack::pop()
{
	deleteHead();
}
