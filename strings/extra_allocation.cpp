// Extra dynamic allocations
// By: Nick from CoffeeBeforeArch

#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

// Track dynamic allocations
void *operator new(std::size_t size) {
  std::cout << "Reserving " << size << " bytes!\n";
  return malloc(size);
}

int main() {
  // A string that doesn't fit in the SSO optimization
  // This gets allocated on the heap instead of the stack!
  std::string s("Too long to fit in stack buffer!");

  return 0;
}
