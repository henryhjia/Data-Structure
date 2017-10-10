// adt.h

struct ListNode {
    int value;
    ListNode* next;
};

MyList
{
	public:
		MyList();
		void insertNode(int val);
		void deleteNode(int val);
		void printMyList();
		bool searchNode(int val);
		bool isEmpty();
		
	private:
	
		ListNode* head;

};