// Repeated dynamic allocation
// By: Nick from CoffeeBeforeArch

#include <cstdlib>
#include <iostream>
#include <vector>

// Overloaded new operator to capture std::vector dynamic allocations
void *operator new(size_t N) {
  std::cout << "Allocatng " << N << " bytes!\n";
  return malloc(N);
}

int main() {
  // Create a vector and push back 10 elements
  // Vector performs dynamic allocations as it needs a greater capacity
  // In many cases, growth is exponential (powers of 2), so it does perform
  // fewer allocation as it grows larger
  std::vector<int> v;
  for (std::size_t i = 0; i < 10; i++) v.push_back(i);

  return 0;
}
