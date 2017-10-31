#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <array>
#include <vector>

using namespace std;

int main()
{
	  ofstream myfile;
	  myfile.open("example.txt");
	  const int mysize=10;
	  int num;

	  for (int i = 0; i < mysize; i++) {
		    num = rand() % 100;
		    myfile << num << endl;
	  }

	  myfile.close();

	  ifstream myfile1;
	  myfile1.open("example.txt");
	  string line;
	  array<int, mysize> myarray;
	  vector<int> myvector;
	  int j = 0;

	  // read data from file
	  if (myfile1.is_open())
	  {
		    while (getline(myfile1, line))
		    {			
			      num = stoi(line);
			      myarray[j] = num;
			      myvector.push_back(num);
			      j++;
		    }
		    myfile1.close();
	  }

	  char ch;
	  cout << "Do you want to print array and vector? y/n ";
	  cin >> ch;

  	  if (ch == 'y') {
		    cout << "print data" << endl;	
		    // iterator

		    cout << "array: " << endl;
		    array<int, mysize>::const_iterator iter;
		    iter = myarray.cbegin();
		    while (iter != myarray.cend()) {
			      cout << *iter++ << " ";
		    }
		    cout << endl;

		    cout << "vector:" << endl;
		    vector<int>::const_iterator viter;
		    viter = myvector.cbegin();
		    while (viter != myvector.cend()) {
			      cout << *viter++ << " ";
		    }
		    cout << endl;
	  }
	  system("pause");
}     
     
