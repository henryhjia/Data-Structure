#include <iostream>
#include "queue_derived.h"

using namespace std;

int main() {
        cout << "hello" << endl;
        
        MyQueue q;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.print();

        q.dequeue();
        q.print();

        q.dequeue();
        q.print();

        q.dequeue();
        q.print();

        return 0;
}
