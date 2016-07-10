#include <cstdlib>
#include <iostream>

/* A derived class can inherit from multiple base classes. */

class base1 {
  public:
    int x;
    int myfun() { return 1; }
    base1() { std::cout << "Constructing base 1" << std::endl; }
    ~base1() { std::cout << "destryoing base 1" << std::endl; }
};

class base2 {
  public:
    int y;
    /* int myfun() { return 2; }  If you would add this, myfun would
       will be ambiguous in derived class and programm wouldn't compile. */
    base2() { std::cout << "Constructing base 2" << std::endl; }
    ~base2() { std::cout << "Destryoing base 2" << std::endl; }
};

class derived : public base1, public base2 {
  public:
    derived() { std::cout << "Constructing derived." << std::endl; }
    ~derived() { std::cout << "Destryoing derived." << std::endl; }
};

int main(int argc, char *argv[])
{
    derived d;

    d.x = 7;  // Setting a member variable inherited from base 1.
    d.y = 8;  // Setting a member variable inherited from base 1.
    std::cout << d.myfun() << std::endl;

    return EXIT_SUCCESS;
}
