#include <stdio.h>
#include <stdlib.h>

/* You can read in input from the console. */

int main(int argc, char *argv[])
{

    /* Single character input works like this. This loop echos any single
       character input, */
    char c;
    printf("Enter a character and hit 'Return' to mirror it (and a '.' to quit). \n");
    do {
        c = getchar();
        putchar(c);
    } while (c != '.');
    printf("\n");

    /* More advanced input using 'scanf'. */
    char line[100];
    int a;
    float x;

    printf("Enter an integer: ");
    scanf("%i", &a);   /* 'scanf' works analogous to 'printf'. */
    printf("You entered: %i \n", a);

    printf("Enter a short string: ");
    scanf("%s", line);
    printf("You entered: %s \n", &line);

    printf("Enter an integer, hit return, and enter a float: ");
    scanf("%i%f", &a, &x);
    printf("You entered: %i and %f\n", a, x);

    system("PAUSE");
    return 0;
}
