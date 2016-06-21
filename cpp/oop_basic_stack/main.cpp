#include <cstdlib>
#include <iostream>

/* One of the main features of C++ is the support of OOP, the object oriented
   programming paradigm. This example implements a stack in an OOP fashion. */


#define SIZE 100        // The stack can store up to 100 members.

class stack {           // Declare a class like this.
public:                 // Public members are accessible from outside the class.
    stack();            // Constructor
    ~stack();           // Destructor
    void push(int i);   // A member function (to push an element to the stack).
    int pop();          // A member function to pop the top element from the stack.
private:                // Private members are only visible inside the class.
    int stck[SIZE];     // A member variable to store the stack data.
    int tos;            // A member variable for the top of the stack.
};

// Define member functions like this.
stack::stack()
{
    std::cout << "Stack created." << std::endl;
    tos=0; // Automatically uses the namespace of the class.
}

void stack::push(int i) {
    if(tos==SIZE) {
        std::cout << "Stackoverflow." << std::endl;
        return;     // Leaves the function without returning anything.
    }
    stck[tos] = i;
    tos++;
}

int stack::pop() {
    if(tos==0) {
        std::cout << "Stack empty." << std::endl;
        return 0;
    }
    tos--;
    return stck[tos];
}

stack::~stack() {
    std::cout << "Stack destroyed." << std::endl;
}


int main(int argc, char *argv[])
{
    stack s1;   // Instantiate a stack object s1.

    s1.push(1); // Play around with it.
    s1.push(7);
    s1.push(42);

    std::cout << s1.pop() << std::endl;

    stack s2;   // Create a second stack object s2.
    s2 = s1;    // By default this creates a deep copy.
    std::cout << s1.pop() << s2.pop() << std::endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

/* The stacks get destroyed automatically after we leave the scope in which 
   they were declared. Hence, in this example the destructors of s1 and s2 are
   called after the '}' of 'main' and the messages are only visible then. */
