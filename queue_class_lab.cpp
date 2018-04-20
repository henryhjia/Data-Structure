#include <iostream>
#include "queue_class.h"

using namespace std;

int main() {

    MyQueue q;

    int value = 0;
    char ch = 'q';
    MyQueue::ListNode* nodePtr;

    do {

        cout << "a - push" << endl;
        cout << "d - pop" << endl;
        cout << "p - print" << endl;
        cout << "q - quit" << endl;

        cin >> ch;
        cout << "ch=" << ch << endl;

        switch (ch) {

            case 'a':
                cout << "Enter an integer to push to queue:" << endl;
                cin >> value;
                q.push(value);
                break;

            case 'd':
                cout << "pop a queue" << endl;
                nodePtr = q.pop();
                cout << "poped node= " << nodePtr->value << endl;
                cout << "delte the poped node=" << nodePtr << endl;
                delete nodePtr;
                break;

            case 'p':
                cout << "print queue" << endl;
                q.print();
                break;

            case 'q':
                cout << "quit" << endl;
                break;

            default:
                cout << "invalid entry" << endl;
            }

        } while (ch != 'q');                        

        return 0;
}
~  
