#include <iostream>
#include "stack_derived.h"

using namespace std;

int main() {

    MyStack s;

    int value = 0;
    char ch = 'q';
    MyStack::ListNode* nodePtr;

    do {

        cout << "a - push" << endl;
        cout << "d - pop" << endl;
        cout << "p - print" << endl;
        cout << "q - quit" << endl;

        cin >> ch;
        cout << "ch=" << ch << endl;

        switch (ch) {

            case 'a':
                cout << "Enter an integer to push to stack:" << endl;
                cin >> value;
                s.push(value);
                break;

            case 'd':
                cout << "pop a stack" << endl;
                nodePtr = s.pop();
                cout << "poped node= " << nodePtr->value << endl;
                cout << "delte the poped node=" << nodePtr << endl;
                delete nodePtr;
                break;

            case 'p':
                cout << "print stack" << endl;
                s.print();
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
