#include <stdio.h>
#include <stdlib.h>


/* Structs are more complex data types, the prequel to classes. */

/* Defines a struct 'address'. */
struct address{
    int number;     /* simple member datatype */
    char name[30];  /* members can be arrays */
    char *city;     /* members can be pointers*/
} a1;   /* the a1 declares a variable a1 of type struct address (this is optional)*/


/* Defines another struct 'person'. */
struct person{
    int id;
    struct address adr; /* structs can be nested. */
};

void print_adress_name(struct address adr)  /* Structs are also passed by value. */
{
    printf("%s\n", adr.name);
    adr.number=-1; /* Leaves william from main unchanged. */
}

void set_number(struct address *adr, int number) /* Structs can also be passed by reference. */
{
    adr->number=number; /* But then elements have to be accessed like this. */
    (*adr).number=number; /* This is equivalent to the line above. */
}


int main(int argc, char *argv[])
{
    struct address william, james;  /* struct variables are declared like this. */
    struct person foo;

    william.number = 1;   /* Set a member variable. */
    strcpy(william.name,"William Smith");
    william.city = malloc(30*sizeof(char));
    strcpy(william.city, "Downing Street");

    printf("william.number: %i \n", william.number);

    foo.id = 1;
    foo.adr = william; /* struct members behave like any other member. */

    printf("foo.adr.name: %s \n", foo.adr.name);

    james = william;  /* Copy is a deep copy by default. */
    printf("james.name: %s \n", james.name);

    print_adress_name(william); /* Pass struct to function by value. */
    printf("william.number: %i\n", william.number);

    set_number(&william, 7);    /* Pass struct to function by reference. */
    printf("william.number: %i\n", william.number);

    system("PAUSE");
    return 0;
}
