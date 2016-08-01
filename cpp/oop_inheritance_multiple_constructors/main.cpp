#include <cstdlib>
#include <iostream>

/* When a class inherits from multiple base classes, its constructor might have to call
   the constructors of the base classes. This example illustrates how to do this using
   a MIL (member initialization list). */

class base1 {
  public:
    int x;
    base1(int val){ x = val; }  // Constructor has a parameter x.
};

class base2 {
  public:
    int y;
    base2(int val){ y = val; } // Constructor has a parameter y.
};

class derived : public base1, public base2 {
  public:
    int z;
    // Constructor calls base constructors via MIL.
    derived(int valx, int valy, int valz): base1(valx) , base2(valy) {z = valz;}
};

int main(int argc, char *argv[])
{
    derived d(1,2,3);
    std::cout << d.x << d.y << d.z << std::endl;

    return EXIT_SUCCESS;
}
