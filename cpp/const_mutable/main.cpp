#include <iostream>
/* A derived class can inherit from multiple base classes. */

class A {
public:
    int x_ = 0;
    mutable int y_ = 1;                 // can be changed even on const instances of A
    int get_x() const { return x_; };   // a const function does not change any of the members of A
    int set_x(int x) { x_ = x; };
};


int main(int argc, char* argv[])
{
    // CONSTANT VARIABLES
    int a = 1;                // this is an integer, which is non-const, i.e. it can be changed later
    a = 2;                    // this is legit
    const int b = 7;          // declaring a variable as const means that it has to be initalized on declaration and can never change
    // b = 8;                 // this would throw an error
    int const b1 = 8;         // the const can be on either side of the type: int const == const int
    int* p = &a;              // this is a non-const pointer to a
    //p = &b;                 // this would throw an error: a pointer to int cannot point to a const int
    int const* q = &a;        // pointer to a const int: the pointer can be changed, but the int cannot
    q = &a;                   // pointer to a const int can be changed even to point at a non-const int
    //*q = 8;                 // would throw an error as q is a pointer to a const int (even when given the address of an int initiall declared non-const)
    int* const r = &a;        // this is a const pointer to int
    //r = &b;                 // would throw an error: we cannot change to what r points to
    int const * const s = &a; // const pointer to a const int
    // *s = 9;                // would throw an error as we are pointing to a const int
    // s = &b;                // would throw an error as s is a const pointer

    // CONSTANT OBJECTS
    const A o;                // does not allow any value in A to be changed (except mutables)
    // o.x_ = 1;              // this would throw an error
    o.y_ = 2;                 // this is legit as y_ has been declared mutable


    return EXIT_SUCCESS;
}

/*  REMARKS
    There are various tricks to memorize the const/pointer behavior:
    * For variable declaration, just read from right to left (special case of spiral rule).
    * Split the declaration at the '*': If const is left of it, it refers to the data, 
      if it is right of it, it refers to the pointer.
    * https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
*/
