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
                    cout << "delete node 0x" << head << endl;
                    delete head;      
                    head = nullptr;
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
                nodePtr = nullptr;
                
                break;
                
            case 'n': cout << "add node after an elem: " << endl;
                if(head == nullptr) break;
                cout << "enter a value: ";
                cin >> val;
                
                newNode = new ListNode;
                newNode->value = val;
                newNode->prev = nullptr;
                newNode->next = nullptr;
                cout << "new node created: 0x" << newNode << " value=" << val << endl;
                
                // only one node
                if(head->next == nullptr) {
                    if(head->value < val) {
                        head->next = newNode;
                        newNode->prev = head;
                        break;
                    }
                    else {
                        // delete the newNode to avoid memory leak
                        cout << "val not satisfied, delete newNode 0x" << newNode << endl;
                        delete newNode;
                        newNode = nullptr;
                        break;
                    }
                }
                
                // more than 2 nodes in the middle
                nodePtr= head;               
                while(nodePtr->next != nullptr) {
                    if(nodePtr->value < val) {
                        ListNode *tmp;
                        
                        tmp = nodePtr->next;
                        nodePtr->next = newNode;
                        newNode->prev = nodePtr;
                        newNode->next = tmp;
                        tmp->prev = newNode;
                        
                        break;
                    }
                    else {
                        nodePtr = nodePtr->next;
                    }
                }
                
                // last node
                if(nodePtr->value < val) {
                    nodePtr->next = newNode;
                    newNode->prev = nodePtr;
                }
                else {
                    // delete the newNode to avoid memory leak
                    cout << "val not satisfied, delete it 0x" << newNode << endl;
                    delete newNode;
                    newNode = nullptr;
                }
                
                break;
                
            case 'o': cout << "delete an item that has specified value" << endl;
                cin >> val;
                
                if(head == nullptr) break;
                
                if(head->next == nullptr) {
                    // only one node
                    if(head->value == val) {
                        cout << "only one node, delete it 0x" << head << " with value:" << val << endl;
                        delete head;
                    }
                    break;                    
                }
                
                // more than 2 nodes
                nodePtr = head;
                while(nodePtr != nullptr) {
                    if(nodePtr->value == val) {   
                        if(nodePtr->prev != nullptr) {                        
                            nodePtr->prev->next = nodePtr->next;
                        }
                        else {
                            // this is the head
                            head = nodePtr->next;
                            head->prev = nullptr;                            
                        }
                        
                        if(nodePtr->next != nullptr) {
                            nodePtr->next->prev = nodePtr->prev;
                        }
                        cout << "delete the node 0x" << nodePtr << " with value:" << val << endl;
                        delete nodePtr;
                        nodePtr = nullptr;                        
                        break;
                    }
                    else {
                        nodePtr = nodePtr->next;
                    }   
                }
                
                break;
                
            case 'p': cout << "display element forward" << endl;
                nodePtr = head;
                cout << "node value = ";
                
                while(nodePtr) {
                    cout << nodePtr->value << " ";
                    nodePtr = nodePtr->next;
                }
                cout << endl;
                break;
                
            case 'r': cout << "display element backward" << endl;
                cout << "node value (reversed) = ";
                nodePtr = head;
                if(head == nullptr) {
                    cout << "" << endl;
                    break;
                }
                
                // traverse to the last node
                while(nodePtr->next) {
                    nodePtr = nodePtr->next;
                }
                
                // last node               
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
    
