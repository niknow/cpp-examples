#include <stdio.h>
#include <stdlib.h>

/* Loops are a mean to execute the same code over and over again. There are
three types of loops in C: The 'for'-loop, the 'while'-loop and the
'do'-'while'*-loop. */

int main(int argc, char *argv[])
{
    int i, n=5;

    /* 'for'-loops: */
    for(i=0;            i<n;       i++) /*prints the first 5 numbers*/
    /*  initialization; condition; increment*/
        printf("%i\n",i);   /* statement */

    for(i=0; i<n & n!=2; i+=2){ /*all four parts can be more complex*/
        printf("%i\n",i);
    }

    for(i=0; i<n; i++){
        if(i==1)
            continue; /* skips the rest of the loop for i=1*/
        if(i==3)
            break;  /* exits the loop at i=3 */
    }

    /* while: entry condition */
    i=0;
    while(i<n){ /* executed till as long as entry condition holds (might stop before first iteration) */
        printf("%i",i);
        i++;
    }

    /*do while: exit condition  */
    i=0;
    do{ /* Start of the loop. At least one iteration is executed. */
        printf("%i",i);
        i++;
    } while (i<n);  /* Iteration stops of exit condition is met. */

    system("PAUSE");
    return 0;
}
