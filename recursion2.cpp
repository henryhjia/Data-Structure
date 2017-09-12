#include <iostream>
using namespace std;

/* Result:
1
number=12 result=2
number=123 result=3
number=1234 result=4
number=12345 result=5
*/

// recursive function
void write_vertical(unsigned int number) {
    if(number < 10) {
        cout << number << endl;
    }
    else {
        write_vertical(number/10);
        cout << "number=" << number << " result=" << number % 10 << endl;
    }
}

//

int main() {
    unsigned int a= 12345;
    write_vertical(a);
}
