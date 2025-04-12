#include <iostream>
#include <vector>

int main() {
  std::vector<char> delimiters = {
      ",", ";"}; // tries to interpret it as delimiters(x,y)
  std::cout << delimiters[0];
  return 0;
}
