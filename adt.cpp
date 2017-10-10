#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
};

class MyList {
    private:
    ListNode *head;    
    
    public:
    
	MyList() 
    {
        head = nullptr;
    }
        
	~MyList()
    {
	   ListNode *nodePtr = head;
	   while (nodePtr) {
		  ListNode *tmp = nodePtr;
		  cout << "node to be deleted: 0x" << tmp << endl;
		  nodePtr = nodePtr->next;
		  delete tmp;
	   }        
    }   
    
	void insertNode(int val)
    {
	   ListNode *newNode = nullptr;
	   newNode = new ListNode;
       newNode->value = val;
        
	   if (head == nullptr) {
		   head = newNode;
	   }
	   else {
		   ListNode *nodePtr = head;
		   ListNode *prevPtr = nullptr;
		   while (nodePtr != nullptr && nodePtr->value < newNode->value) {
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
    
	void deleteNode(int val)
    {
	   ListNode *prevPtr = nullptr;
	   ListNode *nodePtr = head;
	   if (head == nullptr) return;

	   // First node
	   if (nodePtr->value == val) {
		  head = nodePtr->next;
		  cout << val << " found, delete it: " << nodePtr << endl;
		  delete nodePtr;
		  return;
	   }

	   // Rest of nodes
	   while (nodePtr != nullptr && nodePtr->value != val) {
		  prevPtr = nodePtr;
		  nodePtr = nodePtr->next;
	   }

	   // Got it
	   if (nodePtr != nullptr && nodePtr->value == val) {
		  prevPtr->next = nodePtr->next;
		  cout << val << " found, delete it: " << nodePtr << " value=" << nodePtr->value << endl;
		  delete nodePtr;
		  nodePtr = nullptr;
	   }
	   else {
		  cout << val << " not found, nothing to delete" << endl;
	   }        
    }
    
	void printMyList() 
    {
	   ListNode *nodePtr = head;
	   cout << "node value= ";

	   while (nodePtr) {
		  cout << nodePtr->value << " ";
		  nodePtr = nodePtr->next;
	   }
	   cout << endl;        
    }
    
	bool searchNode(int val) 
    { 
	   ListNode *nodePtr = head;
	   while (nodePtr != nullptr) {
		   if (val == nodePtr->value) {
		      return true;
	       }
	       nodePtr = nodePtr->next;
	   }
	   return false;                
    }
    
	bool isEmpty() 
    { 
       if (head != nullptr) return true;
	   else return false;
    }

};

int main()
{
	char ch = 'q';
	int val;
	MyList ml;
	bool flag;

	do {
		
		cout << "i -- insert in the middle ... \n";
		cout << "d -- find & delte ...\n";
		cout << "p -- print ... \n";
		cout << "s -- search ... \n";
		cout << "f -- empty ... \n";
		cout << "q -- quit ... \n";

		cin >> ch;
		
		switch (ch)
		{						
		case 'i': cout << "inserting in the middle ..." << endl;
			cout << "enter an integer ";
			cin >> val;
			ml.insertNode(val); // void return type
			break;
		
		case 'd': cout << "deleting ... " << endl;
			cout << "enter a value to be deleted ";
			cin >> val;
			ml.deleteNode(val); // void return type
			break;
		
		case 'p': cout << "printing ... " << endl;
			ml.printMyList(); // void return type
			break;

		case 's':
			cout << "enter a value to be searched \n";
			cin >> val;
			flag = ml.searchNode(val); // bool return type
			if (flag) {
				cout << "node found" << endl;
			}
			else { cout << "node not found" << endl; }
			break;

		case 'f':
			flag = ml.isEmpty(); // bool return type
			if (flag) cout << "not empty" << endl;
			else { cout << "empty" << endl; }
			break;

		case 'q': cout << "quitting ... " << endl;
			break;

		default:
			cout << "Invalid entry" << endl;
			break;
		}
	} while (ch != 'q');

	system("pause");
	return 0;
}
