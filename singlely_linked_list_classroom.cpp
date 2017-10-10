    #include <iostream>
    using namespace std;
    
    int main() {
    
    // Linked List
    ListNode *head = nullptr;
    ListNode *nodePtr = nullptr;
    ListNode *prevPtr = nullptr;
    ListNode *newNode = nullptr;
    int val = 0;
    
    char ch = 'q';
    do {
        cout << "a - add" << endl;
        cout << "i - insert" << endl;
        cout << "d - delete" << endl;
        cout << "p - print" << endl;
        cout << "q - quit" << endl;

        cin >> ch;
        cout << "ch=" << ch << endl;
        
        switch (ch) {
            case 'a': 
                cout << "enter an integer to append:";
                int value;
                cin >> value;

                newNode = new ListNode;
                cout << "node created: 0x" << newNode << endl;
                
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
                
            case 'i': cout << "insert" << endl;
                cout << "enter an integer to insert: " << endl;
                cin >> val;
                
                // always create a new ListNode instance
                newNode = new ListNode;
                cout << "node created: 0x" << newNode << endl;
                newNode->value = val;
                newNode->next = nullptr;
               
                // new single node
                if(head == nullptr) {
                    head = newNode;
                    break;
                }     
                
                // insert at the beginning
                if(val < head->value) {
                    newNode->next = head;
                    head = newNode;
                    break;
                }
                
                nodePtr = head;
                while(nodePtr) {
                    if(nodePtr->value < val && nodePtr->next != nullptr && nodePtr->next->value > val) {
                        // insert the newNode between nodePtr and nodePtr->next
                        newNode->next = nodePtr->next;
                        nodePtr->next = newNode;                                                
                    }
                    else if (nodePtr->value < val && nodePtr->next == nullptr) {
                        // insert at the end
                        nodePtr->next = newNode;
                    }
                    else {     
                        // move to next node
                        nodePtr = nodePtr->next;
                    }
                }

                break;
               
            case 'd': 
                cout << "enter an integer " << endl;
                cin >> val;
                cout << "delete a node with value:" << val << endl;
                if(head == nullptr) {
                    break;
                }
                
                // first node
                if(head->value == val) {
                    ListNode* tmp = head;
                    head = head->next;
                    delete tmp;
                    break;
                }
                
                // rest of nodes
                nodePtr = head;
                while(nodePtr && nodePtr->value != val) {
                        prevPtr = nodePtr;
                        nodePtr = nodePtr->next;   
                } 
                
                // got it                
                if(nodePtr) {
                    prevPtr->next = nodePtr->next;
                    cout << "deleting node 0x" << nodePtr << " value=" << nodePtr->value << endl;
                    delete nodePtr;                
                }
                break;
                
                
            case 'p': cout << "print" << endl;
                nodePtr = head;
                cout << "node value= ";
                
                while(nodePtr) {
                    cout << nodePtr->value << " ";
                    nodePtr = nodePtr->next;
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
                cout << "Invalid" << endl;
                break;
        }
    } while (ch != 'q');
            
    return EXIT_SUCCESS;        
}
