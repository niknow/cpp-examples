#include <stdio.h>
#include <stdlib.h>

/* You can read and write data from a file. */
/* This example assumes that 'data.txt' is in same folder as the executable. */

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("data.txt", "r"); /* Opens file for read access. */
    close(fp);  /* Closes the file. */

    /* Accessing a file from the disk can go wrong. This opens the file if
       possible and handles a potential failure. */
    if(!(fp = fopen("data.txt", "r"))){
        printf("Cant open file.\n");
        return 1;
    }
    /* If we made it here, the file was opened successfully. */
    /* This reads in the two words in the first line of 'data.txt'. */
    char word1[80], word2[80];
    fscanf(fp, "%s", &word1);
    fscanf(fp, "%s", &word2);
    printf("%s", word1);    /* Print the result on console. */
    printf(" %s\n", word2);
    close(fp);  /* Don't forget to close the file. */

    /* You can also write into a file: */
    if(fp=fopen("newdata.txt", "w")){
        fprintf(fp, "Hello World");
        close(fp);
    }
    else{
        printf("Opening file 'newdata.txt' failed.\n");
    }

    system("PAUSE");
    return 0;
}
