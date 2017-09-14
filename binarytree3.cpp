// use *& node as an argument of the recursive function call

#include <iostream>

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

void insertme2(TreeNode*& nod, int val) {
    if(nod == nullptr) {
        nod = new TreeNode;
        nod->value = val;
        nod->left = nullptr;
        nod->right = nullptr;
        cout << "node=" << nod << " *** new node created ***" << endl;
        return;
    } 
    else {
        TreeNode* cur;        
        if(val < nod->value) {
            cout << "node=" << nod << " node->left=" << nod->left << " ***bef insertme ***" << endl;
            insertme2(nod->left, val);
            cout << "node=" << nod << " *** aft insertme ***" << endl;
        }
        else {
            cout << "node=" << nod << " node->left=" << nod->right << " *** bef insertme ***" << endl;
            insertme2(nod->right, val);
            cout << "node=" << nod << " *** aft insertme ***" << endl;
        }          
    }
    return;
}

void deleteme(TreeNode*& root) {
    if(root != nullptr) {    
        deleteme(root->left);
        deleteme(root->right);
        delete root;
        root = nullptr;
    }
}

// Binary tree
void btree_insert() {
    int num;
	char ch;

	do {
		cout << "i-insert\nd-delete\np-print\nq-quit\n";
		cin >> ch;

		switch (ch) {

		case 'i':
			cout << "please enter a value to be inserted: " << endl;
			cin >> num;
           
        		insertme2(root, num);
        		cout << "root=" << root << endl;
                
			break;

		case 'd':
        		cout << "Delete all node of the tree" << endl;   
        		deleteme(root);
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
    btree_insert();  
}
