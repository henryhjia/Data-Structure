#ifndef _MYQUEUE_
#define _MYQUEUE_

#pragma once
#include "listADT.h"

class MyQueue : public MyList
{
private:

public:

	MyQueue();

	void enqueue(int num);
	void dequeue();


};

#endif
