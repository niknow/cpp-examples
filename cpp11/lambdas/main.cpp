#include <iostream>


int main(int argc, char* argv[]) {

    auto f = [&](int x) {return x * 2; };

    return EXIT_SUCCESS;
}

