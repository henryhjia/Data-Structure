#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

int* createArray(int);
void copyArray(int*, int*);
void freeArray(int*);
void printArray(int*);

int main() {       
    int array[] = {1,2,3,4,5,6,7,8,9,10};    
    int *new_array = nullptr;
    
    new_array = createArray(10);
    copyArray(new_array, array);
    printArray(new_array);
    freeArray(new_array);
    
    return EXIT_SUCCESS;
}

int* createArray(int size) {    
    int *newArray = new int [size];   
    
    int* henry = new int[3] {10,9,8}; // has to have the size of the array
    
    //char *array = new char[14] { "Hello, world!" }; C++14 will work
    return newArray;
}

void copyArray(int *new_array, int *array) {
    for(int i=0; i<10; i++) {
        new_array[i] = array[i];
    }    
}

void freeArray(int* new_array) {
    delete [] new_array;
}

void printArray(int* arr) {
    for(int i=0; i<10; i++) {
        cout << *(arr+i) << " ";
    }
    cout << endl;
}
