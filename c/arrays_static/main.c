#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x[3];          /* Declares an array of size 3. */
    int y[3]={4,5,6};  /* Arrays can be initialized too. */
    int z[3][4];       /* Aarrays can have any number of dimensions. */
    int A[] = {1,2,3}; /* Arrays can be sized automatically by initialization. */

    /* Assignment of values to a declared array. */
    x[0] = 15;       /* Arrays in C are zero indexed. */
    x[1] = 17;
    x[2] = 42;

    /* You are responsible to check the bounds. */
    x[3] = 1;        /* No error check here! This might accidentally work. Never do that!*/

    /* Access values stored in an array. */
    printf("0: %i\n",x[0]);
    printf("1: %i\n",x[1]);
    printf("2: %i\n",x[2]);

    printf("3: %i\n",x[3]);    /* Danger! This accesses memory in an unknown state. Never do that! */

    system("PAUSE");
    return 0;
}
