#include <iostream>

using namespace std;

void print_array(int n, int* a) {
    for(int i=0;i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertionSort(int ar_size, int *  ar) {
    int item;
    
    for(int i=1; i< ar_size; i++) {
        item = ar[i];               
        for(int j=0; j< i; j++) {           
            if(ar[j] > item ) {                
                for(int k=i; k>j; k--) {
                    ar[k] = ar[k-1];                        
                }
                ar[j] = item;
                break;
            }            
        }  
        print_array(ar_size, ar);
    }      
}


int main(void) {
   
    int ar_size;
    cin >> ar_size;

    int ar[ar_size], i;
    for(i = 0; i < ar_size; i++) { 
        cin >> ar[i];       
    }

   insertionSort(ar_size, ar);
   
   return 0;
}
