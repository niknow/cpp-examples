#include <iostream>
#include <vector>

/* C++ supports vectors as part of the standard template library (STL). Unlike lists
   the memory allocated for the nodes is contingous and random access is possible.
*/


int main(int argc, char* argv[])
{
    std::vector<int> x(3);         // declares a vector of integers of size 3

    // elements can be written into a vector using []
    x[0] = 7;
    x[1] = 8;
    x[2] = 19;

    // elements can also be read using []
    std::cout << x[0] << " " << x[1] << " " << x[2] << std::endl;

    // elements can be accessed also using at() which checks the bounds
    std::cout << x.at(0) << " " << x.at(1) << " " << x.at(2) << std::endl;

    std::vector<int> y;         // declare a vector of unspecified size
    y.push_back(2);             // add elements at the end of the vector
    y.push_back(3);
    y.push_back(4);
    x.push_back(4);             // this also works if x was declared previously of size 3
    // elements can still be read using []
    std::cout << y[0] << " " << y[1] << " " << y[2] << std::endl;

    // the size of the vector is dynamically expanded as needed and can be retrieved via
    std::cout << "y.size: " << y.size() << std::endl;

    /* Expanding the size of the vector while still ensuring contiguous memory
       might require reallocation and copying from time to time, which costs performance.
       The size of the allocated region is the capacity and in general different from the
       currently used size. */

    y.reserve(10);      // increases size of capacity, i.e. allocated memory
    std::cout << "y.capacity: " << y.capacity() << std::endl;

    // iterate via random access
    for (int i = 0; i < x.size(); i++)
        std::cout << x[i] << " ";
    std::cout << std::endl;

    // iterate via iterator
    for (std::vector<int>::const_iterator p = x.begin(); p != x.end(); p++)
        std::cout << *p << " ";
    std::cout << std::endl;

    // insert elements in the middle
    std::vector<int>::const_iterator p = x.begin();
    p += 2;
    x.insert(p, 3, 2);                      // inserts at p three times the element 2 
    for (int i = 0; i < x.size(); i++)
        std::cout << x[i] << " ";
    std::cout << std::endl;

    // delete elements
    std::vector<int>::iterator q = x.begin();
    q += 3;
    x.erase(q, q + 2);                      // delete the next 2 elements after q starting with *q
    for (int i = 0; i < x.size(); i++)
        std::cout << x[i] << " ";
    std::cout << std::endl;

    // advanced initialization
    std::vector<int> w(3, 7);   // declares a vector of size 3 and initializes all entries with 7
    std::vector<int> u(w);      // declares a vector that is a copy of w
    std::vector<std::vector<int>> z(3, std::vector<int>(4)); // declares a vector of length 3 of vectors of length 4
    z[1][2] = 17;   // access like this
    
    return EXIT_SUCCESS;
}
