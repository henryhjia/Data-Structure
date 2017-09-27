#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>

using namespace std;

struct ListNode {
	int value;
	ListNode *next;
};

ListNode* createNode() {
	ListNode *new_node = new ListNode;
	new_node->next = nullptr;
	new_node->value = 0;
    //cout << "newNode: " << new_node << endl;
	return new_node;
}

int getHashKey(int num) {   
    return num % 10;
}

int getLocation(ListNode* node_ptr) {
    //int val = rand() % 100; // 0 -> 99
    int val = rand() % 1000;
	node_ptr->value = val;
	return getHashKey(val);
}

void insertNode(ListNode* v[], ListNode *newNode, int index) {
	if (v[index] == nullptr) {
		v[index] = newNode;
	}
	else {
		ListNode *nodePtr = v[index];
		ListNode *prevPtr = nullptr;
        /*
		while (nodePtr != nullptr && nodePtr->value < newNode->value) {                 
			prevPtr = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (prevPtr == nullptr) {
			v[index] = newNode;
			newNode->next = nodePtr;
		}
		else {
			prevPtr->next = newNode;
			newNode->next = nodePtr;
		}
        */
        /*
        while (nodePtr != nullptr) {
            if(nodePtr->value < newNode->value) {
                prevPtr = nodePtr;                  
            }
            else {      
                if(prevPtr != nullptr) {
                    prevPtr->next = newNode;
                    newNode->next = nodePtr;
                }
                else {
                    v[index] = newNode;
                    newNode->next = nodePtr;                    
                }      
                prevPtr = nodePtr;
            }
            nodePtr = nodePtr->next;
        }
        */
        while (nodePtr != nullptr) {
            if(nodePtr->value >= newNode->value) {    
                if(prevPtr != nullptr) {
                    prevPtr->next = newNode;
                    newNode->next = nodePtr;
                }
                else {
                    v[index] = newNode;
                    newNode->next = nodePtr;                    
                }                      
            }
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }        
        // Last node if it is not inserted
        if(prevPtr->value < newNode->value) {
            prevPtr->next = newNode;
        }
	}
}

void printHashTable(ListNode* v[]) {
	ListNode *nodePtr = nullptr;
    cout << "Printing Hash Table:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "[" << i << "]: " ;
		nodePtr = v[i];
		while (nodePtr != nullptr) {
			cout  << nodePtr->value << " ";
			nodePtr = nodePtr->next;
		}
        cout << endl;
	}
}

void deleteNode(ListNode* v[], int val) {   
    ListNode *prevPtr;
    ListNode *nodePtr;
    
	for (int i = 0; i < 10; i++) {
        nodePtr = v[i];   
        
        if(nodePtr == nullptr) continue;
        
        // First node
	    if (nodePtr->value == val) {
			v[i] = nodePtr->next;
            cout << "["<< i <<"]: " << val << " found, delete it: " << nodePtr << endl;
			delete nodePtr;
			continue;
		}
        
        // Rest of nodes
        while(nodePtr != nullptr && nodePtr->value != val) {
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }        
        
        // Got it
        if(nodePtr != nullptr && nodePtr->value == val) {
            prevPtr->next = nodePtr->next;
            cout << "[" << i << "]: " << val << " found, delete it: " << nodePtr << " value=" << nodePtr->value << endl;
            delete nodePtr;
            nodePtr = nullptr;
        }
        else {
            cout << "[" << i << "]: " << val << " not found, nothing to delete" << endl;
        }
    }
}

void destroyHashTable(ListNode* v[]) {
    cout << "Destroy hash table" << endl;
	for (int i = 0; i < 10; i++) {
        ListNode *nodePtr = v[i];        
        while(nodePtr != nullptr) {
            ListNode *tmp = nodePtr;
            nodePtr = nodePtr->next;
            //cout << "delete: " << tmp << endl;
            delete tmp;
            tmp = nullptr;
        }        
        v[i] = nullptr;
    }
}

bool searchNode(ListNode* v[], int val) {

	for (int i = 0; i < 10; i++) {
        ListNode *nodePtr = v[i];        
        while(nodePtr != nullptr) {
            if(nodePtr->value != val) {
                nodePtr = nodePtr->next;
            }
            else {
                // found the node
                return true;
            }
        }        
    }    
    return false;
}

void batch_insert_hashtable(ListNode* v[], int num) {
    ListNode *node = nullptr;
    int index;
    
    for(int i=0; i< num; i++) {
		node = createNode();
		index = getLocation(node);
		insertNode(v, node, index);    
    }
}

ListNode* batch_insert_list(int num) {
    int val;
    ListNode *newNode = nullptr;
    ListNode *head = nullptr;
    ListNode *nodePtr = nullptr;
    ListNode *prevPtr = nullptr;
    
    for(int i=0; i<num; i++) {
        val = rand() % 100;
	    newNode = new ListNode;
        newNode->value = val;
        newNode->next = nullptr;
        
 	    // new single node
		if (head == nullptr) {
			head = newNode;
		}
		else {
			nodePtr = head;
			prevPtr = nullptr;
			//while (nodePtr->next != nullptr && nodePtr->value < val) {
			while (nodePtr != nullptr && nodePtr->value < val) {	
				prevPtr = nodePtr;
				nodePtr = nodePtr->next;
			}
			if (prevPtr == nullptr) {
				head = newNode;
				newNode->next = nodePtr;
			}
			else {
				prevPtr->next = newNode;
				newNode->next = nodePtr;
			}
        }                       
    }  
    
    // Print first 100 node
    nodePtr = head;
    int total = 0;
	cout << "node value= ";

	while (nodePtr && total < 100) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
        total++;
	}
	cout << endl;    
    return head;
}

bool search_node_from_list(ListNode* head, int val) {
    
    ListNode *nodePtr = head;
	while (nodePtr != nullptr) {
		if (val == nodePtr->value) {			
			return true;
		}
		nodePtr = nodePtr->next;
	}        
    return false;
}


void hash_table() {
	cout << "Week 6: Hash Table" << endl;

	ListNode* arr[10] = {0};
    ListNode *head = nullptr;
    ListNode *nodePtr = nullptr;
    
	int index;
    int num;
    
	char ch = 'q';
	do {
		cout << "What do you want to do?" << endl;
		cout << "a - add a node to hash table" << endl;
        cout << "b - batch insert to hash table" << endl;
        cout << "c - batch insert to singlely linked list " << endl;
        cout << "d - delete a node from hash table" << endl;
        cout << "i - insert node with value to hash table" << endl;
		cout << "x - destroy hash table" << endl;
        cout << "s - search a node from hash table" << endl;
        cout << "t - search a node from list" << endl;
		cout << "p - print hash table" << endl;
		cout << "q - quit" << endl;

		cin >> ch;
		cout << "ch=" << ch << endl;

		switch (ch) {
		case 'a': 
            cout << "Add node to hash table" << endl;
			nodePtr = createNode();
			index = getLocation(nodePtr);
			insertNode(arr, nodePtr, index);

			break;
              
        case 'b':
            cout << "Batch insert to hash table" << endl;
            cout << "How many node do you want to insert to the hash table?" << endl;
            cin >> num;                
            batch_insert_hashtable(arr, num);
            break;
              
        case 'c':                
            cout << "Batch insert to linked list" << endl;
            cout << "How many node do you want to insert to the linked list?" << endl;
            cin >> num;                
            head = batch_insert_list(num);
            break;
                
		case 'd':
            cout << "enter a value to delete from hash table" << endl;
            cin >> num;
            deleteNode(arr, num);
            printHashTable(arr);
            break;
               
        case 'i':
            {
                cout << "enter a value to insert to hash table" << endl;
                cin >> num;
                nodePtr = new ListNode;
                nodePtr->value = num;
                nodePtr->next = nullptr;
                int hash_key = num % 10;
                insertNode(arr, nodePtr, hash_key);   
            }                 
            break;
                  
		case 'x':
            cout << "delete hash table" << endl;
            destroyHashTable(arr);
            break;

        case 's':
            {
                cout << "search a node from hash table:" << endl;
                cout << "please enter a value:" << endl;
                cin >> num;
                
                clock_t t1;
                t1 = clock();   
                
                if(searchNode(arr, num)) {
                    cout << "node (value=" << num << ") found from hash table" << endl;
                }
                else cout << "node (value=" << num << ") not found from hash table" << endl;
   
                clock_t t2 = clock();
                cout << fixed << showpoint;
                cout << "Elapsed time=" << setprecision(6) << (t2-t1)*1.0/CLOCKS_PER_SEC << " seconds" << endl;                
            }  
            break;
                
        case 't':
            {
                cout << "search a node from linked list:" << endl;
                cout << "please enter a value:" << endl;
                cin >> num;
                
                clock_t t1;
                t1 = clock();   
                
                if(search_node_from_list(head, num)) {
                    cout << "node (value=" << num << ") found from list" << endl;
                }
                else cout << "node (value=" << num << ") not found from list" << endl;
   
                clock_t t2 = clock();
                cout << fixed << showpoint;
                cout << "Elapsed time=" << setprecision(6) << (t2-t1)*1.0/CLOCKS_PER_SEC << " seconds" << endl;                    
            }
            break;
                
		case 'p': cout << "print" << endl;
			printHashTable(arr);
			break;

		case 'q': cout << "quit" << endl;
            destroyHashTable(arr);
                
			nodePtr = head;
			while (nodePtr) {
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
    
}


int main() {
    // Complete the code.
    
    hash_table();
    
    return EXIT_SUCCESS;                

}
