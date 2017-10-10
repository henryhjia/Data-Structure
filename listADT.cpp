#include "listADT.h"
#include <iostream>
using namespace std;

ListNode::ListNode()
{
	value = 0;
	next = nullptr;
	head = nullptr;
}

ListNode::ListNode(int num)
{
	value = num;
	next = nullptr;
	head = nullptr;
}	

ListNode::~ListNode()
{
	ListNode *nodePtr = head;
	while (nodePtr) {
		ListNode *tmp = nodePtr;
		cout << "node to be deleted: 0x" << tmp << endl;
		nodePtr = nodePtr->next;
		delete tmp;
	}
}

void ListNode::appendNode(int num) {

	ListNode *nodePtr = nullptr;
	ListNode *prevPtr = nullptr;
	ListNode *newNode = nullptr;

	newNode = new ListNode(num);

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

}

void ListNode::insertNode(int num) {

	ListNode *newNode = nullptr;
	newNode = new ListNode(num);

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

void ListNode::deleteNode(int val) {
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

void ListNode::printMyList() {
	ListNode *nodePtr = head;
	cout << "node value= ";

	while (nodePtr) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

bool ListNode::searchNode(int val) {

	ListNode *nodePtr = head;
	while (nodePtr != nullptr) {
		if (val == nodePtr->value) {
			return true;
		}
		nodePtr = nodePtr->next;
	}
	return false;
}

bool ListNode::isEmpty() {
	if (head != nullptr) return true;
	else return false;
}
