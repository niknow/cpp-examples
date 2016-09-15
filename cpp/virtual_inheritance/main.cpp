#include <cstdlib>
#include <iostream>

/* In diamond shaped inhericance like this

               base
              /   \
             /     \
       derived1    derived2
             \     /
              \   /
             derived3

    an object of type derived3 inherits two versions of base:
    one via derived1 and one via derived2. This can cause ambiguities.
    By using virtual inhericance this ambiguity is avoided.

*/

class base {
  public:
    int i;
};

/* --------------------------------
   non-virtual inheritance
   ------------------------------- */
class derived1 : public base {
  public:
    int j;
};
class derived2 : public base {
  public:
    int k;
};
class derived3 : public derived1, public derived2 {
  public:
    int sum;
};

/* --------------------------------
   virtual inheritance
   -------------------------------- */
class derivedv1 : virtual public base {
  public:
    int j;
};
class derivedv2 : virtual public base {
  public:
    int k;
};
class derivedv3 : virtual public derivedv1, virtual public derivedv2 {
  public:
    int sum;
};

int main(int argc, char *argv[])
{
    derived3 ob1;
    derivedv3 ob2;

    // ob1.i = 10;  Would throw an error, since there are two bases in ob1.
    ob1.derived1::i = 10;  // Uses the base of derived1.
    ob1.derived2::i = 20;  // Uses base of derived2.

    ob2.i = 10; // This causes no problem, since 'virtual' enforces that only one base is present.

    return EXIT_SUCCESS;
}

/* --------------------------------
   HINT
   --------------------------------
   These problems with diamond inheritance can be avoided
   by avoiding diamond shaped class hierachies.

   */
