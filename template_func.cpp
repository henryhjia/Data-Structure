#include <iostream>

using namespace std;

template <class T>
T mymax(T i, T j)
{
	if (i > j) { return i; }
	else return j;
}


template <class T>
void swap(T& a, T& b) 
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    auto a=10;
    auto b=20;
    auto c = mymax(a,b);
    cout << "max=" << c << endl;
    
    auto x=4.5;
    auto y=4.6;
    auto z = mymax(x,y);
    cout << "max=" << z << endl;
}
