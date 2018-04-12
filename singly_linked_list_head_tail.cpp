#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
};

int main () {

    // Linked List
    ListNode *head = nullptr;
    ListNode *nodePtr = nullptr;
    ListNode *prevPtr = nullptr;
    ListNode *newNode = nullptr;
    int value = 0;

    char ch = 'q';
    do {
        cout << "a - append to tail" << endl;
        cout << "i - insert to head" << endl;
        cout << "d - delete tail" << endl;
        cout << "e - delete head" << endl;
        cout << "p - print" << endl;
        cout << "q - quit" << endl;

        cin >> ch;
        cout << "ch=" << ch << endl;

        switch (ch) {

            case 'a':
                cout << "Append an integer to tail:" << endl;
                cin >> value;

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
                
             case 'i':
                cout << "Insert an integer to the head:" << endl;
                cin >> value;

                newNode = new ListNode;
                cout << "node created: " << newNode << endl;

                newNode->value = value;
                newNode->next = nullptr;

                if(head == nullptr) {
                    head = newNode;
                }
                else {
                    newNode->next = head;
                    head = newNode;
                }

                break;

            case 'd':
                cout << "deleting tail" << endl;
                if(head != nullptr && head->next == nullptr) {
                    // only one node
                    cout << "deleting: " << head << endl;
                    delete head;
                    head = nullptr;
                }
                else if (head != nullptr) {
                    nodePtr = head;
                    while(nodePtr->next != nullptr) {
                        prevPtr = nodePtr;
                        nodePtr = nodePtr->next;
                    }
                    cout << "found it: " << nodePtr << endl;
                    // got the last one
                    prevPtr->next = nullptr;

                    cout << "deleting " << nodePtr << endl;
                    delete nodePtr;
                    nodePtr = nullptr;

                }
                else {
                    cout << "empty list, nothing to delete" << endl;
                }

                break;
                
             case 'e':
                cout << "deleting head" << endl;
                if(head != nullptr) {
                    if(head->next == nullptr) {
                        cout << "deleting single head: " << head << endl;
                        delete head;
                        head = nullptr;
                    }
                    else {
                        nodePtr = head;
                        head = head->next;
                        cout << "deleting head: " << nodePtr << endl;
                        delete nodePtr;
                        nodePtr = nullptr;
                    }
                }
                else {
                    cout << "empty list, nothing to delete" << endl;
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
                    cout << "node to be deleted: 0x" << tmp << endl;
                    nodePtr = nodePtr->next;
                    delete tmp;
                }
                break;

            default:
                cout << "Invalid" << endl;
                break;

            }
        } while (ch != 'q');

    return 0;
}                
