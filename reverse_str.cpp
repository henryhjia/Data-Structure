// result
//
// yrneh

#include <iostream>

using namespace std;

void rev_string(string me) {
    if(me.length() > 0) {
        rev_string(me.substr(1));
        cout << me[0];
    }
}

int main() {
  rev_string("henry");
}
