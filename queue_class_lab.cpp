#include <iostream>
#include "queue_class.h"

using namespace std;

int main() {

        MyQueue q;
        q.push(10);
        q.push(20);
        q.push(30);
        q.printMyQueue();

        MyQueue::ListNode* nodePtr;
        nodePtr = q.pop();
        cout << "poped node= " << nodePtr->value << endl;
        q.printMyQueue();

        nodePtr = q.pop();
        cout << "poped node= " << nodePtr->value << endl;
        q.printMyQueue();

        nodePtr = q.pop();
        cout << "poped node= " << nodePtr->value << endl;
        q.printMyQueue();

        return 0;
}
~  
