#include "bag.h"

Bag::Bag(int s) {
    used = s;
    for(int i=0; i<used; i++) {
        data[i] = i;
    }
}
