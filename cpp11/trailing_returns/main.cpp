#include <iostream>

/* In C++03 the return type of a function has to be put in front of the function declaration:
   int myfun(int x);
   This can cause problems in situation where due to the use of templates, the return type
   is not obvious. In C++11 this problem is solved by using a trailing return.
*/

// trailing return types can be used like this (the auto is just cosmetics here)
auto myfun(int x) -> int {
    return 2 * x;
}

// in case the + operator is overloaded for multiple types, this is now legit C++11:
template<class Lhs, class Rhs>
auto adding_func(const Lhs& lhs, const Rhs& rhs) -> decltype(lhs + rhs) { return lhs + rhs; }



int main(int argc, char* argv[]) {

    auto x = myfun(7);
    auto y = adding_func<int, double>(2, 3.5);

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    return EXIT_SUCCESS;
}

