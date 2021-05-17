#include <iostream>
#include <vector>
#include <algorithm>
#include "myfunctor.hpp"

/* C++11 supports anonymous functions, called lambda expressions, i.e. functions, which do not
   necessarily need to have a name. The overall structure of a lambda is
   
   [capture](input_parameters) -> return_type { function_body }

   The capture clause captures other variables (then called closures) in the code that should 
   be available in the function_body. The input_parameters, the return_type and 
   the function_body are implemented just like for ordinary functions. Notice that in C++ the 
   function_body can have an arbitrary number of lines.
   One may leave out the return type like this
   
   [capture](input_parameters) { function_body }
   
   in which case the return type is inferred automatically.
*/

int main(int argc, char* argv[]) {

    auto f = [](int x) {return x * 2; };        // a simple function, no external variables captured
    std::cout << f(2) << std::endl;

    int a = 7;
    std::cout << [&a](int x) {a++; return x * a;}(5) << std::endl; // this calls the lambda with 5 changing a
    std::cout << a << std::endl;

    std::cout << [a](int x) mutable {a++; return x * a; }(5) << std::endl; // this calls the lambda with 5. the mutable enables us to change the copy of a, but not the external a
    std::cout << a << std::endl;

    // anonymous functions can be passed to other functions (see myfunctor.hpp)
    std::cout << [](int x) {return x * x; }(7) << std::endl;

    // a typical use case for lambdas is when we want to apply a function once to every element in a container
    std::vector<int> v = { 1, 2, 8 };
    std::for_each(v.begin(), v.end(), [](int& x) {x *= 3; });
    for (const auto& p : v)
        std::cout << p << " ";
    std::cout << std::endl;

    // similar in case we want to transform
    std::vector<double> w(v.size());
    std::transform(v.begin(), v.end(), w.begin(), [](int x) -> double {return 1.5 * x; });
    for (const auto& p : w)
        std::cout << p << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

/* FURTHER READING
   https://en.wikipedia.org/wiki/Anonymous_function#C++_(since_C++11)

   CAPTURE LOGIC
    []        // no variables captured at all
    [x, &y]   // x is captured by value, y is captured by reference
    [&]       // all external variables are captured by reference implicitly
    [=]       // all external variables are captured by value implicitly
    [&, x]    // x is captured by value explicitly , all other variables captured by reference implicitly
    [=, &z]   // z captured by reference explicitly, all other variables captured by value implicitly
*/