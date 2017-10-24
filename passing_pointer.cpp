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

//e.g. 2:
void func(int*& p, int v) {
	cout << "ptr inside func=" << p << endl;	
    	p = new int;    
	cout << "ptr inside func(1)=" << p << " value=" << *p << endl;
    	*p = 55;
    	cout << "ptr inside func(2)=" << p << " value=" << *p << endl;
}
// e.g. 2 output:
// ptr before=0x7ffcda7b599c value=10
// ptr inside func=0x7ffcda7b599c
// ptr inside func(1)=0x1676c30 value=0
// ptr inside func(2)=0x1676c30 value=55
// ptr after =0x1676c30 value=55
	

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

// e.g. 2:
void func(int* p, int v) {
	cout << "ptr inside func=" << p << endl;	
    	p = new int;    
	cout << "ptr inside func(1)=" << p << " value=" << *p << endl;
    	*p = 55;
    	cout << "ptr inside func(2)=" << p << " value=" << *p << endl;
}

// e.g. 2. output:
// ptr before=0x7ffc8d52c2f4 value=10
// ptr inside func=0x7ffc8d52c2f4
// ptr inside func(1)=0x1147c30 value=0
// ptr inside func(2)=0x1147c30 value=55
// ptr after =0x7ffc8d52c2f4 value=10
	

int main() {
    	int val = 10;
    	int *ptr = &val;
    
    	cout << "ptr before=" << ptr << " value=" << *ptr << endl;
    	func(ptr, val);
    	cout << "ptr after =" << ptr << " value=" << *ptr << " gi=" << gi << endl;    
    
    	return EXIT_SUCCESS;
}

