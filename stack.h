#ifndef _MYSTACK_
#define _MYSTACK_
#pragma once
#include "listADT.h"

class MyStack : public MyList
{
    private:

    public:
	MyStack();
	void push(int num);
	void pop();
};

#endif
