#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode {
	int value;
	ListNode *next;
};

ListNode* createNode(int val) {
	ListNode *new_node = new ListNode;
	new_node->next = nullptr;
	new_node->value = val;
    cout << "newNode: " << new_node << " value=" << val << endl;
	return new_node;
}

int getLocation(ListNode* node_ptr) {
	int val = node_ptr->value;
	return val % 10;
}

int getHashKey(int num) {   
    return num % 10;
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
            cout << "delete: " << nodePtr;
			delete nodePtr;
			continue;
		}
        
        // Rest of nodes
        while(nodePtr != nullptr && nodePtr->value != val) {
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }        
        
        // Got it
        if(nodePtr != nullptr) {
            prevPtr->next = nodePtr->next;
            cout << "delete: " << nodePtr << " value=" << nodePtr->value << endl;
            delete nodePtr;
            nodePtr = nullptr;
        }
    }
}

void destroyHashTable(ListNode* v[]) {
	for (int i = 0; i < 10; i++) {
        ListNode *nodePtr = v[i];        
        while(nodePtr != nullptr) {
            ListNode *tmp = nodePtr;
            nodePtr = nodePtr->next;
            cout << "delete: " << tmp << endl;
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
            cout << "enter a value to insert:" << endl;
            cin >> num;
			node = createNode(num);
			index = getLocation(node);
			insertNode(arr, node, index);

			break;
                
		case 'd':
            cout << "enter a value to delete" << endl;
            cin >> num;
            deleteNode(arr, num);
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
    //hash_table();
	return EXIT_SUCCESS;                

}
