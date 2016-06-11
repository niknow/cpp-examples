#include <stdio.h>
#include <stdlib.h>

/* Enums are a custom data type that is suitable to represent anything that 
   can be enumerated. */

/* Enums are declared like this: */
enum currency {
    euro,
    dollar,
    pound=10,
};

int main(int argc, char *argv[]){
    enum currency c;

    c = euro;
    printf("%i\n", c);      /* Enums are just named integers. */
    printf("%i\n", dollar); /* Usually enumerated automatically. */
    printf("%i\n", pound);  /* But for pound we modified the int representation 
                               to 10, see above. */

    /* It is not advisable to rely on the internal integer enumeration. */

    if(c == euro){  /* Tests should be performed like this. */
        printf("I'm a euro.\n");
    }

    system("PAUSE");
    return 0;
}
