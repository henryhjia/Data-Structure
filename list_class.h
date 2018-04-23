// list_class.h
#ifndef _LISTADT_H_
#define _LISTADT_H_
#include <iostream>
#include <cstdio>
using namespace std;

class MyList
{
    public:
        MyList();
        ~MyList();

        struct ListNode {
            int value;
            ListNode* next;
        };
    
        void insertNode(int val);
        void deleteNode(int val);
        void printMyList();
        bool searchNode(int val);
        bool isEmpty();

        void insertHead(int val);
        ListNode* deleteHead();
        void insertTail(int val);
        ListNode* deleteTail();
        

    private:

        ListNode* head;
};


#endif
