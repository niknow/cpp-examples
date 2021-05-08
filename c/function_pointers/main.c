#include <stdio.h>
#include <stdlib.h>

/* Function pointers are variables that store the memory address of a 
   funtion. They can be used similarly to pointers that point to data.
*/



int f2(int x) {
    return 2 * x;
}

int f3(int x) {
    return 3 * x;
}

int add(int x, int y) {
    return x + y;
}

int g1(int (*h)(int, int), int x, int y, int z) {
    return h(x, y) + z;
}


int main(int argc, char* argv[])
{
    // this declares a function pointer with name f that points to a function that takes an int and returns an int
    int (*f)(int);          

    // now we can dynamically chose, which function to use
    int n = 2;
    if (n == 2) {
        f = &f2;
    }
    else {
        f = f3;
    }

    printf("%i \n", (*f)(2));       // function pointers can be dereferenced and used like any other pointer
    printf("%i \n", f(3));          // but it is also allowed to drop the (* ) around the name and the behavior is identical
    
    // we can also pass function pointers to funtions and have a pointer pointing to that function
    // g is a pointer to a function that returns an int and takes as arguments: a pointer to a function that returns an int and takes two ints, and three intergers
    int (*g)(int (*)(int, int), int, int, int);

    g = g1;
    printf("%i \n", g(add, 4, 5, 6));

    return 0;
}
