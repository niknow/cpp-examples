#include <cstdlib>
#include <iostream>

/* References are a new C++ feature that simplifies 'call by reference'. */

void replace_by_square_pointer(int *a) { // Passing 'a' by reference using C-style.
    *a = *a * *a;   // This looks a bit confusing.
}

void replace_by_square_ref(int &a) { // Passing 'a' by reference using C++-style.
    a = a*a;    // This looks much better.
}


class ob1 {
 public:
  int x;
};

void set_ob1_x(ob1 &o) {   // Even objects can be passed by reference (very efficiently).
    o.x=7;  // Changes the object.
}

void print_ob1_value(const ob1 &o) { // Passed by const reference.
    std::cout << o.x << std::endl;
    //o.x = 7;  // Would not compile.
}

// Fuctions can also return a reference to something.
char s[20] = "Hello World";
char &replace(int n){  // Returns a reference to the n-th element of s.
    return s[n];
}


int main(int argc, char *argv[])
{
    int a=7;
    int &ref = a; // References have to be initialized on declaration.
    // Now 'ref' behaves exactly like 'a' (this is pretty useless here though).

    replace_by_square_pointer(&a); // Notice that '&' is neccessary here.
    std::cout << a << std::endl;

    replace_by_square_ref(a); // This is now a call by reference. No '&' sign here!
    std::cout << a << std::endl;

    ob1 o;  // Pass objects as references.
    set_ob1_x(o);
    print_ob1_value(o);

    /* A function that returns a reference has the rare property that it 
       is allowed to be on the left hand side of an assigment. */
    replace(5) = 'X'; // Now replace(5) is a reference to the 5-th element of s.
    std::cout << s << std::endl; // Gives 'HelloXWorld'.

    system("PAUSE");
    return EXIT_SUCCESS;
}


/*  SOME THOUGHTS/BEST PRACTICES ON THIS

    C-style vs. C++-style: 
      - Using references requires only one '&' sign in the function's prototype.
      - Using pointers requires an '&' everywhere the function is called.
      - Google's C++ guide suggests to use references for input parameters and
        pointers for output parameters (don't rely on this in other codebases though). 
      - If you want it to be possible to pass a nullpointer, you have to use pointers.

    Pointers vs. References:
      - References must be initalized on declaration (pointers can be uninitialized).
      - With pointers you can do pointer arithmetics, but not with references.
      - A pointer can be a nullpointer, but there is nothing like a 'nullreference'.

    Pass by value vs. pass by reference vs. pass by const reference:
      - Pass by value if the parameter is small (like int or double) and you 
        don't have to change its value in the function.
      - Pass by reference if the parameter is large (like an object) and you
        want to change its members in the function.
      - Pass by const reference if the parameter is large and you don't want to
        change its value in the function.
*/
