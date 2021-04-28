#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> /* Needed only for variadic functions. */

/* Functions allow you to split up more complex code into smaller pieces that
   are easier to understand. That makes your code more readable, easier to debug,
   less likely to have errors, shorter and better to maintain.

    We are going to define a few functions and call them later in 'main'
    as usual, see below. */

/* A function can be defined like this: */
int addition(int x, int y) {
    return x + y;
}
/* In this case 'int' is the return type and 'addition' is the name. This function
   takes two parameters 'x' and 'y' of type 'int'. It computes their sum. */

/* A function can be declared first like this and been given a definition
    later. This is very useful for bigger libraries (a topic in its own), */
int subtraction(int x, int y);
/* For a declaration it would even be sufficient to write:
int substraction(int, int);
*/

int z = 7; /* This is a global variable. It can be accessed by any function in
            scope. We only use it for educational purposes below. */

/* Functions do not need to return something. Then the return type is 'void'. */
void myfunction(int z, int b, int* a) {
    z = 5;      /* Functions have their own namespace, the global 'z' is still 7. */
    b = 6;      /* Parameters are 'called by value', i.e. the b from the call in 'main' below is not changed. */
    *a = 7;     /* Passing a pointer is a 'call by reference', i.e. *a  from the call below will be changed. */
}

/* Functions to not need to have parameters. */
double getPi(void) {
    return 3.141592454;
}

/* Warning: This function accepts an arbitrary number of parameters: */
int sum() {
    return 0; /* See below for handling of variadic functions. */
}

/* You can pass an array to a function like this. */
void print_int_array(int* A, int n) {
    int i;
    printf("A: ");
    for (i = 0; i < n; i++) {
        printf("%i ", A[i]);
    }
    printf("\n");
}

/* A function can fill a new array either by passing a parameter by reference like this: */
void zeros(int** B, int n) {
    *B = (int*)calloc(n, sizeof(int));
}

/* or by returning a pointer like this: */
int* zeros_return(int n) {
    int *B = (int*)calloc(n, sizeof(int));
    return B;
}

/* Functions can call themselves. Its called 'recursion'. */
int factorial(int n)
{
    if (n > 0)
        return n * factorial(n - 1);
    else
        return 1;
}

/* Variadic functions are functions with an arbitrary number of arguments. They
   have to be passed at the end of the fixed-length parameter list like this: */
void my_int_print_fun(int n, ...) {
    va_list argptr;
    va_start(argptr, n);
    int i;
    printf("positional argument: %i \n", n);
    for (i = 0; i < n; i++) {
        printf("optional argument %i: %i\n", i, va_arg(argptr, int));
    }
    va_end(argptr);
}

/* Actually, 'main' is a function too! It is the function called by the OS.
   Its arguments are used to process command line arguments (a topic in its own). */
int main(int argc, char* argv[])
{
    /* Now we can call all the functions we have defined above:*/

    /* Call a function. */
    int a = 2, b = 4, c;
    c = addition(a, b);     /* Now the return value of 'addition' is written into c. */
    printf("a+b: %i\n", c);
    addition(4, 5);         /* We don't have to use the return value though. */

    /* Parameter handling: Call by value vs call by reference. */
    int x = 1, y = 2;
    myfunction(x, b, &y);  /* Functions having return type 'void' are always called like this. */
    printf("z: %i\n", z);  /* Gives the global 'z' defined above. */
    printf("b: %i\n", b);  /* b is still 4, because it was passed by value. */
    printf("y: %i\n", y);  /* y is now 7, because it was passed by reference. */

    /* Functions without parameters. */
    double pi = getPi(); /* Call a function without parameters. */
    printf("pi: %f\n", pi);
    /* getPi(3); would not compile */

    printf("sum: %i\n", sum());   /* The parameter has no effect, but this does compile. */
    printf("sum: %i\n", sum(3));

    /* Calling a function that as an array-parameter. */
    int A[3] = { 1, 2, 3 };
    print_int_array(A, 3);

    /* Calling a function that returns an array. */
    int* B;
    zeros(&B, 3);           /* Now B is an array of size 3 initialized with zeros. */
    print_int_array(B, 3);
    B = zeros_return(3);    /* The same can be accomplished like this. */
    print_int_array(B, 3);
    free(B);

    /* Call a recursive function. */
    printf("5! = %i \n", factorial(5));

    /* Call a variadic function. */
    my_int_print_fun(3, 2, 3, 4);
    my_int_print_fun(1, 2);

    return 0;
}
