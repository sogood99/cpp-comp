#include <iostream>
#include <limits>

int main() {
  std::cout
      << std::numeric_limits<unsigned char>::digits; // not guarenteed to be 8

  return 0;
}
