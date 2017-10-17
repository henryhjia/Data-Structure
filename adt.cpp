#include "adt.h"
#include <iostream>
using namespace std;

MyList::MyList() 
{
     head = nullptr;
}
        
MyList::~MyList()
{
	ListNode *nodePtr = head;
	while (nodePtr) {
		ListNode *tmp = nodePtr;
		cout << "node to be deleted: 0x" << tmp << endl;
		nodePtr = nodePtr->next;
		delete tmp;
	}        
}   

void MyList::insertNode(int val)
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

void MyList::deleteNode(int val)
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
void MyList::printMyList() 
{
	ListNode *nodePtr = head;
	cout << "node value= ";

	while (nodePtr) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
	cout << endl;        
}
    
bool MyList::searchNode(int val) 
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
    
bool MyList::isEmpty() 
{ 
	if (head != nullptr) return true;
	else return false;
}
