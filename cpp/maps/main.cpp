#include <iostream>
#include <map>

/* C++ supports maps as part of the standard template library (STL). These allow you
   to store (key, value) pairs of data and conveniently accessing them via the key.
*/


int main(int argc, char* argv[])
{
    std::map<std::string, int> m;                            // declares an empty map

    std::pair<std::string, int> p("foo", 1);                // a key-value pair can be created like this
    m.insert(p);                                            // inserts p into the map

    // if you insert an element where the key already exists, then insert ignores this
    m.insert(std::make_pair<std::string, int>("foo", 2));
    
    // existing elements can be accessed like this
    std::cout << m.at("foo") << std::endl;
    try {               // at() ensures that the element exists
        m.at("baz");
    }
    catch (...) {
        std::cout << "Element baz does not exist!" << std::endl;
    }

    // the [] operator is overloaded: for existing elements, one can access them via key and change their value
    m["foo"] = 2;
    m["bar"] = 7;   // for new elements, the pair is created automatically (using default constructor)
    std::cout << m["baz"] << std::endl;     // [] does not enture that the element exists, but rather creates it with default value


    // one can iterate over a map like this
    for (std::map<std::string, int>::const_iterator p = m.begin(); p != m.end(); p++)
        std::cout << "key: " << p->first << " value: " << p->second << std::endl;

    // one can find elements like this
    std::map<std::string, int>::iterator q = m.find("bar");
    std::cout << "found key: " << q->first << " value: " << q->second << std::endl;

    // one can delete elements like this
    m.erase(q);

    return EXIT_SUCCESS;
}
