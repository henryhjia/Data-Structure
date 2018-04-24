// stack_class.cpp
#include "stack_class.h"

MyStack::MyStack()
{
    head = nullptr;
}

MyStack::~MyStack()
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
void MyStack::push(int value)
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

// remove node from tail
MyStack::ListNode* MyStack::pop()
{
    ListNode *nodePtr = head;
    ListNode *prevPtr = nullptr;
    ListNode *retPtr = nullptr;

    if (head == nullptr) {
        cout << "Empty list, nothing to delete" << endl;
        return nullptr;
    }

    if(head->next == nullptr) {
        // head only
        retPtr = head;
        head = nullptr;
        return retPtr;
    }

    while (nodePtr->next != nullptr) {
        prevPtr = nodePtr;
        nodePtr = nodePtr->next;
    }

    // Last node
    prevPtr->next = nullptr;
    retPtr = nodePtr;
    nodePtr = nullptr;

    return retPtr;
}

void MyStack::print()
{
    ListNode *nodePtr = head;
    cout << "node value= ";

    while (nodePtr != nullptr) {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}
