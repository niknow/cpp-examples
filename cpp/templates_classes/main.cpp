#include <cstdlib>
#include <iostream>

const int SIZE = 10;

/* Just like template functions, one can also code template
   classes. These are classes in which at least one data type X
   is not specified. */

// This declares template class with one template type called X.
template <class X>
class stack {
    X stck[SIZE];
    int tos;
public:
    stack() { tos = 0; }
    void push(X e);                    // This declares a member template function.
    X pop();
};

// This defines a template member function of the template class.
template <class X>
void stack<X>::push(X e) {
    if (tos == SIZE) {
        std::cout << "Stackoverflow!" << std::endl;
        return;
    }
    stck[tos] = e;
    tos++;
}

template <class X>
X stack<X>::pop() {
    if (tos == 0) {
        std::cout << "Stackunderflow!" << std::endl;
    }
    tos--;
    return stck[tos];
}

int main(int argc, char* argv[])
{
    stack<int> s;   // To instantiate an object from a template class, one has 
                    // to specify what type X is in this instance (an int in this case).

    s.push(1);      // Now we can use s like any other object.
    s.push(2);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    return EXIT_SUCCESS;
}
