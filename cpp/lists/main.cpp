#include <iostream>
#include <list>
#include "listra.hpp"   // only needed for last example

/* C++ supports lists as part of the standard template library (STL). The nodes
   of the list can have any type. Internally, lists are implemented dually linked
   list. The nodes are typically not in a contiguous memory location. Insertion 
   and deletion are very efficient as only pointers need to be rearranged.
   For the same reason, random access is not possible.
*/


int main(int argc, char* argv[])
{
    std::list<int> L;       // declares a new list of integers

    L.push_back(1);         // inserts at the end of the list
    L.push_front(2);        // inserts at the beginning of the list
    L.push_back(3);

    // std::cout << L[0];   // this would throw an error as random access is not possible

    for (std::list<int>::const_iterator i = L.begin();     // we can iterate over lists using iterators (a const iterator prevents us from changing the elements)
        i != L.end();                                      // begin() and end() point to begin and end of the list
        i++)                                               // increment is overloaded, so this moves to the next element of the list
        std::cout << *i << " ";                            // i is a pointer to the current node, so we have to dereference to get the element
    std::cout << std::endl;

    // if we want to change the elements of the list, then we need to use an iterator with writing permissions
    for (std::list<int>::iterator i = L.begin(); i != L.end(); i++)
        (*i)++;     // increment all elements of the list

    // again, print all elements of the list
    for (std::list<int>::const_iterator i = L.begin(); i != L.end(); i++)
        std::cout << *i << " "; 
    std::cout << std::endl;

    // lists can be easily sorted
    L.sort();
    for (std::list<int>::const_iterator i = L.begin(); i != L.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    // lists can be easily merged with another list
    std::list<int> K;
    K.push_back(4);
    K.push_back(5);
    K.push_back(6);
    L.merge(K);
    for (std::list<int>::const_iterator i = L.begin(); i != L.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    // items can be erased via iterators
    std::list<int>::iterator i = L.begin();
    i++;            // move to second element
    L.erase(i);     // delete it
    for (std::list<int>::const_iterator i = L.begin(); i != L.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    // one can modify list to allow for random access, but bear in mind that this will be slow
    ListRandomAccess<int> lra;
    lra.push_back(1);
    lra.push_back(2);
    lra.push_back(3);
    std::cout << lra[1] << std::endl;
    lra[0] = 7;
    std::cout << lra[0];

    return EXIT_SUCCESS;
}
