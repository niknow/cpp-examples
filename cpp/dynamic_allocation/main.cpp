#include <cstdlib>
#include <iostream>

/* Dynamic memory allocation is easier in C++. */

int main(int argc, char *argv[]) {
    int n = 5;             // Static memory allocation is done like in C.
    int *p = new int [n];  // Allocates dynamic int array of length n (without exception handling).
    p[0] = 7;              // Use a dynamic array as usual.
    p[1] = 3;

    std::cout << p[0] << " " << p[1] << std::endl;  // gives '7 3'

    delete [] p; // Disallocates the memory dynamically allocated at p.

    int *q; // Dynamic allication with exception handling can be done like this.
    try {
        q = new int [n];
    }
    catch (std::bad_alloc xa) {
        std::cout << "Memory allocation failed." << std::endl;
        return 1;
    }

    q[0]=1;
    std::cout << q[0] << std::endl;  // gives '1'
    delete [] q;

    return EXIT_SUCCESS;
}

