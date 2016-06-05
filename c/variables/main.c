#include <stdio.h>
#include <stdlib.h>

/* C is a statically typed language. That means you have to declare a
variable before its first use and state its type. In C variables should
be declared at the beginning of their scope. */

int main(int argc, char *argv[])
{

    /* the basic datatypes: */
    int a;         /* integer */
    float b;       /* floating point */
    double c;      /* double precision floating point*/
    char d;        /* character */

    int x = 5;  /*variables can be initialized on declaration*/
    int y, z;  /*these are several integers*/

    /* datatypes can be modified */
    signed int e;  /* positive and negative integers (=integers) */
    unsigned int f; /* only non-negative integers but larger range*/
    long int g;      /* larger range */
    short int h;     /* shorter range, less memory */

    /* you can assign values to unitizialized and initialized variables later */
    x = 5;
    y = 6;
    z = x+y; /* =11 */
    z = x*y; /* =30 */
    z = x-y; /* =-1 */
    z = x/y; /* =0,  because integer division is truncated*/
    b = (float) x/y;    /* = 0.83333, because we made a typecast*/

    x += 5; /*equivalent to x = x + 5*; same for - * or / */
    x++; /* equivalent to x = x+1; same for - */

    b = 5.0/6.0; /* gives 0.8333...*/
    b = 0.78;    /* use dot to denote the comma */
    b = 0.78e7;  /* you can just use scientific notation*/

    /* printing is a topic in its own*/
    printf("x: %i\n", x);
    printf("b: %f\n", b);

    system("PAUSE");
    return 0;
}
