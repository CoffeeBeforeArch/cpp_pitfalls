// Extra moves
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib>

// Track dynamic allocations
void *operator new(std::size_t size) {
  std::cout << "Reserving " << size << " bytes!\n";
  return malloc(size);
}

int main() {
  // A string that doesn't fit in the SSO optimization
  std::string s("Too long to fit in stack buffer!");

  // If we are trying to place existing strings into a vector, this
  // will lead to an extra dynamic allocation. If we don't care about
  // the existing string, we should move the string!
  std::vector<std::string> v;
  v.emplace_back(std::move(s));
  
  return 0;
}
