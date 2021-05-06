#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>

/* C++ supports sets as part of the standard template library (STL) including some
   typical set operations.
*/


int main(int argc, char* argv[])
{
 
    std::set<int> a;        // declares an empty set

    a.insert(3);            // this inserts elements into the set
    a.insert(2);
    a.insert(1);
    a.insert(1);            // elements can be inserted multiple times, but are only present once

    // just like vectors a set has a size
    std::cout << "size: " << a.size() << std::endl;

    // one can iterate over the set, it has a begin() and end(), and it is internally ordered
    for (std::set<int>::const_iterator p = a.begin(); p != a.end(); p++)
        std::cout << *p << " ";
    std::cout << std::endl;

    // check if set is empty
    std::cout << "empty? " << a.empty() << std::endl;

    // delete an element
    std::set<int>::iterator q = a.begin();
    q++;
    a.erase(q); // deletes element *p, i.e. the second one in the set

    // set operations
    std::set<int> b, c, d;
    b.insert(3);
    b.insert(4);
    b.insert(5);

    // computes the union of a and b and puts the result into c
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::inserter(c, c.begin()));
    for (std::set<int>::const_iterator p = c.begin(); p != c.end(); p++)
        std::cout << *p << " ";
    std::cout << std::endl;

    // computes the intersection of a and b and puts the result into d
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(d, d.begin()));
    for (std::set<int>::const_iterator p = d.begin(); p != d.end(); p++)
        std::cout << *p << " ";
    std::cout << std::endl;

    // convert a vector into the underlying set
    std::vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    std::set<int> vset(v.begin(), v.end());
    for (std::set<int>::const_iterator p = vset.begin(); p != vset.end(); p++)
        std::cout << *p << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

/*  REMARK
    If the internal order of the set does not matter, one can use an unordered_set instead, which
    increases the performance.
*/