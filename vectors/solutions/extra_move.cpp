// Extra moves
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <vector>

struct S {
  // Constructor
  S() { std::cout << "Default Constructor!\n"; }
  // Copy constructor
  S(const S &s1) { std::cout << "Copy Constructor!\n"; }
  // Move constructor
  S(S &&s) { std::cout << "Move Constructor!\n"; }
};

int main() {
  // Calling push back Causes a constructor call followed by a move! 
  // If we don't define a move constructor, it will use the copy constructor!
  std::vector<S> v;
  v.push_back(S());
  return 0;
}
