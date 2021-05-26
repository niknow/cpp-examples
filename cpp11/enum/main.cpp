#include <iostream>

/* In C++03 enums are not type-safe, which can lead to counter-intuitive behavior.
   C++11 suppors strongly typed enums to avoid that.
*/

enum Animals {
    Cat,
    Dog,
    Fish
};

enum Appliances {
    Fridge,
    Dishwasher,
    Oven
};

enum class Buildings {
    Cathedral,
    Townhall,
    LumberMill
};

enum class Beers {
    Becks,
    Heinecken,
    Peroni
};

int main(int argc, char* argv[]) {

    Animals a1 = Animals::Cat;
    Appliances a2 = Appliances::Fridge;
    Buildings b1 = Buildings::Townhall;
    Beers b2 = Beers::Heinecken;

    if (a1 == a2) {         // this is true as enums in C++03 are just integers
        std::cout << "Enums are not type-safe!" << std::endl;
    }

    // if (b1 == b2) {     // this throws a compile time error


    return EXIT_SUCCESS;
}
