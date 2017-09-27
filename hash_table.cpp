#include <iostream>
#include <cstdio>
#include <ctime>

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

void batch_insert(ListNode* v[], int num) {
    ListNode *node = nullptr;
    int index;
    
    for(int i=0; i< num; i++) {
		node = createNode();
		index = getLocation(node);
		insertNode(v, node, index);    
    }
}

void hash_table() {
	cout << "Week 6: Hash Table" << endl;

	ListNode* arr[10] = {0};
	ListNode* node = nullptr;
	int index;
	int num;
    
	char ch = 'q';
	do {
		cout << "What do you want to do?" << endl;
		cout << "a - add a node" << endl;
        cout << "b - batch insert" << endl;
        cout << "d - delete a node" << endl;
		cout << "x - destroy hash table" << endl;
        cout << "s - seach a node" << endl;
		cout << "p - print hash table" << endl;
		cout << "q - quit" << endl;

		cin >> ch;
		cout << "ch=" << ch << endl;

		switch (ch) {
		case 'a': 
            cout << "add" << endl;
			node = createNode();
			index = getLocation(node);
			insertNode(arr, node, index);

			break;
              
            case 'b':
            cout << "Batch insert" << endl;
            cout << "How many node do you want to insert?" << endl;
            cin >> num;                
            batch_insert(arr, num);
            break;
                
		case 'd':
            cout << "enter a value to delete" << endl;
            cin >> num;
            deleteNode(arr, num);
            printHashTable(arr);
            break;
                
		case 'x':
            cout << "delete all node" << endl;
            destroyHashTable(arr);
            break;

            case 's':
            cout << "search a node:" << endl;
            cout << "please enter a value:" << endl;
            cin >> num;
            if(searchNode(arr, num)) {
                cout << "node (value=" << num << ") found" << endl;
            }
            else cout << "node (value=" << num << ") not found" << endl;
                
            break;
                
		case 'p': cout << "print" << endl;
			printHashTable(arr);
			break;

		case 'q': cout << "quit" << endl;
            destroyHashTable(arr);
			break;

		default:
			cout << "Invalid" << endl;
			break;
		}
	} while (ch != 'q');
    
}


int main() {
    // Complete the code.
    clock_t t1;
    t1 = clock();
    
    hash_table();
    
    clock_t t2 = clock();
    
    cout << "Elapsed time=" << (t2-t1)*1.0/CLOCKS_PER_SEC << " seconds" << endl;
    
    return EXIT_SUCCESS;                

}
