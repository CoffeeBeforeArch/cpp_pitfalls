// Accidental Construction
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <vector>

struct S {
  // Constructor
  S() : x(0), y(0) { std::cout << "Default Constructor!\n"; }
  // Copy constructor
  S(const S &s1) : x(s1.x), y(s1.y) { std::cout << "Copy Constructor!\n"; }

  // Data members
  int x;
  int y;
};

int main() {
  // Creates a vector w/ 10 elements of type S
  // Will call default constructor for each element
  // This can be wasted work if we don't need default constructed elements
  std::vector<S> v;
  v.reserve(10);

  return 0;
}
