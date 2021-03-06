#include <cstdlib>
#include <iostream>

/* Operators like '+' can be overloaded just like functions can. Overloading
   operators allows you to work with objects of your classes in your code
   analogously to built-in types. */


class vect {                        // Class for 2D vectors
public:
    int x;
    int y;
    vect(int valx, int valy) { x = valx; y = valy; }
    vect() {}
    vect operator+(vect ob2);                   // Declare an overload of '+'-operator.
    friend vect operator-(vect ob1, vect ob2);  // Declare overload of '-' via friend
    vect operator=(vect ob2);                   // Declare overload of '='.
    vect operator++(int);                         // Declare overload of prefix increment
};

// Implementation of the overload of the '+' operator.
vect vect::operator+(vect ob2) {
    vect r;
    r.x = x + ob2.x;                            // The 'x' refers to the member variable 'x' of this object.
    r.y = y + ob2.y;
    return r;
}

// Overloads the '-'-operator via a friend function (could also be done via member function).
vect operator-(vect ob1, vect ob2) {
    vect r;
    r.x = ob1.x - ob2.x;
    r.y = ob1.y - ob2.y;
    return r;
}

vect vect::operator=(vect ob2) {
    x = ob2.x;
    y = ob2.y;
    return *this;                               // 'this' is a pointer to this object, i.e. this specific instance of the class.
}

vect vect::operator++(int) {                    // the int is a dummy needed to distinguish this postfix increment operator from the prefix operator (that one has no int)
    x++;
    y++;
    return *this;
}

int main(int argc, char* argv[]) {
    vect v1(1, 2), v2(2, 3), sum, diff;

    sum = v1 + v2;          // Use '+' on objects just like you use it on integers.
    std::cout << "sum.x = " << sum.x << ", sum.y= " << sum.y << std::endl;

    diff = v1 - v2;         // Use '-' on objects as well.
    std::cout << "diff.x = " << diff.x << ", diff.y = " << diff.y << std::endl;

    v2 = v1;                // Use '=' on objects.
    std::cout << "v2.x = " << v2.x << ", v2.y = " << v2.y << std::endl;

    v1++;
    std::cout << "v1.x = " << v1.x << ", v1.y = " << v1.y << std::endl;

    return EXIT_SUCCESS;
}

/* REMARK
   More on postfix vs prefix increment operator overloading:
   https://stackoverflow.com/questions/12740378/why-use-int-as-an-argument-for-post-increment-operator-overload

   Full list of overloadable operators:
   https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
*/
