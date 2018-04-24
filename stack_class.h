// stack_class.h
#ifndef _STACK_CLASS_H_
#define _STACK_CLASS_H_
#include <iostream>
#include <cstdio>
using namespace std;

class MyStack
{
    public:
        MyStack();
        ~MyStack();

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
