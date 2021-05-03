#include <cstdlib>
#include <iostream>

/* Inheritance is one of the most fundamental concepts in OOP. It allows to
   implement a fairly general base class and then derive more specialized
   versions of it. The members of the base class can have the three
   access modifiers 'private', 'proteced' and 'public' (private is the default).
   Inheritance has three types of visibility also called 'private',
   'protected' and 'public' (private is default). This example studies
   how the different access modifier behave under the different types of
   inheritance. */

class base {
public:
    int x;                      // Visible from inside and outside the class.
    base() { x = 1; y = 2; z = 3; }
protected:                      // Only visible in classes that inherit from base.
    int y;
private:                        // Only visible in base class.
    int z;
};

// This is a derived class.
class dpub : public base {      // Inheritance of type 'public'.
    // x is public.
    // y is protected.
    // z is not accessible from dpub.
public:
    void showx() { std::cout << "dpub.x: " << x << std::endl; }
    void showy() { std::cout << "dpub.y: " << y << std::endl; }
};

class dprot : protected base {  // Inheritance of type 'protected'.
  // x is protected.
  // y is protected.
  // z is not accessible from dprot.
public:
    void incy() { y++; }        // Derived class has access to base class' protected members.
};

class dpriv : private base {    // Inheritance of type 'private' (this is the default if nothing is specified).
    // x is private.
    // y private.
    // z is not accessible from dpriv.

};


int main(int argc, char* argv[]) {
    base b;
    dpub d1;
    dprot d2;
    dpriv d3;

    std::cout << "b.x = " << b.x << std::endl;  // b.y or b.z would cause an error.

    d1.showx();                                 // Can all be called from outside the class.
    d1.showy();

    d2.incy();

    // d3.x, d3.y, d3.z are not accessible from outside the class.

    return EXIT_SUCCESS;
}

/*                     S U M M A R Y

 Inheritance type     Access in base     Acess in derived

     public            protected     ->    protected
                       public        ->    public

     protected         protected     ->    protected
                       public        ->    protected

     private           protected     ->    private
                       public        ->    private

*/