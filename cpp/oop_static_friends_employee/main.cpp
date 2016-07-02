#include <cstdlib>
#include <iostream>

/* This is another example of working with classes. Illustrates static 
   variables and friends. */

class some_class; /* You can declare a class before you define it. This is
                     called a forward declaration and sometimes neccessary 
                     to avoid circles. */

class employee {
  int id;         // By default a member is private.
  char name[80];
  float wage;
 public:             // These member are public.
  employee() {};     // Short functions can be implemented on the fly.
  int mood;
  static int company_id; // Static members only exist once for the whole class.
  static int helper_function(int x); // and are shared between all objects.
 private:           // Again private.
  void calc_wage();
 public:           // Again public.
  void set_name(char *c);
  char *get_name();
  friend void reset_id(employee e); // A friend function has access to private members.
  friend class some_class;  // You can also friend a class (= all of its functions).
};

/* Although it is possible to switch between private and public members as
   often as you want, this is discouraged. Choose one order and stick
   to it. */

// Now we define the class we declared earlier.
class some_class {
  int a;
 public:
  void do_something(employee e);
};

void some_class::do_something(employee e) {
    e.id=-1;  // Only possible because some_class is a friend of employee.
}

int employee::company_id; // Define the static variable (now ready for use).

// We could have initalized the static variable like this:
// int employee::company_id=0;

int employee::helper_function(int x) {
    return x*x;
}

void reset_id(employee e) {
    e.id=0;
}

void employee::set_name(char *c) {
    strcpy_s(name, c);
}

char *employee::get_name() {
    return name;
}

employee replace_bob(employee e) {
    if (!strcmp(e.get_name(), "Bob")) {
        employee new_guy;
		new_guy.set_name("new_guy");
        return new_guy;
    }
	else {
		return e;
	}
}

int main(int argc, char *argv[]) {
    employee bob, alice;

    bob.set_name("Bob");

    std::cout << bob.get_name() << std::endl;

    reset_id(bob);  // Now bob.id is 0.

    bob.company_id=1;
    alice.company_id=2;
    std::cout << bob.company_id << std::endl; // Prints '2', because 'company_id' is static.

    std::cout << bob.helper_function(2) << std::endl;

    alice = replace_bob(bob);   // Deep copy by default.
    std::cout << alice.get_name() << std::endl; // Will be uninitialized.

    return EXIT_SUCCESS;
}
