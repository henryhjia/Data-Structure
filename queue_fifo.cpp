#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
// FIFO queue implementation

struct ListNode {
    int value;
    ListNode* next;
};

ListNode *head = nullptr;

ListNode* queue_func(char ch, int value = 0) {

    // Linked List
    ListNode *nodePtr = nullptr;
    ListNode *prevPtr = nullptr;
    ListNode *newNode = nullptr;

    // head is the oldeast node, tail is the newest node

        switch (ch) {

            case 'a':
                cout << "Append an integer to tail:" << endl;

                newNode = new ListNode;
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

                break;

            case 'e':
                cout << "pop" << endl;
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
                break;

            case 'p':
                cout << "print" << endl;
                nodePtr = head;
                if(head == nullptr) {
                    cout << "empty list" << endl;
                }
                else {
                    cout << "node value= ";

                    while(nodePtr) {
                        cout << nodePtr->value << " ";
                        nodePtr = nodePtr->next;
                    }
                    cout << endl;
                }
                break;
                

            case 'q':
                cout << "quit" << endl;
                cout << "deleting all nodes"<< endl;
                nodePtr = head;
                while(nodePtr) {
                    ListNode *tmp = nodePtr;
                    cout << "node to be deleted: " << tmp << endl;
                    nodePtr = nodePtr->next;
                    delete tmp;
                }
                break;

            default:
                cout << "Invalid" << endl;
                break;

            }

    return 0;
}

void queue_push(int value) {
        queue_func('a', value);
}

ListNode* queue_pop() {
        return queue_func('e');
}

int main() {
        ListNode* nodePtr;
        
        queue_push(10);
        queue_push(20);
        queue_push(30);
        queue_func('p');
        nodePtr = queue_pop();
        cout << "poped node= " << nodePtr << endl;
        queue_func('p');
        nodePtr = queue_pop();
        cout << "poped node= " << nodePtr << endl;
        queue_func('p');
        nodePtr = queue_pop();
        cout << "poped node= " << nodePtr << endl;
        queue_func('p');
        queue_func('q');

        return 0;
}        
