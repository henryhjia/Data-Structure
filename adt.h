#ifndef __MYLIST_
#define _MYLIST_
// adt.h
MyList
{
    public:
	MyList();
	void insertNode(int val);
	void deleteNode(int val);
	void printMyList();
	bool searchNode(int val);
	bool isEmpty();
	void insertHead(int val);
	void deleteTail();
	void deleteHead();
	
    private:
	struct ListNode {
	    int value;
    	    ListNode* next;
	};
	
	ListNode* head;
};

#endif
