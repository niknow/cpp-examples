#include <stdio.h>
#include <stdlib.h>

/* Loops are a mean to execute the same code over and over again. There are
three types of loops in C: The 'for'-loop, the 'while'-loop and the
'do..while'-loop. */

int main(int argc, char* argv[])
{
    int i, n = 5;

    /* 'for'-loops: number of iterations is known in advance*/
    for (i = 0; i < n; i++)      /* prints the first 5 numbers*/
    /*  1. initialization; 2. condition; 3. increment*/
        printf("for: i: %i\n", i);       /* 4. statement */

    for (i = 0; (i < n) && (n != 2); i += 2) { /*all four parts can be more complex*/
        printf("for2: i: %i\n", i);
        printf("for2: i**2: %i\n", i*i);
    }

    for (i = 0; i < n; i++) {
        if (i == 1)
            continue;  /* skips the rest of the loop for i=1*/
        if (i == 3)
            break;     /* exits the loop at i=3 */
    }

    /* while: loop with entry condition */
    i = 0;
    while (i < n) { /* executed as long as entry condition holds (might stop before first iteration) */
        printf("while: %i\n", i);
        i++;
    }

    /*do while: loop with exit condition  */
    i = 0;
    do { /* start of the loop. At least one iteration is executed. */
        printf("do..while: %i\n", i);
        i++;
    } while (i < n);  /* iteration stops if exit condition is met. */

    return 0;
}
