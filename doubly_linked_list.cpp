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
    int elem_val = 0;
    bool found = false;
    
    char ch = 'q';
    do {
        cout << "a - Adds an element at the beginning of the list" << endl;        
        cout << "d - Deletes an element at the beginning of the list" << endl;
        cout << "i - Adds an element at the end of the list" << endl;
        cout << "m - Deletes an element from the end of the list" << endl;
        cout << "n - Adds an element after an item of the list" << endl;
        cout << "o - Deletes an elemment from the list using the key" << endl;
        cout << "p - Displays the complete list in a forward manner" << endl;
        cout << "r - Displays the complete list in a backward manner" << endl;
        cout << "q - Quit" << endl;

        cin >> ch;
        cout << "ch=" << ch << endl;
        
        switch (ch) {
            case 'a': cout << "Adds an element at the beginning of the list" << endl; 
                cout << "Enter an integer to add at front: " << endl;
                cin >> val;
                cout << "Add an element " << val << " at the beginning of the list" << endl;
                
                newNode = new ListNode;
                cout << "Node created: 0x" << newNode << endl;
                
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
                cout << "Deletes an element at the beginning of the list: " << endl;
                if(head) {
                    if(head->next) {
                        nodePtr = head->next;
                        cout << "Delete node=0x" << head << " value=" << head->value << endl;
                        delete head;
                        nodePtr->prev = nullptr;
                        head = nodePtr;
                    }
                    else {
                        cout << "Delete node=0x" << head << " value=" << head->value << endl;
                        delete head;
                        head = nullptr;
                    }
                }   
                else {
                    cout << "Empty list, nothing to delete" << endl;    
                }
                break;
                
            case 'i': cout << "Adds an element at the end of the list" << endl;
                cout << "Enter an integer to add at the end: " << endl;
                cin >> val;
                cout << "Add an element " << val << " at the end of the list" << endl;
                newNode = new ListNode;
                cout << "Node created: 0x" << newNode << endl;
                
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
                    
            case 'm': cout << "Deletes an element from the end of the list: " << endl;
                nodePtr= head;                
                if(head == nullptr) { 
                    cout << "Empty list, nothing to delete" << endl;
                    break; }
                       
                while(nodePtr->next) {                                        
                    nodePtr = nodePtr->next;
                }
                
                // Last node
                if(nodePtr->prev == nullptr) {
                    // Head and only one node
                    cout << "Delete node=0x" << head << " value=" << head->value << endl;
                    head = nullptr;
                }
                else {
                    nodePtr->prev->next = nullptr;
                    cout << "Delete node=0x" << nodePtr << " value=" << nodePtr->value << endl;
                    delete nodePtr;
                    nodePtr = nullptr;                                        
                }                              
                break;
                
            case 'n': cout << "Adds an element after an item of the list:" << endl;              
                cout << "Enter a value to insert: ";
                cin >> val;
                cout << "Enter a value for existing element:" << endl;
                cin >> elem_val;
                
                cout << "Add " << val << " after " << elem_val << endl;
                
                found = false;
                
                if(head == nullptr) {
                    cout << "Empty list, nothing to add" << endl;
                    break;                                                
                }
                // Find the node with elem_val
                nodePtr = head;
                while(nodePtr != nullptr) {
                    if(nodePtr->value == elem_val) {
                        found = true;
                        // Only create  the newNode after we find the elem_val
                        newNode = new ListNode;
                        newNode->value = val;
                        newNode->prev = nullptr;
                        newNode->next = nullptr;                                               
                        cout << "Node created: 0x" << newNode << " value=" << val << endl;
                        
                        ListNode *tmp = nodePtr->next;
                        
                        nodePtr->next = newNode;
                        newNode->prev = nodePtr;
                        
                        if(tmp) {
                            newNode->next = tmp;
                            tmp->prev = newNode;
                        }
                        break;
                    }                    
                    nodePtr = nodePtr->next;
                }
                if(found == false) {
                    cout << "The element with value=" << elem_val << " is not found, nothing is added" << endl;
                }
                break;                                
                
            case 'o': cout << "Deletes an elemment from the list using the key" << endl;
                cout << "Enter a value to be deleted: " << endl;
                cin >> val;
                cout << "Delete an item that has value=" << val << endl;

                found = false;
                
                if(head == nullptr) {                    
                    cout << "Empty list, nothing to delete" << endl;                    
                    break;
                }
                
                nodePtr = head;
                
                while(nodePtr != nullptr) {
                    
                    if(nodePtr->value == val) {
                        // Found the node
                        found = true;
                        if(nodePtr->prev != nullptr && nodePtr->next != nullptr) {
                            // Middle node
                            nodePtr->prev->next = nodePtr->next;
                            nodePtr->next->prev = nodePtr->prev;
                            cout << "Delete node 0x" << nodePtr << " with value:" << val << endl;
                            delete nodePtr;
                            nodePtr = nullptr;                            
                        }
                        else if(nodePtr->prev == nullptr && nodePtr->next == nullptr) {
                            // The only node : head = nodePtr                            
                            cout << "Delete node 0x" << nodePtr << " with value:" << val << endl;
                            delete nodePtr;
                            nodePtr = nullptr; 
                            head = nullptr;
                        }
                        else if(nodePtr->prev == nullptr && nodePtr->next != nullptr) {
                            // Head node
                            head = nodePtr->next;
                            nodePtr->next->prev = nullptr;
                            cout << "Delete node 0x" << nodePtr << " with value:" << val << endl;
                            delete nodePtr;
                            nodePtr = nullptr;                            
                        }
                        else if(nodePtr->prev != nullptr && nodePtr->next == nullptr) {
                            // Last node
                            nodePtr->prev->next = nullptr;    
                            cout << "Delete node 0x" << nodePtr << " with value:" << val << endl;
                            delete nodePtr;
                            nodePtr = nullptr;                            
                        }                        
                        break;
                    }
                    else {
                        nodePtr = nodePtr->next;
                    }                                                               
                }   
                if(found == false) {
                    cout << "Did not find the node with value:" << val << ", nothing to delete" << endl;
                }
                break;
                
            case 'p': cout << "Displays the complete list in a forward manner" << endl;
                nodePtr = head;
                cout << "Node value = ";
                
                while(nodePtr) {
                    cout << nodePtr->value << " ";
                    nodePtr = nodePtr->next;
                }
                cout << endl;
                break;
                
            case 'r': cout << "Displays the complete list in a backward manner" << endl;
                cout << "Node value (reversed) = ";
                nodePtr = head;
                if(head == nullptr) {
                    cout << "" << endl;
                    break;
                }
                
                // Traverse to the last node
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
                cout << "Delete all nodes"<< endl;
                nodePtr = head;               
                while(nodePtr) { 
                    ListNode *tmp = nodePtr;
                    cout << "Node to be deleted: 0x" << tmp << endl;
                    nodePtr = nodePtr->next;
                    delete tmp;                    
                }                
                break;
                
            default:
                cout << "Invalid" << endl;
                break;
        }
    } while (ch != 'q');
    return EXIT_SUCCESS;
}
    
