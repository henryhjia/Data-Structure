#include "listADT.h"
#include <iostream>
using namespace std;

int main()
{
	char ch = 'q';
	int val;
	ListNode ml;
	bool flag;

	do {
		
		cout << "i -- insert in the middle ... \n";
		cout << "d -- find & delte ...\n";
		cout << "p -- print ... \n";
		cout << "s -- search ... \n";
		cout << "f -- empty ... \n";
		cout << "q -- quit ... \n";

		cin >> ch;

		
		switch (ch)
		{
			
		
		
		case 'i': cout << "inserting in the middle ..." << endl;
			cout << "enter an integer ";
			cin >> val;
			ml.insertNode(val); // void return type
			break;
		
		case 'd': cout << "deleting ... " << endl;
			cout << "enter a value to be deleted ";
			cin >> val;
			ml.deleteNode(val); // void return type
			break;
		
		case 'p': cout << "printing ... " << endl;
			ml.printMyList(); // void return type
			break;

		case 's':
			cout << "enter a value to be searched \n";
			cin >> val;
			flag = ml.searchNode(val); // bool return type
			if (flag) {
				cout << "node found" << endl;
			}
			else { cout << "node not found" << endl; }
			break;

		case 'f':
			flag = ml.isEmpty(); // bool return type
			if (flag) cout << "not empty" << endl;
			else { cout << "empty" << endl; }
			break;

		case 'q': cout << "quitting ... " << endl;
			break;

		default:
			cout << "Invalid entry" << endl;
			break;
		}
	} while (ch != 'q');

	system("pause");
	return 0;
}
