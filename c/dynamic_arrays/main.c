#include <stdio.h>
#include <stdlib.h>

/* Memory can be allocated and disallocated dynamically. This allows the 
   creation of dynamically sized arrays. The most important functions here
   are 'malloc', 'calloc' and 'free'. */

int main(int argc, char *argv[])
{
    int *a;   /* A (statically allocated) pointer for our array. */
    int n=5;  /* The size of the array. */

    /* The easiest case using 'malloc': */
    a = (int *) malloc(n*sizeof(int));  /* Dynamically allocate memory. */
    a[0]=1;  /* Now you can use 'a' just like any other array. */
    printf("%i% \n",a[0]);
    printf("%i% \n",a[1]);   /* Produces unpredictable output. Never do that. */
    free(a); /* Disallocate your memory at the end to avoid memory leaks. */
    /* The easiest case using 'calloc': */
    a = (int *) calloc(n, sizeof(int));  /* Dynamically allocate memory. */
    printf("%i% \n",a[0]);    /* Gives 0, because 'calloc' initializes the array with 0. */
    free(a);        /* Disallocate your memory to avoid memory leaks. */

    /* You can create a 2D array as an array of arrays. Here, we create an
       array with m rows and n columns. */
    int **b;
    int m=2;
    int i;
    b = (int **) malloc(m*sizeof(int*));    /* Memory for the row pointers. */
    for(i=0;i<m;i++){
        b[i] = (int *) malloc(n*sizeof(int));   /* Memory for the columns. */
    }
    /* Access to a 2D array is like accessing an array of arrays: */
    b[0][1] = 7; /* Access row at index 0, column at index 1. */
    printf("%i\n",b[0][1]);

    for(i=0;i<m;i++){   /* Don't forget to free all column arrays in the end. */
        free(b[i]);
    }
    free(b);    /* Finally free row array. */

    /* You can create arrays of arbitrary dimension in a similar fashion. */

    system("PAUSE");
    return 0;
}


