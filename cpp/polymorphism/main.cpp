#include <cstdlib>
#include <iostream>

/* Polymorphism is one of the most powerful features of OOP. In short,
   it means that a pointer that points to a derived class is
   type-compatible with a pointer to its base class. This works
   particularly well in conjunction with virtual functions. */


class base {
public:
    void nfun()          { std::cout << "base.nfun" << std::endl; }    // This is a normal function.
    virtual void vfun()  { std::cout << "base.vfun" << std::endl; }    // This is a virtual function.
    virtual void vfun2() { std::cout << "base.vfun2" << std::endl; }   // This is a virtual function.
};

class derived : public base {
public:
    void nfun() { std::cout << "derived.nfun" << std::endl; }          // Overwrites base.nfun.
    void vfun() { std::cout << "derived.vfun" << std::endl; }          // Reimplemented in derived, automatically virtual too.
    // vfun2() just stays virtual from base
};

class dderived : public derived {
public:
    void vfun2() { std::cout << "dderived.vfun2" << std::endl; }       // Ovewrites vfun2 from base.
};

// base class can be passed by reference, yet function still accepts derived objects
void callvfun(base& b) {
    b.vfun();
}

int main(int argc, char* argv[])
{
    base b;
    derived d;
    dderived dd;
    base* pb;     // This is a pointer to base type.

    std::cout << "Base pointer to base class: " << std::endl;
    pb = &b;
    pb->nfun();   // This calls base::nfun.
    pb->vfun();   // This calls base::vfun.
    pb->vfun2();  // This calls base::vfun2.
    std::cout << std::endl;

    std::cout << "Base pointer to derived class: " << std::endl;
    pb = &d;      // Now p points to d. Although p was declared as pointer to base this is possible.
    pb->nfun();   // This calls base::nfun because pb is of type base* and nfun is a normal function.
    pb->vfun();   // This calls derived::vfun because vfun is virtual.
    pb->vfun2();  // Still calls base::vfun2 because it was not reimplemented in derived.
    std::cout << std::endl;

    std::cout << "Derived pointer to derived class: " << std::endl;
    derived* pd = &d;
    pd->nfun();   // This calls derived::nfun because pd is of type derived* and nfun is a normal function.
    pd->vfun();   // This calls derived::vfun because vfun is virtual.
    pd->vfun2();  // Still calls base::vfun2 because it was not reimplemented in derived.
    std::cout << std::endl;

    std::cout << "Base pointer to dderived class: " << std::endl;
    pb = &dd;
    pb->nfun();   // Calls derived::nfun.
    pb->vfun();   // Calls derived::vfun because vfun is virtual.
    pb->vfun2();  // Calls dderived::vfun2 because vfun2 is virtual.
    std::cout << std::endl;

    std::cout << "DDerived pointer to dderived class: " << std::endl;
    dderived* pdd = &dd;
    pdd->nfun();   // Calls derived::nfun as this was defined last in the hierarchy in derived.
    pdd->vfun();   // Calls derived::vfun because vfun is virtual.
    pdd->vfun2();  // Calls dderived::vfun2.
    std::cout << std::endl;

    std::cout << "Pass by reference: " << std::endl;
    callvfun(d); // will call derived.vfun

    return EXIT_SUCCESS;
}
