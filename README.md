# Data-Structure
CIS-2542-004 Advanced C++ with Data Structure

#Note on constructor
A constructor that takes no parameters (or has parameters that all have default values) is called a default constructor.
e.g. Student s;
There is no such thing as:  Student s();

If your class has no other constructors, C++ will automatically generate a public default constructor for you. This is sometimes called an implicit constructor (or implicitly generated constructor).

If your class has any other constructors, the implicitly generated constructor will not be provided.

If a constructor takes argument and each argument has a default value, then this constructor can be used as default constructor when no argument is given:

e.g. 
class Student {
public:
    Student(string name="None", int age=20, char gender = ' ');
private:
    string name;
    int age;
    char gender;
};
     Student s; // default constructor
or 
     Student("John", 30, 'm');  // regular constructor
     
