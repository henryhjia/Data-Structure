#include <iostream>

using namespace std;
// binary tree data structure
struct TreeNode {
	  int value;
	  TreeNode *left;
	  TreeNode *right;
};

TreeNode *root = nullptr;

void PreOrder(TreeNode *nodePtr) {
	  if (nodePtr != nullptr) {
		  cout << nodePtr->value << endl;
		  PreOrder(nodePtr->left);
		  PreOrder(nodePtr->right);
	  }
}

void PostOrder(TreeNode *nodePtr) {
	  if (nodePtr != nullptr) {
		  PostOrder(nodePtr->left);
		  PostOrder(nodePtr->right);
		  cout << nodePtr->value << endl;
	  }
}

void InOrder(TreeNode *nodePtr) {
	  if (nodePtr != nullptr) {
		  InOrder(nodePtr->left);
		  cout << nodePtr->value << endl;
		  InOrder(nodePtr->right);
	  }
}

void printNode() {
	  int val;
	  cout << "Please select traversing method " << endl;	
	  cout << "1-preOrder\n2-postOrder\n3-InOrder\n";
	  cin >> val;

	  switch (val) {
	  case 1:
		  PreOrder(root);
		  break;
      
	  case 2:
		  PostOrder(root);
		  break;

	  case 3:
		  InOrder(root);
		  break;

	  default:
		  cout << "invalid" << endl;
		  break;
	  }
}

// binary tree insert
// NOTE: Must passing TreeNode *& nodePtr to update root node
void insert(TreeNode *&nodePtr, TreeNode *newNode) {
	cout << "nodePtr=" << nodePtr << " newNode=" << newNode << " root=" << root 
        << " *** just entered insert() ***" << endl;
	if (nodePtr == nullptr) {
		nodePtr = newNode;
        	cout << "nodePtr=" << nodePtr << " root=" << root << endl;
	}
	else if (newNode->value < nodePtr->value) {
        	cout << "nodePtr=" << nodePtr << " nodePtr->left=" << nodePtr->left <<  " root=" << root 
             	     << " *** before insert ***" << endl;
		insert(nodePtr->left, newNode);
        	cout << "nodePtr=" << nodePtr << " nodePtr->left=" << nodePtr->left << " root=" << root 
             	     << " *** after insert" << endl;
	}
	else if (newNode->value > nodePtr->value) {
		insert(nodePtr->right, newNode);
	}	  
}

void insertNode(int num) {
	  TreeNode *newNode;
	  newNode = new TreeNode;
	  newNode->value = num;
	  newNode->left = nullptr;
	  newNode->right = nullptr;
    	  cout << "New node created=" << newNode << endl;
    
	  if (root != nullptr)
		  cout << "value inserted=" << num << " root=" << root << " root val=" << root->value << endl;
	  else
		  cout << "value inserted=" << num << " root=nullptr" << endl;

	  insert(root, newNode);
    	  cout << "After insert, root=" << root << " root value=" << root->value << endl;
}

// Binary tree
void binary_tree() {
    int num;
	  char ch;

	  do {
		  cout << "i-insert\nd-delete\np-print\nq-quit\n";
		  cin >> ch;

		  switch (ch) {

		  case 'i':
			  cout << "please enter a value to be inserted: " << endl;
			  cin >> num;
			  insertNode(num);
			  break;

		  case 'd':
			  break;

		  case 'p':
			  printNode();
			  break;

		  case 'q':
			  break;

		  default:
			  cout << "invlid " << endl;
			  break;
		  }
	  } while (ch != 'q');
    
    return;
}

int main() {
    binary_tree();
}
