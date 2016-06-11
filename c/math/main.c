#include <stdio.h>
#include <stdlib.h>
#include <math.h>   /* Enables special math functions. */

/* In case one needs mathematical functions more advanced than '+', '-'. '*'
   or '/', chances are that they are already implemented in that math
   header. */

int main(int argc, char *argv[])
{
    /* Special math functions can be used like this: */
    printf("cos(7) : %f \n", cos(7));
    printf("exp(2) : %f \n", exp(2));
    printf("log(2) : %f \n", log(2));
    printf("3**2.7 : %f \n", pow(3, 2.7));
    printf("sqrt(2): %f \n", sqrt(2));

    /* to be continued */

    /* For a complete list of all available functions, simply open the
       math.h. */

    system("PAUSE");
    return 0;
}
