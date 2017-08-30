#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

struct ListNode {
    int value;
    ListNode *next;
    ListNode *prev;
};

int main() {
    // Linked List
    ListNode *head = nullptr;
    ListNode *nodePtr = nullptr;
    ListNode *prevPtr = nullptr;
    ListNode *newNode = nullptr;
    int val = 0;
    
    char ch = 'q';
    do {
        cout << "a - add an element at beginning of the list" << endl;        
        cout << "d - delete an element at beginning of the list" << endl;
        cout << "l - add an element at the end of the list" << endl;
        cout << "m - delete an element from the end of the list" << endl;
        cout << "n - add an element after an item of the list" << endl;
        cout << "o - delete an elemment from the list using a key" << endl;
        cout << "p - display all elements forward" << endl;
        cout << "r - display all elements backward" << endl;
        cout << "q - quit" << endl;

        cin >> ch;
        cout << "ch=" << ch << endl;
        
        switch (ch) {
            case 'a':                  
                cin >> val;
                cout << "add an element " << val << " at the beginning of the list" << endl;
                
                newNode = new ListNode;
                cout << "node created: 0x" << newNode << endl;
                
                newNode->value = val;
                newNode->next = nullptr;
                newNode->prev = nullptr;
                
                if (head == nullptr) {
                    head = newNode;
                }
                else {
                    newNode->next = head;
                    head->prev = newNode;                    
                    head = newNode;
                }
                
            break;
            
            case 'd':                
                cout << "delete first element" << endl;
                if(head) {
                    if(head->next) {
                        nodePtr = head->next;
                        delete head;
                        nodePtr->prev = nullptr;
                        head = nodePtr;
                    }
                    else {
                        delete head;
                        head = nullptr;
                    }
                }
                
                break;
                
            case 'l': 
                cin >> val;
                cout << "add an element " << val << " at the end of the list" << endl;
                newNode = new ListNode;
                cout << "node created: 0x" << newNode << endl;
                
                newNode->value = val;
                newNode->next = nullptr;
                newNode->prev = nullptr;
                
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
                    newNode->prev = nodePtr;
                }
                
                break;
                    
            case 'm': cout << "delete last element" << endl;
                nodePtr= head;
                
                if(head == nullptr) { break; }
                
                if(head->next == nullptr) {
                    delete head;
                    break;
                }
                
                while(nodePtr->next) {
                    nodePtr = nodePtr->next;
                }
                // last node
                prevPtr = nodePtr->prev;
                prevPtr->next = nullptr;
                cout << "deleting last node 0x" << nodePtr << endl;
                delete nodePtr;
                
                break;
                
            case 'p': cout << "display element forward" << endl;
                nodePtr = head;
                cout << "node value= ";
                
                while(nodePtr) {
                    cout << nodePtr->value << " ";
                    nodePtr = nodePtr->next;
                }
                cout << endl;
                break;
                
            case 'r': cout << "display element backward" << endl;
                nodePtr = head;
                if(head == nullptr) break;
                
                while(nodePtr->next) {
                    nodePtr = nodePtr->next;
                }
                // last node
                cout << "node value (reversed) = ";
                
                while(nodePtr) {
                    cout << nodePtr->value << " ";
                    nodePtr = nodePtr->prev;
                }
                cout << endl;
                
                break;
                
            case 'q': cout << "quit" << endl;
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
                cout << "invalid" << endl;
                break;
        }
    } while (ch != 'q');
    return EXIT_SUCCESS;
}
    
