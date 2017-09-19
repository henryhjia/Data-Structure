#include <iostream>
using namespace std;

// Work on maximum
void selectionSort(int data[], int size) {
	int largest = 0;
	int indxlargest;
	int j;

	if (size == 0) return;

	for (int i = size - 1; i > 0; i--) {
		  largest = data[0];
		  indxlargest = 0;

		  for (j = 1; j <= i; j++) {
			  if (data[j] > largest) {
				  largest = data[j];
				  indxlargest = j;
			  }
		  }
		  //swap(data[i], data[indxlargest]);
		  int tmp = data[i];
		  data[i] = data[indxlargest];
		  data[indxlargest] = tmp;
	  }
}

// Work on minimum
void selectionSort2(int data[], int size) {
	int min = 0;
	int min_index=0;
	int j;

	if (size == 0) return;

	for (int i =0; i<= size - 1; i++) {
		min = data[i];
		min_index = i;

		for (j = i+1; j <= size-1; j++) {
			if (data[j] < min) {
				min = data[j];
				min_index = j;
			}
		}
		//swap(data[i], data[min]);
		int tmp = data[i];
		data[i] = data[min_index];
		data[min_index] = tmp;
        cout << "data[" << i <<"]=" << data[i] << " data[" << min_index << "]=" << data[min_index] << endl;
	}
}

// Work on singlely linked list
struct ListNode {
	int value;
	ListNode *next;
};

// selection sort to singlely linked list
void selection_sort(ListNode* head) {
    int min = 0;
    int tmp = 0;
    ListNode *n1;
    ListNode *n2;
    ListNode *minPtr;
    
    // Empty list
    if(head == nullptr) {return;}
    
    // Only one node
    if(head->next == nullptr) { return;}
    
    // Sort start:   
    n1 = head;
    while(n1 != nullptr) {
        min = n1->value;
        n2 = n1->next;
	minPtr = n1;
        while(n2 != nullptr) {
            if(n2->value < min) {
                min = n2->value;
                minPtr = n2;
            }
            n2 = n2->next;
        }
        // swap data
        tmp = n1->value;
        n1->value = min;
        minPtr->value = tmp;
        
        // Go to next node
        n1 = n1->next;
    }
}


void singlely_linked_list() {
	ListNode *head = nullptr;
	ListNode *nodePtr = nullptr;
	ListNode *prevPtr = nullptr;
	ListNode *newNode = nullptr;
	int val = 0;

	char ch = 'q';
	do {
		cout << "e - add at the end" << endl;
		cout << "i - insert in the middle" << endl;
		cout << "b - add in the beginning" << endl;
		cout << "d - find and delete ..." << endl;
		cout << "h - delete head ... " << endl;
		cout << "t - delete tail ..." << endl;
		cout << "p - print" << endl;
		cout << "s - search ... " << endl;
		cout << "f - empty" << endl;
        cout << "m - ascending selection sort" << endl;
		cout << "q - quit" << endl;

		cin >> ch;
		cout << "ch=" << ch << endl;

		switch (ch) {
		case 'e': cout << "adding at the end ... " << endl;
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

		case 'i': cout << "insert in the middle" << endl; // in asend order e.g. 2 3 4 ...
			cout << "enter an integer to insert: " << endl;
			cin >> val;

			// always create a new ListNode instance
			newNode = new ListNode;
			cout << "node created: 0x" << newNode << endl;
			newNode->value = val;
			newNode->next = nullptr;

			// new single node
			if (head == nullptr) {
				head = newNode;
			}
			else {
				nodePtr = head;
				prevPtr = nullptr;
				while (nodePtr->next != nullptr && nodePtr->value < val) {
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

			break;

		case 'b':
			cout << "adding in the beginning..." << endl;
			cout << "enter a value to be added to the beginning ";
			cin >> val;

			newNode = new ListNode;
			newNode->value = val;
			newNode->next = nullptr;

			if (head == nullptr) {
				head = newNode;
			}
			else {
				newNode->next = head;
				head = newNode;
			}
			break;

		case 'd':
			cout << "enter an integer " << endl;
			cin >> val;
			cout << "delete a node with value:" << val << endl;
			if (head == nullptr) {
				break;
			}

			// first node
			if (head->value == val) {
				ListNode* tmp = head;
				head = head->next;
				delete tmp;
				break;
			}

			// rest of nodes
			nodePtr = head;
			while (nodePtr && nodePtr->value != val) {
				prevPtr = nodePtr;
				nodePtr = nodePtr->next;
			}

			// got it                
			if (nodePtr) {
				prevPtr->next = nodePtr->next;
				cout << "deleting node 0x" << nodePtr << " value=" << nodePtr->value << endl;
				delete nodePtr;
			}
			break;
      
      		case 'h':
			cout << "delete head..." << endl;
			if (head == nullptr) {
				cout << " empty " << endl;
			}
			else {
				nodePtr = head->next;
				delete head;
				head = nodePtr;
			}
			break;

		case 't':
			cout << "delete tail..." << endl;
			if (head == nullptr) {
				cout << "nothing to delete" << endl;
			}
			else {
				nodePtr = head;
				while (nodePtr->next != nullptr) {
					prevPtr = nodePtr;
					nodePtr = nodePtr->next;
				}
				prevPtr->next = nullptr;
				delete nodePtr;
				nodePtr = nullptr;
			}
			break;

		case 's':
			cout << "enter a value to search: " << endl;
			cin >> val;

			nodePtr = head;
			while (nodePtr != nullptr) {
				if (val == nodePtr->value) {
					cout << "found it!" << endl;
					system("pause");
					break;
				}
				nodePtr = nodePtr->next;
			}

			break;
      
      			
		case 'p': cout << "print" << endl;
			nodePtr = head;
			cout << "node value= ";

			while (nodePtr) {
				cout << nodePtr->value << " ";
				nodePtr = nodePtr->next;
			}
			cout << endl;
			break;

		case 'f':
			if (head == nullptr) {
				cout << "empty" << endl;
			}
			else {
				cout << "list is not empty" << endl;
			}
			break;

        case 'm':
            cout << "selection sort" << endl;
            selection_sort(head);                
            break;
                
		case 'q': cout << "quit" << endl;
			cout << "deleting all nodes" << endl;
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

	return;   
}
    
int main() {
    singlely_linked_list();
    
    return 0;
}

    
