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


template <class T>
class MyClass 
{
    private:
        T a;
    
    public:
        MyClass(T b) {
            a = b;
        }
    
        T get_myvalue() { return a;}
};


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
	
    string s1="David";
    string s2="John";
    string s = mymax(s1,s2);
    cout << "max=" << s << endl;
	
    MyClass<string> m1("Edward");
    cout << "value=" << m1.get_myvalue() << endl;
    
    MyClass<int> m2(100);
    cout << "value=" << m2.get_myvalue() << endl;
	
}
