// queue_class.h
#ifndef _QUEUE_CLASS_H_
#define _QUEUE_CLASS_H_
#include <iostream>
#include <cstdio>
using namespace std;

class MyQueue
{
    public:
        MyQueue();
        ~MyQueue();

        struct ListNode {
            int value;
            ListNode* next;
        };

        void push(int val);
        ListNode* pop();
        void print();

    private:

        ListNode* head;
};

#endif
