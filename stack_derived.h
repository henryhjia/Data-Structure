#ifndef _MYSTACK_
#define _MYSTACK_
#pragma once
#include "list_class.h"

class MyStack : public MyList
{
    private:

    public:
	MyStack();
	void push(int num);
	MyList::ListNode* pop();
};

#endif
