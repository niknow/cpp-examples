#include <stdio.h>
#include <stdlib.h>

/* Sometimes certain part of the code should only be executed under certain
conditions. C provides three possibilities to achieve that: The ternary '?'-
operator, the 'if'-keyword and the 'switch'-keyword. */

int main(int argc, char *argv[])
{
    int x=0, y=1;

    /*the terniary ? operator*/
    x>0 ? printf("yes\n") : printf("no\n"); /* prints 'yes' */

    /*if keyword */
    if(x==1) printf("x: Yeah\n");    /* will not be printed */
    if(y==1) printf("y: Yeah\n");    /* will be printed */
    if(y==1){
        printf("y: Foo\n"); /* If more than 1 line of code should be executed, */
        printf("y: Bar\n"); /* we need to put them in a block. */
    }

    if(x>=0 & y!=0){     /* more complex boolean expressions are possible */
        printf("Yeah Yeah\n");   /* It is also allowed to put 1 line into a block. */
    }
    else if(x>=0){
        printf("Yeah\n");   /* This is not executed because the first 'if' matched.*/
        if (y>0) printf("ah"); /* if's can be nested */
    }
    else{
        printf("Boo.\n"); /* Not executed because first 'if' matched.*/
    }

    if (x < 0)
        printf("x < 0 \n");  /* Not executed. */
    else
        printf("x >= 0 \n"); /* Executed because first 'if' didn't match.*/

    /* switch keyword */
    switch(x) {
    case 0:
         printf("x==0\n");
         break; /* optional, but otherwise the next block will be executed! */
    case 1:
         printf("x==1\n");
    default:   /* this is optional and is executed if no other match is found */
         printf("something else");
    }

    system("PAUSE");
    return 0;
}
