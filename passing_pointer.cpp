#include <iostream>

// pass by reference or value
// void func(int* p, int v) - passing by value
// void func(int*& p, int v) - passing by reference
// Note:
// If passing a pointer to a function, any changes to the value the pointer points to 
// will be carried out in calling function; whereas any changes to the pointer itself
// will not be effected in calling function.
// 
// Output: (passing int*&)
// ptr before=0x7ffd1c341e14 value=10
// ptr inside func=0x7ffd1c341e14 &gi=0x6060d0
// ptr inside func(1)=0x6060d0 value=20
// ptr inside func(2)=0x6060d0 value=50
// ptr after =0x6060d0 value=50 gi=50
//

int gi = 20;

void func(int*& p, int v) {
	cout << "ptr inside func=" << p << " &gi=" << &gi << endl;
	//p = &v;
    	//p = new int;
    	p = &gi;    
	cout << "ptr inside func(1)=" << p << " value=" << *p << endl;
    	*p = 50;
    	cout << "ptr inside func(2)=" << p << " value=" << *p << endl;
}

// Output (passing int*)
// ptr before=0x7ffcf33a8dbc value=10
// ptr inside func=0x7ffcf33a8dbc &gi=0x6060d0
// ptr inside func(1)=0x6060d0 value=20
// ptr inside func(2)=0x6060d0 value=50
// ptr after =0x7ffcf33a8dbc value=10 gi=50
//
void func(int* p, int v) {
	cout << "ptr inside func=" << p << " &gi=" << &gi << endl;
	//p = &v;
    	//p = new int;
    	p = &gi;    
	cout << "ptr inside func(1)=" << p << " value=" << *p << endl;
    	*p = 50;
    	cout << "ptr inside func(2)=" << p << " value=" << *p << endl;
}

int main() {
    	int val = 10;
    	int *ptr = &val;
    
    	cout << "ptr before=" << ptr << " value=" << *ptr << endl;
    	func(ptr, val);
    	cout << "ptr after =" << ptr << " value=" << *ptr << " gi=" << gi << endl;    
    
    	return EXIT_SUCCESS;
}

