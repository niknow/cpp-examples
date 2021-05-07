#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

/* The STL contains a library of algorithms that work on STL containers like
   vectors, lists and maps. We illustrate a few examples of those.
*/

bool pred(int x) {
    if (x >= 3)
        return true;
    else
        return false;
}

void f(int& x) {
    x = x * x;
}

int g(int x) {
    return 2 * x;
}

int main(int argc, char* argv[])
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);

    int n = std::count(v.begin(), v.end(), 4);          // counts the number of occurences of 4 in v
    
    int m = std::count_if(v.begin(), v.end(), pred);    // counts the number of elements for which the praedicate pred yields true

    int vmax = *std::max_element(v.begin(), v.end());   // max_element gives a pointer a maximal element in the range
    
    std::for_each(v.begin(), v.end(), f);               // applies the function f to all elements of v

    std::vector<int> w(v);
    std::transform(v.begin(), v.end(), w.begin(), g);   // applies g to all elements of v and stores result in w

    return EXIT_SUCCESS;
}
