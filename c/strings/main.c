#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>     /* include this library for handling strings */

int main(int argc, char* argv[])
{
    char s1[12];                /* Strings are arrays of chars. */
    char s2[3] = "ld";          /* Strings can be initialized too. */
    char r[] = "Good morning";  /* Size can be set automatically on initialization. */
    char s3[3] = "01";          /* Strings are null-terminated, so leave the last
                                   character for the null termination. */

    printf("%s\n", r);               /* Print a string on console. */

    strcpy(s1, "Hello Wor");         /* Copy strings into each other. */

    printf("%s\n", s1);              /* Prints "Hello Wor". */

    printf("%s\n", strcat(s1, s2));  /* strcat concatinates strings and stores result in s1. */

    printf("%i\n", strlen(s1));      /* strlen gives the length of the string (without terminating null-character) */

    char* p = strstr(s1, "ello");    /* strstr returns a pointer to the first
                                        occurence of the second string in the first. */

    return 0;
}
