#include <iostream>
#include <vector>

/* In C++03 iterating over containers can be cumbersome. In C++11 this is simplified
   using range based for loops.
*/

int main(int argc, char* argv[]) {

    // in C++03 a for loop over a vector looks like this
    std::vector<int> v = { 1, 2, 3 };
    for (std::vector<int>::iterator p = v.begin(); p != v.end(); p++)
        std::cout << *p;
    std::cout << std::endl;

    // thanks to type inference via auto we can now first simplify
    for (auto p = v.begin(); p != v.end(); p++)
        std::cout << *p;
    std::cout << std::endl;

    // finally, this can be simplified further using a range based for loop
    for (auto p : v)        // this iterates from v.begin() till v.end() and works with every container that has these functions implemented
        std::cout << p;     // the items are captured by value, i.e. p is a copy of the element in v (can be modified, but does NOT modify the element in v)
    std::cout << std::endl;

    // for items that are expensive to copy one can use 
    for (const auto& p : v)
        std::cout << p;     // now p is a const ref to the item in v
    std::cout << std::endl;

    // in case we want to change items
    for (auto& p : v)
        p += 2;         // now p is a reference to the elements in v, which can now be changed

    // for the special case of proxy iterators, we have to use this syntax
    std::vector<bool> x = { true, false, false, true };
    std::vector<bool>::iterator q = x.begin();
    *q = !*q;
    for (auto&& p : x)      // will not compile with just one '&'
        p = !p;             // flips true and false
    /* the auto&& is needed here because in vector<bool> the booleans are not stored in a byte, but instead in a bit
       to be more memory efficient. Thus, when dereferenced it returns a proxy iterator, which is a reference
       to a reference. Notice that
       bool& b = x[0];  would not compile
       This is considered to be a mistake in the STL.
    */

    return EXIT_SUCCESS;
}

/* FURTHER READING
   https://stackoverflow.com/questions/15927033/what-is-the-correct-way-of-using-c11s-range-based-for
   https://en.wikipedia.org/w/index.php?title=Sequence_container_(C%2B%2B)&oldid=767869909#Specialization_for_bool
*/
