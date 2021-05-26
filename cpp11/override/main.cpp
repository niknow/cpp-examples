#include <iostream>

/* In C++03 one can use virtual functions, which are often overriden in
   derived classes. However, this only works if the signatures match exactly
   and if they don't a new function is created. This problem can be avoided
   by using the override keyword in C++11.
   The final keyword also prevents functions from being overriden down the 
   class hierarchy.
*/

class Base {
public:
    virtual bool f(int x) { return true; }
    virtual int g() { return 1; }
    virtual int h() { return 2; }
};

class Derived : Base {
public:
    virtual bool f(float x) { return false; }   // this does not override due to a slight mismatch in the signature
    virtual int g() { return 2; }               // this overrides and will throw an error if signatures do not match
    virtual int h() final { return 3; }         // this prevents h from being overriden in derived classes
};

class DDerived : Derived {
public:
    //virtual int h() { return 4; }             // this would throw an error
};


int main(int argc, char* argv[]) {

    Base b;
    Derived d;

    std::cout << b.f(0) << " " << b.g() << " " << b.h() << std::endl;
    std::cout << d.f(0) << " " << d.g() << " " << d.h() << std::endl;

    return EXIT_SUCCESS;
}
