#include <cstdlib>
#include <iostream>

/* A derived class can inherit from multiple base classes. */

class base1 {
public:
    int x = 0;
    int f() { return 1; }
    int h() { return 2; }
    base1()  { std::cout << "Constructing base1." << std::endl; }
    ~base1() { std::cout << "Destryoing base1." << std::endl; }
};

class base2 {
public:
    int y = 1;
    int g() { return 3; }
    int h() { return 4; }
    base2() { std::cout << "Constructing base2" << std::endl; }
    ~base2() { std::cout << "Destryoing base2" << std::endl; }
};

class derived : public base1, public base2 {        // Has all the members of base1 and base2, even h, which is ambiguous.
public:
    derived()  { std::cout << "Constructing derived." << std::endl; }
    ~derived() { std::cout << "Destryoing derived." << std::endl; }
};

int main(int argc, char* argv[])
{
    derived d;

    d.x = 7;                                 // Setting a member variable inherited from base 1.
    d.y = 8;                                 // Setting a member variable inherited from base 2.
    std::cout << d.f() << std::endl;         // The member function name f is unambiguous, so it can be called directly.
    std::cout << d.g() << std::endl;         // The member function name g is unambiguous, so it can be called directly.
  //std::cout << d.h() << std::endl;         // This would through an error as h is ambiguous (defined in base1 and base2).
    std::cout << d.base1::h() << std::endl;  // The solution is to use scope resolution to resolve the ambiguity.
    std::cout << d.base2::h() << std::endl;
    std::cout << d.base1::f() << std::endl;  // It is not forbidden to use scope resolution explicitly even when it is not required.
    return EXIT_SUCCESS;
}

