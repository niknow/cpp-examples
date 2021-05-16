#include <iostream>
#include <vector>

/* C++ is a statically typed language. That means that every variable must have a type
   and be declared before use. C++11 is still statically typed but has the `auto' 
   keyword that allows for type inference whenever possible.
*/

int main(int argc, char* argv[]) {

    // in C++03 iterating over a vector can easliy be annoying due to the complicated types
    std::vector<int> v = { 1, 2, 3 };
    std::vector<int>::iterator p = v.begin();
    p++;

    // in C++11 we may use:
    auto w = std::vector<int>{ 1, 2, 3 };
    auto q = w.begin();
    q++;

    // in case we need the type of an auto declared variable, we can use
    decltype(w) x;
    x.push_back(7);


    return EXIT_SUCCESS;
}
