#include <iostream>

/* In C++03 a class can have multiple constructors, but constructors cannot call each other.
   This has been improved in C++11 by using the delegation principle.
*/

// This defines the interface
class Foo {
public:
    Foo();
    Foo(int x);
    int x_;
};


// This implements the interface
Foo::Foo(int x) {
    x_ = x;
}

// this constructor delegates to the first one
Foo::Foo() : Foo(42) {}     // notice that the constant is in the implementation! 
                            // (unlike default parameters, which are in the interface)


int main(int argc, char* argv[]) {
    Foo a;
    Foo b(3);
    
    std::cout << a.x_ << std::endl;
    std::cout << b.x_ << std::endl;

    return EXIT_SUCCESS;
}
