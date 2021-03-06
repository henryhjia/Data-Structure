#include "list_class.h"
  
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

void MyList::insertHead(int val)
{
    ListNode* newNode = new ListNode;
    newNode->value = val;
    newNode->next = nullptr;

    cout << "Node created: 0x" << newNode << endl;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

MyList::ListNode* MyList::deleteHead()
{
    ListNode *nodePtr = nullPtr;
    ListNode *retPtr = nullptr;
  
    if (head) {
        if (head->next) {
            nodePtr = head->next;
            retPtr = head;
            head = nodePtr;
        }
        else {
            retPtr = head;
            head = nullptr;
        }
    }
    else {
        cout << "Empty list, nothing to delete" << endl;
    }
    return retPtr;
}

void MyList::insertTail(int val)
{
    ListNode* newPtr = new ListNode;
    newPtr->value = val;
    newPtr->next = nullptr;

    ListNode* nodePtr = head;
    ListNode* prevPtr = nullptr;

    if(nodePtr == nullptr) {
        head = newPtr;
        return;
    }

    // method 1
    while(nodePtr->next != nullptr) {
        nodePtr = nodePtr->next;
    }
    nodePtr->next = newPtr;

    // method 2
    //while(nodePtr != nullptr) {
    //    prevPtr = nodePtr;
    //    nodePtr = nodePtr->next;
    //}
    // reaches end, prevPtr is the last node
    //prevPtr->next = newPtr;
}

MyList::ListNode* MyList::deleteTail()
{
    ListNode *nodePtr = head;
    ListNode *prevPtr = nullptr;
    ListNode *retPtr = nullptr;
  
    if (head == nullptr) {
        cout << "Empty list, nothing to delete" << endl;
        return;
    }

    if(head->next == nullptr) {
        // head only
        retPtr = head;
        head = nullptr;
        return retPtr;
    }

    while (nodePtr->next != nullptr) {
        prevPtr = nodePtr;
        nodePtr = nodePtr->next;
    }

    // Last node
    prevPtr->next = nullptr;
    retPtr = nodePtr;
    nodePtr = nullptr;
  
    return retPtr;
}

void MyList::insertNode(int val)
{
    ListNode* newNode = new ListNode;
    newNode->value = val;
    newNode->next = nullptr;
    cout << "newNode created " << newNode << endl;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        ListNode *nodePtr = head;
        ListNode *prevPtr = nullptr;
        while (nodePtr != nullptr && nodePtr->value < newNode->value) {
            // this is to search the node that is greater than the newNode
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
            cout << "step 1 : prevPtr->value=" << prevPtr->value << endl;
            if(nodePtr != nullptr) {
                cout << "step 1 : nodePtr->value=" << nodePtr->value << endl;
            }
            else {
                cout << "step 1 : nodePtr is nullptr" << endl;
            }
        }
        if (prevPtr == nullptr) {
            // this is to insert at the head
            head = newNode;
            newNode->next = nodePtr;
            cout << "step 2 : prevPtr=" << prevPtr << " nodePtr=" << nodePtr << endl;
        }
        else {
            // this is to insert at any other location
            prevPtr->next = newNode;
            newNode->next = nodePtr;
            cout << "step 3 : prevPtr->value=" << prevPtr->value << endl;
            if(nodePtr != nullptr) {
                cout << "step 3 : nodePtr->value=" << nodePtr->value << endl;
            }
            else {
                cout << "step 3 : nodePtr is nullptr" << endl;
            }
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
    cout << "got it" << endl;

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

    while (nodePtr != nullptr) {
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

