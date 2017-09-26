#include <iostream>

using namespace std;

struct ListNode {
	  int value;
	  ListNode *next;
};

ListNode* create_node(int val) {
	  ListNode *new_node = new ListNode;
	  new_node->next = nullptr;
	  new_node->value = val;
    cout << "newNode: " << new_node << " value=" << val << endl;
	  return new_node;
}

int get_location(ListNode* node_ptr) {
	  int val = node_ptr->value;
	  return val % 10;
}

void insert(ListNode* v[], ListNode *newNode, int index) {
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

void print_list(ListNode* v[]) {
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

void delete_a_node(ListNode* v[], int val) {   
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


void delete_all_node(ListNode* v[]) {
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

void hash_table() {
	  cout << "Week 6: Hash Table" << endl;

	  ListNode* arr[10] = {0};
	  ListNode* node = nullptr;
	  int index;
    int num;
    
	  char ch = 'q';
	  do {
		    cout << "What do you want to do?" << endl;
		    cout << "a - add" << endl;
        cout << "b - delete a node" << endl;
		    cout << "d - delete all" << endl;
		    cout << "p - print" << endl;
		    cout << "q - quit" << endl;

		    cin >> ch;
		    cout << "ch=" << ch << endl;

		    switch (ch) {
		        case 'a': 
                cout << "add" << endl;
                cout << "enter a value to insert:" << endl;
                cin >> num;
			          node = create_node(num);
			          index = get_location(node);
			          insert(arr, node, index);

			      break;
                
		        case 'b':
                cout << "enter a value to delete" << endl;
                cin >> num;
                delete_a_node(arr, num);
            break;
                
		        case 'd':
                cout << "delete all node" << endl;
                delete_all_node(arr);
            break;

		        case 'p': cout << "print" << endl;
			          print_list(arr);
			      break;

		        case 'q': cout << "quit" << endl;
                delete_all_node(arr);
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
