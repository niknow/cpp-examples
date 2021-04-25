#include <stdio.h>
#include <stdlib.h>

/* There is a very important connection between pointers and arrays in C. */

int main(int argc, char* argv[])
{
    int x[3] = { 1,2,3 };   /* Initializes an array of integers. */
    int *p, *q;

    /* Now x itself is actually pointer that points to the first element! */
    printf("x: %p\n", x);       /* Gives something like '0028FF30'. */
    printf("*x: %i \n", *x);    /* Gives '1', the first element of the array. */

    p = x;                       /* This is how we assign arrays by reference.
                                    The elements of the array are NOT copied. */

    printf("p: %p \n", p);       /* Gives the same address as x. */
    printf("*p: %i \n", *p);     /* Gives the first element of x. */

    /* We can calculate with pointers. This is called 'pointer arithmetics'. */
    q = p + 1;                   /* Now q points to the second element of x. */
    printf("*q: %i\n", *q);      /* Gives '2', the second element of x. */

    /* We can also substract pointers (but not multiply or divide). */
    printf("*(q-1): %i\n", *(q - 1));   /* Gives the first element of x. */
    printf("*(q-2): %i\n", *(q - 2));   /* Gives a number that happens to be
                                         in memory before q-1. Never do that. */

    /* The brackets '[' and ']' used to index arrays are actually just
    syntactic sugar for pointer arithmetics: */
    printf("x[1]: %i\n", x[1]);          /* Gives 2. */
    printf("*(x+1): %i\n", *(x + 1));    /* Gives also 2, because x[1] is equivalent
                                            to *(x+1). */

    return 0;
}
