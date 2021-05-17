#pragma once
#include <functional>

// anonymous functions can be passed as parameters to functions
int doubleFunctor(std::function<int(int)> f, int a) {
    return 2 * f(a);
}
