#include <stdio.h>
#include <stdlib.h>

/* Enums are a custom data type that is suitable to represent anything that
   can be enumerated. */

   /* Enums are declared like this: */
enum currency {
    euro,
    dollar,
    pound = 10,
};

enum animal {
    cat,
    mouse
};


int main(int argc, char* argv[]) {
    enum currency c;
    enum animal d;

    c = euro;
    printf("%i\n", c);      /* Enums are just named integers. */
    printf("%i\n", dollar); /* Usually enumerated automatically. */
    printf("%i\n", pound);  /* But for pound we modified the int representation
                               to 10, see above. */

    /* It is not advisable to rely on the internal integer enumeration. */

    if (c == euro)          /* Tests should be performed like this. */
        printf("I'm a euro.\n");

    d = cat;
    if (c == d)             /* Enums are not type safe! This compares the underlying integers.*/
        printf("Surprise!\n");
    return 0;
}
