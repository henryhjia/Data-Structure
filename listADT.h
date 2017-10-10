#ifndef _LISTADT_H_
#define _LISTADT_H_


class ListNode {

public:
	ListNode();
	ListNode(int num);
	~ListNode();

	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void printMyList();
	bool searchNode(int);
	bool isEmpty();

private:
	int value;
	ListNode *next;
	ListNode *head;
};

#endif
