#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>


class Bag {
    public:
    Bag() { used=0;}
    Bag(int s);
    static const int CAPACITY = 10;
    void show_array() {
        for (int i=0; i<used; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    bool erase(const int& target) {
        int index;
        index = 0;
        while((index < used) && (data[index] != target))
            ++index;
        
        if(index == used)
            return false;
        
        //--used;
        //cout << "index=" << index << " used=" << used << endl;
        data[index] = data[--used];
        return true;
        
    }   
    
    void operator +=(Bag& addend) {
        assert(size() + addend.size() <= CAPACITY);   
        
        copy(addend.data, addend.data + addend.used, data + used);
        used += addend.used;
    }
    
    int size() const { return used;}
    
    private:
        int data[CAPACITY];
        int used;
};
