// queue_class.cpp
#include "queue_class.h"

MyQueue::MyQueue()
{
    head = nullptr;
}

MyQueue::~MyQueue()
{
    ListNode *nodePtr = head;
    while (nodePtr) {
        ListNode *tmp = nodePtr;
        cout << "node to be deleted: 0x" << tmp << endl;
        nodePtr = nodePtr->next;
        delete tmp;
    }
}


// append a node to the tail
void MyQueue::push(int value)
{
    cout << "push " << value << endl;
    ListNode* nodePtr = nullptr;
    ListNode* newNode = new ListNode;
    cout << "node created: " << newNode << endl;

    newNode->value = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        nodePtr = head;
        while (nodePtr->next != nullptr) {
            nodePtr = nodePtr->next;
        }
        // nodePtr is the end of the node, add the newNode to "next"
        nodePtr->next = newNode;
    }
}


// remove a node from head
MyQueue::ListNode* MyQueue::pop()
{
    cout << "pop" << endl;
    ListNode* nodePtr = nullptr;

    if(head != nullptr) {
        if(head->next == nullptr) {
            nodePtr = head;
            head = nullptr;
            return nodePtr;
        }
        else {
            nodePtr = head;
            head = head->next;
            return nodePtr;
        }
    }
    else {
        cout << "empty list, nothing to pop" << endl;
        return nullptr;
    }
}

void MyQueue::print()
{
    ListNode *nodePtr = head;
    cout << "node value= ";

    while (nodePtr != nullptr) {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

