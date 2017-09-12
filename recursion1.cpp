#include <iostream>
using namespace str;

// Recursion
//
// Result:
/* 
(1) i=5
(1) i=4
(1) i=3
(1) i=2
(1) i=1
before showRecursion return
(2) i=0
before showRecursion return
(2) i=1
before showRecursion return
(2) i=2
before showRecursion return
(2) i=3
before showRecursion return
(2) i=4
before showRecursion return
*/

void showRecursion(int i) {
	  if (i > 0) {
		cout << "(1) i=" << i << endl;
		i--;
		showRecursion(i);
		cout << "(2) i=" << i << endl; // remember last location
    }
    cout << "before showRecursion return" << endl;
}

int main() {
    int i=5;
    showRecursion(i);
}


