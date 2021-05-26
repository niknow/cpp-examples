#include <iostream>

/* In C++ the symbol 0 has the double meaning of the integer 0 and a nullpointer.
   This can lead to counter-intuitive results when combined with function overloading,
   see below. In C++11 one can avoid those using the nullptr constant.
*/

void foo(char* c) {
    std::cout << "char" << std::endl;
}

void foo(int i) {
    std::cout << "int" << std::endl;
}


int main(int argc, char* argv[]) {

    foo(0);         // this will call the int version
    foo(nullptr);   // this will call the char* version

    return EXIT_SUCCESS;
}
