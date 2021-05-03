#include <cstdlib>
#include <iostream>

/* One often faces the problem that two functions conceptually
   do the same thing, but on different types of data. Because the
   type of the data has to be specified in the function prototype,
   one has no choice but to implement two functions (or use
   pre-processor macros). This yields to ugly code duplication.
   Templates are a mighty feature of C++ that provide a way out
   by allowing to define functions without specifying the type
   of the data in advance. */


   // A template function with one unknown data type X can be defined like this.
template <class X> void swapargs(X& a, X& b) {  // swaps these arguments regardless of the type
    X temp;
    temp = b;
    b = a;
    a = temp;
}

// Template functions can have multiple data types.
template <class X, class Y>                     // A newline here is possible and common for cosmetic reasons.
void printtuple(X a, Y b) {
    std::cout << a << " " << b << std::endl;
}

// Template functions can be overloaded for specific types.
template <> void printtuple<int, double>(int a, double b) {
    std::cout << "int: " << a << " " << "double: " << b << std::endl;
}

// Template functions can also be overloaded by the same mechanisms as normal functions can.
template <class X, class Y, class Z>
void printtuple(X a, Y b, Z c) {
    std::cout << a << " " << b << " " << c << std::endl;
}

int main(int argc, char* argv[])
{
    int a = 2, b = 3;
    swapargs(a, b);
    std::cout << a << " " << b << std::endl; // Prints '3 2'.
    printtuple(a, b);       // Chooses the version with two arguments.

    double d = 2.3;
    printtuple(a, d);       // Chooses the version with two arguments where X is int and Y is double.

    printtuple(a, b, d);    // Chooses the version with three arguments.

    return EXIT_SUCCESS;
}
