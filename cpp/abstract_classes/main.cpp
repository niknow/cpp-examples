#include <cstdlib>
#include <iostream>

/* A function is called purely virtual if it has no implementation
  in the base class. A base class is called abstract if it has at
  least one purely virtual function. It is not possible to 
  instantiate an object from an abstract class. However, an abstract
  class can serve as a blueprint for derived classes, which are
  not abstract. Abstract classes are useful for building class 
  libraries. */


class base {    // This will be an abstract class.
  public:
    virtual void vfun() = 0;  // The '=0' defines this function as purely virtual.
};


class derived : public base { // This class will not be abstract.
  public:
    void vfun(){ std::cout << "derived.vfun" << std::endl; } // Virtual function is implemented in derived class.
};

int main(int argc, char *argv[])
{
    // base b;  This would throw an error. It is not possible to declare objects of type base, because base is abstract.
    base *p;    // However, one can declare a pointer to an abstract class.
    derived d;  // Since derived is not abstract, we can instantiate an object.

    p = &d;    // Points to d now.
    p->vfun(); // This will call derived.vfun.

    return EXIT_SUCCESS;
}
