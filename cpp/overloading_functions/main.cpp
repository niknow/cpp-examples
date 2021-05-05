#include <cstdlib>
#include <iostream>

/* In C++ functions are more powerful. They can be overloaded and their
   parameters can have default arguments. */

// Default arguments can be specified after positional arguments like this.
int add_inc(int a, int b = 5) {
    return a + b;
}

// When separating declaration from definition, default arguments have to be set in declaration only
int sub_dec(int a, int b = 1);

int sub_dec(int a, int b) {
    return a - b;
}

// Functions are overloaded by defining a function with the same name, but different signatures.
int myfun(int a, int b) {
    return a + b;
}
int myfun(int a) {   // The name has to be equal, the prototype has to be different.
    return a * 3;
}

// The type of 'number' determines which argument gets called.
void print_number(int number) {
    std::cout << "Printing integer: " << number << std::endl;
}
void print_number(double number) {
    std::cout << "Printing double: " << number << std::endl;
}

// The constructor of an object is a function, which is often overloaded.
class MyObject {
public:
    int x;
    MyObject(int val) { x = val; }              // Constructor with parameter.
    MyObject() { x = 0; }                       // Overloaded constructor without parameter.
    MyObject(const MyObject& o) { x = o.x; }    // This is called a 'copy constructor'.
};


int main(int argc, char* argv[]) {
    std::cout << "add_inc(2): " << add_inc(2) << std::endl;          // Prints '7'.
    std::cout << "add_inc(2,3): " << add_inc(2, 3) << std::endl;     // Prints '5'.

    std::cout << "sub_dec(5): " << sub_dec(5) << std::endl;          // Prints '4'.
    std::cout << "sub_dec(5, 3): " << sub_dec(5, 3) << std::endl;    // Prints '2'.

    std::cout << "myfun(2,3): " << myfun(2, 3) << std::endl;         // Prints 5.
    std::cout << "myfun(10): " << myfun(10) << std::endl;            // Prints 30.

    int a = 7;
    double b = 9.234;
    print_number(a);    // Prints 'Printing integer 7'.
    print_number(b);    // Prints 'Printing double 9.234.'
    // When using this be aware of automatic type casts.

    // Overloads and function pointers behave nicely:
    int (*fp) (int a);
    fp = myfun;         // Points to the one with 1 parameter.

    // Overloaded constructors allow a more flexible construction of an object.
    MyObject A;         // Uses constructor without a parameter.
    MyObject B = 7;     // Uses constructor with a parameter.
    MyObject C = B;      // Uses copy constructor.
    std::cout << "C.x: " << C.x << std::endl; // Prints '7'.

    return EXIT_SUCCESS;
}

/*
    REMARK
    Overload resolution takes into account the function signature, i.e.
    1. the function name
    2. the const/volatile qualifiers 
    3. parameter types

    The return type is not relevant.
*/