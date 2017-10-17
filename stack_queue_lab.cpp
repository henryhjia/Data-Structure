#include "stack.h"
@include "queue.h"

using namespace std;

int main()
{
	  MyStack s;
	  s.push(10);
	  s.push(20);
	  s.push(30);
	  s.printMyList();
	  s.pop();
	  s.printMyList();
	  s.pop();
	  s.printMyList();
	  s.pop();
	  s.printMyList();

	  MyQueue q;
	  q.enqueue(10);
	  q.enqueue(20);
	  q.enqueue(30);
	  q.printMyList();

	  q.dequeue();
	  q.printMyList();
	
	  q.dequeue();
	  q.printMyList();

	  q.dequeue();
	  q.printMyList();
	
	  system("pause");
	  return 0;
}
