#pragma warning( disable : 4700 )
#include <stdio.h>
#include <stdlib.h>

/* A pointer is simply a variable that stores the memory address
of another variable. */

int main(int argc, char* argv[])
{
    int x = 5, y;   /* These are some integer variables. */
    int* p;         /* This is a pointer to an integer variable. */
    int** a;        /* This is a pointer to a pointer to an integer variable. */

    p = &x;         /* Now p contains the memory address of the integer x. */
                    /* We say 'p points to x'. */

    printf("p: %p\n", p);    /* Gives something like 0028FF44.*/

    y = *p;   /* Now y contains the content of the variable to which p points
                 to, i.e. to the variable with address p (x in this case). */

              /* The operator '*' is called 'dereference operator'. */

    printf("y: %i\n", y);    /* Yields 5, because x was initialized to 5. */

    int *q;     /* same as: int* q. */

    /*printf("*q: %i\n", *q); */ /* Dereferencing an uninitialized pointer returns
                               an unknown value that happens to be there in
                               memory. Never do that. */

    /* You can play the same game with pointers of pointers. */

    a = &p; /* Now a contains the memory address of the pointer p. */

    printf("a: %p\n", a);       /* Gives something like 0028FF3C. */
    printf("*a: %i\n", *a);     /* Gets the pointer, something like 0028FF44. */
    printf("**a: %i\n", **a);   /* Gets the content, in this case 5.*/

    return 0;

}
