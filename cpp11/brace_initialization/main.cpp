#include <iostream>
#include <vector>
#include <map>
#include "myclass.hpp"


int main(int argc, char* argv[]) {

    // In C++03 only some few data types can be brace initialized, e.g.
    int d[3] = { 1, 2, 3 };

    // in c++11 this extends to object of all classes that implement a constructor with an initalizer list, e.g.
    std::vector<int> s = { 1, 2, 3};
    std::map<std::string, int> m = { {"a", 1}, {"b", 2} };   // brace initalizers are recursive - here they initalize the pairs and then the map
    MyClass c = { 1, 2 };

    return EXIT_SUCCESS;
}

